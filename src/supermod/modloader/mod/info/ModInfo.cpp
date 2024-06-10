#include <supermod/modloader/mod/info/ModInfo.hpp>
#include <supermod/pch.hpp>

#include <regex>
#include <supermod/game/Game.hpp>

using namespace sm::utils;

namespace sm::modloader
{
bool ModInfo::HasDependency(const std::string& id) const
{
    return std::ranges::find_if(dependencies, [&](const Dependency& dep) { return dep.id == id; }) !=
           dependencies.end();
}

ModInfo::Dependency ModInfo::AsDependency() const
{
    return Dependency{id, title, VersionRange({{{VersionRange::Operator::GREATER_EQUAL, version}}})};
}

void ModInfo::Parse(YAML::Node& node)
{
    assert(id.empty() && "Tried to parse ModInfo overriding existing data");

    if (!node.IsMap())
        throw ParseError("Неверный формат манифеста");
    if (!node["id"])
        throw ParseError("Не удалось найти ID в манифесте");

    id = node["id"].as<std::string>();
    const std::regex idRegex("^[a-zA-Z0-9_-]{2,32}$");

    if (!std::regex_match(id, idRegex))
    {
        throw Error("ID в манифесте должен состоять из символов английского алфавита, цифр, _ или - и быть длиной от 2 "
                    "до 32 символов");
    }

    title = node["title"].as<std::string>(id);
    author = node["author"].as<std::string>("");
    version = semver::version::parse(node["version"].as<std::string>("0.0.0"), false);
    description = std::regex_replace(node["description"].as<std::string>(""), std::regex("^\\s+|\\s+$"), "");

    if (node["deps"])
    {
        for (auto depsArr = Clone(node["deps"]); const auto& dep : depsArr)
        {
            Dependency dependency;
            if (dep.IsScalar())
            {
                dependency.id = dep.as<std::string>();
            }
            else
            {
                dependency.id = dep["id"].as<std::string>();
                dependency.version = VersionRange::Parse(dep["version"].as<std::string>(""));
                dependency.name = dep["name"].as<std::string>("");
            }
            dependencies.push_back(dependency);
        }
    }

    socialLinks = node["socialLinks"].as<std::map<std::string, std::string>>(std::map<std::string, std::string>{});

    sdkVersion = semver::version::parse(node["sdk-version"].as<std::string>(SUPERMOD_VERSION));
    const auto versions = node["game-versions"].as<std::vector<std::string>>(std::vector<std::string>{});
    if (!versions.empty())
    {
        for (const auto& gameVersionString : versions)
        {
            auto gameVersion = game::Game::ParseGameVersion(gameVersionString);
            if (!gameVersion)
            {
                spdlog::warn("Invalid game version {} in mod {}", gameVersionString, title);
                continue;
            }
            gameVersions.push_back(gameVersion);
        }
    }

    scriptMain = node["main"].as<std::string>(node["lua-script"].as<std::string>(""));
    scriptType = scriptMain.ends_with(".lua")   ? ScriptType::LUA
                 : scriptMain.ends_with(".dll") ? ScriptType::DLL
                                                : ScriptType::NONE; // TODO: better script type handling

    if (!node["title"])
        spdlog::warn("No title found in mod {}", id);
    // todo compatibility check somewhere
}

std::string ModInfo::ToString() const
{
    return std::format("Mod<{}>", GetID());
}
} // namespace sm::modloader
