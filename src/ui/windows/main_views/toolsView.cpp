#include "views.h"

#include <IconsMaterialDesign.h>
#include <imgui.h>
#include <sdk/Game.h>
#include <ui/Ui.h>
#include <ui/popups/popups.h>
#include <ui/styles/styles.h>
#include <ui/widgets/widgets.h>

void SetWindowSize(const int w, const int h)
{
    SetWindowPos(
        *sdk::Game::window,
        nullptr,
        0, 0,
        GetSystemMetrics(SM_CXBORDER) + w,
        GetSystemMetrics(SM_CYCAPTION) + GetSystemMetrics(SM_CYBORDER) + h,
        SWP_NOMOVE | SWP_NOZORDER
    );
}

void ui::windows::main::ToolsView()
{
    static int newSize[2] = {800, 600};

    ImGui::SeparatorText("Инструменты");
    if (ImGui::Button(ICON_MD_FILTER " Просмотр текстур"))
    {
        Ui::textureViewerOpen = true;
    }

    if (ImGui::Button(ICON_MD_ANIMATION " Просмотр анимаций"))
    {
        Ui::animationViewerOpen = true;
    }

    if (ImGui::Button(ICON_MD_VIEW_IN_AR " Просмотр моделей"))
    {
        Ui::modelViewerOpen = true;
    }

    if (ImGui::Button(ICON_MD_REFRESH " Перезапустить игру"))
    {
        ImGui::OpenPopup("Перезапуск игры");
    }

    popups::DisableSuperMod(true);
    styles::danger::PushStyle();
    if (ImGui::Button(ICON_MD_DISABLED_BY_DEFAULT " Выключить SuperMod"))
    {
        popups::open::DisableSuperMod();
    }
    styles::danger::PopStyle();

    ImGui::Spacing();
    ImGui::SeparatorText("Окно игры");
    const auto fullscreen = sdk::Game::IsGameFullscreen();

    ImGui::BeginDisabled(fullscreen);
    if (ImGui::Button(ICON_MD_FULLSCREEN " Вернуть окно в 800x600"))
    {
        SetWindowSize(800, 600);
    }
    ImGui::EndDisabled();

    if (fullscreen)
    {
        ImGui::SameLine();
        ui::widgets::HelpMarker("Это действие недоступно в полноэкранном режиме");
    }

    ImGui::BeginDisabled(fullscreen);
    if (ImGui::Button(ICON_MD_OPEN_IN_FULL " Установить свой размер окна"))
    {
        ImGui::OpenPopup("Изменить размер окна");
    }
    ImGui::EndDisabled();

    if (fullscreen)
    {
        ImGui::SameLine();
        ui::widgets::HelpMarker("Это действие недоступно в полноэкранном режиме");
    }

    Ui::FixNextPopupModal();
    if (ImGui::BeginPopupModal("Перезапуск игры", nullptr, ImGuiWindowFlags_AlwaysAutoResize))
    {
        ImGui::BringWindowToDisplayFront(ImGui::GetCurrentWindow());
        ImGui::BringWindowToFocusFront(ImGui::GetCurrentWindow());
        ImGui::Text("Вы уверены, что хотите перезапустить игру?");

        if (ImGui::Button("Да"))
        {
            sdk::Game::Restart();
        }
        ImGui::SetItemDefaultFocus();

        ImGui::SameLine();
        if (ImGui::Button("Отмена"))
        {
            ImGui::CloseCurrentPopup();
        }

        ImGui::EndPopup();
    }

    Ui::FixNextPopupModal();
    if (ImGui::BeginPopupModal("Изменить размер окна", nullptr, ImGuiWindowFlags_AlwaysAutoResize))
    {
        ImGui::Text("Выберите новый размер окна:");

        ImGui::InputInt2("", newSize);

        if (ImGui::Button("Применить"))
        {
            SetWindowSize(newSize[0], newSize[1]);
        }
        ImGui::SetItemDefaultFocus();

        ImGui::SameLine();
        if (ImGui::Button("Отмена"))
        {
            ImGui::CloseCurrentPopup();
        }

        ImGui::EndPopup();
    }
}
