#include "widgets.h"

#include <imgui.h>

void ui::widgets::Tooltip(const char* text, const ImGuiHoveredFlags flags)
{
    if (ImGui::IsItemHovered(ImGuiHoveredFlags_DelayShort | flags))
    {
        ImGui::BeginTooltip();
        ImGui::PushTextWrapPos(ImGui::GetFontSize() * 35.0f);
        ImGui::TextUnformatted(text);
        ImGui::PopTextWrapPos();
        ImGui::EndTooltip();
    }
}