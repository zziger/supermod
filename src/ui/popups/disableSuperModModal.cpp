#include <Config.h>
#include <imgui.h>
#include <sdk/Game.h>
#include <ui/Ui.h>
#include <ui/styles/styles.h>

#include "popups.h"

void ui::popups::DisableSuperMod(const bool restart)
{
    Ui::FixNextPopupModal();
    if (ImGui::BeginPopupModal("Выключение SuperMod###Disable SuperMod", nullptr, ImGuiWindowFlags_AlwaysAutoResize))
    {
        ImGui::Text("Вы уверены, что хотите выключить SuperMod?");
        ImGui::Text("Удерживайте Shift при запуске игры, чтоб включить SuperMod обратно.");
        if (restart) ImGui::Text("Это действие перезапустит игру.");

        ImGui::Spacing();
        styles::danger::PushStyle();
        if (ImGui::Button("Да, я внимательно прочитал(-а) и запомнил(-а)")) {
            ImGui::CloseCurrentPopup();
            auto& cfg = Config::Get();
            cfg.disabled = true;
            cfg.Save();
            sdk::Game::Restart();
        }
        styles::danger::PopStyle();
        ImGui::SetItemDefaultFocus();

        ImGui::SameLine();
        if (ImGui::Button("Отмена")) {
            ImGui::CloseCurrentPopup();
        }

        ImGui::EndPopup();
    }
}

void ui::popups::open::DisableSuperMod()
{
     ImGui::OpenPopup("###Disable SuperMod");
}

