#include "Game.h"

#include <filesystem>

#include "Data.h"
#include "DirectX.h"
#include "Log.h"
#include "Utils.h"
#include "game/AssetPool.h"
#include "game/SoundHost.h"
#include "memory/HookManager.h"
#include "memory/Memory.h"

namespace sdk
{
    void Game::Init() {
        constexpr Memory::Pattern movWindow("A3 ? ? ? ? 83 3D ? ? ? ? ? 74 ? 68 ? ? ? ? E8 ? ? ? ?");
        window = *movWindow.Search().Get<HWND**>(1);

        sdk::DirectX::Init();
    }
    
    void Game::Restart() {
        wchar_t buf[MAX_PATH];
        GetModuleFileNameW(nullptr, buf, MAX_PATH);
        std::filesystem::current_path(GetDataPath() / "..");
        
        STARTUPINFOW si(0);
        si.cb = sizeof(STARTUPINFOW);
        PROCESS_INFORMATION	pi(nullptr);
        
        CreateProcessW(nullptr, buf, nullptr, nullptr, false, 0, nullptr, nullptr, &si, &pi);
        ExitProcess(0);
    }
    
    void Game::StartEditor() {
        static constexpr Memory::Pattern editorDisableInstruction("C6 05 ? ? ? ? ? 0F B6 15 ? ? ? ? 85 D2 75 ? C7 05 ? ? ? ? ? ? ? ?");
        static auto mem4 = editorDisableInstruction.Search();
        const auto ptr = *mem4.Get<byte**>(2); 
        *ptr = 1;
        ShowWindow(*window, SW_SHOWMAXIMIZED);
    }

    bool Game::IsGameLoaded() {
        static constexpr Memory::Pattern gameLoadFinishedPat("C6 05 ? ? ? ? ? E8 ? ? ? ? 68"); // mov gameLoadFinished, 1
        static auto mem = gameLoadFinishedPat.Search();
        static auto ptr = *mem.Get<bool**>(2);
        if (ptr == nullptr) return false;
        return *ptr;
    }

    bool Game::IsGameInLoadingTick() {
        static constexpr Memory::Pattern gameLoadFinishedPat("C6 05 ? ? ? ? ? E9 ? ? ? ? 0F B6 0D"); // mov shouldRenderInReadfile, 1
        static auto mem = gameLoadFinishedPat.Search();
        static auto ptr = *mem.Get<bool**>(2);
        if (ptr == nullptr) return false;
        return *ptr;
    }
    
    bool Game::IsGameFullscreen() {
        static constexpr Memory::Pattern pat("83 3D ? ? ? ? ? 0F 94 C0"); // cmp fullscreen, 0
        static auto mem = pat.Search();
        return **mem.Get<bool**>(2);
    }

    std::filesystem::path Game::GetRootPath() {
        if (_rootPath) return *_rootPath;

        const auto hModule = GetModuleHandleW(nullptr);
        if (hModule != nullptr)
        {
            wchar_t path[MAX_PATH];
            GetModuleFileNameW(hModule, path, sizeof path);
            auto rootPath = std::filesystem::path(path).parent_path(); 
            _rootPath = rootPath;
            return rootPath;
        }
        
        return std::filesystem::path {};
    }

    char* Game::GetRawDataPath()
    {
        static constexpr Memory::Pattern pat("68 ? ? ? ? FF 15 ? ? ? ? B9");
        static auto mem = pat.Search();
        return *mem.Get<char**>(1);
    }

    std::filesystem::path Game::GetDataPath() {
        return GetRootPath() / "data";
    }

    std::filesystem::path Game::GetModsPath() {
        return GetRootPath() / "mods";
    }

    uint64_t Game::GetGameVersion() {
        const auto dosHeader = (IMAGE_DOS_HEADER*) GetModuleHandleW(nullptr);
        const auto ntHeaders = (IMAGE_NT_HEADERS*) ((byte*)dosHeader + dosHeader->e_lfanew);
        return ntHeaders->FileHeader.TimeDateStamp;
    }
    
