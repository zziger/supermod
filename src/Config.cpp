#include "Config.h"

#include <filesystem>
#include <Log.h>

Config::Config()
{
    if (exists(path))
    {
        node = YAML::LoadFile(path.string());
    }
    else
    {
        std::ofstream fstream(path);
        fstream << node;
    }
    node.SetStyle(YAML::EmitterStyle::Block);
    Process(true);
}

Config::~Config()
{
    Save();
}

void Config::Save() {
    Process(false);
    node.SetStyle(YAML::EmitterStyle::Block);
    std::ofstream fstream(path);
    fstream << node;
}

void Config::AddToLua(LuaContext& context, const std::string& modId) {
    context.writeFunction("__getModConfig", std::function([=] {
        return GetYaml()["modConfigs"][modId];
    }));
    context.writeFunction("__configKeyExists", std::function([](YAML::Node node, const std::string& key) {
        if (node[key]) return true;
        return false;
    }));
    context.writeFunction("__configGetString", std::function([](YAML::Node node, const std::string& key) {
        return node[key].as<std::string>("");
    }));
    context.writeFunction("__configGetDouble", std::function([](YAML::Node node, const std::string& key) {
        return node[key].as<double>(0);
    }));
    context.writeFunction("__configGetBool", std::function([](YAML::Node node, const std::string& key) {
        return node[key].as<bool>(false);
    }));
    context.writeFunction("__configGetNested", std::function([](YAML::Node node, const std::string& key) {
        return node[key];
    }));
    context.writeFunction("__configSet", std::function([](YAML::Node& node, std::variant<bool, long long, double, std::string> val, const std::string& key) {
        std::visit([&](auto&& visited) {
            node[key] = visited;
        }, val);
    }));
    context.writeFunction("__configSave", std::function([] {
        Get().Save();
    }));
}
