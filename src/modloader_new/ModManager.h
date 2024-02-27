#pragma once
#include <memory>
#include <vector>

#include "mod/Mod.h"

class ModloaderFixture;

namespace modloader {
    class ModManager {
        inline static std::vector<std::shared_ptr<Mod>> mods {};
        inline static std::map<std::string, std::shared_ptr<Mod>> mods_map {};
        inline static bool dirty = false;

    public:
        static constexpr std::string_view MODS_DIRECTORY = "mods";

        static void Init();
        static void ScanMods();
        static void Tick();

        static void LogStates();

        static const std::vector<std::shared_ptr<Mod>>& GetMods() { return mods; }
        static std::shared_ptr<Mod> FindModByID(const std::string& id);

        static void AddMod(const std::shared_ptr<Mod>& mod);
        static void ReorderMods(const std::vector<std::shared_ptr<Mod>>& newMods);

    private:

#ifdef UNIT_TESTS
        static void Reset();

        friend class ModloaderFixture;
#endif
    };
}
