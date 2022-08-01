#pragma once
#include "Utils.h"
#include "module/IPatch.h"

class CAdditionalMusic : public IPatch {
    static void LoadSound(const char* soundFile) {
        static constexpr CMemory::Pattern loadSoundPat("55 8B EC 68 ? ? ? ? 8B 45 08");
        static auto mem = loadSoundPat.Search();
        mem.Call(soundFile);
    }
    
    HOOK_DEF(
            "55 8B EC 81 EC ? ? ? ? A1 ? ? ? ? 89 45 FC 68 ? ? ? ? E8",
        void, loadSounds, ARGS(char* filename),
        {
            loadSounds_orig(filename);
            Log::Debug << "Loading additional music..." << Log::Endl;
            const auto sounds = GetMusic();
            if (sounds.empty()) Log::Warn << "No additional music found in config" << Log::Endl;
            for (auto& sound : sounds) {
                LoadSound(sound.c_str());
            }
        }
    );

public:
    void Load() override {
        IPatch::Load();
        HOOK_APPLY(loadSounds);
    }

    std::string GetName() override {
        return "ADD_MUSIC";
    }

    static std::vector<std::string> GetMusic() {
        const auto cfg = CConfig::Instance().cfg;
        if (!cfg.contains("additionalMusic")) return {};
        return CConfig::Instance().cfg["additionalMusic"].get<std::vector<std::string>>();
    }

    bool HandleCommand(Command command) override {
        auto cfg = CConfig::Instance().cfg;
        if (command.cmd == "addMusic") {
            if (command.args.empty()) {
                Log::Error << "Usage: addMusic path/to/file.ogg" << Log::Endl;
                return true;
            }
            
            if (!cfg.contains("additionalMusic")) cfg["additionalMusic"] = {};
            CConfig::Instance().cfg["additionalMusic"].push_back(command.args[0]);
            CConfig::Instance().Save();
            return true;
        }
        if (command.cmd == "removeMusic") {
            if (command.args.empty()) {
                Log::Error << "Usage: removeMusic path/to/file.ogg" << Log::Endl;
                return true;
            }
            
            if (!cfg.contains("additionalMusic")) cfg["additionalMusic"] = {};
            auto v = cfg["additionalMusic"].get<std::vector<std::string>>();
            const auto itr = std::find(v.begin(), v.end(), command.args[0]);
            if (itr != v.end()) v.erase(itr);
            cfg["additionalMusic"] = v;
            CConfig::Instance().Save();
            return true;
        }
        if (command.cmd == "additionalMusic") {
            if (!cfg.contains("additionalMusic")) Log::Info << "No additional music found" << Log::Endl;
            else {
                // ReSharper disable once CppExpressionWithoutSideEffects
                Log::Info << "Additional music: ";
                for (auto& file : GetMusic()) { 
                    Log::Instance() << file << " ";
                }
                Log::Instance() << Log::Endl;
            }
            return true;
        }

        return false;
    }

    void LogDescription() override {
        std::stringstream ss;
        for (auto& file : GetMusic()) { 
            ss << file << " ";
        }
        Log::Instance() << Log::Color::GRAY << "    Загруженная дополнительная музыка: " << ss.str() << Log::Endl;
        Log::Instance() << Log::Color::GRAY << "    Доступные команды:" << Log::Endl;
        Log::Instance() << Log::Color::GRAY << "    - addMusic path/to/file.ogg\t\tДобавляет новую музыку, требует рестарта игры" << Log::Endl;
        Log::Instance() << Log::Color::GRAY << "    - removeMusic path/to/file.ogg\tУдаляет дополнительную музыку, требует рестарта игры" << Log::Endl;
        Log::Instance() << Log::Color::GRAY << "    - additionalMusic\t\t\tВыводит все дополнительные файлы музыки" << Log::Endl;
    }
};