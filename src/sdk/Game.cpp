#include "Game.h"

#include <filesystem>

#include "DirectX.h"
#include "Utils.h"
#include "game/AssetPool.h"
#include "memory/HookManager.h"
#include "memory/Memory.h"

HOOK_FN_CONV(char*, getCachedFile, ARGS(char* name), __cdecl) {
    return nullptr;
}


namespace sdk
{
    void Game::Init() {
        constexpr Memory::Pattern movWindow("A3 ? ? ? ? 83 3D ? ? ? ? ? 74 ? 68 ? ? ? ? E8 ? ? ? ?");
        window = *movWindow.Search().Get<HWND**>(1);

        sdk::DirectX::Init();
        HookManager::RegisterHook("55 8B EC 83 EC ? A1 ? ? ? ? 89 45 ? 8B 45 ? 50 8D 4D", HOOK_REF(getCachedFile));
    }


    
    
    void Game::Restart() {
        // ReloadTexture(GetDataPath() / "ui" / "_a_lifebar.jpg");
        // auto pool = (game::AssetPool*) 0x1423CF8;
        // Log::Debug << "Asset count was " << pool->assetCount << Log::Endl;
        // Log::Debug << "Assets:" << Log::Endl;
        //
        // for (auto i = 0; i < pool->assetCount; i++) {
        //     Log::Debug << "Asset " << i << ": " << pool->assets[i]->name << Log::Endl;
        // }
        // static constexpr Memory::Pattern pat("55 8B EC E8 ? ? ? ? E8 ? ? ? ? E8");
        // static auto mem = pat.Search();
        // mem.Call();
        char buf[MAX_PATH];
        GetModuleFileNameA(nullptr, buf, MAX_PATH);
        std::filesystem::current_path(GetDataPath() / "..");
        
        STARTUPINFOA si(0);
        si.cb = sizeof(STARTUPINFOA);
        PROCESS_INFORMATION	pi(nullptr);
        
        CreateProcessA(nullptr, buf, nullptr, nullptr, false, 0, nullptr, nullptr, &si, &pi);
        ExitProcess(0);
    }
    
    bool Game::IsGameLoaded() {
        static constexpr Memory::Pattern gameLoadFinishedPat("C6 05 ? ? ? ? ? E8 ? ? ? ? 68"); // mov gameLoadFinished, 1
        const auto mem = gameLoadFinishedPat.Search();
        const auto ptr = *mem.Get<bool**>(2);
        if (ptr == nullptr) return false;
        return ptr;
    }

    // todo wtf is this
    std::filesystem::path Game::GetDataPath() {
        if (_dataPath) return *_dataPath;
        
        static constexpr Memory::Pattern path_to_data_pat("68 ? ? ? ? FF 15 ? ? ? ? 68 ? ? ? ? 6A ? 6A ?");
        std::string strPath;
        auto strPtr = *path_to_data_pat.Search().Get<char**>(1);
        strPath.assign(strPtr, std::find(strPtr, strPtr + 256, '\0'));
        static auto pathToData = strPath.empty() ? std::filesystem::current_path() / "data" : std::filesystem::path(strPath);
        _dataPath = new std::filesystem::path(pathToData);
        return pathToData;
    }

    std::filesystem::path Game::GetModsPath() {
        return GetDataPath() / ".." / "mods";
    }
}