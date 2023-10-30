#pragma once
#include "DirectX.h"
#include "game/AssetPool.h"

namespace sdk
{
	class Graphics
	{
	public:
		static void SetRenderAsset(game::Asset* asset)
		{
			(*sdk::DirectX::d3dDevice)->SetTexture(0, !asset || !asset->texture
				? game::AssetPool::Instance()->GetSharedUnknownAsset()->texture
				: asset->texture);
		}

		static void SetTextColor(rgba color)
		{
			static constexpr Memory::Pattern pat("55 8B EC 8A 45");
			static auto fn = pat.Search().Get<rgba (__cdecl *)(uint8_t, uint8_t, uint8_t, uint8_t)>();
			fn(color.r, color.g, color.b, color.a);
		}

		static void Render(vector2 coords, vector2 size, rect uv = { 0, 0, 1, 1 }, rgba color = { 255, 255, 255, 255 })
		{
			static constexpr Memory::Pattern pat("55 8B EC 81 EC ? ? ? ? D9 45 ? D8 0D");
			static auto fn = pat.Search().Get<void (__stdcall *)(float, float, float, float, rect*, rgba, float)>();
			fn(coords.x, coords.y, size.x, size.y, &uv, color, 0);
		}

		static void RenderText(vector2 coords, float size, std::string text)
		{
			static constexpr Memory::Pattern pat("55 8B EC 68 ? ? ? ? 8D 45");
			static auto fn = pat.Search().Get<int (__cdecl *)(float, float, float, const wchar_t*)>();
			fn(coords.x, coords.y, size, utils::str_to_wstr(text).c_str());
		}

		static void AddToLua(LuaContext& context)
		{
			context.writeModuleVariable("graphics", LuaContext::Table{});
			context.writeModuleVariable("graphics", "setRenderAsset", SetRenderAsset);
			context.writeModuleVariable("graphics", "setTextColor", SetTextColor	);
			context.writeModuleVariable("graphics", "renderText", RenderText);
			context.writeModuleVariable("graphics", "render", std::function([](vector2 coords, vector2 size, tl::optional<rect> uv, tl::optional<rgba> color) {
				Render(coords, size, uv ? *uv : rect { 0, 0, 1, 1 }, color ? *color : rgba { 255, 255, 255, 255 });
			}));
		}
	};
}