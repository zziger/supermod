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
#include "logs/Console.h"
#include "CrashHandler.h"
#include "DirectXUtils.h"
#include "ui/UI.h"
#include "events/EventManager.h"
#include "events/ResolveFileEvent.h"
#include "events/GameLoadedEvent.h"
#include "events/StartExecutionEvent.h"
#include "events/D3dInitEvent.h"
#include "events/SoundHostInitEvent.h"
#include "memory/HookManager.h"
#include "memory/Memory.h"
#include <mod/ModImplInternal.h>
#include <modloader/files/ModFileResolver.h>
#include <modloader/install/ModInstaller.h>

#include "modloader/ModManager.h"
#include "sdk/Game.h"
#include <thirdparty/zip_file.h>
#include <utils/TempManager.h>
#include <spdlog/spdlog.h>
#include <spdlog/fmt/bundled/color.h>
#include <modloader/mod/impl/lua/lua.h>


void InitMemory()
{
    const auto base = reinterpret_cast<uintptr_t>(GetModuleHandle(nullptr));

    Memory::Base() = base;
    Memory::OnPatternNotFound([](const std::string& pattern)
    {
        spdlog::error("Failed to find pattern {}", styled(pattern, fg(fmt::color::red) | fmt::emphasis::bold));
    });
}

void PostInit()
{
    modloader::ModManager::Init();
    modloader::ModInstaller::Init();
    modloader::ModFileResolver::Init();
    EventManager::Emit(ReadyEvent());
}

HOOK_FN(int, load_game, ARGS())
{
    spdlog::info("Initializing game loading...");

    for (const auto& mod : modloader::ModManager::GetMods())
    {
        const auto fsInfo = std::dynamic_pointer_cast<modloader::ModInfoFilesystem>(mod->GetInfo());
        if (fsInfo) fsInfo->UpdateIcon();
    }
    if (!sdk::Game::bootMenuActive && GetAsyncKeyState(VK_SHIFT) & 0x01)
    {
        spdlog::info("Detected SHIFT (2nd chance), activating boot menu");
        sdk::Game::bootMenuActive = true;
    }

    if (sdk::Game::bootMenuActive)
    {
        EnableMenuItem(GetSystemMenu(*sdk::Game::window, FALSE), SC_CLOSE, MF_BYCOMMAND | MF_DISABLED | MF_GRAYED);
    }

    while (sdk::Game::bootMenuActive || !modloader::ModInstaller::GetInstallRequests().empty())
    {
        auto start = GetTickCount64();
        dx_utils::force_render_tick();
        const auto delta = GetTickCount64() - start;
        constexpr int needed = 10;

        if (delta < needed) Sleep(needed - delta);
    }

    EnableMenuItem(GetSystemMenu(*sdk::Game::window, FALSE), SC_CLOSE, MF_BYCOMMAND | MF_ENABLED);
    sdk::Game::booted = true;
    EventManager::Emit(WindowReadyEvent{});
    return load_game_orig();
}

void Init()
{
    auto cwd = std::filesystem::current_path();
    Console::Initialize();
    spdlog::info("Loading {} by {}...", styled("SuperMod " SUPERMOD_VERSION, fmt::emphasis::bold), styled("zziger", fmt::emphasis::bold));

    const Gdiplus::GdiplusStartupInput gdiplusStartupInput;
    ULONG_PTR gdiplusToken;

    GdiplusStartup(&gdiplusToken, &gdiplusStartupInput, nullptr);

    MH_Initialize();
    sdk::Game::Init();
    game::AssetPool::Init();
    TempManager::Init();

    hook_start_execution();

    static constexpr Memory::Pattern pat("E8 ? ? ? ? C6 05 ? ? ? ? ? 0F B6 05 ? ? ? ? 85 C0 74 ? 6A");
    HookManager::RegisterHook(Memory(pat.Search().GoToNearCall().Get<void*>()), HOOK_REF(load_game));

    EventManager::On<StartExecutionEvent>([]
    {
        spdlog::info("Starting post-initialization...");
        utils::handle_error(PostInit, "пост-инициализации");
        spdlog::info("Post-initialization finished");
    });

    EventManager::On<GameLoadedEvent>([]
    {
        spdlog::info("Game loading finished!");
    });
}

BOOL APIENTRY main(HMODULE hModule, const DWORD ulReasonForCall, LPVOID)
{
    if (ulReasonForCall == DLL_PROCESS_ATTACH)
    {
        std::setlocale(LC_ALL, "en_US.utf-8");
        std::locale::global(std::locale("en_US.utf-8"));

        current_path(sdk::Game::GetRootPath());
        try
        {
            auto _ = std::filesystem::current_path().string();
        }
        catch (...)
        {
            MessageBoxW(nullptr, L"Путь к игре не может содержать буквы русского алфавита", L"SuperMod", MB_OK);
            exit(0);
        }

        const bool shiftPressed = GetAsyncKeyState(VK_SHIFT) & 0x01;

        auto& cfg = Config::Get();
        if (cfg.disabled)
        {
            if (!shiftPressed) return TRUE;
            cfg.disabled = false;
            cfg.Save();
        }
        if (shiftPressed) sdk::Game::bootMenuActive = true;

        utils::handle_error(InitMemory, "инициализации памяти");
        utils::handle_error(InitCrashHandler, "инициализации обработчика ошибок");
        utils::handle_error(Init, "инициализации мода");

        if (shiftPressed)
            spdlog::info("Detected SHIFT, activating boot menu");

        spdlog::info("Initialization finished");
    }

    if (ulReasonForCall == DLL_PROCESS_DETACH)
    {
        Console::Disable();
        ShowWindow(GetConsoleWindow(), SW_HIDE);
    }

    return TRUE;
}

#ifndef UNIT_TESTS
BOOL APIENTRY DllMain(HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpReserved) {
    return main(hModule, ul_reason_for_call, lpReserved);
}
#endif