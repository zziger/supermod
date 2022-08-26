#pragma once
#include <chrono>
#include <thread>

#include "CConfig.h"
#include "Utils.h"
#include "module/IPatch.h"

using namespace std::literals;

class CFpsLimit final : public IPatch {
    static constexpr int default_fps_cap = 120;
    static inline std::chrono::milliseconds frameTimeLimit = std::chrono::milliseconds((int) std::floor(1000.0 / default_fps_cap)); 

    HOOK_THISCALL_NOARG_DEF("55 8B EC 51 E8 ? ? ? ? 6A ?",
        int, render, {
            static constexpr CMemory::Pattern gameLoadFinishedPat("C6 05 ? ? ? ? ? E8 ? ? ? ? 68 ? ? ? ?");
            static int* gameLoadFinished = *gameLoadFinishedPat.Search().Get<int**>(2);
            if (!*gameLoadFinished) return render_orig(this_);
            
            const auto begin = std::chrono::time_point_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now());
            const auto res = render_orig(this_);
            const auto end = std::chrono::time_point_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now());
            auto time = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
            if (time < frameTimeLimit) std::this_thread::sleep_for(frameTimeLimit - (end - begin));
            return res;
        });

public:
    void Load() override {
        IPatch::Load();
        const auto cfg = CConfig::Instance().cfg;
        if (cfg.contains("fpsCap")) {
            const auto fpsCap = cfg["fpsCap"].get<int>();
            frameTimeLimit = std::chrono::milliseconds((int) std::floor(1000.0 / fpsCap));
        }
        HOOK_APPLY(render);
    }

    bool HandleCommand(Command command) override {
        if (command.cmd == "setFps") {
            if (command.args.empty()) {
                Log::Error << "Usage: setFps 120" << Log::Endl;
                return true;
            }
            
            auto cap = std::stoi(command.args[0]);
            CConfig::Instance().cfg["fpsCap"] = cap;
            CConfig::Instance().Save();
            frameTimeLimit = std::chrono::milliseconds((int) std::floor(1000.0 / cap));
            return true;
        }

        return false;
    }

    void LogDescription(const bool loaded) override {
        if (!loaded) return;
        const auto cfg = CConfig::Instance().cfg;
        auto cap = default_fps_cap;
        if (cfg.contains("fpsCap"))cap = cfg["fpsCap"].get<int>();
        Log::Instance() << Log::Color::GRAY << "    Текущий лимит FPS: " << cap << Log::Endl;
        Log::Instance() << Log::Color::GRAY << "    Доступные команды:" << Log::Endl;
        Log::Instance() << Log::Color::GRAY << "    - setFps 120\tУстанавливает лимит FPS" << Log::Endl;
    }


    std::string GetName() override {
        return "FPS_LIMIT";
    }
};