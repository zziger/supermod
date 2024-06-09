#include "Utils.h"
#include "events/EventManager.h"
#include "memory/HookManager.h"
#include <game/animations/AnimationPool.h>
#include <queue>

#include "DirectXUtils.h"
#include "events/ResolveFileEvent.h"
#include "sdk/Graphics.h"

game::Animation*(__thiscall* animation_pool_get_orig)(game::AnimationPool* this_, char* name) = nullptr;
game::Animation* __fastcall animation_pool_get(game::AnimationPool* this_, void*, char* name)
{
    if (game::AnimationPool::overrideAllocation)
        return nullptr;

    return animation_pool_get_orig(this_, name);
}
game::Animation*(__thiscall* animation_pool_alloc_orig)(game::AnimationPool* this_, char* name) = nullptr;
game::Animation* __fastcall animation_pool_alloc(game::AnimationPool* this_, void*, char* name)
{
    if (game::AnimationPool::overrideAllocation)
        return game::AnimationPool::overrideAllocation;

    return animation_pool_alloc_orig(this_, name);
}

inline EventManager::Ready $animation_pool_patch([] {
    HookManager::RegisterHook(
        "55 8B EC 83 EC ? 89 4D ? C7 45 ? ? ? ? ? EB ? 8B 45 ? 83 C0 ? 89 45 ? 8B 4D ? 8B 55 ? 3B 51 ? 7D ? 8B 45 ? 8B "
        "4D ? 8B 54 81 ? 52 8B 45 ? 50 E8 ? ? ? ? 83 C4 ? 85 C0 75 ? 8B 4D",
        HOOK_REF_FORCE(animation_pool_get));
    HookManager::RegisterHook(
        Memory::Pattern(
            "E8 ? ? ? ? 89 45 ? 6A ? 6A ? 8B 55 ? 52 E8 ? ? ? ? 83 C4 ? 89 45 ? 8B 45 ? 89 45 ? 8B 4D ? 8B 55 ? 8B 02 "
            "89 41 ? 8B 4D ? 83 C1 ? 89 4D ? 8B 55 ? 8B 45 ? 8B 08 89 4A ? 8B 55 ? 83 C2 ? 89 55 ? 8B 45 ? 8B 4D")
            .Search()
            .GoToNearCall(),
        HOOK_REF_FORCE(animation_pool_alloc));
});