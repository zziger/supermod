#pragma once
#include <fstream>
#include <filesystem>
#include <yaml-cpp/yaml.h>
#include <mutex>
#include <sdk/Game.h>

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
            bool enabled = true;
            ResolutionPatchMode mode = ResolutionPatchMode::WINDOW;
            int width = 800;
            int height = 600;
        } resolution {};
        struct
        {
            bool enabled = false;
            bool writeToLog = false;
        } forwardGameLogs {};
        struct
        {
            bool enabled = false;
        } renderUnfocused {};
    } patches {};

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
        LINK(patches.resolution.enabled, ["patches"]["resolution"]["enabled"]);
        LINK(patches.resolution.height, ["patches"]["resolution"]["height"]);
        LINK(patches.resolution.width, ["patches"]["resolution"]["width"]);
        LINK_T(patches.resolution.mode, ["patches"]["resolution"]["mode"], int);
    }

    static void AddToLua(LuaContext& context, const std::string& modId);
};
