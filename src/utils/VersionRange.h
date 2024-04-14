#pragma once
#include <map>
#include <ranges>

#include "VersionRange.h"
#include <modloader/mod/impl/lua/lua.h>

class VersionRange {
public:
    enum class Operator {
        EQUAL,
        GREATER,
        LESS,
        GREATER_EQUAL,
        LESS_EQUAL
    };

    using ConditionGroup = std::vector<std::pair<Operator, semver::version>>;
    explicit VersionRange(const std::vector<ConditionGroup>& conditionGroups) : conditionGroups(conditionGroups) {}
    explicit VersionRange(std::vector<ConditionGroup>&& conditionGroups) : conditionGroups(std::move(conditionGroups)) {}
    VersionRange() = default;
    VersionRange(const VersionRange&) = default;
    VersionRange(VersionRange&&) = default;

    VersionRange& operator=(const VersionRange&) = default;

    [[nodiscard]] bool Match(const semver::version& ver) const
    {
        if (conditionGroups.empty()) return true;
        return std::ranges::any_of(
            conditionGroups,
            [&](const auto& group) { return VersionRange::MatchGroup(ver, group); }
        );
    }

    [[nodiscard]] std::string Serialize(const bool localize = false) const
    {
        std::stringstream ss;

        auto groups = conditionGroups.size();
        for (auto i = 0; i < groups; i++)
        {
            const auto& group = conditionGroups[i];
            auto versions = group.size();
            for (auto j = 0; j < versions; j++)
            {
                const auto& [op, version] = group[j];
                switch(op)
                {
                    case Operator::EQUAL: ss << "="; break;
                    case Operator::GREATER: ss << ">"; break;
                    case Operator::LESS: ss << "<"; break;
                    case Operator::GREATER_EQUAL: ss << ">="; break;
                    case Operator::LESS_EQUAL: ss << "<="; break;
                }

                ss << version.str();
                if (i != groups - 1 || j != versions - 1) ss << " ";
            }

            if (i != groups - 1) ss << (localize ? " или" : " ||");
        }

        return ss.str();
    }

    static VersionRange Parse(const std::string& str)
    {
        std::vector<ConditionGroup> conditionGroups;
        ConditionGroup currentGroup;

        std::stringstream ss(str);
        std::string token;

        while(std::getline(ss, token, ' '))
        {
            if (token.empty()) continue;

            if (token == "||")
            {
                if (!currentGroup.empty())
                {
                    conditionGroups.push_back(currentGroup);
                    currentGroup.clear();
                }
                continue;
            }

            Operator op = Operator::GREATER_EQUAL;
            int versionOffset = 0;

            if (token.size() > 1 && token[0] == '<' && token[1] == '=')
            {
                op = Operator::LESS_EQUAL;
                versionOffset = 2;
            }
            else if (token[0] == '<')
            {
                op = Operator::LESS;
                versionOffset = 1;
            }
            else if (token.size() > 1 && token[0] == '>' && token[1] == '=')
            {
                op = Operator::GREATER_EQUAL;
                versionOffset = 2;
            }
            else if (token[0] == '>')
            {
                op = Operator::GREATER;
                versionOffset = 1;
            }
            else if (token[0] == '=')
            {
                op = Operator::EQUAL;
                versionOffset = 1;
            }

            auto ver = semver::version::parse(token.substr(versionOffset), false);
            currentGroup.emplace_back(op, ver);
        }

        if (!currentGroup.empty())
            conditionGroups.push_back(currentGroup);

        return VersionRange(std::move(conditionGroups));
    }

    static void RegisterLuaType(sol::state& lua)
    {
        auto package = get_package_table(lua, "data");

        package.new_usertype<semver::version>("version",
            sol::call_constructor, sol::constructors<semver::version()>(),
            "string", &semver::version::str,
            "parse", &semver::version::parse,
            sol::meta_function::to_string, [](const semver::version& ver) { return std::format("Version<{}>", ver.str()); },
            sol::meta_function::equal_to, &semver::version::operator==,
            sol::meta_function::less_than, &semver::version::operator<,
            sol::meta_function::less_than_or_equal_to, &semver::version::operator<=
        );

        package.new_usertype<VersionRange>("versionRange",
            sol::call_constructor, sol::constructors<VersionRange()>(),
            "serialize", &VersionRange::Serialize,
            "match", &VersionRange::Match,
            "parse", &VersionRange::Parse,
            sol::meta_function::to_string, [](const VersionRange& ver) { return std::format("VersionRange<{}>", ver.Serialize()); }
        );
    }

private:
    [[nodiscard]] static bool MatchGroup(const semver::version& ver, const ConditionGroup& group)
    {
        for (const auto& [op, targetVer] : group)
        {
            switch(op)
            {
                case Operator::EQUAL: if (ver != targetVer) return false; break;
                case Operator::GREATER: if (ver <= targetVer) return false; break;
                case Operator::LESS: if (ver >= targetVer) return false; break;
                case Operator::GREATER_EQUAL: if (ver < targetVer) return false; break;
                case Operator::LESS_EQUAL: if (ver > targetVer) return false; break;
            }
        }

        return true;
    }

    std::vector<ConditionGroup> conditionGroups;
};
