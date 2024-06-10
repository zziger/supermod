#pragma once
#include <supermod/pch.hpp>

#include <imgui.h>
#include <supermod/data.hpp>
#include <supermod/game/AssetPool.hpp>

namespace sm::modloader
{
struct ModIcon
{
    std::shared_ptr<game::OwnedAsset> asset;
    rect uv = {0, 0, 1, 1};

    void Draw(ImDrawList* drawList, const ImVec2& from, const ImVec2& to, ImU32 color = IM_COL32_WHITE) const;
    void Draw(const ImVec2& imageSize) const;
};
} // namespace sm::modloader
