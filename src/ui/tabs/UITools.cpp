#include "Config.h"
#include "Console.h"
#include "modloader/mods/Mod.h"
#include "modloader/mods/ModManager.h"
#include "sdk/Game.h"
#include "ui/ImGuiWidgets.h"
#include "ui/UI.h"

namespace ui
{
    
    void UI::RenderToolsTab() {
        if (ImGui::Button("Перезапустить игру")) {
            ImGui::OpenPopup("Перезапуск игры");
        }
    
        ImVec2 center = ImGui::GetMainViewport()->GetCenter();
        ImGui::SetNextWindowPos(center, ImGuiCond_Appearing, ImVec2(0.5f, 0.5f));
        if (ImGui::BeginPopupModal("Перезапуск игры", nullptr, ImGuiWindowFlags_AlwaysAutoResize))
        {
            ImGui::Text("Вы уверены, что хотите перезапустить игру?");
    
            if (ImGui::Button("Да")) {
                sdk::Game::Restart();
            }
            ImGui::SetItemDefaultFocus();
    
            ImGui::SameLine();
            if (ImGui::Button("Отмена")) {
                ImGui::CloseCurrentPopup();
            }
    
            ImGui::EndPopup();
        }

        if (ImGui::Button("Просмотр текстур")) {
            _textureViewerOpen = true;
        }
    }

}