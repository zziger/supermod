#pragma once
#include <fstream>
#include <optional>

#include "thirdparty/LuaContext.h"
#include "thirdparty/directx/d3d8.h"

namespace sdk
{
    class Game {
    public:
    
        static inline HWND* window = nullptr;

        static void Init();

        static void Restart();

        static bool IsGameLoaded();

        static std::filesystem::path GetDataPath();
        static std::filesystem::path GetModsPath();

        static void AddToLua(LuaContext& context);
    private:
        inline static std::filesystem::path* _dataPath;
    };
}