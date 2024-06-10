#include <supermod/pch.hpp>
#include <supermod/ui/widgets/widgets.hpp>

#include <imgui.h>

void sm::ui::widgets::Tooltip(const char* text, ImGuiHoveredFlags flags)
{
    constexpr auto anyDelay =
        ImGuiHoveredFlags_DelayNone | ImGuiHoveredFlags_DelayShort | ImGuiHoveredFlags_DelayNormal;
    if (flags & anyDelay == 0)
        flags |= ImGuiHoveredFlags_DelayShort;
    if (ImGui::IsItemHovered(flags))
    {
        ImGui::BeginTooltip();
        ImGui::PushTextWrapPos(ImGui::GetFontSize() * 35.0f);
        ImGui::TextUnformatted(text);
        ImGui::PopTextWrapPos();
        ImGui::EndTooltip();
    }
}