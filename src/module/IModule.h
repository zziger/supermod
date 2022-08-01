#pragma once
#include <string>
#include <vector>

#include "Data.h"
#include "CMemory.h"

class IModule {
public:
    virtual ~IModule() = default;

    virtual std::string GetName() = 0;
    
    virtual void Load() = 0;
    virtual void Unload() {
        for (auto hook : _hooks) hook.DeactivateDetour();
    }

    virtual bool HandleCommand(Command command) {
        return false;
    }

    virtual void LogDescription(bool loaded) {}

protected:
    std::vector<CMemory> _hooks;
    
    void RegisterHook(const CMemory mem) {
        _hooks.push_back(mem);
    }
};
