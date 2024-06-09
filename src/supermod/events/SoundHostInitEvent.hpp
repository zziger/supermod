#pragma once
#include <supermod/pch.hpp>

#include <supermod/Utils.hpp>
#include <supermod/events/EventManager.hpp>
#include <supermod/game/SoundHost.hpp>
#include <supermod/memory/HookManager.hpp>

struct SoundHostInitEvent final : IEvent<"soundHostInit", SoundHostInitEvent>
{
};

HOOK_FN_CONV(inline char, soundhost_init, ARGS(), __cdecl)
{
    const auto res = soundhost_init_orig();
    game::SoundHost::initialized = true;
    if (res)
    {
        spdlog::trace("SoundHostInit event");
        EventManager::Emit(SoundHostInitEvent{});
    }
    return res;
}

inline EventManager::Ready $soundhost_init_event_hook([] {
    HookManager::RegisterHook("55 8B EC A1 ? ? ? ? 50 6A", HOOK_REF(soundhost_init));
});
