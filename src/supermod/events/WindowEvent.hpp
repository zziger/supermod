#pragma once
#include <supermod/pch.hpp>

#include <supermod/Utils.hpp>
#include <supermod/events/EventManager.hpp>
#include <supermod/memory/HookManager.hpp>

namespace sm
{
struct WindowEvent final : ICancellableEvent<"windowEvent", WindowEvent>
{
    HWND hWnd;
    UINT msg;
    WPARAM wParam;
    LPARAM lParam;

    WindowEvent(const HWND hWnd, const UINT msg, const WPARAM wParam, const LPARAM lParam)
        : hWnd(hWnd),
          msg(msg),
          wParam(wParam),
          lParam(lParam)
    {
    }

    void RegisterLuaType(sol::state& state) override
    {
        state.new_usertype<WindowEvent>(sol::no_constructor, "hWnd", &WindowEvent::hWnd, "msg", &WindowEvent::msg,
                                        "wParam", &WindowEvent::wParam, "lParam", &WindowEvent::lParam, "cancel",
                                        &WindowEvent::Cancel, "isCancelled", &WindowEvent::IsCancelled);
    }
};

inline int(__stdcall* wndproc_orig)(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) = nullptr;
inline int wndproc(const HWND hWnd, const UINT msg, const WPARAM wParam, const LPARAM lParam)
{
    WindowEvent evt{hWnd, msg, wParam, lParam};
    EventManager::Emit(evt);

    if (evt.IsCancelled())
        return DefWindowProcA(hWnd, msg, wParam, lParam);

    return wndproc_orig(hWnd, msg, wParam, lParam);
}

inline EventManager::Ready $window_event_hook([] {
    HookManager::RegisterHook("55 8B EC 51 8B 45 0C 89 45 FC", HOOK_REF_FORCE(wndproc));
});
} // namespace sm