#pragma once
#include <supermod/pch.hpp>

#include <supermod/memory/HookManager.hpp>

namespace sm::builtin
{
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
} // namespace sm::builtin