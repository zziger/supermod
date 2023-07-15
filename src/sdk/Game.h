#pragma once
#include <fstream>
#include <optional>

#include "Data.h"
#include "thirdparty/LuaContext.h"
#include <semver.hpp>
#include "thirdparty/directx/d3d8.h"

namespace sdk
{
    class Game {
    public:
    
        static inline HWND* window = nullptr;

        static void Init();

        static void Restart();
        static void StartEditor();

        static bool IsGameLoaded();
        static bool IsGameInLoadingTick();
        static bool IsGameFullscreen();
        static inline bool currentTickIsInner = false;
        static inline bool bootMenuActive = false;
        static inline bool booted = false;

        static std::filesystem::path GetRootPath();
        static char* GetRawDataPath();
        static std::filesystem::path GetDataPath();
        static std::filesystem::path GetModsPath();

        static constexpr semver::version GetSdkVersion() {
            return semver::version { VERSION };
        }
        static uint64_t GetGameVersion();

        static std::string SerializeGameVersion(uint64_t version);
        static uint64_t ParseGameVersion(const std::string& version);
        static vector2 GetRenderSize();

        struct World
        {
            static rect GetCamWorldRect();
            static float GetCamZoom();
            static vector2 ScreenToWorld(vector2 coords);
            // boolean determines if the coords are on screen currently or no
            static std::tuple<vector2, bool> WorldToScreen(vector2 coords);
        };

        static void AddDataToLua(LuaContext& context);
        static void AddToLua(LuaContext& context);
    private:
        inline static std::optional<std::filesystem::path> _rootPath;
    };
}