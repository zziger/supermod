#include <supermod/pch.hpp>
#include <supermod/ui/widgets/widgets.hpp>

#include <imgui_internal.h>
#include <supermod/Utils.hpp>
#include <supermod/modloader/ModManager.hpp>
#include <supermod/modloader/mod/info/ModInfoFilesystem.hpp>
#include <supermod/ui/Ui.hpp>

void sm::ui::widgets::mods::ContextMenu(const std::shared_ptr<modloader::Mod>& mod)
{
    if (ImGui::MenuItem(mod->IsEnabled() ? ICON_MD_POWER_SETTINGS_NEW " Выключить"
                                         : ICON_MD_POWER_SETTINGS_NEW "Включить"))
    {
        modloader::ModManager::ToggleMod(mod, !mod->IsEnabled());
    }

    if (mod->IsEnabled() ? !modloader::ModManager::GetModDependents(mod->GetID()).empty()
                         : !mod->GetInfo()->dependencies.empty())
    {
        if (ImGui::MenuItem(mod->IsEnabled() ? ICON_MD_POWER_SETTINGS_NEW " Выключить без зависимых модов"
                                             : ICON_MD_POWER_SETTINGS_NEW " Включить без зависимостей"))
        {
            mod->Toggle(!mod->IsEnabled());
            modloader::ModManager::SaveConfig(mod);
        }
    }

    ImGui::Separator();

    auto fsInfo = std::dynamic_pointer_cast<modloader::ModInfoFilesystem>(mod->GetInfo());
    if (ImGui::MenuItem(ICON_MD_FOLDER_OPEN " Открыть папку", nullptr, false, !!fsInfo) && fsInfo)
    {
        fsInfo->OpenFolder();
    }

    if (ImGui::MenuItem(ICON_MD_REFRESH " Перезагрузить", nullptr, false, !mod->IsActive()))
    {
        modloader::ModManager::ReloadMod(mod);
    }
    if (mod->IsActive())
        Tooltip("Мод должен быть выключен для перезагрузки", ImGuiHoveredFlags_AllowWhenDisabled);

    ImGui::Separator();

    const auto willRemove = mod->HasFlag(modloader::Mod::Flag::REMOVAL_SCHEDULED);

    ImGui::PushStyleColor(ImGuiCol_HeaderHovered, 0xE0422ECC_color);
    if (ImGui::MenuItem(willRemove ? ICON_MD_REPLAY " Отменить удаление" : ICON_MD_DELETE " Удалить"))
    {
        if (willRemove)
        {
            modloader::ModManager::ScheduleModRemoval(mod, false);
        }
        else
        {
            ImGui::PushOverrideID(Ui::GetModalsId(mod));
            ImGui::OpenPopup("Удаление мода");
            ImGui::PopID();
        }
    }
    ImGui::PopStyleColor();
}
