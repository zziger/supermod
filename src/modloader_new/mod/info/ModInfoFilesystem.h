#pragma once
#include "ModInfo.h"

namespace modloader {
    struct ModInfoFilesystem final : ModInfo {
        static constexpr std::string MANIFEST_FILENAME = "manifest.yml";

        std::filesystem::path basePath;

        class ModFileError final : public Error
        {
            using Error::Error;
        };

        /**
         * \brief Creates mod info from folder
         * \param path Mod folder
         * \throws ParseError YAML parse error
         * \throws ModFileError Error related to mod directory or manifest
         */
        void FromPath(const std::filesystem::path& path);
    };
}
