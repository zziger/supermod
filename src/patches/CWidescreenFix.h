#pragma once
#include "Utils.h"
#include "module/IPatch.h"

class CWidescreenFix final : public IPatch {
    static inline bool overrideResolution = false;
    static inline int width = 0;
    static inline int height = 0;
    
    HOOK_DEF(
        "55 8B EC 51 C7 45 FC ? ? ? ? EB ? 8B 45 FC 83 C0 ? 89 45 FC 8B 4D FC 3B 0D ? ? ? ? 7D ? 8B 55 FC 8B 04 D5",
        int, setupD3dParams, ARGS(),
        {
            static constexpr CMemory::Pattern paramsSetPat("89 15 ? ? ? ? 8B 41 04");
            static constexpr CMemory::Pattern set32BitPat("C7 05 ? ? ? ? ? ? ? ? D9 ? ? ? ? ? D8 ? ? ? ? ? E8");
            static int* ptr = *paramsSetPat.Search().Get<int**>(2);
            static int* set32BitPtr = *set32BitPat.Search().Get<int**>(2);
            static HWND desktopWnd = GetDesktopWindow();

            *set32BitPtr = 1;
            const auto value = setupD3dParams_orig();
            RECT desktop;
            if (overrideResolution) desktop = RECT({ 0, 0, width, height });
            else GetWindowRect(desktopWnd, &desktop);
            Log::Debug << "Setting render params to " << desktop.right << "x" << desktop.bottom << Log::Endl;
            ptr[0] = desktop.right;
            ptr[1] = desktop.bottom;
            ptr[2] = 21;
            return value;
        }
    );
    
public:
    void Load() override {
        IPatch::Load();
        auto cfg = CConfig::Instance().cfg; 
        if (cfg.contains("widescreenFixOverride")) {
            overrideResolution = true;
            auto arr = cfg["widescreenFixOverride"].get<std::vector<int>>();
            width = arr[0];
            height = arr[1];
        }
        HOOK_APPLY(setupD3dParams);
    }

    bool HandleCommand(Command command) override {
        if (command.cmd == "overrideRes") {
            Log::Info << command.args.size() << Log::Endl; 
            if (command.args.size() < 2) {
                Log::Error << "Usage: overrideRes 1920 1080" << Log::Endl;
                return true;
            }
            
            width = std::stoi(command.args[0]);
            height = std::stoi(command.args[1]);
            overrideResolution = true;
            CConfig::Instance().cfg["widescreenFixOverride"] = { width, height };
            CConfig::Instance().Save();
            return true;
        }

        if (command.cmd == "resetResOverride") {
            width = 0;
            height = 0;
            overrideResolution = false;
            CConfig::Instance().cfg.erase("widescreenFixOverride");
            CConfig::Instance().Save();
            return true;
        }

        return false;
    }

    void LogDescription() override {
        Log::Instance() << Log::Color::GRAY << "    Available commands:" << Log::Endl;
        Log::Instance() << Log::Color::GRAY << "    - overrideRes 1920 1020\tOverrides set resolution" << Log::Endl;
        Log::Instance() << Log::Color::GRAY << "    - resetResOverride\t\tResets resolution override" << Log::Endl;
    }

    std::string GetName() override {
        return "WIDESCREEN_FIX";
    }
};