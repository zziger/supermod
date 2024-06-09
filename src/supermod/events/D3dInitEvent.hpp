#pragma once
#include <supermod/pch.hpp>

#include <spdlog/spdlog.h>
#include <supermod/Utils.hpp>
#include <supermod/events/EventManager.hpp>
#include <supermod/memory/HookManager.hpp>

struct D3dInitEvent final : IEvent<"d3dInit", D3dInitEvent>
{
};

HOOK_FN_CONV(inline char, d3d_init, ARGS(HWND a1), __cdecl)
{
    const auto res = d3d_init_orig(a1);
    if (res)
    {
        spdlog::trace("D3dInit event");
        EventManager::Emit(D3dInitEvent{});
    }
    return res;
}

inline EventManager::Ready $d3d_init_event_hook([] {
    HookManager::RegisterHook("55 8B EC 83 EC ? 68 ? ? ? ? E8 ? ? ? ? A3", HOOK_REF(d3d_init));
});
