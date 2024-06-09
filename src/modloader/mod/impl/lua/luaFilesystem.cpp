#pragma once
#include "lua.h"
#include <Data.h>

namespace sol::stack
{
inline std::filesystem::path pop_path(lua_State* L)
{
    return sol::stack::check_usertype<std::filesystem::path>(L) ? sol::stack::pop<std::filesystem::path>(L)
                                                                : sol::stack::pop<std::string>(L);
}
} // namespace sol::stack

namespace lua::helpers
{
inline std::filesystem::copy_options makeCopyFlagsFromLua(const sol::table& table)
{
    using namespace std::filesystem;
    copy_options flags = copy_options::none;

    if (const std::optional<bool> recursive = table["recursive"])
    {
        if (*recursive)
            flags |= copy_options::recursive;
    }
    else if (!table["recursive"].is<sol::nil_t>())
    {
        throw std::exception(std::format("expected 'recursive' to be a boolean, got {} instead",
                                         type_name(table.lua_state(), table["recursive"].get_type()))
                                 .c_str());
    }

    if (const std::optional<std::string> existing = table["existing"])
    {
        if (*existing == "skip")
            flags |= copy_options::skip_existing;
        if (*existing == "update")
            flags |= copy_options::update_existing;
        if (*existing == "overwrite")
            flags |= copy_options::overwrite_existing;
        else
            throw std::exception(
                std::format("expected 'existing' to be 'skip', 'update' or 'overwrite', got '{}' instead", *existing)
                    .c_str());
    }
    else if (!table["existing"].is<sol::nil_t>())
    {
        throw std::exception(std::format("expected 'existing' to be 'skip', 'update' or 'overwrite', got {} instead",
                                         type_name(table.lua_state(), table["existing"].get_type()))
                                 .c_str());
    }

    if (const std::optional<std::string> symlinks = table["symlinks"])
    {
        if (symlinks == "copy")
            flags |= copy_options::copy_symlinks;
        if (symlinks == "skip")
            flags |= copy_options::skip_symlinks;
        else
            throw std::exception(
                std::format("expected 'symlinks' to be 'skip' or 'copy', got '{}' instead", *symlinks).c_str());
    }
    else if (!table["symlinks"].is<sol::nil_t>())
    {
        throw std::exception(std::format("expected 'symlinks' to be 'skip' or 'copy', got {} instead",
                                         type_name(table.lua_state(), table["symlinks"].get_type()))
                                 .c_str());
    }

    return flags;
}
} // namespace lua::helpers

void registerLuaFilesystem(sol::table table)
{
    using namespace std::filesystem;
    using string = std::string;
    using namespace lua::helpers;

    table.new_usertype<path>(
        "path", sol::call_constructor, sol::constructors<path(), path(std::string)>(),

        sol::meta_function::to_string, static_cast<std::string (path::*)() const>(&path::generic_string),

        sol::meta_function::division,
        [](lua_State* L) -> int {
            const path other = sol::stack::pop_path(L);
            const path self = sol::stack::pop_path(L);

            sol::stack::push(L, self / other);
            return 1;
        },

        "clear", &path::clear, "removeFilename", &path::remove_filename, "replaceFilename",
        sol::overload_conv<path(path&, const path&), path(path&, const string&)>(
            [](path& path, auto... args) { return path.replace_filename(args...); }),
        "replaceExtension",
        sol::overload_conv<path(path&, const path&), path(path&, const string&)>(
            [](path& path, auto... args) { return path.replace_extension(args...); }),
        "makePreferred", &path::make_preferred,

        "append",
        sol::overload_conv<path(const path&, const path&), path(const path&, const string&)>(
            [](const path& path, auto arg) { return path / arg; }),

        "parentPath", &path::parent_path, "filename", &path::filename, "stem", &path::stem, "extension",
        &path::extension,

        "isEmpty", &path::empty, "hasParentPath", &path::has_parent_path, "hasFilename", &path::has_filename, "hasStem",
        &path::has_stem, "hasExtension", &path::has_extension,

        "isAbsolute", &path::is_absolute, "isRelative", &path::is_relative,

        "genericString", static_cast<std::string (path::*)() const>(&path::generic_string), "string",
        static_cast<std::string (path::*)() const>(&path::string));

    table["currentPath"] = sol::overload_conv<path(), void(const path&), void(const std::string&)>(
        [](auto... args) { return current_path(args...); });

    table["tempDirectoryPath"] = sol::resolve<path()>(&temp_directory_path); // tempDirectoryPath() -> path

    table["absolute"] =
        sol::overload_conv<path(const path&), path(const string&)>([](auto... args) { return absolute(args...); });
    table["relative"] =
        sol::overload_conv<path(const path&), path(const string&), path(const path&, const path&),
                           path(const string&, const string&), path(const path&, const string&),
                           path(const string&, const path&)>([](auto... args) { return relative(args...); });

    table["isDirectory"] =
        sol::overload_conv<bool(const path&), bool(const string&)>([](auto... args) { return is_directory(args...); });
    table["isEmpty"] =
        sol::overload_conv<bool(const path&), bool(const string&)>([](auto... args) { return is_empty(args...); });
    table["exists"] =
        sol::overload_conv<bool(const path&), bool(const string&)>([](auto... args) { return exists(args...); });

    table["remove"] =
        sol::overload_conv<bool(const path&), bool(const string&)>([](auto... args) { return remove(args...); });
    table["removeAll"] = sol::overload_conv<uint64_t(const path&), uint64_t(const string&)>(
        [](auto... args) { return remove_all(args...); });

    table["createDirectory"] = sol::overload_conv<bool(const path&), bool(const string&)>(
        [](auto... args) { return create_directory(args...); });
    table["createDirectories"] = sol::overload_conv<bool(const path&), bool(const string&)>(
        [](auto... args) { return create_directories(args...); });

    table["copy"] = sol::overload(
        sol::resolve<void(const path&, const path&)>(&copy),                         // copy(path, path) -> void
        [](const string& from, const string& to) -> void { return copy(from, to); }, // copy(string, string) -> void
        [](const path& from, const string& to) -> void { return copy(from, to); },   // copy(path, string) -> void
        [](const string& from, const path& to) -> void { return copy(from, to); },   // copy(string, path) -> void
        [](const path& from, const path& to, const sol::table& options) -> void {
            copy(from, to, makeCopyFlagsFromLua(options));
        }, // copy(path, path, options) -> void
        [](const string& from, const string& to, const sol::table& options) -> void {
            copy(path(from), path(to), makeCopyFlagsFromLua(options));
        }, // copy(string, string, options) -> void
        [](const path& from, const string& to, const sol::table& options) -> void {
            copy(path(from), path(to), makeCopyFlagsFromLua(options));
        }, // copy(path, string, options) -> void
        [](const string& from, const path& to, const sol::table& options) -> void {
            copy(path(from), path(to), makeCopyFlagsFromLua(options));
        } // copy(string, path, options) -> void
    );
    table["move"] = table["rename"] =
        sol::overload_conv<void(const path&, const path&), void(const string&, const string&)>(
            [](auto... args) { return rename(args...); });
}
