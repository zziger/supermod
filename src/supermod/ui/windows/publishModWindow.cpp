#include <supermod/pch.hpp>
#include <supermod/ui/windows/windows.hpp>

#include <imgui.h>
#include <supermod/Config.hpp>
#include <supermod/Utils.hpp>
#include <supermod/modloader/ModManager.hpp>
#include <supermod/modloader/ModPublisher.hpp>
#include <supermod/ui/Ui.hpp>
#include <supermod/ui/styles/styles.hpp>
#include <supermod/ui/widgets/widgets.hpp>

void sm::ui::windows::PublishMod()
{
    auto mod = modloader::ModManager::FindModByID(WindowsState::publishModID);
    if (!mod)
    {
        WindowsState::publishModOpened = false;
        return;
    }

    if (ImGui::Begin("Опубликовать мод", &WindowsState::publishModOpened,
                     ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_AlwaysAutoResize))
    {
        auto info = mod->GetInfo();
        widgets::mods::InfoBlock(*info);
        ImGui::Spacing();

        ImGui::Dummy(ImVec2(0, 10));
        ImGui::Text("Требования для публикации выбранного мода:");
        ImGui::Spacing();

        auto check = [](bool value) {
            if (value)
                ImGui::TextColored(0x77EE77FF_color, ICON_MD_CHECK_CIRCLE);
            else
                ImGui::TextColored(0xEE7777FF_color, ICON_MD_CANCEL);
            ImGui::SameLine();
        };

        auto user = registry::RegistryManager::GetUser();
        check(user.has_value());
        ImGui::Text("Войти в аккаунт");
        ImGui::Spacing();

        ImGui::BeginChild("auth", ImVec2(0, 0),
                          ImGuiChildFlags_Border | ImGuiChildFlags_AlwaysAutoResize | ImGuiChildFlags_AutoResizeY);
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
            if (ImGui::Button("Войти через Discord"))
            {
                registry::RegistryManager::AuthorizeWithDiscord();
            }
        }
        ImGui::EndChild();

        ImGui::Spacing();

        auto& entries = registry::RegistryManager::GetEntries();
        const auto exists = entries.contains(info->GetID());
        const auto owning = exists ? registry::RegistryManager::CanManageMod(entries.at(info->GetID())) : true;
        check(owning);
        ImGui::Text("Быть владельцем мода или публиковать новый мод");
        if (!owning)
        {
            ImGui::Spacing();
            styles::warning::PanelText(
                std::format("Мод был загружен пользователем {}", entries[info->GetID()].uploader.name).c_str());
        }
        else if (!exists)
        {
            ImGui::Indent();
            ImGui::Text("Новый мод");
            ImGui::Unindent();
        }

        const auto versionExists = entries[info->GetID()].HasVersion(info->version.str());
        if (versionExists)
        {
            ImGui::Dummy(ImVec2(0, 10));
            styles::danger::PanelText(
                "Эта версия мода уже существует. Перед загрузкой новой версии нужно удалить с серверов старую.");
        }

        if (modloader::ModPublisher::publishing)
        {
            ImGui::Dummy(ImVec2(0, 10));
            widgets::ProgressBar(modloader::ModPublisher::publishProgress);
        }

        ImGui::Dummy(ImVec2(0, 10));
        ImGui::BeginDisabled(!user.has_value() || !owning || versionExists || modloader::ModPublisher::publishing);
        if (ImGui::Button("Опубликовать"))
        {
            modloader::ModPublisher::Publish(mod);
        }
        ImGui::EndDisabled();

        ImGui::SameLine();
        ImGui::BeginDisabled(modloader::ModPublisher::publishing);
        if (ImGui::Button("Отмена"))
        {
            WindowsState::publishModOpened = false;
        }
        ImGui::EndDisabled();
    }
    ImGui::End();
}
