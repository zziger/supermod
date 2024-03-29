#include "ForwardGameLogsModule.h"

#include <logs/Console.h>
#include <ui/widgets/widgets.h>

#include "Config.h"
#include "Utils.h"

HOOK_FN(int, debug_log, ARGS(char* format, ...)) {
    if (!Config::Get().patches.forwardGameLogs.writeToLog) return 0;
    va_list va;
    va_start(va, format);
    char buffer[1024];
    vsprintf_s(buffer, 1024, format, va);
    Console::gameLogger->info(buffer);
    return 0;
}

void ForwardGameLogsModule::Init()
{
    state = Config::Get().patches.forwardGameLogs.enabled;
    if (state) OnLoad();
}

void ForwardGameLogsModule::Render()
{
    auto& cfg = Config::Get();
    auto& cfgBlock = cfg.patches.forwardGameLogs;

    if (ImGui::Checkbox("Перенаправление логов", &state))
    {
        cfgBlock.enabled = state;
        cfg.Save();

        if (state) OnLoad();
        else OnUnload();
    }

    ImGui::SameLine();
    ui::widgets::HelpMarker("Позволяет отключить или перенаправить логи игры");

    if (!state) return;

    ImGui::Spacing();
    ImGui::TreePush("Параметры логов");
    int mode = cfgBlock.writeToLog ? 1 : 0;

    if (ImGui::RadioButton("Выключить логи", &mode, 0))
    {
        cfgBlock.writeToLog = false;
        cfg.Save();
    }

    if (ImGui::RadioButton("Перенаправить в лог SuperMod", &mode, 1))
    {
        cfgBlock.writeToLog = true;
        cfg.Save();
    }

    ImGui::TreePop();
}

void ForwardGameLogsModule::OnLoad()
{
    logHook = HookManager::RegisterHook("55 8B EC 83 EC ? 0F B6 05 ? ? ? ? 85 C0 75 ? E9 ? ? ? ? 8D 4D", HOOK_REF(debug_log));
}

void ForwardGameLogsModule::OnUnload()
{
    if (logHook) HookManager::UnregisterHook(*logHook);
}
