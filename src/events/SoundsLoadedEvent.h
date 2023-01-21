#pragma once
#include <filesystem>

#include "EventManager.h"
#include "Utils.h"
#include "memory/HookManager.h"
#include "memory/Memory.h"
#include "sdk/Game.h"

struct SoundsLoadedEvent final : IEvent<"soundsLoaded", SoundsLoadedEvent> {};

HOOK_FN(inline int, load_sounds, ARGS()) {
    const auto res = load_sounds_orig();
    Log::Debug << "Звуки игры загружены" << Log::Endl;
    EventManager::Emit(SoundsLoadedEvent{});
    return res;
}

inline EventManager::Ready $sounds_loaded_event_hook([] {
    static constexpr Memory::Pattern pat("E8 ? ? ? ? E8 ? ? ? ? B9 ? ? ? ? E8 ? ? ? ? B9 ? ? ? ? E8 ? ? ? ? B9");
    static auto mem = pat.Search().GoToNearCall();
    mem.Detour(HOOK_REF(load_sounds));
});