#include <Config.h>
#include <imgui.h>
#include <ui/Ui.h>

#include "windows.h"

void ui::windows::Watermark()
{
    const auto& cfg = Config::Get().watermark;
    if (!cfg.show)
        return;

    const ImGuiViewport* viewport = ImGui::GetMainViewport();
    const ImVec2 workPos = viewport->WorkPos;
    const ImVec2 workSize = viewport->WorkSize;
    constexpr float margin = 10.0f;
    float x = 0.0f, xPivot = 0.0f, y = 0.0f, yPivot = 0.0f;

    switch (cfg.position)
    {
    case Config::WatermarkPosition::TOP_LEFT:
    case Config::WatermarkPosition::TOP_CENTER:
    case Config::WatermarkPosition::TOP_RIGHT:
        y = margin;
        yPivot = 0;
        break;
    case Config::WatermarkPosition::BOTTOM_LEFT:
    case Config::WatermarkPosition::BOTTOM_CENTER:
    case Config::WatermarkPosition::BOTTOM_RIGHT:
        y = workSize.y - margin;
        yPivot = 1.f;
    }

    switch (cfg.position)
    {
    case Config::WatermarkPosition::TOP_LEFT:
    case Config::WatermarkPosition::BOTTOM_LEFT:
        x = margin;
        xPivot = 0;
        break;
    case Config::WatermarkPosition::TOP_CENTER:
    case Config::WatermarkPosition::BOTTOM_CENTER:
        x = workSize.x * 0.5f;
        xPivot = 0.5f;
        break;
    case Config::WatermarkPosition::TOP_RIGHT:
    case Config::WatermarkPosition::BOTTOM_RIGHT:
        x = workSize.x - margin;
        xPivot = 1.f;
    }

    ImGui::SetNextWindowPos({workPos.x + x, workPos.y + y}, ImGuiCond_Always, {xPivot, yPivot});
    ImGui::SetNextWindowBgAlpha(cfg.bgOpacity * cfg.opacity);
    ImGui::PushStyleVar(ImGuiStyleVar_Alpha, cfg.opacity);
    if (ImGui::Begin("watermark", nullptr,
                     ImGuiWindowFlags_NoDecoration | ImGuiWindowFlags_AlwaysAutoResize |
                         ImGuiWindowFlags_NoSavedSettings | ImGuiWindowFlags_NoFocusOnAppearing |
                         ImGuiWindowFlags_NoNav | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoDocking))
    {
        ImGui::TextColored(0xFFCC00FF_color, "SuperMod");
    }
    ImGui::End();
    ImGui::PopStyleVar();
}
