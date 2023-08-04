#include "modloader/mods/ModInfo.h"

#include <regex>
#include <yaml-cpp/yaml.h>

#include "DirectXUtils.h"
#include "Log.h"
#include "Utils.h"
#include "assets/assets.h"
#include "exceptions/Error.h"
#include "sdk/DirectX.h"
#include "sdk/Game.h"
#include <semver.hpp>
#include <lodepng.h>

void ModInfo::ReadManifest() {
    const auto filePath = basePath / "manifest.yml";
    const auto strPath = filePath.generic_string();
        
    if (!exists(filePath)) throw Error("Не удалось найти файл " + strPath);

    auto node = YAML::LoadFile(strPath);
    ModInfo::ReadManifest(node);
}

void ModInfo::ReadIcon()
{
    ReleaseIcon();
    const auto path = basePath / "icon.png";
    if (!exists(path)) return;
    
    const auto readRes = lodepng::decode(iconData, iconWidth, iconHeight, path.string());
    if (readRes != 0) throw Error("Не удалось прочитать PNG");
    hasIcon = true;
}


void ModInfo::ReadManifest(YAML::Node node) {
    if (!node.IsMap()) throw Error("Неверный формат манифеста");
    if (!node["id"]) throw Error("Не удалось найти id в манифесте");
        
    id = node["id"].as<std::string>();
    const std::regex idRegex("^[a-zA-Z0-9_-]{2,32}$");

    if (!std::regex_match(id, idRegex)) {
        throw Error("Id в манифесте должен состоять из символов английского алфавита, цифр, _ или - и быть длиной от 2 до 32 символов");
    }
    
    title = node["title"].as<std::string>(id);
    description = std::regex_replace(node["description"].as<std::string>(""), std::regex("^\\s+|\\s+$"), "");
    author = node["author"].as<std::string>("");
    version = node["version"].as<std::string>("");
    luaScript = node["lua-script"].as<std::string>("");
    sdkVersion = semver::version {node["sdk-version"].as<std::string>(VERSION)};
    socialLinks = node["socialLinks"].as<std::map<std::string, std::string>>(std::map<std::string, std::string>{});

    const auto currentGameVersion = sdk::Game::GetGameVersion();
    const auto versions = node["game-versions"].as<std::vector<std::string>>(std::vector<std::string>{});

    if (!versions.empty()) {
        compatible = false;
        for (const auto& gameVersionString : versions) {
            auto gameVersion = sdk::Game::ParseGameVersion(gameVersionString);
            if (!gameVersion) {
                Log::Warn << "Неверная версия " << gameVersionString << " в моде " << title << Log::Endl;
                continue;
            }
            gameVersions.push_back(gameVersion);
            if (gameVersion == currentGameVersion) {
                compatible = true;
            }
        } 
    }

    if (!node["title"]) Log::Warn << "Не указано название для мода " << id << Log::Endl;
    if (!compatible) Log::Warn << "Мод " << title << " не совместим с текущей версией игры" << Log::Endl;
}

void ModInfo::EnsureIcon() {
    if (!this->hasIcon || !*sdk::DirectX::d3dDevice) return;
    if (icon != nullptr) return;
    icon = dx_utils::load_argb_pixel_data(*sdk::DirectX::d3dDevice, iconWidth, iconHeight, iconData.data());
}

void ModInfo::ReleaseIcon()
{
    if (icon == nullptr) return;
    icon->Release();
    icon = nullptr;
}

ModInfo::ModInfo(): id("invalid"), title("Invalid"), author("unknown"), version("invalid") {}

ModInfo::ModInfo(const std::string& manifestContent) {
    ReadManifest(YAML::Load(manifestContent));
    ReadIcon();
}

ModInfo::ModInfo(std::filesystem::path modPath): basePath(std::move(modPath)) {
    ReadManifest();
    ReadIcon();
}

ModInfo::ModInfo(std::string id, std::string title, std::string description, std::string author, std::string version)
    : id(std::move(id)), title(std::move(title)), author(std::move(author)), version(std::move(version)), description(description),
      sdkVersion(VERSION), basePath(""), internal(true)
{
    socialLinks["discord"] = "https://discord.supercow.community";
    socialLinks["github"] = "https://github.com/zziger/supercow-mod";
    const auto buf = *utils::read_resource(RES_LOGO);
    const auto readRes = lodepng::decode(iconData, iconWidth, iconHeight, reinterpret_cast<const unsigned char*>(buf.data()), buf.size());
    if (readRes == 0) hasIcon = true;
}