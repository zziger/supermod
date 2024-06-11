#include <supermod/pch.hpp>
#include <supermod/ui/windows/main_views/views.hpp>

#include <imgui_internal.h>
#include <supermod/game/Game.hpp>
#include <supermod/modloader/ModManager.hpp>
#include <supermod/modloader/mod/Mod.hpp>
#include <supermod/registry/RegistryManager.hpp>
#include <supermod/ui/Ui.hpp>
#include <supermod/ui/popups/popups.hpp>
#include <supermod/ui/styles/styles.hpp>
#include <supermod/ui/widgets/widgets.hpp>

using namespace std::chrono;

void sm::ui::windows::main::RegistryView()
{
    static std::optional<std::string> activeMod;
    static int activeVersion = 0;

    auto& mods = registry::RegistryManager::GetEntries();

    const auto width = ImGui::GetContentRegionAvail().x / 2;
    ImGui::BeginChild("Left block", ImVec2(width, 0));
    {
        const auto listHeight = ImGui::GetContentRegionAvail().y - ImGui::GetFrameHeightWithSpacing();
        ImGui::BeginChild("Mods", ImVec2(width, listHeight), true);
        {
            for (const auto& loadedMod : mods)
            {
                if (widgets::mods::SelectableRegistry(loadedMod.second.latestVersion, loadedMod.first == activeMod) &&
                    loadedMod.second.versions.size() > 0)
                {
                    activeVersion = 0;
                    activeMod = loadedMod.first;
                }
                ImGui::Spacing();
            }
        }
        ImGui::EndChild();

        auto user = registry::RegistryManager::GetUser();
        auto accountButtonText = user ? user->name : "Аккаунт";

        if (ImGui::Button((ICON_MD_ACCOUNT_CIRCLE " " + accountButtonText).c_str()))
        {
            ImGui::OpenPopup("account");
        }

        ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(10, 10) * Ui::GetScalingFactor());
        if (ImGui::BeginPopup("account"))
        {
            if (user)
            {
                ImGui::Text("Вы авторизованы как: %s", user->name.c_str());
                ImGui::Spacing();
                if (ImGui::Button("Выйти"))
                {
                    registry::RegistryManager::Logout();
                }
            }
            else if (registry::RegistryManager::IsAuthorizing())
            {
                ImGui::Text("Авторизация...");
                ImGui::Spacing();
                if (ImGui::Button("Отмена"))
                {
                    registry::RegistryManager::CancelAuth();
                }
            }
            else
            {
                ImGui::Text("Вы не авторизованы");
                ImGui::Spacing();
                if (ImGui::Button("Войти через Discord"))
                {
                    registry::RegistryManager::AuthorizeWithDiscord();
                }
            }
            ImGui::EndPopup();
        }
        ImGui::PopStyleVar();
    }
    ImGui::EndChild();

    ImGui::SameLine();
    ImGui::BeginChild("Mod content", ImVec2(0, 0));
    {
        if (activeMod && mods.contains(*activeMod))
        {
            const auto& mod = mods.find(*activeMod)->second;
            const auto info = mod.latestVersion;
            const auto version = mod.versions[activeVersion];

            widgets::mods::InfoBlock(info);
            ImGui::Spacing();
            ImGui::Spacing();

            ImGui::Text("Загрузил:");
            ImGui::SameLine();
            widgets::registry::Uploader(mod.uploader);
            ImGui::Spacing();

            ImGui::SetNextItemWidth(300);
            auto versionPreview = version.version.str();
            if (!version.verified)
            {
                versionPreview += " " ICON_MD_SAFETY_CHECK;
            }

            if (ImGui::BeginCombo("##Version", versionPreview.c_str()))
            {
                for (int n = 0; n < mod.versions.size(); n++)
                {
                    const bool is_selected = activeVersion == n;
                    auto text = mod.versions[n].version.str();
                    if (!mod.versions[n].verified)
                        text += " " ICON_MD_SAFETY_CHECK;
                    if (ImGui::Selectable(text.c_str(), is_selected))
                        activeVersion = n;

                    // Set the initial focus when opening the combo (scrolling + keyboard navigation focus)
                    if (is_selected)
                        ImGui::SetItemDefaultFocus();
                }
                ImGui::EndCombo();
            }

            ImGui::SameLine();
            ImGui::Button("Установить");

            if (!version.verified)
            {
                ImGui::Spacing();
                styles::warning::PanelText(ICON_MD_SAFETY_CHECK " Выбранная версия находится на ручной проверке.\n\nДо "
                                                                "окончания проверки версия скрыта из общего списка.");
            }

            ImGui::Separator();

            widgets::mods::Description(info);
            // if (!mod->HasFlag(modloader::Mod::Flag::INTERNAL))
            // {
            //     widgets::mods::Status(mod);
            //     ImGui::Spacing();
            //
            //     const auto currentVersion = game::Game::GetGameVersion();
            //     if (!info->gameVersions.empty())
            //     {
            //         if (ImGui::TreeNode("Поддерживаемые версии игры:"))
            //         {
            //             for (auto gameVersion : info->gameVersions)
            //             {
            //                 ImGui::Text(game::Game::SerializeGameVersion(gameVersion).c_str());
            //                 if (currentVersion == gameVersion)
            //                 {
            //                     ImGui::SameLine();
            //                     widgets::HelpMarker("Текущая версия", ICON_MD_DONE);
            //                 }
            //             }
            //             ImGui::TreePop();
            //         }
            //
            //         ImGui::Spacing();
            //     }
            //
            //     if (ImGui::BeginPopupContextItem("Mod menu"))
            //     {
            //         widgets::mods::ContextMenu(mod);
            //         ImGui::EndPopup();
            //     }
            //
            //     if (widgets::ToggleButton(
            //             "Toggle", mod->IsEnabled(),
            //             static_cast<float>(duration_cast<milliseconds>(mod->GetTimeSinceUpdate()).count()) / 1000.f))
            //     {
            //         modloader::ModManager::ToggleMod(mod, !mod->IsEnabled());
            //     }
            //
            //     ImGui::SameLine();
            //     if (ImGui::Button(ICON_MD_MORE_HORIZ))
            //     {
            //         ImGui::OpenPopup("Mod menu");
            //     }
            //
            //     if (mod->HasFlag(modloader::Mod::Flag::REMOVAL_SCHEDULED))
            //     {
            //         ImGui::Spacing();
            //         styles::warning::BeginPanel("Removal scheduled warning");
            //
            //         styles::warning::Icon();
            //         ImGui::SameLine(0, 0);
            //         ImGui::TextWrapped(" Мод будет удалён после выключения");
            //         ImGui::Spacing();
            //
            //         if (ImGui::Button(ICON_MD_REPLAY " Отменить"))
            //         {
            //             modloader::ModManager::ScheduleModRemoval(mod, false);
            //         }
            //
            //         styles::warning::EndPanel();
            //     }
            //
            //     if (const auto& error = mod->GetLoadingError(); !error.empty())
            //     {
            //         ImGui::Spacing();
            //         styles::danger::BeginPanel("Loading error");
            //
            //         ImGui::TextWrapped("Ошибка загрузки:");
            //         ImGui::TextWrapped(error.c_str());
            //         ImGui::Spacing();
            //
            //         if (ImGui::Button(ICON_MD_REFRESH " Перезагрузить"))
            //         {
            //             mod->Toggle(true);
            //         }
            //
            //         styles::danger::EndPanel();
            //     }
            //     ImGui::Spacing();
            // }
            //
            // if (widgets::mods::Description(info))
            //     ImGui::Spacing();
            //
            // ImGui::Separator();
            // ImGui::Spacing();
            //
            // if (!mod->GetInfo()->dependencies.empty())
            // {
            //     ImGui::Text("Зависимости:");
            //     ImGui::Spacing();
            //     ImGui::PushID("Dependencies");
            //
            //     for (const auto& dependency : mod->GetInfo()->dependencies)
            //     {
            //         widgets::mods::Reference(dependency.id, dependency);
            //         ImGui::Spacing();
            //     }
            //
            //     ImGui::PopID();
            //     ImGui::Separator();
            //     ImGui::Spacing();
            // }
            //
            // const auto dependents = modloader::ModManager::GetModDependents(mod->GetID());
            // if (!dependents.empty())
            // {
            //     ImGui::Text("Зависимые моды:");
            //     ImGui::Spacing();
            //     ImGui::PushID("Dependents");
            //
            //     for (const auto& dependant : dependents)
            //     {
            //         widgets::mods::Reference(dependant->GetID());
            //         ImGui::Spacing();
            //     }
            //
            //     ImGui::PopID();
            //     ImGui::Separator();
            //     ImGui::Spacing();
            // }
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
    // if (registry::RegistryManager::IsAuthorizing())
    // {
    //     ImGui::Text("Authorizing...");
    //
    //     if (ImGui::Button("Cancel"))
    //     {
    //         registry::RegistryManager::CancelAuth();
    //     }
    // }
    // else
    // {
    //     auto user = registry::RegistryManager::GetUser();
    //     if (user)
    //     {
    //         if (ImGui::Button("Logout"))
    //         {
    //             registry::RegistryManager::Logout();
    //         }
    //
    //         ImGui::Text("User: %s", user->name.c_str());
    //         ImGui::Text("Role: %d", user->role);
    //     }
    //     else
    //     {
    //         if (ImGui::Button("Authorize"))
    //         {
    //             registry::RegistryManager::AuthorizeWithDiscord();
    //         }
    //
    //         ImGui::Text("Not authorized");
    //     }
    // }
    //
    // auto mods = registry::RegistryManager::GetEntries();
    // for (auto& mod : mods)
    // {
    //     ImGui::Text("Mod: %s", mod.id.c_str());
    //     ImGui::Separator();
    // }
}
