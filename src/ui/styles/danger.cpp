#include "styles.h"

#include <Utils.h>
#include <imgui.h>
#include <ui/Ui.h>

void ui::styles::danger::PushStyle()
{
    ImGui::PushStyleColor(ImGuiCol_Button, 0x993D3DFF_color);
    ImGui::PushStyleColor(ImGuiCol_ButtonHovered, 0xB33636FF_color);
    ImGui::PushStyleColor(ImGuiCol_ButtonActive, 0xCC2929FF_color);
}

void ui::styles::danger::PopStyle()
{
    ImGui::PopStyleColor(3);
}

void ui::styles::danger::BeginPanel(const char* id)
{
    ImGui::PushStyleColor(ImGuiCol_ChildBg, 0x993D3D52_color);
    ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, {Ui::ScaledPx(15), Ui::ScaledPx(10)});
    ImGui::BeginChild(id, ImVec2(-FLT_MIN, 0), ImGuiChildFlags_Border | ImGuiChildFlags_AutoResizeY);
    ImGui::PushTextWrapPos(ImGui::GetWindowSize().x);
    PushStyle();
}

void ui::styles::danger::EndPanel()
{
    PopStyle();
    ImGui::PopTextWrapPos();
    ImGui::EndChild();
    ImGui::PopStyleColor();
    ImGui::PopStyleVar();

    const auto childRectMin = ImGui::GetItemRectMin();
    const auto childRectMax = ImGui::GetItemRectMax();
    ImGui::GetWindowDrawList()->AddRectFilled(childRectMin, {childRectMin.x + Ui::ScaledPx(3), childRectMax.y},
                                              0x993D3DEE, Ui::ScaledPx(3));
}

void ui::styles::danger::PanelText(const char* text)
{
    BeginPanel(text);
    ImGui::Text(text);
    EndPanel();
}