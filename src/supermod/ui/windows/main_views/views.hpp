#pragma once
#include <string>
#include <supermod/modloader/mod/Mod.hpp>
#include <vector>

namespace sm::ui::windows::main
{
enum ViewType
{
    MODS,
    REGISTRY,
    SETTINGS,
    TOOLS
};

static const std::vector<std::string> VIEW_NAMES = {"Моды", "Скачать моды", "Настройки", "Инструменты"};

void ModsView();
void RegistryView();
void SettingsView();
void ToolsView();

inline void View(const ViewType index)
{
    switch (index)
    {
    case MODS:
        ModsView();
        break;
    case REGISTRY:
        RegistryView();
        break;
    case SETTINGS:
        SettingsView();
        break;
    case TOOLS:
        ToolsView();
        break;
    default:
        break;
    }
}

struct MainWindowState
{
    static inline ViewType currentView = MODS;
    static inline std::optional<std::string> activeRegistryMod = std::nullopt;
    static inline std::optional<std::shared_ptr<modloader::Mod>> activeMod = std::nullopt;
};
} // namespace sm::ui::windows::main