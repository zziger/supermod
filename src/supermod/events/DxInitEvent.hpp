#pragma once
#include <supermod/pch.hpp>

#include <spdlog/spdlog.h>
#include <supermod/Utils.hpp>
#include <supermod/events/EventManager.hpp>
#include <supermod/memory/HookManager.hpp>

namespace sm
{
struct DxInitEvent final : IEvent<"dxInit", DxInitEvent>
{
};

HOOK_FN_CONV(inline char, d3d_init, ARGS(HWND a1), __cdecl)
{
    const auto res = d3d_init_orig(a1);
    if (res)
    {
        spdlog::trace("DxInit event");
        EventManager::Emit(DxInitEvent{});
    }
    return res;
}

inline EventManager::Ready $d3d_init_event_hook([] {
    HookManager::RegisterHook("55 8B EC 83 EC ? 68 ? ? ? ? E8 ? ? ? ? A3", HOOK_REF(d3d_init));
});
} // namespace sm