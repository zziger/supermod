#include "modloader/mixins/HookUser.h"
#include "memory/HookManager.h"


HookManager::RegisteredHook HookUser::UnregisterHook(const HookManager::RegisteredHook mem) {
    _hooks -= mem;
    HookManager::UnregisterHook(mem);
    return mem;
}

void HookUser::UnloadHooks() {
    _hooks.Unload();
}