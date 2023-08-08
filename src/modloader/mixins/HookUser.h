#pragma once
#include "memory/HookManager.h"
#include "modloader/containers/HookContainer.h"

class HookUser {
    HookContainer _hooks {};
    
protected:
    template<class T, std::size_t Size>
    HookManager::RegisteredHook RegisterHook(const char (&pattern)[Size], T* fn, T** orig) {
        const HookManager::RegisteredHook mem = HookManager::RegisterHook(pattern, fn, orig);
        return _hooks += mem;
    }

    HookManager::RegisteredHook UnregisterHook(HookManager::RegisteredHook mem);

public:
    virtual ~HookUser() = default;
    void UnloadHooks();
};
