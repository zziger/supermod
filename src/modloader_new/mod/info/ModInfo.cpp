#include "ModInfo.h"

#include <Log.h>
#include <regex>
#include <sdk/Game.h>

void modloader::ModInfo::Parse(YAML::Node& node)
{
    assert(id.empty() && "Tried to parse ModInfo overriding existing data");

    if (!node.IsMap()) throw ParseError("Неверный формат манифеста");
    if (!node["id"]) throw ParseError("Не удалось найти ID в манифесте");

    id = node["id"].as<std::string>();
    const std::regex idRegex("^[a-zA-Z0-9_-]{2,32}$");

    if (!std::regex_match(id, idRegex)) {
        throw Error("ID в манифесте должен состоять из символов английского алфавита, цифр, _ или - и быть длиной от 2 до 32 символов");
    }

    title = node["title"].as<std::string>(id);
    author = node["author"].as<std::string>("");
    version = node["version"].as<std::string>("");
    description = std::regex_replace(node["description"].as<std::string>(""), std::regex("^\\s+|\\s+$"), "");
    auto depsVector = node["deps"].as<std::vector<std::string>>(std::vector<std::string> {});
    deps = { depsVector.begin(), depsVector.end() };
    socialLinks = node["socialLinks"].as<std::map<std::string, std::string>>(std::map<std::string, std::string>{});

    sdkVersion = semver::version {node["sdk-version"].as<std::string>(VERSION)};
    const auto versions = node["game-versions"].as<std::vector<std::string>>(std::vector<std::string>{});
    if (!versions.empty()) {
        for (const auto& gameVersionString : versions) {
            auto gameVersion = sdk::Game::ParseGameVersion(gameVersionString);
            if (!gameVersion) {
                Log::Warn << "Неверная версия " << gameVersionString << " в моде " << title << Log::Endl; // todo warning container
                continue;
            }
            gameVersions.push_back(gameVersion);
        }
    }

    scriptMain = node["main"].as<std::string>(node["lua-script"].as<std::string>(""));
    scriptType = scriptMain.ends_with(".lua")
        ? ScriptType::LUA
        : scriptMain.ends_with(".dll")
            ? ScriptType::DLL
            : ScriptType::NONE; // TODO: better script type handling


    if (!node["title"]) Log::Warn << "Не указано название для мода " << id << Log::Endl;
    // todo compatibility check somewhere
}
