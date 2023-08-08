#pragma once
#include <mutex>
#include <unordered_set>

#include "memory/HookManager.h"
#include "memory/Memory.h"

struct HookContainer {
    std::unordered_set<HookManager::RegisteredHook> items {};

    HookManager::RegisteredHook operator += (HookManager::RegisteredHook mem);
    
    HookManager::RegisteredHook operator -= (HookManager::RegisteredHook mem);

    void Unload();

private:
    inline static std::recursive_mutex _mutex {};
};
