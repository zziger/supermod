#include <supermod/pch.hpp>
#include <supermod/ui/widgets/widgets.hpp>

#include <imgui.h>

void sm::ui::widgets::HelpMarker(const char* desc, const char* icon)
{
    ImGui::TextDisabled(icon);
    Tooltip(desc);
}
