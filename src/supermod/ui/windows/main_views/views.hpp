#pragma once
#include <string>
#include <vector>

namespace sm::ui::windows::main
{
static const std::vector<std::string> VIEW_NAMES = {"Моды", "Скачать моды", "Настройки", "Инструменты"};

void ModsView();
void RegistryView();
void SettingsView();
void ToolsView();

inline void View(const int index)
{
    switch (index)
    {
    case 0:
        ModsView();
        break;
    case 1:
        RegistryView();
        break;
    case 2:
        SettingsView();
        break;
    case 3:
        ToolsView();
        break;
    default:
        break;
    }
}

static inline int currentView = 0;
} // namespace sm::ui::windows::main