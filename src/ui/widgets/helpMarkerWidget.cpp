#include "widgets.h"

#include <imgui.h>

void ui::widgets::HelpMarker(const char* desc, const char* icon) {
    ImGui::TextDisabled(icon);
    Tooltip(desc);
}
