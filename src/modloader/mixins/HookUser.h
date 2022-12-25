#pragma once
#include "modloader/containers/HookContainer.h"

class HookUser {
    HookContainer _hooks {};
    
protected:
    template<class T, std::size_t Size>
    Memory RegisterHook(const char (&pattern)[Size], T* fn, T** orig);

    Memory UnregisterHook(Memory mem);

public:
    virtual ~HookUser() = default;
    void UnloadHooks();
};
