#pragma once
#include "CConfig.h"
#include "CGameApis.h"
#include "Utils.h"
#include "module/IMod.h"
#include "module/IPatch.h"

class CStartupSplash final : public IMod {
public:
    void Load() override {
        IMod::Load();
        CGameApis::ShowLowerMessage(U16(GetMsg()));
    }

    static std::string GetMsg() {
        auto cfg = CConfig::Instance().cfg;
        if (!cfg.contains("startupSplashMessage")) return "Ваш текст";
        return cfg["startupSplashMessage"].get<std::string>();
    }

    std::string GetName() override {
        return "STARTUP_SPLASH";
    }

    bool HandleCommand(Command command) override {
        if (command.cmd == "setStartupSplash") {
            CConfig::Instance().cfg["startupSplashMessage"] = command.rawArgs;
            CConfig::Instance().Save();
            CGameApis::ShowLowerMessage(U16(command.rawArgs));
            return true;
        }

        return false;
    }
    
    void LogDescription() override {
        Log::Instance() << Log::Color::GRAY << "    Available commands:" << Log::Endl;
        Log::Instance() << Log::Color::GRAY << "    - setStartupSplash\tSets startup splash message" << Log::Endl;
    }
};