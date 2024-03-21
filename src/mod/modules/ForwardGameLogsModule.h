#pragma once
#include <optional>
#include <memory/HookManager.h>

class ForwardGameLogsModule {
public:
    bool state = true;

    std::optional<HookManager::RegisteredHook> logHook;

    void Init();
    void Render();

private:
    void OnLoad();
    void OnUnload();
};
