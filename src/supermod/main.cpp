#include "main.h"

#include "game/DirectX.hpp"
#include "modloader/install/ModInstaller.hpp"
#include "registry/RegistryManager.hpp"
#include "utils/WindowsRegistry.hpp"

#include <supermod/pch.hpp>

#include <async/task.h>
#include <cpr/cpr.h>
#include <d3dx9.h>
#include <d3dx9shader.h>
#include <filesystem>
#include <gdiplus.h>
#include <locale>
#include <supermod/Config.hpp>
#include <supermod/CrashHandler.hpp>
#include <supermod/DirectXUtils.hpp>
#include <supermod/UpdateManager.hpp>
#include <supermod/Utils.hpp>
#include <supermod/builtin/ModImplBuiltin.hpp>
#include <supermod/constants.hpp>
#include <supermod/events/DxInitEvent.hpp>
#include <supermod/events/DxResetEvent.hpp>
#include <supermod/events/EventManager.hpp>
#include <supermod/events/GameLoadedEvent.hpp>
#include <supermod/events/ResolveFileEvent.hpp>
#include <supermod/events/SoundHostInitEvent.hpp>
#include <supermod/events/SoundsLoadedEvent.hpp>
#include <supermod/events/StartExecutionEvent.hpp>
#include <supermod/game/Game.hpp>
#include <supermod/io/Async.hpp>
#include <supermod/io/Http.hpp>
#include <supermod/io/TempManager.hpp>
#include <supermod/io/logs/Console.hpp>
#include <supermod/memory/HookManager.hpp>
#include <supermod/memory/Memory.hpp>
#include <supermod/modloader/ModManager.hpp>
#include <supermod/modloader/files/ModFileResolver.hpp>
#include <supermod/modloader/mod/impl/lua/lua.hpp>
#include <supermod/modloader/mod/info/ModInfoFilesystem.hpp>
#include <supermod/ui/UI.hpp>

using namespace sm;

void InitMemory()
{
    const auto base = reinterpret_cast<uintptr_t>(GetModuleHandle(nullptr));

    Memory::Base() = base;
    Memory::OnPatternNotFound([](const std::string& pattern) {
        spdlog::error("Failed to find pattern {}", styled(pattern, fg(fmt::color::red) | fmt::emphasis::bold));
    });
}

void PostInit()
{
    registry::RegistryManager::Initialize();
    modloader::ModManager::Init();
    modloader::ModInstaller::Init();
    modloader::ModFileResolver::Init();
    EventManager::Emit(ReadyEvent());
    if (Config::Get().updater.checkAutomatically)
        update::UpdateManager::CheckForUpdates();
}

HOOK_FN(int, load_game, ARGS())
{
    spdlog::info("Initializing game loading...");

    for (const auto& mod : modloader::ModManager::GetMods())
    {
        const auto fsInfo = std::dynamic_pointer_cast<modloader::ModInfoFilesystem>(mod->GetInfo());
        if (fsInfo)
            fsInfo->UpdateIcon();
    }
    if (!game::Game::bootMenuActive && GetAsyncKeyState(VK_SHIFT) & 0x01)
    {
        spdlog::info("Detected SHIFT (2nd chance), activating boot menu");
        game::Game::bootMenuActive = true;
    }

    if (game::Game::bootMenuActive)
    {
        EnableMenuItem(GetSystemMenu(*game::Game::window, FALSE), SC_CLOSE, MF_BYCOMMAND | MF_DISABLED | MF_GRAYED);
    }

    while (game::Game::bootMenuActive || modloader::ModInstaller::IsInstallerActive())
    {
        auto start = GetTickCount64();
        dx_utils::force_render_tick();
        const auto delta = GetTickCount64() - start;
        constexpr int needed = 5;

        if (delta < needed)
            Sleep(needed - delta);
    }

    EnableMenuItem(GetSystemMenu(*game::Game::window, FALSE), SC_CLOSE, MF_BYCOMMAND | MF_ENABLED);
    game::Game::booted = true;
    EventManager::Emit(WindowReadyEvent{});
    return load_game_orig();
}

