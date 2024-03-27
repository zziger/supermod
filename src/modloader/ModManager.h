#pragma once
#include <memory>
#include <vector>

#include "mod/Mod.h"

class ModloaderFixture;

namespace modloader {
    class ModManager {
        inline static std::vector<std::shared_ptr<Mod>> internal_mods {};
        inline static std::vector<std::shared_ptr<Mod>> mods {};
        inline static std::map<std::string, std::shared_ptr<Mod>> mods_map {};
        inline static std::map<std::string, std::vector<std::shared_ptr<Mod>>> dependent_mods {};
        inline static uint32_t dirty_flags = 0;

    public:
        enum class DirtyFlag
        {
            STATES = 0b1 << 0,
            DEPS = 0b1 << 1,
        };

        static constexpr std::string_view MODS_DIRECTORY = "mods";
        static constexpr uint8_t MAX_STATE_UPDATE_TICKS = 16;

        static void Init();
        static void ScanMods(bool init = false);
        static void Tick();

        static const std::vector<std::shared_ptr<Mod>>& GetMods() { return mods; }
        static const std::vector<std::shared_ptr<Mod>>& GetInternalMods() { return internal_mods; }
        static const std::vector<std::shared_ptr<Mod>>& GetModDependents(const std::string& id);
        static std::shared_ptr<Mod> FindModByID(const std::string& id);

        static void AddMod(const std::shared_ptr<Mod>& mod);
        static void RemoveMods(const std::vector<std::shared_ptr<Mod>>& removalList);
        static void ReorderMods(const std::vector<std::shared_ptr<Mod>>& newMods);
        static void ToggleMod(const std::shared_ptr<Mod>& mod, bool enabled);
        static void ScheduleModRemoval(const std::shared_ptr<Mod>& mod, bool remove = true);
        static void ReloadMod(const std::shared_ptr<Mod>& mod);

        static std::shared_ptr<Mod> CreateMod(const std::filesystem::path& modPath);

        static void SaveConfig(const std::shared_ptr<Mod>& mod);
        static void MarkDirty(const DirtyFlag flag) { dirty_flags |= static_cast<uint32_t>(flag); }

    private:
        static void UpdateStates();
        static void UpdateDeps();
        static void UpdateRemovedMods();

        static void AddInternalMod(const std::shared_ptr<Mod>& mod);

        static void ValidateConfig();
        static void SaveConfig();
        static void PopulateConfig(const std::shared_ptr<Mod>& mod, YAML::Node&& node);

        static bool IsDirty(const DirtyFlag flag) { return dirty_flags & static_cast<uint32_t>(flag); }
        static void ClearDirty(const DirtyFlag flag) { dirty_flags &= ~static_cast<uint32_t>(flag); }

        friend class ModInstaller;

#ifdef UNIT_TESTS
        static void Reset();

        friend class ModloaderFixture;
#endif
    };
}
