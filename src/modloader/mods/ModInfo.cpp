#include "modloader/mods/ModInfo.h"

#include <regex>
#include <yaml-cpp/yaml.h>

#include "CGameApis.h"
#include "DirectXUtils.h"
#include "Log.h"
#include "exceptions/Error.h"

void ModInfo::ReadManifest() {
    const auto filePath = basePath / "manifest.yml";
    const auto strPath = filePath.generic_string();
        
    if (!exists(filePath)) throw Error("Не удалось найти файл " + strPath);

    auto node = YAML::LoadFile(strPath);
    if (!node.IsMap()) throw Error("Неверный формат файла " + strPath);
    if (!node["id"]) throw Error("Не удалось найти id в файле " + strPath);
        
    id = node["id"].as<std::string>();
    const std::regex idRegex("^[a-zA-Z0-9_-]{2,32}$");

    if (!std::regex_match(id, idRegex)) {
        throw Error("Id в файле " + strPath + " должен состоять из символов английского алфавита, цифр, _ или - и быть длиной от 2 до 32 символов");
    }
    
    title = node["title"].as<std::string>(id);
    author = node["author"].as<std::string>("unknown");
    version = node["version"].as<std::string>("0.0.0");
        
    if (!node["title"]) Log::Warn << "Не указано название для мода " << id << Log::Endl;
}

bool ModInfo::ReadIcon() {
    if (!*CGameApis::d3dDevice) return false;
    icon = dx_utils::load_png(*CGameApis::d3dDevice, (basePath / "icon.png").string().c_str());
    return true;
}
ModInfo::ModInfo(): id("invalid"), title("Invalid"), author("unknown"), version("invalid") {}


ModInfo::ModInfo(std::filesystem::path modPath, HMODULE module): basePath(std::move(modPath)), dll(module) {
    ReadManifest();
}

ModInfo::ModInfo(std::string id, std::string title, std::string author, std::string version)
    : id(std::move(id)), title(std::move(title)), author(std::move(author)), version(std::move(version)),
    basePath(""), internal(true) {
        
}