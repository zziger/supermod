#include "modloader/mixins/HookUser.h"
#include "memory/HookManager.h"

template <class T, std::size_t Size>
Memory HookUser::RegisterHook(const char(& pattern)[Size], T* fn, T** orig) {
    const Memory mem = HookManager::RegisterHook(pattern, fn, orig);
    return _hooks += mem;
}


Memory HookUser::UnregisterHook(const Memory mem) {
    return _hooks -= HookManager::UnregisterHook(mem);
}

void HookUser::UnloadHooks() {
    _hooks.Unload();
}