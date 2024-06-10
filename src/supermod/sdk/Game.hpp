#pragma once
#include <supermod/pch.hpp>

#include <d3d8/d3d8helpers.h>
#include <fstream>
#include <semver/semver.hpp>
#include <supermod/data.hpp>
#include <supermod/modloader/mod/impl/lua/lua.hpp>

namespace sm::sdk
{
class Game
{
public:
    static inline HWND* window = nullptr;

    static void Init();

    static void Free(void* mem);

    static void Restart();
    static void StartEditor();

    static bool IsGameLoaded();
    static bool IsGameInLoadingTick();
    static bool IsGameFullscreen();
    static inline bool currentTickIsInner = false;
    static inline bool bootMenuActive = false;
    static inline bool booted = false;
    static inline vector2i lastResolution = {800, 600};

    static std::filesystem::path GetRootPath();
    static char* GetRawDataPath();
    static void RequestExit();
    static std::filesystem::path GetDataPath();
    static std::filesystem::path GetModsPath();

    static semver::version GetSdkVersion() { return semver::version::parse(SUPERMOD_VERSION); }
    static uint64_t GetGameVersion();

    static std::string SerializeGameVersion(uint64_t version);
    static uint64_t ParseGameVersion(const std::string& version);
    static vector2 GetRenderSize();

    struct World
    {
        static rect GetCamWorldRect();
        static vector2 GetWorldProjectionSize();
        static float GetCamZoom();
        static vector2 GetCamPos();
        static vector2 ScreenToWorld(vector2 coords);
        // boolean determines if the coords are on screen currently or no
        static std::tuple<vector2, bool> WorldToScreen(vector2 coords);
    };

    static void AddToLua(sol::table lua)
    {
        lua["restart"] = Restart;
        lua["isGameLoaded"] = IsGameLoaded;
        lua["getDataPath"] = GetDataPath;
        lua["getModsPath"] = GetModsPath;
        lua["getGameVersion"] = GetGameVersion;
        lua["serializeGameVersion"] = SerializeGameVersion;
        lua["parseGameVersion"] = ParseGameVersion;
        lua["getRenderSize"] = GetRenderSize;

        auto world = lua.create_named("world");
        world["getCamWorldRect"] = World::GetCamWorldRect;
        world["getWorldProjectionSize"] = World::GetWorldProjectionSize;
        world["getCamZoom"] = World::GetCamZoom;
        world["getCamPos"] = World::GetCamPos;
        world["screenToWorld"] = World::ScreenToWorld;
        world["worldToScreen"] = World::WorldToScreen;
    }

private:
    inline static std::optional<std::filesystem::path> _rootPath;
};
} // namespace sm::sdk
