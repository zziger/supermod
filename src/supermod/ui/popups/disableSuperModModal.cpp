#include <supermod/pch.hpp>
#include <supermod/ui/popups/popups.hpp>

#include <imgui.h>
#include <supermod/Config.hpp>
#include <supermod/game/Game.hpp>
#include <supermod/ui/Ui.hpp>
#include <supermod/ui/styles/styles.hpp>

void sm::ui::popups::DisableSuperMod(const bool restart)
{
    Ui::FixNextPopupModal();
    if (ImGui::BeginPopupModal("Выключение SuperMod###Disable SuperMod", nullptr, ImGuiWindowFlags_AlwaysAutoResize))
    {
        ImGui::Text("Вы уверены, что хотите выключить SuperMod?");
        ImGui::Text("Удерживайте Shift при запуске игры, чтоб включить SuperMod обратно.");
        if (restart)
            ImGui::Text("Это действие перезапустит игру.");

        ImGui::Spacing();
        styles::danger::PushStyle();
        if (ImGui::Button("Да, я внимательно прочитал(-а) и запомнил(-а)"))
        {
            ImGui::CloseCurrentPopup();
            auto& cfg = Config::Get();
            cfg.disabled = true;
            cfg.Save();
            game::Game::Restart();
        }
        styles::danger::PopStyle();
        ImGui::SetItemDefaultFocus();

        ImGui::SameLine();
        if (ImGui::Button("Отмена"))
        {
            ImGui::CloseCurrentPopup();
        }

        ImGui::EndPopup();
    }
}

void sm::ui::popups::open::DisableSuperMod()
{
    ImGui::OpenPopup("###Disable SuperMod");
}
