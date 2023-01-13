#pragma once
#include <filesystem>

#include "EventManager.h"
#include "Utils.h"
#include "memory/HookManager.h"
#include "memory/Memory.h"
#include "sdk/Game.h"

struct SoundsLoadedEvent final : IEvent<"soundsLoaded"> {
};

HOOK_FN(int, load_sounds, ARGS()) {
    const auto res = load_sounds_orig();
    EventManager::Emit(SoundsLoadedEvent{});
    return res;
}

inline EventManager::Ready $sounds_loaded_event_hook([] {
    HookManager::RegisterHook("55 8B EC 81 EC ? ? ? ? A1 ? ? ? ? 89 45 ? 68 ? ? ? ? E8", HOOK_REF(load_sounds));
});