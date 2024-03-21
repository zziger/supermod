#pragma once
#include <fstream>
#include <filesystem>
#include <yaml-cpp/yaml.h>
#include <mutex>

#include "LuaContext.h"

class Config {
    inline static std::filesystem::path cfgPath {};
    inline static YAML::Node cfgNode { YAML::NodeType::Map };
    
public:
    static void Init();

    static YAML::Node& Get() {
        return cfgNode;
    }

    static void Save();

    YAML::Node& data;

    // todo optional lock somehow

    Config() : data(cfgNode) {
    } 

    ~Config() {
        Save();
    }

    static void AddToLua(LuaContext& context, std::string modId);
};
