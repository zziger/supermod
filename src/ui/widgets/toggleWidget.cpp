#include "widgets.h"

#include <imgui.h>
#include <imgui_internal.h>

bool ui::widgets::ToggleButton(const char* strId, const bool value, const float time, const ImVec2 size)
{
    static constexpr ImVec4 SLIDER_ACTIVE_COLOR = { 0.56f, 0.83f, 0.26f, 1.0f };
    static constexpr ImVec4 SLIDER_ACTIVE_HOVERED_COLOR = { 0.64f, 0.83f, 0.34f, 1.0f };
    static constexpr ImVec4 SLIDER_COLOR = { 0.85f, 0.85f, 0.85f, 1.0f };
    static constexpr ImVec4 SLIDER_HOVERED_COLOR = { 0.78f, 0.78f, 0.78f, 1.0f };

    const auto pos = ImGui::GetCursorScreenPos();
    const auto drawList = ImGui::GetWindowDrawList();
    const auto context = ImGui::GetCurrentContext();

    const float height = size.y == -1 ? ImGui::GetFrameHeight() : size.y;
    const float width = size.x == -1 ? height * 1.65f : size.x;
    const float radius = height * 0.5f;
    const float rounding = height * 0.005f;
    const float trackWidth = width - radius * 2.0f;
    bool result = false;

    ImGui::InvisibleButton(strId, ImVec2(width, height));
    if (ImGui::IsItemClicked())
        result = true;

    float t = value ? 1.0f : 0.0f;
    if (time > -1 || context->LastActiveId == context->CurrentWindow->GetID(strId))
    {
        const float tAnim = ImSaturate((time > -1 ? time : context->LastActiveIdTimer) / 0.08f);
        t = value ? tAnim : 1.0f - tAnim;
    }

    ImU32 colBg;
    if (ImGui::IsItemHovered())
        colBg = ImGui::GetColorU32(ImLerp(SLIDER_HOVERED_COLOR, SLIDER_ACTIVE_HOVERED_COLOR, t));
    else
        colBg = ImGui::GetColorU32(ImLerp(SLIDER_COLOR, SLIDER_ACTIVE_COLOR, t));

    drawList->AddRectFilled(pos, ImVec2(pos.x + width, pos.y + height), colBg, height * rounding);
    drawList->AddRectFilled(ImVec2(pos.x + t * trackWidth, pos.y), ImVec2(pos.x + radius * 2 + t * trackWidth, pos.y + height), IM_COL32(255, 255, 255, 255), height * rounding);

    return result;
}
