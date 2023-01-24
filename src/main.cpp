#include <iostream>
#include <locale>
#include <Windows.h>
#include <shellapi.h>
#include <thread>

#include "Utils.h"
#include "main.h"

#include <filesystem>
#include <yaml-cpp/yaml.h>
#include <objidl.h>
#include <gdiplus.h>

#include "Config.h"
#include "Console.h"
#include "CrashHandler.h"
#include "ui/UI.h"
#include "Log.h"
#include "events/EventManager.h"
#include "events/ResolveFileEvent.h"
#include "events/GameLoadedEvent.h"
#include "events/StartExecutionEvent.h"
#include "memory/HookManager.h"
#include "memory/Memory.h"
#include "modloader/mods/files/ModFileResolver.h"
#include "modloader/mods/ModManager.h"
#include "sdk/Game.h"

void init_memory() {
    const auto base = (uintptr_t) GetModuleHandle(nullptr);
    
    Memory::Base() = base;
    Memory::OnPatternNotFound([](const std::string& pattern) {
        Log::Error << "Не удалось найти паттерн " << pattern << Log::Endl;
    });
    Memory::InitCacheStorage(new MemoryCacheStorage());
}

void postInit() {
    ModManager::LoadMods();
    ModFileResolver::Init();
    EventManager::Emit(ReadyEvent());
}

HOOK_FN(int, load_game, ARGS()) {
    Log::Info << "Инициализация загрузки игры" << Log::Endl;
    tagMSG msg {};

    if (GetAsyncKeyState(VK_SHIFT) & 0x01) {
        sdk::Game::bootMenuActive = true;
    }

    if (sdk::Game::bootMenuActive) {
        Log::Info << "Boot меню активно" << Log::Endl;
        EnableMenuItem(GetSystemMenu(*sdk::Game::window, FALSE), SC_CLOSE, MF_BYCOMMAND | MF_DISABLED | MF_GRAYED);
    }
    
    while (sdk::Game::bootMenuActive) {
        sdk::Game::currentTickIsInner = true;
        auto start = GetTickCount64();
        (*sdk::DirectX::d3dDevice)->Clear(0, nullptr, D3DCLEAR_TARGET, 0xFF121212, 0, 0);
        EventManager::Emit(BeforeTickEvent{});
        (*sdk::DirectX::d3dDevice)->Present(nullptr, nullptr, nullptr, nullptr);
        EventManager::Emit(AfterTickEvent{});
        sdk::Game::currentTickIsInner = false;
        
        if ( PeekMessageA(&msg, nullptr, 0, 0, 1u) ) {
            TranslateMessage(&msg);
            DispatchMessageA(&msg);
        }

        const auto delta = GetTickCount64() - start;
        constexpr int needed = 10; 
        
        if (delta < needed) Sleep(needed - delta);
    }
    
    EnableMenuItem(GetSystemMenu(*sdk::Game::window, FALSE), SC_CLOSE, MF_BYCOMMAND | MF_ENABLED);
    return load_game_orig();
}

void init() {
    auto cwd = std::filesystem::current_path();
    Console::Initialize();
    Log::Info << "Загрузка SuperMod " << VERSION << " by zziger..." << Log::Endl;


    Gdiplus::GdiplusStartupInput gdiplusStartupInput;
    ULONG_PTR           gdiplusToken;

    GdiplusStartup(&gdiplusToken, &gdiplusStartupInput, NULL);
    
    MH_Initialize();
    sdk::Game::Init();

    ModManager::Init();
    hook_start_execution();

    static constexpr Memory::Pattern pat("E8 ? ? ? ? C6 05 ? ? ? ? ? 0F B6 05 ? ? ? ? 85 C0 74 ? 6A");
    HookManager::RegisterHook(Memory(pat.Search().GoToNearCall().Get<void*>()), HOOK_REF(load_game));

    EventManager::On<StartExecutionEvent>([] {
        Log::Info << "Пост-инициализация" << Log::Endl;
        postInit();
    });
    
    EventManager::On<GameLoadedEvent>([] {
        Log::Info << "Игра загружена!" << Log::Endl;
        
        ModManager::ReloadIcons();
        DragAcceptFiles(*sdk::Game::window, true);
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
}

BOOL APIENTRY main(HMODULE hModule, const DWORD ulReasonForCall, LPVOID) {
    if (ulReasonForCall == DLL_PROCESS_ATTACH) {
        const bool shiftPressed = GetAsyncKeyState(VK_SHIFT) & 0x01;
        
        Config::Init();
        if (Config::Get()["disabled"].as<bool>(false)) {
            if (!shiftPressed) return TRUE;
            Config::Get()["disabled"] = false;
            Config::Save();
        }
        if (shiftPressed) sdk::Game::bootMenuActive = true;
        
        utils::handle_error(init_memory, "инициализации памяти");
        utils::handle_error(init_crash_handler, "инициализации обработчика ошибок");
        utils::handle_error(init, "инициализации мода");

        Log::Info << "Мод загружен!" << Log::Endl;
    }

    if (ulReasonForCall == DLL_PROCESS_DETACH) {
        Console::Disable();
        ShowWindow(GetConsoleWindow(), SW_HIDE);
    }
    
    return TRUE;
}