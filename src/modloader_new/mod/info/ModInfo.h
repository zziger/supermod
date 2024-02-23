#pragma once
#include <filesystem>
#include <map>
#include <semver.hpp>
#include <set>
#include <utility>
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

        virtual ~ModInfo() = default;
        ModInfo() = default;
        explicit ModInfo(std::string id) : id(std::move(id)) {}

        std::string GetID() { return id; };
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
        // TODO serialize

    private:
        std::string id;
    };
}
