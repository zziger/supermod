#pragma once
#include "CConfig.h"
#include "Utils.h"
#include "module/IMod.h"

inline int new_grounds_buffer[100];

class CExtendGroundsLimit final : public IMod {
        
    static constexpr CMemory::Pattern fillOutPat = {"89 04 8D ? ? ? ? EB ? 68 ? ? ? ? FF 15 ? ? ? ? 68 ? ? ? ?"};
    static constexpr CMemory::Pattern readPat = {"8B 04 95 ? ? ? ? 50 E8 ? ? ? ? 83 C4 ? 8B 4D 98"};
    static constexpr CMemory::Pattern fillOutLimitPat = {"83 7D D8 ? 7D ? 8B 4D D8 83 C1 ?"};
    static constexpr CMemory::Pattern readLimitPat = {"83 7D F8 ? 7C ? C7 45 F8 ? ? ? ?"};
    static constexpr CMemory::Pattern reloadTexPat = {"55 8B EC 83 EC ? A1 ? ? ? ? 89 45 FC 68 ? ? ? ? FF 15 ? ? ? ? C7 45 D8 ? ? ? ?"};
    void* buffer = nullptr;

    void UpdateLimit(int limit) {
        if (buffer != nullptr) free(buffer);
        buffer = calloc(limit, 4);
        fillOutPat.Search().Add(3).Put(buffer);
        readPat.Search().Add(3).Put(buffer);
        fillOutLimitPat.Search().Add(3).Put((char) limit);
        readLimitPat.Search().Add(3).Put((char) limit);
    }
public:
    void Load() override {
        IMod::Load();
        const auto cfg = CConfig::Instance().cfg;
        
        auto limit = 5;
        if (cfg.contains("groundLimit")) {
            limit = cfg["groundLimit"].get<int>();
        }

        UpdateLimit(limit);
    }

    bool HandleCommand(Command command) override {
        if (command.cmd == "setGrounds") {
            if (command.args.empty()) {
                Log::Error << "Usage: setGrounds 10" << Log::Endl;
                return true;
            }
            
            auto limit = std::stoi(command.args[0]);
            CConfig::Instance().cfg["groundLimit"] = limit;
            CConfig::Instance().Save();
            UpdateLimit(limit);
            reloadTexPat.Search().Call();
            return true;
        }

        return false;
    }

    void LogDescription(const bool loaded) override {
        if (!loaded) return;
        const auto cfg = CConfig::Instance().cfg;
        auto limit = 5;
        if (cfg.contains("groundLimit")) limit = cfg["groundLimit"].get<int>();
        Log::Instance() << Log::Color::GRAY << "    Текущее количество граундов: " << limit << Log::Endl;
        Log::Instance() << Log::Color::GRAY << "    Доступные команды:" << Log::Endl;
        Log::Instance() << Log::Color::GRAY << "    - setGrounds 10\tУстанавливает количество граундов" << Log::Endl;
    }

    std::string GetName() override {
        return "EXTEND_GROUNDS_LIMIT";
    }
};