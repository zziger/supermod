#include "ModIcon.h"

namespace modloader
{
    void ModIcon::Draw(ImDrawList* drawList, const ImVec2& from, const ImVec2& to, const ImU32 color) const
    {
        if (!asset) return;
        drawList->AddImage(asset->asset->texture, from, to, { uv.left, uv.top }, { uv.right, uv.bottom }, color);
    }

    void ModIcon::Draw(const ImVec2& imageSize) const
    {
        if (!asset) return;
        ImGui::Image(asset->asset->texture, imageSize, { uv.left, uv.top }, { uv.right, uv.bottom });
    }
}
