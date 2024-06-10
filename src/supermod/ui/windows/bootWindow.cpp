#include <supermod/pch.hpp>
#include <supermod/ui/windows/windows.hpp>

#include <supermod/Utils.hpp>
#include <supermod/game/Game.hpp>
#include <supermod/ui/popups/popups.hpp>
#include <supermod/ui/styles/styles.hpp>

void sm::ui::windows::Boot()
{
    if (!game::Game::bootMenuActive)
        return;

    const ImGuiViewport* viewport = ImGui::GetMainViewport();
    const ImVec2 workPos = viewport->WorkPos;
    const ImVec2 workSize = viewport->WorkSize;

    ImGui::SetNextWindowPos({workPos.x + workSize.x - 10, workPos.y + workSize.y - 10}, ImGuiCond_Always, {1, 1});
    if (ImGui::Begin("Startup options", nullptr,
                     ImGuiWindowFlags_NoDecoration | ImGuiWindowFlags_AlwaysAutoResize |
                         ImGuiWindowFlags_NoSavedSettings | ImGuiWindowFlags_NoFocusOnAppearing |
                         ImGuiWindowFlags_NoNav | ImGuiWindowFlags_NoMove))
    {
        ImGui::TextColored(0xFFCC00FF_color, "Опции запуска:");
        ImGui::Spacing();

        if (ImGui::Button("Выход"))
            exit(0);

        ImGui::SameLine();
        if (ImGui::Button("Игра"))
            game::Game::bootMenuActive = false;

        ImGui::SameLine();
        if (ImGui::Button("Редактор"))
        {
            game::Game::StartEditor();
            game::Game::bootMenuActive = false;
        }

        ImGui::Spacing();
        ImGui::Spacing();

        popups::DisableSuperMod(false);

        styles::danger::PushStyle();
        if (ImGui::Button("Выключить SuperMod"))
            popups::open::DisableSuperMod();
        styles::danger::PopStyle();
    }
    ImGui::End();
}