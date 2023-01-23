

#include "Config.h"
#include "ImGuiWidgets.h"
#include "UI.h"
#include "sdk/Game.h"

namespace ui
{
    void UI::RenderDisableModPopup(bool restart) {
        
        if (ImGui::BeginPopupModal("Выключение SuperMod", nullptr, ImGuiWindowFlags_AlwaysAutoResize))
        {
            ImGui::Text("Вы уверены, что хотите выключить SuperMod?");
            ImGui::Text("Удерживайте Shift при запуске игры, чтоб включить SuperMod обратно.");
            if (restart) ImGui::Text("Это действие перезапустит игру.");

            ImGui::Spacing();
            widgets::styles::PushButtonDanger();
            if (ImGui::Button("Да, я внимательно прочитал(-а) и запомнил(-а)")) {
                ImGui::CloseCurrentPopup();
                Config::Get()["disabled"] = true;
                Config::Save();
                sdk::Game::Restart();
            }
            widgets::styles::PopButtonDanger();
            ImGui::SetItemDefaultFocus();
    
            ImGui::SameLine();
            if (ImGui::Button("Отмена")) {
                ImGui::CloseCurrentPopup();
            }
    
            ImGui::EndPopup();
        }
    }
    void UI::RenderBoot() {
        if (!sdk::Game::bootMenuActive) return;
        const ImGuiViewport* viewport = ImGui::GetMainViewport();
        const ImVec2 workPos = viewport->WorkPos;
        const ImVec2 workSize = viewport->WorkSize;
        ImGui::SetNextWindowPos({ workPos.x + workSize.x - 10, workPos.y + workSize.y - 10 }, ImGuiCond_Always, { 1, 1 });
        if (ImGui::Begin("startupOptions", nullptr, ImGuiWindowFlags_NoDecoration | ImGuiWindowFlags_AlwaysAutoResize | ImGuiWindowFlags_NoSavedSettings | ImGuiWindowFlags_NoFocusOnAppearing | ImGuiWindowFlags_NoNav | ImGuiWindowFlags_NoMove)) {
            ImGui::TextColored(0xFFCC00FF_color, "Опции запуска:");
            ImGui::Spacing();
            if (ImGui::Button("Выход")) exit(0);
            ImGui::SameLine();
            if (ImGui::Button("Игра")) sdk::Game::bootMenuActive = false;
            ImGui::SameLine();
            if (ImGui::Button("Редактор")) {
                sdk::Game::StartEditor();
                sdk::Game::bootMenuActive = false;
            }

            
            ImGui::Spacing();
            ImGui::Spacing();

            RenderDisableModPopup();

            ui::widgets::styles::PushButtonDanger();
            if (ImGui::Button("Выключить SuperMod")) {
                ImGui::OpenPopup("Выключение SuperMod");
            };
            ui::widgets::styles::PopButtonDanger();
        }
        ImGui::End();
    }
}