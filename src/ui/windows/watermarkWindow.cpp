#include <Config.h>
#include <imgui.h>
#include <ui/Ui.h>

#include "windows.h"

void ui::windows::Watermark()
{
    auto cfg = Config::Get()["watermark"];
    const auto show = cfg["show"].as<bool>(true);

    if (!show) return;

    const auto position = static_cast<WatermarkPosition>(cfg["position"].as<int>(TOP_CENTER));
    const auto opacity = cfg["opacity"].as<float>(1.0f);
    const auto bgOpacity = cfg["bgOpacity"].as<float>(0.35f);

    const ImGuiViewport* viewport = ImGui::GetMainViewport();
    const ImVec2 workPos = viewport->WorkPos;
    const ImVec2 workSize = viewport->WorkSize;
    constexpr float margin = 10.0f;
    float x = 0.0f, xPivot = 0.0f, y = 0.0f, yPivot = 0.0f;

    switch(position) {
        case TOP_LEFT:
        case TOP_CENTER:
        case TOP_RIGHT:
            y = margin;
            yPivot = 0;
            break;
        case BOTTOM_LEFT:
        case BOTTOM_CENTER:
        case BOTTOM_RIGHT:
            y = workSize.y - margin;
            yPivot = 1.f;
    }

    switch(position) {
        case TOP_LEFT:
        case BOTTOM_LEFT:
            x = margin;
            xPivot = 0;
            break;
        case TOP_CENTER:
        case BOTTOM_CENTER:
            x = workSize.x * 0.5f;
            xPivot = 0.5f;
            break;
        case TOP_RIGHT:
        case BOTTOM_RIGHT:
            x = workSize.x - margin;
            xPivot = 1.f;
    }

    ImGui::SetNextWindowPos({ workPos.x + x, workPos.y + y }, ImGuiCond_Always, { xPivot, yPivot });
    ImGui::SetNextWindowBgAlpha(bgOpacity * opacity);
    ImGui::PushStyleVar(ImGuiStyleVar_Alpha, opacity);
    if (ImGui::Begin("watermark", nullptr, ImGuiWindowFlags_NoDecoration | ImGuiWindowFlags_AlwaysAutoResize
                     | ImGuiWindowFlags_NoSavedSettings | ImGuiWindowFlags_NoFocusOnAppearing | ImGuiWindowFlags_NoNav | ImGuiWindowFlags_NoMove)) {
        ImGui::TextColored(0xFFCC00FF_color, "SuperMod");
    }
    ImGui::End();
    ImGui::PopStyleVar();
}
