#pragma once
#include <fstream>
#include <filesystem>
#include <yaml-cpp/yaml.h>
#include <mutex>
#include <sdk/Game.h>
#include <spdlog/common.h>

#include "LuaContext.h"

class Config {
    const std::filesystem::path path = sdk::Game::GetRootPath() / "modcfg.yml";
    YAML::Node node { YAML::NodeType::Map };

    Config();

public:
    static Config& Get()
    {
        static Config cfg;
        return cfg;
    }

    static YAML::Node& GetYaml() {
        return Get().node;
    }

    void Save();

    enum class WatermarkPosition : int {
        TOP_LEFT,
        TOP_CENTER,
        TOP_RIGHT,
        BOTTOM_LEFT,
        BOTTOM_CENTER,
        BOTTOM_RIGHT
    };

    enum class ResolutionPatchMode : int {
        WINDOW,
        SCREEN,
        CUSTOM
    };

    bool disabled = false;
    bool console = true;
    struct
    {
        bool show = true;
        WatermarkPosition position = WatermarkPosition::TOP_CENTER;
        float opacity = 1.f;
        float bgOpacity = 0.35f;
    } watermark {};
    struct
    {
        struct
        {
            bool enabled = false;
            bool writeToLog = false;
        } forwardGameLogs {};
    } patches {};
    struct
    {
        bool showImGuiDemo = false;
    } developer {};
    struct
    {
        spdlog::level::level_enum level = spdlog::level::info;
        int maxFiles = 5;
        bool limitFiles = true;
    } log {};

    #define LINK(struct, path) if (read) struct = node##path.as<decltype(struct)>(struct); else node##path = struct
    #define LINK_T(struct, path, type) if (read) struct = static_cast<decltype(struct)>(node##path.as<type>(static_cast<type>(struct))); else node##path = static_cast<type>(struct)
    void Process(const bool read)
    {
        LINK(disabled, ["disabled"]);
        LINK(console, ["console"]);
        LINK(watermark.show, ["watermark"]["show"]);
        LINK_T(watermark.position, ["watermark"]["position"], int);
        LINK(watermark.opacity, ["watermark"]["opacity"]);
        LINK(watermark.bgOpacity, ["watermark"]["bgOpacity"]);
        LINK(patches.forwardGameLogs.enabled, ["patches"]["forwardGameLogs"]["enabled"]);
        LINK(patches.forwardGameLogs.writeToLog, ["patches"]["forwardGameLogs"]["writeToLog"]);
        LINK(developer.showImGuiDemo, ["developer"]["showImGuiDemo"]);
        LINK_T(log.level, ["log"]["level"], int);
        LINK(log.maxFiles, ["log"]["maxFiles"]);
        LINK(log.limitFiles, ["log"]["limitFiles"]);
    }

    static void AddToLua(LuaContext& context, const std::string& modId);
};
