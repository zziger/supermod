#include <imgui_internal.h>
#include <memory>
#include <vector>
#include <modloader_new/ModManager.h>
#include <modloader_new/mod/Mod.h>
#include <sdk/Game.h>
#include <ui/Ui.h>
#include <ui/popups/popups.h>
#include <ui/styles/styles.h>
#include <ui/widgets/widgets.h>

#include "views.h"

using namespace std::chrono;

void ui::windows::main::ModsView()
{
    static std::optional<std::shared_ptr<modloader::Mod>> activeMod;

    if (activeMod && !(*activeMod)->HasFlag(modloader::Mod::Flag::EXISTS))
        activeMod = std::nullopt;

    static bool reorder = false;
    static std::vector<std::shared_ptr<modloader::Mod>> reorderMods{};

    for (const auto& loadedMod : modloader::ModManager::GetInternalMods())
    {
        popups::ModModals(loadedMod);
    }

    for (const auto& loadedMod : modloader::ModManager::GetMods())
    {
        popups::ModModals(loadedMod);
    }

    const auto width = ImGui::GetContentRegionAvail().x / 2;
    ImGui::BeginChild("Left block", ImVec2(width, 0));
    {
        const auto listHeight = ImGui::GetContentRegionAvail().y - ImGui::GetFrameHeightWithSpacing();
        ImGui::BeginChild("Mods", ImVec2(width, listHeight), true);
        {
            if (!reorder)
            {
                for (const auto& loadedMod : modloader::ModManager::GetInternalMods())
                {
                    if (widgets::mods::Selectable(loadedMod, loadedMod == activeMod)) activeMod = loadedMod;
                    ImGui::Spacing();
                }
                for (const auto& loadedMod : modloader::ModManager::GetMods())
                {
                    if (widgets::mods::Selectable(loadedMod, loadedMod == activeMod)) activeMod = loadedMod;
                    ImGui::Spacing();
                }
            }
            else
            {
                const auto count = reorderMods.size();
                for (auto i = 0; i < count; i++)
                {
                    const auto loadedMod = reorderMods[i];
                    bool hovered, active;
                    widgets::mods::Selectable(loadedMod, false, false, true, &hovered, &active);

                    if (active && !hovered)
                    {
                        const auto dragY = ImGui::GetMouseDragDelta(0).y;
                        if (dragY < 5 && dragY > -5) continue;
                        const int nextI = i + (dragY < 0.f ? -1 : 1);
                        if (nextI < 0 || nextI >= count) continue;
                        std::swap(reorderMods[i], reorderMods[nextI]);
                        ImGui::ResetMouseDragDelta();
                    }

                    ImGui::Spacing();
                }
            }
        }
        ImGui::EndChild();

        if (!reorder)
        {
            if (ImGui::Button(ICON_MD_REORDER " Изменить порядок"))
            {
                reorderMods.clear();
                for (const auto& mod : modloader::ModManager::GetMods()) reorderMods.push_back(mod);

                reorder = true;
                activeMod = std::nullopt;
            }

            ImGui::SameLine();
            ImGui::BeginDisabled(sdk::Game::currentTickIsInner);
            if (ImGui::Button(ICON_MD_REFRESH))
            {
                activeMod = std::nullopt;
            }

            widgets::Tooltip("Перезагрузить все моды");

            ImGui::EndDisabled();
        }
        else
        {
            ImGui::BeginDisabled(sdk::Game::currentTickIsInner);
            if (ImGui::Button(ICON_MD_SAVE " Сохранить"))
            {
                modloader::ModManager::ReorderMods(reorderMods);
                reorder = false;
            }
            ImGui::EndDisabled();
            ImGui::SameLine();
            if (ImGui::Button(ICON_MD_CANCEL " Отмена")) reorder = false;
            ImGui::SameLine();
            widgets::HelpMarker("Перетащите моды мышкой для изменения порядка загрузки");
        }
    }
    ImGui::EndChild();

    ImGui::SameLine();
    ImGui::BeginChild("Mod content", ImVec2(0, 0));
    {
        if (activeMod && !reorder)
        {
            const auto mod = *activeMod;
            const auto info = mod->GetInfo();

            widgets::mods::InfoBlock(info);
            ImGui::Spacing();

            if (!mod->HasFlag(modloader::Mod::Flag::INTERNAL))
            {
                widgets::mods::Status(mod);
                ImGui::Spacing();

                const auto currentVersion = sdk::Game::GetGameVersion();
                if (!info->gameVersions.empty())
                {
                    if (ImGui::TreeNode("Поддерживаемые версии игры:"))
                    {
                        for (auto gameVersion : info->gameVersions)
                        {
                            ImGui::Text(sdk::Game::SerializeGameVersion(gameVersion).c_str());
                            if (currentVersion == gameVersion)
                            {
                                ImGui::SameLine();
                                widgets::HelpMarker("Текущая версия", ICON_MD_DONE);
                            }
                        }
                        ImGui::TreePop();
                    }

                    ImGui::Spacing();
                }

                if (ImGui::BeginPopupContextItem("Mod menu"))
                {
                    widgets::mods::ContextMenu(mod);
                    ImGui::EndPopup();
                }

                if (widgets::ToggleButton(
                    "Toggle",
                    mod->IsEnabled(),
                    static_cast<float>(duration_cast<milliseconds>(mod->GetTimeSinceUpdate()).count()) / 1000.f
                ))
                {
                    modloader::ModManager::ToggleMod(mod, !mod->IsEnabled());
                }

                ImGui::SameLine();
                if (ImGui::Button(ICON_MD_MORE_HORIZ))
                {
                    ImGui::OpenPopup("Mod menu");
                }

                if (mod->HasFlag(modloader::Mod::Flag::REMOVAL_SCHEDULED))
                {
                    styles::warning::BeginPanel("Removal scheduled warning");

                    styles::warning::Icon();
                    ImGui::SameLine(0, 0);
                    ImGui::TextWrapped(" Мод будет удалён после выключения");
                    ImGui::Spacing();

                    if (ImGui::Button(ICON_MD_REPLAY " Отменить"))
                    {
                        modloader::ModManager::ScheduleModRemoval(mod, false);
                    }

                    styles::warning::EndPanel();
                }
                ImGui::Spacing();
            }

            if (widgets::mods::Description(info))
                ImGui::Spacing();

            ImGui::Separator();
            ImGui::Spacing();

            if (!mod->GetInfo()->deps.empty())
            {
                ImGui::Text("Зависимости:");
                ImGui::Spacing();

                for (const auto& dependency : mod->GetInfo()->deps)
                {
                    widgets::mods::Reference(dependency);
                    ImGui::Spacing();
                }

                ImGui::Separator();
                ImGui::Spacing();
            }

            const auto dependents = modloader::ModManager::GetModDependents(mod->GetID());
            if (!dependents.empty())
            {
                ImGui::Text("Зависимые моды:");
                ImGui::Spacing();

                for (const auto& dependant : dependents)
                {
                    widgets::mods::Reference(dependant->GetID());
                    ImGui::Spacing();
                }

                ImGui::Separator();
                ImGui::Spacing();
            }

            mod->GetImpl()->RenderUI();
        }
        else
        {
            ImGui::PushStyleVar(ImGuiStyleVar_SelectableTextAlign, ImVec2(0.5f, 0.5f));
            ImGui::Selectable("Выберите мод из\nсписка слева", false, ImGuiSelectableFlags_Disabled,
                              ImGui::GetContentRegionAvail());
            ImGui::PopStyleVar();
        }

        ImGui::ErrorCheckEndWindowRecover(Ui::ImGuiErrorHandler, (void*)"при отрисовке информации о моде");
    }
    ImGui::EndChild();
}
