#pragma once
#include <memory>
#include <vector>

#include "mod/Mod.h"

namespace modloader {
    class ModManager {
        inline static std::vector<std::unique_ptr<Mod>> mods {};

    public:
        static constexpr std::string_view MODS_DIRECTORY = "mods";

        static void Init();
        static void ScanMods();
        static void Tick();
        static const std::vector<std::unique_ptr<Mod>>& GetMods() { return mods; }
    };
}
