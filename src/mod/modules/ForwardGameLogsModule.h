#pragma once
#include <memory/HookManager.h>
#include <optional>

class ForwardGameLogsModule
{
public:
    bool state = true;

    std::optional<HookManager::RegisteredHook> logHook;

    void Init();
    void Render();

private:
    void OnLoad();
    void OnUnload();
};
