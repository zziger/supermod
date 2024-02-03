#pragma once
#include <filesystem>
#include <map>
#include <semver.hpp>
#include <exceptions/Error.h>
#include <yaml-cpp/node/node.h>

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

        std::string id;
        std::string title;
        std::string author;
        std::string version;
        std::string description;
        std::map<std::string, std::string> socialLinks {};

        semver::version sdkVersion;
        std::vector<uint64_t> gameVersions {};

        ScriptType scriptType;
        std::string scriptMain;

        /**
         * \brief Parse mod info from YAML node
         * \param node YAML node to parse from
         * \throws ParseError YAML parse error
         */
        void Parse(const YAML::Node& node);
        // TODO serialize
    };
}
