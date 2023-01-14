#pragma once
#include <filesystem>

#include "modloader/mods/Mod.h"

class ModFileResolver {
    inline static bool _initialized = false;
    inline static std::unordered_set<std::wstring> resolvedFilePaths {}; 
    inline static std::unordered_set<std::string> filesToReload {};
    inline static std::mutex _reloadMutex {};

    static inline bool listenerEnabled = false;
    static inline bool ignoreTick = false; // used to prevent unnecessary recursion in tick event when reloading assets
    static void FileListenerThread();

    static std::string GetPoolFileName(const std::string& filename);
    static void LoadTexture(std::filesystem::path filepath);
    static void LoadFile(std::filesystem::path filepath);

    static inline std::unordered_map<std::string, void*> _soundMemory{};
    static void LoadSound(std::filesystem::path soundPath);
    static void LoadAdditionalMusic();

public:
    [[nodiscard]] static std::optional<std::filesystem::path> ResolveFile(const std::filesystem::path& path);
    [[nodiscard]] static std::filesystem::path ResolveFileOrOriginal(const std::filesystem::path& path);

    [[nodiscard]] static std::optional<std::filesystem::path> ResolveModFile(const std::shared_ptr<Mod>& mod, const std::filesystem::path& path);

    static void Init();
    static void ToggleFileListener(bool state);
    static void ReloadModFiles(std::filesystem::path dataFolder);
};
