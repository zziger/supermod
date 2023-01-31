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

        if (ImGui::Button(ICON_MD_FILTER " Просмотр текстур")) {
            _textureViewerOpen = true;
        }
        
        if (ImGui::Button(ICON_MD_REFRESH " Перезапустить игру")) {
            ImGui::OpenPopup("Перезапуск игры");
        }

        RenderDisableModPopup(true);
        widgets::styles::PushButtonDanger();
        if (ImGui::Button(ICON_MD_DISABLED_BY_DEFAULT " Выключить SuperMod")) {
            ImGui::OpenPopup("Выключение SuperMod");
        }
        widgets::styles::PopButtonDanger();
    
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
    }

}