#pragma once
#include <filesystem>
#include <map>
#include <semver/semver.hpp>
#include <set>
#include <utility>
#include <exceptions/Error.h>
#include <yaml-cpp/yaml.h>
#include "ModIcon.h"

namespace modloader {
    struct ModInfo {
        enum class ScriptType
        {
            NONE,
            LUA,
            DLL
        };

        class ParseError final : public Error
        {
            using Error::Error;
        };

        virtual ~ModInfo() = default;
        ModInfo() = default;
        explicit ModInfo(std::string id) : id(std::move(id)) {}

        [[nodiscard]] std::string GetID() const { return id; }
        std::optional<ModIcon> icon;
        std::string title;
        std::string author;
        std::string version;
        std::string description;
        std::set<std::string> deps;
        std::map<std::string, std::string> socialLinks {};

        semver::version sdkVersion;
        std::vector<uint64_t> gameVersions {};

        ScriptType scriptType = ScriptType::NONE;
        std::string scriptMain;

        /**
         * \brief Parse mod info from YAML node
         * \param node YAML node to parse from
         * \throws ParseError YAML parse error
         */
        void Parse(YAML::Node& node);

        void SetIcon(std::optional<ModIcon> icon) { this->icon = std::move(icon); }
        // TODO serialize

        [[nodiscard]] std::string ToString() const;

        static void RegisterLuaType(sol::state& lua) {
            lua.new_usertype<ModInfo>(sol::no_constructor,
                "id", &ModInfo::id,
                "title", &ModInfo::title,
                "author", &ModInfo::author,
                "version", &ModInfo::version,
                "description", &ModInfo::description,
                "deps", &ModInfo::deps,
                "socialLinks", &ModInfo::socialLinks,
                "gameVersions", &ModInfo::gameVersions,
                sol::meta_function::to_string, &ModInfo::ToString
            );
        }

    private:
        std::string id;
    };
}
