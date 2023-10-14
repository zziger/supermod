

#include "Config.h"
#include "ImGuiWidgets.h"
#include "UI.h"
#include "modloader/mods/ModInfo.h"
#include "modloader/mods/ModManager.h"
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

    void renderModInstall(ModInfo info) {
        auto title = std::format("Установка мода {}", info.id).c_str();
        ImGui::OpenPopup(title);
        ImVec2 center = ImGui::GetMainViewport()->GetCenter();
        ImGui::SetNextWindowPos(center, ImGuiCond_Appearing, ImVec2(0.5f, 0.5f));
        if (ImGui::BeginPopupModal(title, nullptr, ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoSavedSettings | ImGuiWindowFlags_AlwaysAutoResize))
        {
            
            if (info.icon) {
                ImGui::Image(info.icon->texture, { 50, 50 });
                ImGui::SameLine();
            }
        
            ImGui::BeginGroup();
            ImGui::Text("%s", info.title.c_str());
            ImGui::Text("Версия: %s", info.version != "" ? info.version.c_str() : "Не указана");
            ImGui::EndGroup();
            
            ImGui::Text("Автор: %s", info.author != "" ? info.author.c_str() : "Не указан");
            ImGui::Text("ID: %s", info.id.c_str());

            ImGui::PushStyleColor(ImGuiCol_Text, 0xdeab4eFF_color);
            auto hasDll = exists(info.basePath / "main.dll");
            if (info.luaScript != "" || hasDll) ImGui::Text(ICON_MD_WARNING " В моде присутствует Lua скрипт.");
            if (hasDll) ImGui::Text(ICON_MD_WARNING " В моде присутствует DLL файл.");
            if (info.luaScript != "" || hasDll) ImGui::Text("Это позволяет моду выполнять код на вашем компьтере.\nУстанавливайте только если доверяете автору.");
            ImGui::PopStyleColor();
            
            if (ModManager::installError) {
                ImGui::PushStyleColor(ImGuiCol_Text, 0xEE7777FF_color);
                ImGui::Text((ICON_MD_ERROR " " + *ModManager::installError).c_str());
                ImGui::PopStyleColor();
            }
            
            ImGui::Spacing();

            ui::widgets::styles::PushButtonDanger();
            if (ImGui::Button("Установить")) ModManager::InstallMod(info, true);
            ui::widgets::styles::PopButtonDanger();
            
            ImGui::SameLine();
            if (ImGui::Button("Не устанавливать")) ModManager::InstallMod(info, false);

            if (!sdk::Game::booted) {
                ImGui::SameLine();
                if (ImGui::Button("Выход")) exit(0);
            }
    
            ImGui::EndPopup();
        }
    }
    
    void UI::RenderBoot() {

        auto mods = ModManager::GetModsToInstall();
        if (!mods.empty()) renderModInstall(mods.front());
        
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
        
        // ImGui::SetNextWindowPos(viewport->WorkPos);
        // ImGui::SetNextWindowSize(viewport->WorkSize);
        // if (ImGui::Begin("Cover", nullptr, ImGuiWindowFlags_NoDecoration | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoSavedSettings))
        // {
        //     if (ImGui::Button("Выход")) exit(0);
        // }
        // ImGui::End();
        //
        // ImGui::SetNextWindowPos(ImVec2(viewport->WorkPos.x + viewport->WorkSize.x / 2, viewport->WorkPos.y + viewport->WorkSize.y / 2), ImGuiCond_Always, { 0.5f, 0.5f });
        // ImGui::SetNextWindowSize(ImVec2(viewport->WorkSize.x / 2, viewport->WorkSize.y / 2));
        // if (ImGui::Begin("Shit sus amogus bruh", nullptr, ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoSavedSettings))
        // {
        //     if (ImGui::Button("Выход")) exit(0);
        // }
        // ImGui::End();
    }
}