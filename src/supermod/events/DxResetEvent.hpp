#pragma once
#include <supermod/pch.hpp>

#include <spdlog/spdlog.h>
#include <supermod/Utils.hpp>
#include <supermod/events/EventManager.hpp>
#include <supermod/memory/HookManager.hpp>

namespace sm
{
struct BeforeDxReset final : IEvent<"beforeDxReset", BeforeDxReset>
{
};
struct AfterDxReset final : IEvent<"afterDxReset", AfterDxReset>
{
};

HOOK_FN(inline int, d3d_reset, ARGS())
{
    EventManager::Emit(BeforeDxReset());
    const auto res = d3d_reset_orig();
    EventManager::Emit(AfterDxReset());
    return res;
}

inline EventManager::Ready $d3d_reset_event_hook([] {
    HookManager::RegisterHook("55 8B EC 83 EC ? E8 ? ? ? ? A1", HOOK_REF(d3d_reset));
});
} // namespace sm