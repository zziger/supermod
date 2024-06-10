#pragma once
#include <supermod/pch.hpp>

#include <regex>
#include <supermod/modloader/mod/impl/lua/lua.hpp>

namespace sm
{
class Console
{
public:
    static constexpr std::string_view WARN_COLOR_RESET = "\x1b[1;33m";

    static std::filesystem::path GetLogsDir();
    static void CleanupLogs();
    static void Initialize();

    inline static bool enabled = false;
    inline static FILE* stdinFile = nullptr;
    inline static FILE* stdoutFile = nullptr;

    inline static std::shared_ptr<spdlog::logger> mainLogger;
    inline static std::shared_ptr<spdlog::logger> gameLogger;

    static void Enable();
    static void Disable();
    static void Update();

    static fmt::detail::styled_arg<std::string> StyleToggle(const std::string& modName, bool toggle)
    {
        return styled(modName, fg(toggle ? fmt::rgb(0xa3c9a3) : fmt::rgb(0xc9aea3)));
    }

    static fmt::detail::styled_arg<std::string> StyleModName(const std::string& modName)
    {
        return styled(modName, fg(fmt::rgb(0x9c9b86)));
    }

    template <typename T>
    static fmt::detail::styled_arg<T> StyleEmphasise(const T& value)
    {
        return styled(value, fg(fmt::rgb(0x999999)));
    }

    static void AddToLua(const std::shared_ptr<spdlog::logger>& logger, sol::table table);
};
} // namespace sm