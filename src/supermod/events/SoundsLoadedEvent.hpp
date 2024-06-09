#pragma once
#include <supermod/pch.hpp>

#include <supermod/Utils.hpp>
#include <supermod/events/EventManager.hpp>
#include <supermod/memory/HookManager.hpp>
#include <supermod/memory/Memory.hpp>

struct SoundsLoadedEvent final : IEvent<"soundsLoaded", SoundsLoadedEvent>
{
};

HOOK_FN(inline int, load_sounds, ARGS())
{
    const auto res = load_sounds_orig();
    spdlog::trace("SoundsLoaded event");
    EventManager::Emit(SoundsLoadedEvent{});
    return res;
}

inline EventManager::Ready $sounds_loaded_event_hook([] {
    static constexpr Memory::Pattern pat("E8 ? ? ? ? E8 ? ? ? ? B9 ? ? ? ? E8 ? ? ? ? B9 ? ? ? ? E8 ? ? ? ? B9");
    static auto mem = pat.Search().GoToNearCall();
    HookManager::RegisterHook(mem, HOOK_REF(load_sounds));
});