    std::string Game::SerializeGameVersion(uint64_t version) {
        auto timestamp = (std::chrono::sys_seconds) (std::chrono::seconds) version;
        return std::format("{:%d.%m.%Y %T}", timestamp);
    }
    
    uint64_t Game::ParseGameVersion(const std::string& version) {
        std::chrono::sys_seconds timestamp;
        std::istringstream in(version);
        in >> parse("%d.%m.%Y %T", timestamp);
        return timestamp.time_since_epoch().count();
    }
    
    rect Game::World::GetCamWorldRect()
    {
        static constexpr Memory::Pattern pat("B9 ? ? ? ? E8 ? ? ? ? D9 5D");
        static auto mem = pat.Search();
        static auto ptr = *mem.Get<rect**>(1);
        return *ptr;
    }
    
    float Game::World::GetCamZoom()
    {
        static constexpr Memory::Pattern pat("D8 0D ? ? ? ? D8 0D ? ? ? ? D8 35");
        static auto mem = pat.Search();
        static auto ptr = *mem.Get<float**>(2);
        return *ptr;
    }

    vector2 Game::World::ScreenToWorld(vector2 coords)
    {
        const auto zoom = GetCamZoom();
        const auto cam = GetCamWorldRect();
        return {
            cam.left + coords.x / 32 * zoom,
            cam.top - coords.y / 32 * zoom
        };
    }

    std::tuple<vector2, bool> Game::World::WorldToScreen(vector2 coords)
    {
        const auto zoom = GetCamZoom();
        const auto cam = GetCamWorldRect();

        bool onScreen = coords.x >= cam.left && coords.x <= cam.right && coords.y >= cam.bottom && coords.y <= cam.top;
        
        auto pos = vector2{
            (coords.x - cam.left) / zoom * 32,
            (cam.top - coords.y) / zoom * 32,
        };

        return { pos, onScreen };
    }
    
    void Game::AddDataToLua(LuaContext& context)
    {
        context.writeFunction("vector2", std::function([](float x, float y) {
            return vector2{x, y};
        }));
        
        context.registerMember("x", &vector2::x);
        context.registerMember("y", &vector2::y);

        context.writeFunction("vector3", [](float x, float y, float z) {
            return vector3{x, y, z};
        });
        context.registerMember("x", &vector3::x);
        context.registerMember("y", &vector3::y);
        context.registerMember("z", &vector3::z);
        
        context.writeFunction("rect", [](float left, float top, float right, float bottom) {
            return rect{left, top, right, bottom};
        });
        context.registerMember("left", &rect::left);
        context.registerMember("top", &rect::top);
        context.registerMember("right", &rect::right);
        context.registerMember("bottom", &rect::bottom);
    }

    void Game::AddToLua(LuaContext& context) {
        context.writeVariable("game", std::map<int, int>{});
        context.writeVariable("game", "restart", Restart);
        context.writeVariable("game", "isGameLoaded", IsGameLoaded);
        context.writeVariable("game", "getDataPath", GetDataPath);
        context.writeVariable("game", "getModsPath", GetModsPath);
        context.writeVariable("game", "getGameVersion", GetGameVersion);
        context.writeVariable("game", "serializeGameVersion", SerializeGameVersion);
        context.writeVariable("game", "parseGameVersion", IsGameLoaded);
        context.writeVariable("game", "parseGameVersion", IsGameLoaded);
        
        context.writeVariable("game", "world", std::map<int, int>{});
        context.writeVariable("game", "world", "genCamWorldRect", World::GetCamWorldRect);
        context.writeVariable("game", "world", "getCamZoom", World::GetCamZoom);
        context.writeVariable("game", "world", "screenToWorld", World::ScreenToWorld);
        context.writeVariable("game", "world", "worldToScreen", World::WorldToScreen);
       
    }
}