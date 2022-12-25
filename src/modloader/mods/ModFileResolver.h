#pragma once
#include <filesystem>

#include "CGameApis.h"
#include "modloader/mods/Mod.h"

class ModFileResolver {
    inline static bool _initialized = false;
    
public:
    [[nodiscard]] static std::optional<std::filesystem::path> ResolveFile(const std::filesystem::path& path);

    [[nodiscard]] static std::optional<std::filesystem::path> ResolveModFile(const std::shared_ptr<Mod>& mod, const std::filesystem::path& path);

    static void Init();
};
