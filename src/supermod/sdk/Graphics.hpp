#pragma once
#include <supermod/pch.hpp>

#include <sol/table.hpp>
#include <supermod/data.hpp>
#include <supermod/game/AssetPool.hpp>
#include <supermod/modloader/mod/impl/lua/lua.hpp>
#include <supermod/sdk/DirectX.hpp>

namespace sm::sdk
{
class Graphics
{
public:
    static void SetRenderAsset(game::Asset* asset);

    static void SetTextColor(rgba color);

    static void Render(vector2 coords, vector2 size, rect uv = {0, 0, 1, 1}, rgba color = {255, 255, 255, 255});

    static void RenderText(vector2 coords, float size, std::string text);

    static void SetRenderProjection(vector2 size, float nearZ, float farZ);

    static void ResetRenderProjection();
    static void SetRenderTransform(vector3 pos);
    static void ResetRenderTransform();

    static void AddToLua(sol::table table)
    {
        table["setRenderAsset"] = &SetRenderAsset;
        table["setTextColor"] = &SetTextColor;
        table["setRenderProjection"] = &SetRenderProjection;
        table["resetRenderProjection"] = &ResetRenderProjection;
        table["setRenderTransform"] = &SetRenderTransform;
        table["resetRenderTransform"] = &ResetRenderTransform;
        table["renderText"] = &RenderText;
        table["render"] = sol::overload_conv<void(vector2, vector2, rect, rgba), void(vector2, vector2, rect),
                                             void(vector2, vector2)>([](auto... args) { Graphics::Render(args...); });
    }
};
} // namespace sm::sdk