void Init()
{
    auto cwd = std::filesystem::current_path();
    io::Console::Initialize();
    spdlog::info("Loading {} by {}...", styled("SuperMod " SUPERMOD_VERSION, fmt::emphasis::bold),
                 styled("zziger", fmt::emphasis::bold));

    const Gdiplus::GdiplusStartupInput gdiplusStartupInput;
    ULONG_PTR gdiplusToken;

    GdiplusStartup(&gdiplusToken, &gdiplusStartupInput, nullptr);

    const auto res = MH_Initialize();
    if (res != MH_OK)
        throw std::runtime_error(std::format("Не удалось инициализировать MinHook (ошибка {})", static_cast<int>(res)));
    io::Async::Initialize();
    game::Game::Init();
    game::AssetPool::Init();
    io::TempManager::Init();

    hook_start_execution();

    static constexpr Memory::Pattern pat("E8 ? ? ? ? C6 05 ? ? ? ? ? 0F B6 05 ? ? ? ? 85 C0 74 ? 6A");
    HookManager::RegisterHook(Memory(pat.Search().GoToNearCall().Get<void*>()), HOOK_REF(load_game));

    EventManager::On<StartExecutionEvent>([] {
        spdlog::info("Starting post-initialization...");
        utils::handle_error(PostInit, "пост-инициализации");
        spdlog::info("Post-initialization finished");
    });

    EventManager::On<GameLoadedEvent>([] { spdlog::info("Game loading finished!"); });
}

void Register()
{
    const auto exePath = utils::get_exe_path();
    const auto argumentStr = std::format(L"\"{}\" \"%1\"", exePath.c_str());

    try
    {
        utils::WindowsRegistry::WriteRegSz(
            HKEY_CURRENT_USER, "Software\\Classes\\" + Constants::PROG_ID + R"(\shell\open\command)", "", argumentStr);
        utils::WindowsRegistry::WriteRegSz(HKEY_CURRENT_USER, "Software\\Classes\\." + Constants::PKG_EXTENSION, "",
                                           utils::str_to_wstr(Constants::PROG_ID));
        spdlog::info("Registered extension {}", Constants::PKG_EXTENSION);
    }
    catch (std::exception& e)
    {
        spdlog::error("Failed to register extension {}: {}", Constants::PKG_EXTENSION, e.what());
    }

    try
    {
        const auto protoBase = "Software\\Classes\\" + Constants::URI_PROTOCOL;
        utils::WindowsRegistry::WriteRegSz(HKEY_CURRENT_USER, protoBase, "", L"URL:SuperMod Protocol");
        utils::WindowsRegistry::WriteRegSz(HKEY_CURRENT_USER, protoBase, "URL Protocol", L"");
        utils::WindowsRegistry::WriteRegSz(HKEY_CURRENT_USER, protoBase + R"(\shell\open\command)", "", argumentStr);
    }
    catch (std::exception& e)
    {
        spdlog::error("Failed to register protocol {}: {}", Constants::URI_PROTOCOL, e.what());
    }
}

BOOL APIENTRY main(HMODULE hModule, const DWORD ulReasonForCall, LPVOID)
{
    if (ulReasonForCall == DLL_PROCESS_ATTACH)
    {
        std::setlocale(LC_ALL, "en_US.utf-8");
        std::locale::global(std::locale("en_US.utf-8"));

        current_path(game::Game::GetRootPath());
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
            if (!shiftPressed)
                return TRUE;
            cfg.disabled = false;
            cfg.Save();
        }
        if (shiftPressed)
            game::Game::bootMenuActive = true;

        utils::handle_error(Register, "регистрации");
        utils::handle_error(InitMemory, "инициализации памяти");
        utils::handle_error(InitCrashHandler, "инициализации обработчика ошибок");
        utils::handle_error(Init, "инициализации мода");

        if (shiftPressed)
            spdlog::info("Detected SHIFT, activating boot menu");

        spdlog::info("Initialization finished");
    }

    if (ulReasonForCall == DLL_PROCESS_DETACH)
    {
        io::Console::Disable();
        ShowWindow(GetConsoleWindow(), SW_HIDE);
    }

    return TRUE;
}

#ifndef UNIT_TESTS
BOOL APIENTRY DllMain(HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpReserved)
{
    return main(hModule, ul_reason_for_call, lpReserved);
}
#endif