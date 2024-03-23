#pragma once
#include "EventManager.h"
#include "Utils.h"
#include "memory/HookManager.h"
#include "memory/Memory.h"
#include "sdk/Game.h"
#include <game/SoundHost.h>

struct SoundHostInitEvent final : IEvent<"soundHostInit", SoundHostInitEvent> {};

HOOK_FN_CONV(inline char, soundhost_init, ARGS(), __cdecl) {
    const auto res = soundhost_init_orig();
    game::SoundHost::initialized = true;
    if (res) {
        EventManager::Emit(SoundHostInitEvent{});
    }
    return res;
}

inline EventManager::Ready $soundhost_init_event_hook([] {
    HookManager::RegisterHook("55 8B EC A1 ? ? ? ? 50 6A", HOOK_REF(soundhost_init));
});
