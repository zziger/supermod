#include "Config.h"

#include <filesystem>

void Config::Init() {
    _cfgPath = std::filesystem::current_path() / "modcfg.yml";
    if (exists(_cfgPath)) _cfg = YAML::LoadFile(_cfgPath.string());
}

void Config::Save() {
    std::ofstream fstream(_cfgPath);
    fstream << _cfg;
}

void Config::AddToLua(LuaContext& context, std::string modId) {
    context.writeFunction("__getModConfig", std::function([=]() {
        return _cfg["modConfigs"][modId];
    }));
    context.writeFunction("__configKeyExists", std::function([](YAML::Node node, std::string key) {
        if (node[key]) return true;
        return false;
    }));
    context.writeFunction("__configGetString", std::function([](YAML::Node node, std::string key) {
        return node[key].as<std::string>("");
    }));
    context.writeFunction("__configGetDouble", std::function([](YAML::Node node, std::string key) {
        return node[key].as<double>(0);
    }));
    context.writeFunction("__configGetBool", std::function([](YAML::Node node, std::string key) {
        return node[key].as<bool>(false);
    }));
    context.writeFunction("__configGetNested", std::function([](YAML::Node node, std::string key) {
        return node[key];
    }));
    context.writeFunction("__configSet", std::function([](YAML::Node& node, std::variant<bool, long long, double, std::string> val, const std::string& key) {
        std::visit([&](auto&& visited) {
            node[key] = visited;
        }, val);
    }));
    context.writeFunction("__configSave", std::function([]() {
        Save();
    }));
}
