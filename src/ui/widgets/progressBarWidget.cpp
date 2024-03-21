#include "widgets.h"

#include <imgui.h>
#include <imgui_internal.h>

void ui::widgets::ProgressBar(const float fraction, const ImVec2& sizeArg, const char* overlay)
{
    const auto window = ImGui::GetCurrentWindow();
    const auto& g = *GImGui;
    const auto& style = g.Style;

    const auto pos = window->DC.CursorPos;
    const auto size = ImGui::CalcItemSize(sizeArg, ImGui::CalcItemWidth(), g.FontSize + style.FramePadding.y * 2.0f);
    ImRect bb(pos, pos + size);
    ImGui::ItemSize(size, style.FramePadding.y);
    if (!ImGui::ItemAdd(bb, 0))
        return;

    float barBegin = 0.0f;
    float barEnd = ImSaturate(fraction);

    const bool indeterminate = fraction < 0.0f;
    if (indeterminate)
    {
        constexpr float barFraction = 0.2f;
        barBegin = ImFmod(-fraction, 1.0f) * (1.0f + barFraction) - barFraction;
        barEnd = barBegin + barFraction;
    }

    // Render
    ImGui::RenderFrame(bb.Min, bb.Max, ImGui::GetColorU32(ImGuiCol_FrameBg), true, style.FrameRounding);
    bb.Expand(ImVec2(-style.FrameBorderSize, -style.FrameBorderSize));
    ImGui::RenderRectFilledRangeH(window->DrawList, bb, ImGui::GetColorU32(ImGuiCol_PlotHistogram), barBegin, barEnd,
                                  style.FrameRounding);

    // Don't display text for indeterminate bars by default
    if (!indeterminate || overlay)
    {
        // Default displaying the fraction as percentage string, but user can override it
        // ReSharper disable once CppTooWideScope - variable needs to be in outer scope as it is referenced in overlay
        char overlayBuf[32];
        if (!overlay)
        {
            ImFormatString(overlayBuf, IM_ARRAYSIZE(overlayBuf), "%.0f%%", fraction * 100 + 0.01f);
            overlay = overlayBuf;
        }

        const ImVec2 overlaySize = ImGui::CalcTextSize(overlay, nullptr);
        if (overlaySize.x > 0.0f)
        {
            const auto fillBr = ImVec2(indeterminate
                                           ? (bb.Min.x + bb.Max.x - overlaySize.x) * 0.5f
                                           : ImLerp(bb.Min.x, bb.Max.x, barEnd), bb.Max.y);
            ImGui::RenderTextClipped(
                ImVec2(ImClamp(fillBr.x + style.ItemSpacing.x, bb.Min.x,
                               bb.Max.x - overlaySize.x - style.ItemInnerSpacing.x), bb.Min.y), bb.Max, overlay,
                nullptr, &overlaySize, ImVec2(0.0f, 0.5f), &bb);
        }
    }
}
