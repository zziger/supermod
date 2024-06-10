#include <supermod/io/logs/Console.hpp>

#include <spdlog/pattern_formatter.h>
#include <spdlog/sinks/basic_file_sink.h>
#include <spdlog/sinks/stdout_color_sinks.h>
#include <supermod/Config.hpp>
#include <supermod/game/Game.hpp>
#include <supermod/io/logs/AnsiFileSink.hpp>
#include <supermod/io/logs/LogLevelFormatterFlag.hpp>
#include <supermod/ui/NotificationManager.hpp>

namespace sm::io
{
static BOOL WINAPI ConsoleCtrlHandler(DWORD dwCtrlType)
{
    switch (dwCtrlType)
    {
    case CTRL_C_EVENT:
    case CTRL_CLOSE_EVENT:
        game::Game::RequestExit();
        return TRUE;

    default:
        return FALSE;
    }
}

std::filesystem::path Console::GetLogsDir()
{
    return game::Game::GetRootPath() / "logs";
}

void Console::CleanupLogs()
{
    if (!exists(GetLogsDir()))
        return;

    const auto& cfg = Config::Get();
    if (!cfg.log.limitFiles)
        return;

    try
    {
        std::vector<std::filesystem::directory_entry> logs;
        for (const auto& entry : std::filesystem::directory_iterator(GetLogsDir()))
        {
            const auto& path = entry.path();
            const auto& filename = path.filename().string();
            if (path.extension() != ".log")
                continue;
            if (filename.find("supermod_") == 0)
                logs.push_back(entry);
        }

        if (logs.size() > cfg.log.maxFiles - 1)
        {
            std::ranges::sort(
                logs, [](const auto& lhs, const auto& rhs) { return lhs.last_write_time() > rhs.last_write_time(); });
            for (size_t i = cfg.log.maxFiles - 1; i < logs.size(); ++i)
                std::filesystem::remove(logs[i]);
        }
    }
    catch (std::exception& e)
    {
        ui::NotificationManager::Notify(std::format("Не удалось очистить папку логов.\n{}", e.what()));
    }
}

void Console::Initialize()
{
    const auto& cfg = Config::Get();

    AllocConsole();
    if (stdinFile == nullptr)
        freopen_s(&stdinFile, "CONIN$", "r", stdin);
    if (stdoutFile == nullptr)
        freopen_s(&stdoutFile, "CONOUT$", "w", stdout);
    SetConsoleTitle(L"SuperMod console");
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    SetConsoleCtrlHandler(ConsoleCtrlHandler, TRUE);
    if (void* hOut = GetStdHandle(STD_OUTPUT_HANDLE); hOut != INVALID_HANDLE_VALUE)
        if (DWORD dwMode = 0; GetConsoleMode(hOut, &dwMode))
            SetConsoleMode(hOut, dwMode | ENABLE_VIRTUAL_TERMINAL_PROCESSING);

    // CleanupLogs();

    std::vector<std::shared_ptr<spdlog::sinks::sink>> sinks{};

    {
        const auto consoleSink = std::make_shared<spdlog::sinks::stdout_color_sink_mt>();
        auto consoleFormatter = std::make_unique<spdlog::pattern_formatter>();
        consoleFormatter->add_flag<LogLevelFormatterFlag>('*').set_pattern("\x1b[1;30m[%T]\x1b[0m [%n] %* %v\x1b[0m");
        consoleSink->set_formatter(std::move(consoleFormatter));
        consoleSink->set_level(spdlog::level::trace);
        sinks.push_back(consoleSink);
    }

    {
        create_directories(GetLogsDir());
        const auto logFilename =
            std::format("supermod_{:%Y-%m-%d-%H-%M-%S}.log",
                        std::chrono::time_point_cast<std::chrono::seconds>(std::chrono::system_clock::now()));
        const auto fileSink = std::make_shared<AnsiFileSink<std::mutex>>((GetLogsDir() / logFilename).string(), true);
        fileSink->set_pattern("[%d.%m.%Y %T] [%n] [%l] %v");
        fileSink->set_level(spdlog::level::debug);
        sinks.push_back(fileSink);
    }

    mainLogger = std::make_shared<spdlog::logger>("core", begin(sinks), end(sinks));
    set_default_logger(mainLogger);

    gameLogger = std::make_shared<spdlog::logger>("game", begin(sinks), end(sinks));
    gameLogger->set_level(spdlog::level::info);

    // spdlog::flush_every(std::chrono::seconds(1));

    Update();
}

void Console::Enable()
{
    if (enabled)
        return;
    enabled = true;
    const auto wnd = GetConsoleWindow();
    if (wnd != nullptr)
    {
        ShowWindow(wnd, SW_RESTORE);

        if (HMENU menu = GetSystemMenu(wnd, FALSE); menu != nullptr)
        {
            DeleteMenu(menu, SC_CLOSE, MF_BYCOMMAND);
        }
    }
}

void Console::Disable()
{
    if (!enabled)
        return;
    enabled = false;
    const auto wnd = GetConsoleWindow();
    if (wnd != nullptr)
    {
        ShowWindow(wnd, SW_HIDE);
    }
}

void Console::Update()
{
    auto& cfg = Config::Get();
    if (cfg.console)
        Enable();
    else
        Disable();
    mainLogger->set_level(cfg.log.level >= 0 && cfg.log.level < spdlog::level::n_levels ? cfg.log.level
                                                                                        : spdlog::level::info);
}

void Console::AddToLua(const std::shared_ptr<spdlog::logger>& logger, sol::table table)
{
    auto log = table.create("log");

    log["info"] = sol::as_function([logger](const std::string& msg) { logger->info(msg); });
    log["error"] = sol::as_function([logger](const std::string& msg) { logger->error(msg); });
    log["warn"] = sol::as_function([logger](const std::string& msg) { logger->warn(msg); });
    log["debug"] = sol::as_function([logger](const std::string& msg) { logger->debug(msg); });
    log["trace"] = sol::as_function([logger](const std::string& msg) { logger->trace(msg); });
    log["critical"] = sol::as_function([logger](const std::string& msg) { logger->critical(msg); });
    log["game"] = sol::as_function([logger](const std::string& msg) { logger->info(msg); }); // TODO: deprecate
}
} // namespace sm::io