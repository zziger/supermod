#include <supermod/pch.hpp>
#include <supermod/ui/styles/styles.hpp>

#include <imgui.h>
#include <supermod/Utils.hpp>
#include <supermod/ui/Ui.hpp>

void ui::styles::warning::PushStyle()
{
    ImGui::PushStyleColor(ImGuiCol_Button, 0xA96D03FF_color);
    ImGui::PushStyleColor(ImGuiCol_ButtonHovered, 0xCC8200FF_color);
    ImGui::PushStyleColor(ImGuiCol_ButtonActive, 0xB97601FF_color);
}

void ui::styles::warning::PopStyle()
{
    ImGui::PopStyleColor(3);
}

void ui::styles::warning::BeginPanel(const char* id)
{
    ImGui::PushStyleColor(ImGuiCol_ChildBg, 0xEF9B0552_color);
    ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, {Ui::ScaledPx(15), Ui::ScaledPx(10)});
    ImGui::BeginChild(id, ImVec2(-FLT_MIN, 0), ImGuiChildFlags_Border | ImGuiChildFlags_AutoResizeY);
    ImGui::PushTextWrapPos(ImGui::GetWindowSize().x);
    PushStyle();
}

void ui::styles::warning::EndPanel()
{
    PopStyle();
    ImGui::PopTextWrapPos();
    ImGui::EndChild();
    ImGui::PopStyleColor();
    ImGui::PopStyleVar();

    const auto childRectMin = ImGui::GetItemRectMin();
    const auto childRectMax = ImGui::GetItemRectMax();
    ImGui::GetWindowDrawList()->AddRectFilled(childRectMin, {childRectMin.x + Ui::ScaledPx(3), childRectMax.y},
                                              0xFF48CEEE, Ui::ScaledPx(3));
}

void ui::styles::warning::PanelText(const char* text)
{
    BeginPanel(text);
    ImGui::Text(text);
    EndPanel();
}

void ui::styles::warning::Icon(const char* text)
{
    ImGui::PushStyleColor(ImGuiCol_Text, 0xEECE48FF_color);
    ImGui::Text(text);
    ImGui::PopStyleColor();
}
