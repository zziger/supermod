#pragma once
#include "EventManager.h"
#include "Utils.h"
#include "memory/HookManager.h"
#include "memory/Memory.h"

struct GameLoadedEvent final : IEvent<"gameLoaded"> {};

inline bool* gameLoadFinished = nullptr;
inline bool sentGameLoaded = false;

inline void (__thiscall *tickLoopInner_orig)(void* this_) = nullptr;
inline void __fastcall tickLoopInner(void* this_, void* _) {
    tickLoopInner_orig(this_);
    if (!sentGameLoaded && gameLoadFinished != nullptr && *gameLoadFinished) {
        sentGameLoaded = true;
        EventManager::Emit(GameLoadedEvent());
    }   
}

inline EventManager::Ready $game_loaded_event_hook([] {
    constexpr Memory::Pattern gameLoadFinishedPat("C6 05 ? ? ? ? ? E8 ? ? ? ? 68"); // mov gameLoadFinished, 1
    gameLoadFinished = *gameLoadFinishedPat.Search().Get<bool**>(2);
    HookManager::RegisterHook("55 8B EC 83 EC ? 89 4D ? D9 05 ? ? ? ? D8 1D", HOOK_REF_FORCE(tickLoopInner)); // push ebp
});