#pragma once
#include <filesystem>
#include <list>
#include "modloader/mods/Mod.h"

class LuaMod;

class ModManager {
    inline static const std::filesystem::path manifest_file_name = "manifest.yml";
    inline static const std::filesystem::path icon_file_name = "icon.png";
    inline static const std::filesystem::path dll_file_name = "main.dll";
    
    inline static std::filesystem::path _mods_folder;
    inline static std::list<std::shared_ptr<Mod>> _mods {};
    inline static std::list<std::shared_ptr<LuaMod>> _luaMods {};
    inline static std::list<ModInfo> _modsToInstall {};
    inline static std::recursive_mutex _modMutex {};
    
    inline static std::shared_ptr<Mod> _internalMod {};

    static std::shared_ptr<Mod> GetInternalMod();

    static void CleanupConfig();

public:

    static void Init();

    static std::filesystem::path GetModsRoot();

    static void LoadMod(ModInfo info, bool manual);
    static void LoadMod(std::string_view modName, bool manual);
    
    static void ReorderMods(std::vector<std::shared_ptr<Mod>>);

    static void InitMods();

    static void ReloadIcons();

    static void DeleteMod(std::shared_ptr<Mod> mod);

    static std::list<ModInfo>& GetModsToInstall();
    
    static void RequestModInstall(ModInfo mod);
    
    static void InstallMod(ModInfo mod, bool state);

    static std::list<std::shared_ptr<Mod>> GetMods();
    static std::list<std::shared_ptr<LuaMod>> GetLuaMods();
};
