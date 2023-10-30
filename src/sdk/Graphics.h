#pragma once
#include "DirectX.h"
#include "game/AssetPool.h"

namespace sdk
{
	class Graphics
	{
	public:
		static void SetRenderAsset(game::Asset* asset);

		static void SetTextColor(rgba color);

		static void Render(vector2 coords, vector2 size, rect uv = { 0, 0, 1, 1 }, rgba color = { 255, 255, 255, 255 });

		static void RenderText(vector2 coords, float size, std::string text);

		static void AddToLua(LuaContext& context);
	};
}