#include "Config.h"
#include "Console.h"
#include "modloader/mods/Mod.h"
#include "modloader/mods/ModManager.h"
#include "sdk/Game.h"
#include "ui/ImGuiWidgets.h"
#include "ui/UI.h"

namespace ui
{
    void SetWindowSize(int w, int h)
    {
        SetWindowPos(*sdk::Game::window, nullptr, 0, 0, GetSystemMetrics(SM_CXBORDER) + w,
            GetSystemMetrics(SM_CYCAPTION) + GetSystemMetrics(SM_CYBORDER) + h, SWP_NOMOVE | SWP_NOZORDER);
    }
    
    void UI::RenderToolsTab() {
        static int newSize[2] = { 800, 600 };

        ImGui::Text("Инструменты");
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

        ImGui::Spacing();
        ImGui::Text("Размер окна");
        auto fullscreen = sdk::Game::IsGameFullscreen();
        
        ImGui::BeginDisabled(fullscreen);
        if (ImGui::Button(ICON_MD_FULLSCREEN " Вернуть окно в 800x600")) {
            SetWindowSize(800, 600);
        }
        ImGui::EndDisabled();
        
        if (fullscreen) {
            ImGui::SameLine();
            ui::widgets::HelpMarker("Это действие недоступно в полноэкранном режиме");
        }
        
        ImGui::BeginDisabled(fullscreen);
        if (ImGui::Button(ICON_MD_OPEN_IN_FULL " Установить свой размер окна")) {
            ImGui::OpenPopup("Изменить размер окна");
        }
        ImGui::EndDisabled();
        
        if (fullscreen) {
            ImGui::SameLine();
            ui::widgets::HelpMarker("Это действие недоступно в полноэкранном режиме");
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
        
        ImGui::SetNextWindowPos(center, ImGuiCond_Appearing, ImVec2(0.5f, 0.5f));
        if (ImGui::BeginPopupModal("Изменить размер окна", nullptr, ImGuiWindowFlags_AlwaysAutoResize))
        {
            ImGui::Text("Выберите новый размер окна:");

            ImGui::InputInt2("", newSize);
    
            if (ImGui::Button("Применить")) {
                SetWindowSize(newSize[0], newSize[1]);
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