#include "windows.h"

#include <modloader/ModManager.h>
#include <modloader/install/ModInstaller.h>
#include <sdk/Game.h>
#include <ui/Ui.h>
#include <ui/styles/styles.h>
#include <ui/widgets/widgets.h>

void ui::windows::Installer()
{
    const auto requests = modloader::ModInstaller::GetInstallRequests();
    if (requests.empty()) return;

    const auto currentIter = std::ranges::find_if(
        requests,
        [](const std::shared_ptr<modloader::ModInstallRequest>& req) { return !req->IsFinished(); }
    );

    if (currentIter == std::end(requests))
    {
        modloader::ModInstaller::ClearInstallRequests();
        return;
    }

    const auto& current = *currentIter;
    const auto index = std::distance(std::begin(requests), currentIter);

    const auto info = current->GetModInfo();
    const auto mod = modloader::ModManager::FindModByID(info->GetID());
    const auto canInstall = !mod || !mod->IsActive();

    ImGui::OpenPopup("###Installer");
    Ui::FixNextPopupModal();
    ImGui::SetNextWindowSize(ImVec2{700, 500}, ImGuiCond_Appearing);
    if (ImGui::BeginPopupModal(
        std::format("{} мода {} из {}###Installer", mod ? "Обновление" : "Установка", index + 1,
                    requests.size()).c_str(),
        nullptr,
        ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoMove |
        ImGuiWindowFlags_NoSavedSettings | ImGuiWindowFlags_AlwaysAutoResize
    ))
    {
        widgets::mods::InfoBlock(info);
        ImGui::Spacing();

        if (mod)
        {
            widgets::mods::Status(mod);
            ImGui::Spacing();
        }

        if (widgets::mods::Description(info))
            ImGui::Spacing();

        // TODO: dependencies

        const auto progress = current->GetProgress();
        if (progress.show)
        {
            const auto progressValue = progress.progress < 0
                                           ? static_cast<float>(ImGui::GetTime()) * -0.2f
                                           : progress.progress;
            widgets::ProgressBar(progressValue, {-FLT_MIN, 0}, progress.message ? progress.message->c_str() : nullptr);
        }

        const auto error = current->GetError();
        if (!error.empty())
        {
            styles::danger::PanelText(error.c_str());
            ImGui::Spacing();
        }

        if (!canInstall)
        {
            styles::warning::PanelText("Для обновления мод должен быть выключен");
            ImGui::Spacing();
        }

        ImGui::BeginDisabled(!canInstall);
        styles::danger::PushStyle();
        if (ImGui::Button(current->GetInstallActionLabel().c_str()))
            current->Install();
        styles::danger::PopStyle();
        ImGui::EndDisabled();

        ImGui::SameLine();
        if (ImGui::Button(current->GetCancelActionLabel().c_str()))
            current->Cancel();

        if (!canInstall)
        {
            ImGui::SameLine();
            ImGui::BeginDisabled(!mod->IsEnabled());
            if (ImGui::Button("Выключить мод"))
                modloader::ModManager::ToggleMod(mod, false);
            ImGui::EndDisabled();
        }

        if (!sdk::Game::booted)
        {
            ImGui::SameLine();
            if (ImGui::Button("Выход")) exit(0);
        }

        ImGui::EndPopup();
    }
}
