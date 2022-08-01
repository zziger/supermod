#pragma once
#include "IModule.h"
#include "Log.h"

class IMod : public IModule {
public:
    void Load() override {
        Log::Info << "Loading mod " << Log::Color::LIGHT_GREEN << GetName() << Log::Endl;
    }

    void Unload() override {
        IModule::Unload();
        Log::Info << "Unloading mod " << Log::Color::LIGHT_GREEN << GetName() << Log::Endl;
    }
};