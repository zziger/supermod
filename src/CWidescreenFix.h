#pragma once
#include <intrin.h>

#include "Utils.h"
#include "events/EventManager.h"
#include "memory/Memory.h"

HOOK_FN(int, setupD3dParams, ARGS())
{
    static constexpr Memory::Pattern paramsSetPat("89 15 ? ? ? ? 8B 41 04");
    static constexpr Memory::Pattern set32BitPat("C7 05 ? ? ? ? ? ? ? ? D9 ? ? ? ? ? D8 ? ? ? ? ? E8");
    static int* ptr = *paramsSetPat.Search().Get<int**>(2);
    static int* set32BitPtr = *set32BitPat.Search().Get<int**>(2);
    static HWND desktopWnd = GetDesktopWindow();

    *set32BitPtr = 1;
    const auto value = setupD3dParams_orig();
    RECT desktop;
    GetWindowRect(desktopWnd, &desktop);
    Log::Debug << "Setting render params to " << desktop.right << "x" << desktop.bottom << Log::Endl;
    ptr[0] = desktop.right - desktop.left;
    ptr[1] = desktop.bottom - desktop.top;
    ptr[2] = 21;
    return value;
};

EventManager::Ready $widescreen_fix([] {
    constexpr Memory::Pattern pat("55 8B EC 51 C7 45 FC ? ? ? ? EB ? 8B 45 FC 83 C0 ? 89 45 FC 8B 4D FC 3B 0D ? ? ? ? 7D ? 8B 55 FC 8B 04 D5");
    pat.Search().Detour(HOOK_REF(setupD3dParams));
});