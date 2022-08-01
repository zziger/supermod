#pragma once
#include "Utils.h"
#include "module/IPatch.h"

class CAllowMultipleInstances final : public IPatch {
    HOOK_DEF(
        "55 8B EC 51 8B 45 08 50 6A ? 6A ? FF 15",
        int, preventMultipleInstances, ARGS(LPCSTR mutexName),
        {
            return 1; // fake successful mutex creation
        }
    );
    
public:
    void Load() override {
        IPatch::Load();
        HOOK_APPLY(preventMultipleInstances);
    }

    std::string GetName() override {
        return "ALLOW_MULTIPLE_INSTANCES";
    }
};