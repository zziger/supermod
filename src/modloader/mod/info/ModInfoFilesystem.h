#pragma once
#include "ModInfo.h"

namespace modloader
{
struct ModInfoFilesystem final : ModInfo
{
    static constexpr std::string_view MANIFEST_FILENAME = "manifest.yml";
    static constexpr std::string_view ICON_FILENAME = "icon.png";

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

    void UpdateIcon();
    void OpenFolder() const;

    static void RegisterLuaType(sol::state& lua)
    {
        lua.new_usertype<ModInfoFilesystem>(sol::no_constructor, "basePath", &ModInfoFilesystem::basePath,
                                            sol::base_classes, sol::bases<ModInfo>());
    }
};
} // namespace modloader
