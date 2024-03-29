#pragma once

#include <spdlog/spdlog.h>

class LogLevelFormatterFlag final : public spdlog::custom_flag_formatter
{
public:
    void format(const spdlog::details::log_msg& msg, const std::tm &, spdlog::memory_buf_t &dest) override
    {
        std::string txt;
        switch(msg.level)
        {
        case spdlog::level::trace:
            txt = "[trace]";
            break;
        case spdlog::level::debug:
            txt = "\x1b[36m[debug]\x1b[0m";
            break;
        case spdlog::level::info:
            txt = "\x1b[1;32m [info]\x1b[0m";
            break;
        case spdlog::level::warn:
            txt = "\x1b[1;33m [warn]"; // don't reset color to cover message
            break;
        case spdlog::level::err:
            txt = "\x1b[1;31m[error]\x1b[0m";
            break;
        case spdlog::level::critical:
            txt = "\x1b[1;37m\x1b[41m[CRITICAL]\x1b[0m";
            break;
        default:
            txt = "";
        }

        dest.append(txt.data(), txt.data() + txt.size());
    }

    [[nodiscard]] std::unique_ptr<custom_flag_formatter> clone() const override
    {
        return spdlog::details::make_unique<LogLevelFormatterFlag>();
    }
};