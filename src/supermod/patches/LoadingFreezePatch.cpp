/// By default the game does not handle window messages while loading, resulting in a "lagged" window, that you can't
/// even move This patch fixes the issue by handling messages in a loading state update method

#include <supermod/pch.hpp>

#include <supermod/Utils.hpp>
#include <supermod/events/EventManager.hpp>
#include <supermod/memory/HookManager.hpp>
#include <supermod/game/Game.hpp>

using namespace sm;

inline int(__thiscall* update_load_orig)(void* this_, int a2);
inline int __fastcall update_load(void* this_, void*, int a2)
{
    if (game::Game::IsGameInLoadingTick())
    {
        tagMSG msg{};

        if (PeekMessageA(&msg, nullptr, 0, 0, 1u))
        {
            TranslateMessage(&msg);
            DispatchMessageA(&msg);
        }
    }

    game::Game::currentTickIsInner = true;
    const auto res = update_load_orig(this_, a2);
    game::Game::currentTickIsInner = false;
    return res;
}

inline EventManager::Ready $loading_freeze_patch([] {
    HookManager::RegisterHook("55 8B EC 83 EC ? 89 4D ? 0F B6 05 ? ? ? ? 85 C0 75 ? E9 ? ? ? ? E8",
                              HOOK_REF_FORCE(update_load));
});
