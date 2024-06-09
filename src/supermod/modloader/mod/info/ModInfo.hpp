#pragma once
#include <supermod/pch.hpp>

#include <map>
#include <semver/semver.hpp>
#include <supermod/exceptions/Error.hpp>
#include <supermod/modloader/mod/info/ModIcon.hpp>
#include <supermod/utils/VersionRange.hpp>
#include <utility>

namespace modloader
{
struct ModInfo
{
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

    struct Dependency
    {
        std::string id;
        std::string name;
        VersionRange version{};

        [[nodiscard]] std::string GetName() const { return name.empty() ? id : name; }

        static void RegisterLuaType(sol::state& lua)
        {
            lua.new_usertype<Dependency>(sol::no_constructor, "id", sol::readonly(&Dependency::id), "name",
                                         sol::readonly(&Dependency::name), "version",
                                         sol::property([](const Dependency& obj) { return obj.version.Serialize(); }),
                                         "getName", &Dependency::GetName);
        }
    };

    virtual ~ModInfo() = default;
    ModInfo() = default;
    explicit ModInfo(std::string id) : id(std::move(id)) {}

    [[nodiscard]] std::string GetID() const { return id; }
    std::optional<ModIcon> icon = std::nullopt;
    std::string title;
    std::string author;
    semver::version version = semver::version(0, 0, 0);
    std::string description;
    std::vector<Dependency> dependencies{};
    std::map<std::string, std::string> socialLinks{};

    semver::version sdkVersion = semver::version::parse(SUPERMOD_VERSION);
    std::vector<uint64_t> gameVersions{};

    ScriptType scriptType = ScriptType::NONE;
    std::string scriptMain;

    [[nodiscard]] bool HasDependency(const std::string& id) const;
    [[nodiscard]] Dependency AsDependency() const;

    /**
     * \brief Parse mod info from YAML node
     * \param node YAML node to parse from
     * \throws ParseError YAML parse error
     */
    void Parse(YAML::Node& node);

    void SetIcon(std::optional<ModIcon> icon) { this->icon = std::move(icon); }
    // TODO serialize

    [[nodiscard]] std::string ToString() const;

    static void RegisterLuaType(sol::state& lua)
    {
        Dependency::RegisterLuaType(lua);

        lua.new_usertype<ModInfo>(sol::no_constructor, "id", &ModInfo::id, "title", &ModInfo::title, "author",
                                  &ModInfo::author, "version", &ModInfo::version, "description", &ModInfo::description,
                                  "dependencies", &ModInfo::dependencies, "socialLinks", &ModInfo::socialLinks,
                                  "gameVersions", &ModInfo::gameVersions, "hasDependency", &ModInfo::HasDependency,
                                  sol::meta_function::to_string, &ModInfo::ToString);
    }

private:
    std::string id;
};
} // namespace modloader
