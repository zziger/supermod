#pragma once

#include <filesystem>
#include <optional>
#include <modloader_new/ModManager.h>
#include <modloader_new/mod/Mod.h>
#include <sdk/Game.h>

#include "loaders/TextureLoader.h"

namespace modloader {
    class ModFileResolver {
        static inline std::map<std::string, std::vector<std::shared_ptr<BaseLoader>>> loaders = {};
        static inline bool initialized = false;

        static void InitLoader(const std::shared_ptr<BaseLoader>& loader);

        template <std::derived_from<BaseLoader> T>
        static void InitLoader() { InitLoader(std::make_shared<T>()); }

    public:
        static void Init();

        [[nodiscard]] static std::optional<std::filesystem::path> ResolveGameFileInMods(const std::filesystem::path& path);
        [[nodiscard]] static std::filesystem::path ResolveGameFile(const std::filesystem::path& path);
        [[nodiscard]] static std::optional<std::filesystem::path> GetGameFileInMod(const std::shared_ptr<Mod>& mod, const std::filesystem::path& path);
        [[nodiscard]] static std::optional<std::filesystem::path> ResolveGameFileInMod(const std::shared_ptr<Mod>& mod, const std::filesystem::path& path);

        static void LoadFile(const std::filesystem::path& path);
        static void LoadFiles(const std::filesystem::path& path);
    };

}
