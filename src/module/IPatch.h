#pragma once
#include "IModule.h"
#include "Log.h"

class IPatch : public IModule {
public:
    void Load() override {
        Log::Info << "Loading patch " << Log::Color::LIGHT_GREEN << GetName() << Log::Endl;
    }

    void Unload() override {
        IModule::Unload();
        Log::Info << "Unloading patch " << Log::Color::LIGHT_GREEN << GetName() << Log::Endl;
    }
};