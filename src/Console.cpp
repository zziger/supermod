#include "Console.h"


static BOOL WINAPI ConsoleCtrlHandler(DWORD dwCtrlType) {
    switch (dwCtrlType) {
    case CTRL_C_EVENT:
    case CTRL_CLOSE_EVENT:
        sdk::Game::RequestExit();
        return TRUE;

    default:
        return FALSE;
    }
}

void Console::Initialize()
{
    if (Config::Get().console) Enable();
    SetConsoleCtrlHandler(ConsoleCtrlHandler, TRUE);
}

void Console::Enable()
{
    if (enabled) return;
    enabled = true;
    AllocConsole();
    if (stdinFile == nullptr) freopen_s(&stdinFile, "CONIN$", "r", stdin);
    if (stdoutFile == nullptr) freopen_s(&stdoutFile, "CONOUT$", "w", stdout);
    SetConsoleTitle(L"SuperMod console");
    SetConsoleOutputCP( CP_UTF8);
    SetConsoleCP( CP_UTF8);
    const auto wnd = GetConsoleWindow();
    if (wnd != nullptr) {
        ShowWindow(wnd, SW_RESTORE);

        if(HMENU menu = GetSystemMenu(wnd, FALSE); menu != nullptr)
        {
            DeleteMenu(menu, SC_CLOSE, MF_BYCOMMAND);
        }
    }
}

void Console::Disable()
{
    if (!enabled) return;
    enabled = false;
    const auto wnd = GetConsoleWindow();
    if (wnd != nullptr) {
        ShowWindow(wnd, SW_HIDE);
    }
}
