#include "CGUI.h"

GLOBAL_HOOK_THISCALL_NOARG("55 8B EC 51 E8 ? ? ? ? 6A ?", int, render, {
    CGUI::Initalize();
    CGUI::Render();
    auto res = render_orig(this_);
    return res;
});

extern IMGUI_IMPL_API LRESULT ImGui_ImplWin32_WndProcHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
GLOBAL_HOOK("55 8B EC 51 8B 45 0C 89 45 FC", int, wndProc, ARGS(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam), {
    if (ImGui_ImplWin32_WndProcHandler(hWnd, msg, wParam, lParam))
        return true;
    return wndProc_orig(hWnd, msg, wParam, lParam);
});

// todo better key handling
GLOBAL_HOOK("55 8B EC 0F B6 05 ? ? ? ? 85 C0 75 ? 0F B6 0D ? ? ? ? 85 C9 74 ? EB ? 83 7D 08 ? 76 ? 8B 55 08 89 15 ? ? ? ? 5D C3 CC CC CC CC 55", int, keydown, ARGS(int keycode), {
    if (keycode != 0) {
        if (keycode == 192) {
            CGUI::menuOpen = !CGUI::menuOpen;
        }
    }
    return keydown_orig(keycode);
});