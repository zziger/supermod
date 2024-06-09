#pragma once
#include <string>
#include <vector>

namespace ui::windows::main
{
static const std::vector<std::string> VIEW_NAMES = {"Моды", "Настройки", "Инструменты"};

void ModsView();
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
        SettingsView();
        break;
    case 2:
        ToolsView();
        break;
    default:
        break;
    }
}

static inline int currentView = 0;
} // namespace ui::windows::main