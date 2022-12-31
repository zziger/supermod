#pragma once
#include <filesystem>

#include "modloader/mods/Mod.h"

class ModFileResolver {
    inline static bool _initialized = false;
    inline static std::unordered_set<std::wstring> resolvedFilePaths {}; 
    inline static std::unordered_set<std::string> filesToReload {};
    inline static std::recursive_mutex _reloadMutex {};

    static void FileListenerThread();
    
public:
    [[nodiscard]] static std::optional<std::filesystem::path> ResolveFile(const std::filesystem::path& path);

    [[nodiscard]] static std::optional<std::filesystem::path> ResolveModFile(const std::shared_ptr<Mod>& mod, const std::filesystem::path& path);

    static void Init();
};
