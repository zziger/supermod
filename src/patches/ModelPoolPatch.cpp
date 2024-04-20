#include "Utils.h"
#include "events/EventManager.h"
#include "memory/HookManager.h"
#include <queue>

#include "DirectXUtils.h"
#include "events/ResolveFileEvent.h"
#include "game/models/ModelPool.h"
#include "sdk/Graphics.h"

game::Model* (__thiscall * model_pool_get_orig)(game::ModelPool* this_, char* name) = nullptr;
game::Model* __fastcall model_pool_get(game::ModelPool* this_, void*, char* name) {
    if (game::ModelPool::overrideAllocation)
        return nullptr;

    return model_pool_get_orig(this_, name);
}
game::Model* (__thiscall * model_pool_alloc_orig)(game::ModelPool* this_, char* name) = nullptr;
game::Model* __fastcall model_pool_alloc(game::ModelPool* this_, void*, char* name) {
    if (game::ModelPool::overrideAllocation)
        return game::ModelPool::overrideAllocation;

    return model_pool_alloc_orig(this_, name);
}

inline EventManager::Ready $model_pool_patch([] {
    HookManager::RegisterHook("55 8B EC 83 EC ? 89 4D ? C7 45 ? ? ? ? ? EB ? 8B 45 ? 83 C0 ? 89 45 ? 8B 4D ? 8B 55 ? 3B 51 ? 7D ? 8B 45 ? 50", HOOK_REF_FORCE(model_pool_get));
    HookManager::RegisterHook(Memory::Pattern("E8 ? ? ? ? 89 45 ? 6A ? 6A ? 8B 55 ? 52 E8 ? ? ? ? 83 C4 ? 89 45 ? 8B 45 ? 89 45 ? 8B 4D ? 8B 55 ? 8B 02 89 41 ? 8B 4D ? 83 C1 ? 89 4D ? 8B 55 ? 8B 45 ? 8B 08 89 4A ? 8B 55 ? 83 C2 ? 89 55 ? 8B 45 ? 8B 48").Search().GoToNearCall(), HOOK_REF_FORCE(model_pool_alloc));
});