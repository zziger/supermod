#pragma once
#include <supermod/pch.hpp>

#include <supermod/Utils.hpp>
#include <supermod/events/EventManager.hpp>
#include <supermod/memory/HookManager.hpp>
#include <supermod/sdk/Game.hpp>

namespace sm
{
struct GameLoadedEvent final : IEvent<"gameLoaded", GameLoadedEvent>
{
};

inline bool sentGameLoaded = false;

inline void(__thiscall* tickLoopInner_orig)(void* this_) = nullptr;
inline void __fastcall tickLoopInner(void* this_, void* _)
{
    tickLoopInner_orig(this_);
    if (!sentGameLoaded && sdk::Game::IsGameLoaded())
    {
        sentGameLoaded = true;
        EventManager::Emit(GameLoadedEvent());
    }
}

inline EventManager::Ready $game_loaded_event_hook([] {
    HookManager::RegisterHook("55 8B EC 83 EC ? 89 4D ? D9 05 ? ? ? ? D8 1D",
                              HOOK_REF_FORCE(tickLoopInner)); // push ebp
});
} // namespace sm