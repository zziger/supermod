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
#include "DirectXUtils.h"
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
#include <thirdparty/zip_file.h>

void init_memory() {
    const auto base = (uintptr_t) GetModuleHandle(nullptr);
    
    Memory::Base() = base;
    Memory::OnPatternNotFound([](const std::string& pattern) {
        Log::Error << "Не удалось найти паттерн " << pattern << Log::Endl;
    });
    Memory::InitCacheStorage(new MemoryCacheStorage());
}

void postInit() {
    ModManager::InitMods();
    ModFileResolver::Init();
    EventManager::Emit(ReadyEvent());
}

HOOK_FN(int, load_game, ARGS()) {
    Log::Info << "Инициализация загрузки игры" << Log::Endl;

    if (GetAsyncKeyState(VK_SHIFT) & 0x01) {
        sdk::Game::bootMenuActive = true;
    }

    if (sdk::Game::bootMenuActive) {
        Log::Info << "Boot меню активно" << Log::Endl;
        EnableMenuItem(GetSystemMenu(*sdk::Game::window, FALSE), SC_CLOSE, MF_BYCOMMAND | MF_DISABLED | MF_GRAYED);
    }
    
    while (sdk::Game::bootMenuActive || !ModManager::GetModsToInstall().empty()) {
        auto start = GetTickCount64();
        dx_utils::force_render_tick();
        const auto delta = GetTickCount64() - start;
        constexpr int needed = 10; 
        
        if (delta < needed) Sleep(needed - delta);
    }
    
    EnableMenuItem(GetSystemMenu(*sdk::Game::window, FALSE), SC_CLOSE, MF_BYCOMMAND | MF_ENABLED);
    sdk::Game::booted = true;
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
        utils::handle_error(postInit, "пост-инициализации");
    });
    
    EventManager::On<GameLoadedEvent>([] {
        Log::Info << "Игра загружена!" << Log::Endl;
        
        DragAcceptFiles(*sdk::Game::window, true);
    });
    
    
    EventManager::On<WindowEvent>([](auto ev) {
        if (ev.msg == WM_DROPFILES) {
            auto drop = (HDROP) (ev.wParam);
            
            uint32_t nCntFiles= DragQueryFileA( drop, -1, 0,0 );
                      
            for (int j=0; j<nCntFiles; j++ ) {
                char szBuf[MAX_PATH];
                DragQueryFileA( drop, j, szBuf, sizeof(szBuf) );
                std::optional<std::filesystem::path> temp;
                try {
                    auto path = std::filesystem::path(szBuf);
                    if (path.extension() == ".zip") {
                        miniz_cpp::zip_file zip {path.string()};
                        auto info = ModInfo(zip.read("manifest.yml"));
                        info.zipFile = path;
                        ModManager::RequestModInstall(info);
                        // temp = std::filesystem::temp_directory_path() / std::tmpnam(nullptr);
                        // create_directories(*temp);
                        // zip.extractall(temp->string());
                        // path = *temp;
                    } else {
                        ModManager::RequestModInstall(ModInfo(path));
                    }
                } catch(std::exception& e) {
                    Log::Error << "Ошибка установки мода: " << e.what() << Log::Endl;
                } catch(...) {
                    Log::Error << "Неизвестная ошибка установки мода" << Log::Endl;
                }
            }
    
            if (nCntFiles > 0) SetForegroundWindow(*sdk::Game::window);
    
            DragFinish(drop);
        }
    });
}

BOOL APIENTRY main(HMODULE hModule, const DWORD ulReasonForCall, LPVOID) {
    try {
        auto _ = std::filesystem::current_path().string();
    } catch(...) {
        MessageBoxW(nullptr, L"Путь к игре не может содержать буквы русского алфавита", L"SuperMod", MB_OK);
        exit(0);
    }
    
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