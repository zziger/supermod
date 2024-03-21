#include "Config.h"

#include <filesystem>
#include <Log.h>

void Config::Init() {
    cfgPath = std::filesystem::current_path() / "modcfg.yml";
    if (exists(cfgPath)) cfgNode = YAML::LoadFile(cfgPath.string());
    cfgNode.SetStyle(YAML::EmitterStyle::Block);
}

void Config::Save() {
    cfgNode.SetStyle(YAML::EmitterStyle::Block);
    std::ofstream fstream(cfgPath);
    fstream << cfgNode;
}

void Config::AddToLua(LuaContext& context, std::string modId) {
    context.writeFunction("__getModConfig", std::function([=]() {
        return cfgNode["modConfigs"][modId];
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
