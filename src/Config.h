#pragma once
#include <filesystem>
#include <fstream>
#include <mutex>
#include <sdk/Game.h>
#include <spdlog/common.h>
#include <yaml-cpp/yaml.h>

class Config
{
    const std::filesystem::path path = sdk::Game::GetRootPath() / "modcfg.yml";
    YAML::Node node{YAML::NodeType::Map};

    Config();

public:
    Config(const Config&) = delete;

    static Config& Get()
    {
        static Config cfg;
        return cfg;
    }

    static YAML::Node& GetYaml() { return Get().node; }

    void Save();

    enum class WatermarkPosition : int
    {
        TOP_LEFT,
        TOP_CENTER,
        TOP_RIGHT,
        BOTTOM_LEFT,
        BOTTOM_CENTER,
        BOTTOM_RIGHT
    };

    enum class ResolutionPatchMode : int
    {
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
    } watermark{};
    struct
    {
        struct
        {
            bool enabled = false;
            bool writeToLog = false;
        } forwardGameLogs{};
    } patches{};
    struct
    {
        bool showImGuiDemo = false;
    } developer{};
    struct
    {
        spdlog::level::level_enum level = spdlog::level::info;
        int maxFiles = 5;
        bool limitFiles = true;
    } log{};
    struct
    {
        bool dockingWithShift = true;
    } imgui{};
    struct
    {
        bool checkAutomatically = true;
        bool usePrerelease = false;
    } updater{};

#define LINK(struct, path)                                                                                             \
    if (read)                                                                                                          \
        struct = node##path.as<decltype(struct)>(struct);                                                              \
    else                                                                                                               \
        node##path = struct
#define LINK_T(struct, path, type)                                                                                     \
    if (read)                                                                                                          \
        struct = static_cast<decltype(struct)>(node##path.as<type>(static_cast<type>(struct)));                        \
    else                                                                                                               \
        node##path = static_cast<type>(struct)

    void Process(const bool read)
    {
        LINK(disabled, ["disabled"]);
        LINK(console, ["console"]);
        LINK(console, ["console"]);
        LINK(watermark.show, ["watermark"]["show"]);
        LINK_T(watermark.position, ["watermark"]["position"], int);
        LINK(watermark.opacity, ["watermark"]["opacity"]);
        LINK(watermark.bgOpacity, ["watermark"]["bgOpacity"]);
        LINK(patches.forwardGameLogs.enabled, ["patches"]["forwardGameLogs"]["enabled"]);
        LINK(patches.forwardGameLogs.writeToLog, ["patches"]["forwardGameLogs"]["writeToLog"]);
        LINK(developer.showImGuiDemo, ["developer"]["showImGuiDemo"]);
        LINK(imgui.dockingWithShift, ["imgui"]["dockingWithShift"]);
        LINK_T(log.level, ["log"]["level"], int);
        LINK(log.maxFiles, ["log"]["maxFiles"]);
        LINK(log.limitFiles, ["log"]["limitFiles"]);
        LINK(updater.checkAutomatically, ["updater"]["checkAutomatically"]);
        LINK(updater.usePrerelease, ["updater"]["usePrerelease"]);
    }

    static void AddLuaIntrinsics(sol::table table, const std::string& modId)
    {
        table["__getModConfig"] = [modId] { return GetYaml()["modConfigs"][modId]; };
        table["__configKeyExists"] = [](const YAML::Node& node, const std::string& key) { return !!node[key]; };
        table["__configGetString"] = [](const YAML::Node& node, const std::string& key) {
            return node[key].as<std::string>("");
        };
        table["__configGetDouble"] = [](const YAML::Node& node, const std::string& key) {
            return node[key].as<double>(0);
        };
        table["__configGetBool"] = [](const YAML::Node& node, const std::string& key) {
            return node[key].as<bool>(false);
        };
        table["__configGetNested"] = [](const YAML::Node& node, const std::string& key) { return node[key]; };
        table["__configSet"] =
            sol::overload([](YAML::Node& node, bool val, const std::string& key) { node[key] = val; },
                          [](YAML::Node& node, long long val, const std::string& key) { node[key] = val; },
                          [](YAML::Node& node, double val, const std::string& key) { node[key] = val; },
                          [](YAML::Node& node, const std::string& val, const std::string& key) { node[key] = val; });
        table["__configSave"] = [] { Get().Save(); };
    }

    static void RemoveLuaIntrinsics(sol::table table)
    {
        table["__getModConfig"] = sol::nil;
        table["__configKeyExists"] = sol::nil;
        table["__configGetString"] = sol::nil;
        table["__configGetDouble"] = sol::nil;
        table["__configGetBool"] = sol::nil;
        table["__configGetNested"] = sol::nil;
        table["__configSet"] = sol::nil;
        table["__configSave"] = sol::nil;
    }
};
