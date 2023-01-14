#include <imgui/imgui.h>
#include <imgui/imgui_internal.h>
#include <windows.h>
#include <shellapi.h>

#include "Config.h"
#include "Console.h"
#include "DirectXUtils.h"
#include "thirdparty/IconsFontAwesome5Brands.h"
#include "thirdparty/IconsMaterialDesign.h"
#include "UI.h"
#include "modloader/mods/ModManager.h"
#include "ImGuiWidgets.h"
#include "game/AssetPool.h"
#include "sdk/Game.h"

using namespace ui;

std::string tabNames[] = { "Моды", "Настройки", "Инструменты" };

static int currentTab = 0;


void Tab(const char* icon, int index) {
    if (widgets::MenuTabSelectable(tabNames[index].c_str(), icon, currentTab == index)) currentTab = index;
}

void Link(const char* title, const char* icon, const char* url) {
    if (widgets::MenuTabSelectable(title, icon, false)) {
        ShellExecuteA(nullptr, "open", url, nullptr, nullptr , SW_SHOWNORMAL);
    }
}


void UI::RenderMenu() {
    RenderWindows();
    
    if (!menuOpen) return;
    
    const auto mods = ModManager::GetMods();

    constexpr auto lowerElements = 2;
    constexpr auto upperElements = 3;

    const auto style = ImGui::GetStyle();
    const auto spacing = style.ItemSpacing;
    constexpr auto elements = lowerElements + upperElements;
    const auto fontSize = fonts->fontDefault2X->FontSize;
    const auto elementSize = fontSize + spacing.y * 2;
    const auto menuSize = elementSize * (elements + 0.5f);
    const auto headerSize = ImGui::GetFontSize();
    
    ImGui::ShowDemoWindow();
    ImGui::SetNextWindowSize(ImVec2(700, 300), ImGuiCond_Once);
    ImGui::SetNextWindowSizeConstraints(ImVec2(500, menuSize + headerSize), ImVec2(FLT_MAX, FLT_MAX));
    if (ImGui::Begin(std::format("SuperMod / {}###MainWindow", tabNames[currentTab]).c_str())) {
        ImGui::BeginChild("menu", ImVec2(fontSize, 0));
        
        ImGui::BeginChild("upper", ImVec2(fontSize, (-fontSize - spacing.y * 2) * 2));
        ImGui::PushFont(UI::fonts->fontDefault2X);
        Tab(ICON_MD_FORMAT_LIST_BULLETED, 0);
        Tab(ICON_MD_SETTINGS, 1);
        Tab(ICON_MD_BUILD, 2);
        ImGui::PopFont();
        ImGui::EndChild();
        
        ImGui::PushFont(UI::fonts->fontFab2X);
        Link("Discord сервер", ICON_FA_DISCORD, "https://discord.gg/UcSzFC9tCB");
        Link("GitHub репозиторий", ICON_FA_GITHUB, "https://github.com/zziger/supercow-mod");
        ImGui::PopFont();
        
        ImGui::EndChild();

        ImGui::SameLine();
        ImGui::BeginChild("content", ImVec2(0, 0));

        switch (currentTab) {
            case 0: UI::RenderModsTab(); break;
            case 1: UI::RenderSettingsTab(); break;
            case 2: UI::RenderToolsTab(); break;
        }
        
        ImGui::EndChild();
    }
    ImGui::End();
}