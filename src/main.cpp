#include <iostream>
#include <locale>
#include <Windows.h>
#include <shellapi.h>
#include <thread>

#include "Utils.h"
#include "main.h"

#include <filesystem>
#include <memory>
#include <yaml-cpp/yaml.h>

#include "Config.h"
#include "CConsole.h"
#include "CGameApis.h"
#include "ui/UI.h"
#include "Log.h"
#include "events/EventManager.h"
#include "events/GameLoadedEvent.h"
#include "memory/HookManager.h"
#include "memory/Memory.h"
#include "CWidescreenFix.h"
#include "modloader/mods/ModFileResolver.h"
#include "modloader/mods/ModManager.h"
#include "patches/LoadingFreezePatch.cpp"
#include "patches/AllowMultipleInstances.cpp"

// #include "patches/CAllowMultipleInstances.h"
// #include "patches/CRenderUnfocused.h"
// #include "patches/CWidescreenFix.h"
// #include "patches/CAdditionalMusic.h"
// #include "patches/CEditor.h"
// #include "patches/CFpsLimit.h"
//
// #include "mods/CPowerupsKill.h"
// #include "mods/CLadno.h"
// #include "mods/CStartupSplash.h"
// #include "mods/CEarlyStats.h"

// HOOK_FN(int, setupD3dParams, ARGS()) {
//     Log::Info << "Sussy!" << Log::Endl;
//     return setupD3dParams_orig();
// }


int (*debug_log_orig)(char* format, ...);
int debug_log(char* format, ...) {
    va_list va;
    va_start(va, format);
    char buffer[1024];
    vsprintf_s(buffer, 1024, format, va);
    // Log::Game << buffer << Log::Endl;
    return 0;
}

DWORD WINAPI Init() {
    auto cwd = std::filesystem::current_path();
    Config::Init(); 
    CConsole::Initialize();
    Log::Info << "Загрузка SuperMod " << VERSION << " by zziger..." << Log::Endl;
    
    const auto base = (uintptr_t) GetModuleHandle(nullptr);
    
    Memory::Base() = base;
    Memory::OnPatternNotFound([](const std::string& pattern) {
        Log::Error << "Failed to find pattern " << pattern << Log::Endl;
    });
    Memory::InitCacheStorage(new MemoryCacheStorage());

    CGameApis::InitializeThis();
    MH_Initialize();
    Memory::RunHooks();

    ModManager::Init();
    ModManager::LoadMods();
    
    // CModuleManager::RegisterModules({
    //     // new CAllowMultipleInstances,
    //     // new CRenderUnfocused,
    //     // new CFpsLimit,
    //     // new CWidescreenFix,
    //     // new CEditor,
    //     // new CAdditionalMusic,
    //     
    //     // new CStartupSplash,
    //     // new CPowerupsKill,
    //     // new CLadno,
    //     // new CEarlyStats
    // });
    // CModuleManager::Initialize();
    // CModuleManager::LogModules();
    // CModLoader::Instance().Initialize();

    HookManager::RegisterHook("55 8B EC 83 EC ? 0F B6 05 ? ? ? ? 85 C0 75 ? E9 ? ? ? ? 8D 4D", HOOK_REF_FORCE(debug_log));
    ModFileResolver::Init();
    EventManager::Emit(ReadyEvent());
    
    EventManager::On<GameLoadedEvent>([](auto ev) {
        // CGameApis::ShowLowerMessage(?"sussy"_u16);
        Log::Info << "Game startup!" << Log::Endl;
        ModManager::ReloadIcons();
        DragAcceptFiles(*CGameApis::window, true);
    });

    EventManager::On<WindowEvent>([](auto ev) {
        if (ev.msg == WM_DROPFILES) {
            auto drop = (HDROP) (ev.wParam);
            
            uint32_t nCntFiles= DragQueryFileA( drop, -1, 0,0 );
            Log::Debug << nCntFiles << Log::Endl;
                      
            for (int j=0; j<nCntFiles; j++ ) {
                char szBuf[MAX_PATH];
                ::DragQueryFileA( drop, j, szBuf, sizeof(szBuf) );
                Log::Debug << szBuf << Log::Endl;
            }

            DragFinish(drop);
        }
    });
    
    return true;
}

BOOL APIENTRY main(HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpReserved) {
    if (ul_reason_for_call == DLL_PROCESS_ATTACH) {
        Init();
        // CreateThread(0, 0, Init, hModule, 0, 0);

        Log::Info << "Mod initialized!" << Log::Endl;
    }

    if (ul_reason_for_call == DLL_PROCESS_DETACH) {
        CConsole::Destroy();
        ShowWindow(GetConsoleWindow(), SW_HIDE);
    }
    return TRUE;
}

// GLOBAL_HOOK("55 8B EC 51 0F B6 45 08", DWORD, showCursorSus, ARGS(char a1), {
//     CGameApis::cursorState = a1;
//     return showCursorSus_orig(a1);
// });
//
// GLOBAL_HOOK("55 8B EC 81 EC ? ? ? ? A1 ? ? ? ? 89 45 ? 68 ? ? ? ? 68", int, sussy, ARGS(), {
//     if (!CGameApis::cursorState && CGUI::menuOpen) {
//         *(int*)0x00AF2BD8 = 0;
//         return false;
//     }
//     return sussy_orig();
// });
//
// bool forcedGamePause = false;
// GLOBAL_HOOK("55 8B EC 51 89 4D ? 0F B6 05 ? ? ? ? 85 C0 75 ? E8", int, sussy2, ARGS(), {
//     auto var = (byte*)0x51430F;
//     if (!CGameApis::cursorState && CGUI::menuOpen) {
//         if (!*var) {
//             *var = true;
//             forcedGamePause = true;
//         }
//     } else {
//         if (forcedGamePause) {
//             *var = false;
//             forcedGamePause = false;
//         }
//     }
//     return sussy2_orig();
// });