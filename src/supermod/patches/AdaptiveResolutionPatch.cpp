/// The game is initially rendered in 800x600 regardless of window size,
/// making picture pixelated or blurry
/// This patch fixes rendered resolution and allows window resizing/maximizing,
/// and resets the device on every window resize

#include <supermod/pch.hpp>

#include <supermod/Utils.hpp>
#include <supermod/events/D3dInitEvent.hpp>
#include <supermod/events/EventManager.hpp>
#include <supermod/events/ResolutionChangeEvent.hpp>
#include <supermod/events/WindowEvent.hpp>
#include <supermod/logs/Console.hpp>
#include <supermod/memory/HookManager.hpp>
#include <supermod/sdk/DirectX.hpp>
#include <supermod/sdk/Game.hpp>

static constexpr long REQUIRED_STYLES = WS_MAXIMIZEBOX | WS_SIZEBOX;

HOOK_FN(inline static int, setup_d3d_params, ARGS())
{
    static constexpr Memory::Pattern paramsSetPat("89 15 ? ? ? ? 8B 41 04");

    static int* ptr = *paramsSetPat.Search().Get<int**>(2);
    const auto value = setup_d3d_params_orig();

    vector2i res = {};
    RECT rect;

    if (sdk::Game::IsGameFullscreen())
    {
        static HWND desktopWnd = GetDesktopWindow();
        GetWindowRect(desktopWnd, &rect);
        res = {static_cast<int>(rect.right - rect.left), static_cast<int>(rect.bottom - rect.top)};
    }
    else
    {
        GetClientRect(*sdk::Game::window, &rect);
        res = {static_cast<int>(rect.right - rect.left), static_cast<int>(rect.bottom - rect.top)};
    }

    if (res.x == 0 || res.y == 0)
        res = sdk::Game::lastResolution;
    else
        sdk::Game::lastResolution = res;

    spdlog::info("Render resolution was set to {}x{}", Console::StyleEmphasise(res.x), Console::StyleEmphasise(res.y));

    ptr[0] = res.x;
    ptr[1] = res.y;

    EventManager::Emit(ResolutionChangeEvent(res.x, res.y));
    return value;
}

inline EventManager::Ready $adaptive_resolution_patch([] {
    HookManager::RegisterHook(
        "55 8B EC 51 C7 45 FC ? ? ? ? EB ? 8B 45 FC 83 C0 ? 89 45 FC 8B 4D FC 3B 0D ? ? ? ? 7D ? 8B 55 FC 8B 04 D5",
        HOOK_REF(setup_d3d_params));

    EventManager::On<WindowEvent>([](const WindowEvent& evt) {
        if (evt.hWnd != *sdk::Game::window)
            return;

        if (evt.msg == WM_SIZE)
            sdk::DirectX::RequestDeviceReset();

        if (evt.msg == WM_STYLECHANGED && evt.wParam == GWL_STYLE && !sdk::Game::IsGameFullscreen())
        {
            const auto style = reinterpret_cast<STYLESTRUCT*>(evt.lParam);
            if ((style->styleNew & REQUIRED_STYLES) != REQUIRED_STYLES)
                SetWindowLongA(evt.hWnd, GWL_STYLE, static_cast<long>(style->styleNew) | REQUIRED_STYLES);
        }

        if (evt.msg == WM_ACTIVATE && !sdk::Game::IsGameFullscreen())
        {
            const auto oldStyle = GetWindowLongA(*sdk::Game::window, GWL_STYLE);
            if ((oldStyle & REQUIRED_STYLES) != REQUIRED_STYLES)
                SetWindowLongA(*sdk::Game::window, GWL_STYLE, oldStyle | REQUIRED_STYLES);
        }
    });

    EventManager::On<D3dInitEvent>([] {
        if (!sdk::Game::IsGameFullscreen())
            SetWindowLongA(*sdk::Game::window, GWL_STYLE,
                           GetWindowLongA(*sdk::Game::window, GWL_STYLE) | REQUIRED_STYLES);
    });

    // Prevent game from changing window size/pos on reset
    Memory::Pattern("FF 15 ? ? ? ? EB ? 6A ? A1").Search().Nop(6);
});