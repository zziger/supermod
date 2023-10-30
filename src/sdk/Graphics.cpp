#include "Graphics.h"

namespace sdk
{
	void Graphics::SetRenderAsset(game::Asset * asset) {
		static constexpr Memory::Pattern pat("55 8B EC 83 7D ? ? 74 ? 8B 45 ? 8B 88");
		static auto fn = pat.Search().Get<int (__cdecl *)(game::Asset*)>();
		fn(asset);
	}
	
	void Graphics::SetTextColor(rgba color) {
		static constexpr Memory::Pattern pat("55 8B EC 8A 45");
		static auto fn = pat.Search().Get<rgba (__cdecl *)(uint8_t, uint8_t, uint8_t, uint8_t)>();
		fn(color.r, color.g, color.b, color.a);
	}
	
	void Graphics::Render(vector2 coords, vector2 size, rect uv, rgba color) {
		static constexpr Memory::Pattern pat("55 8B EC 81 EC ? ? ? ? D9 45 ? D8 0D");
		static auto fn = pat.Search().Get<void (__stdcall *)(float, float, float, float, rect*, rgba, float)>();
		fn(coords.x, coords.y, size.x, size.y, &uv, color, 0);
	}
	
	void Graphics::RenderText(vector2 coords, float size, std::string text) {
		static constexpr Memory::Pattern pat("55 8B EC 68 ? ? ? ? 8D 45");
		static auto fn = pat.Search().Get<int (__cdecl *)(float, float, float, const wchar_t*)>();
		fn(coords.x, coords.y, size, utils::str_to_wstr(text).c_str());
	}
	
	void Graphics::AddToLua(LuaContext & context) {
		context.writeModuleVariable("graphics", LuaContext::Table{});
		context.writeModuleVariable("graphics", "setRenderAsset", std::function([](std::variant<game::Asset*, std::nullptr_t> asset) {
			std::visit([&](auto&& visited) {
				SetRenderAsset(visited);
			}, asset);
		}));
		context.writeModuleVariable("graphics", "setTextColor", SetTextColor	);
		context.writeModuleVariable("graphics", "renderText", RenderText);
		context.writeModuleVariable("graphics", "render", std::function([](vector2 coords, vector2 size, tl::optional<rect> uv, tl::optional<rgba> color) {
			Render(coords, size, uv ? *uv : rect { 0, 0, 1, 1 }, color ? *color : rgba { 255, 255, 255, 255 });
		}));
	}
}
