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
	
	void Graphics::SetRenderProjection(vector2 size, float nearZ, float farZ)
	{
		static constexpr Memory::Pattern pat("E8 ? ? ? ? 83 C4 ? 0F B6 05 ? ? ? ? 85 C0 74 ? E8 ? ? ? ? 6A");
		static auto fn = pat.Search().GoToNearCall().Get<int (__cdecl *)(float, float, float, float)>();
		fn(size.x, size.y, nearZ, farZ);
	}

	void Graphics::ResetRenderProjection()
	{
		SetRenderProjection({ 800, 600 }, 1.f, 500.f);
	}
	
	void Graphics::SetRenderTransform(vector3 pos)
	{
		static constexpr Memory::Pattern matrixPat("B9 ? ? ? ? E8 ? ? ? ? 68 ? ? ? ? 6A ? 6A ? B9 ? ? ? ? E8 ? ? ? ? B9 ? ? ? ? E8 ? ? ? ? 50 E8 ? ? ? ? 83 C4 ? B9 ? ? ? ? E8 ? ? ? ? 68");
		static auto matrix = *matrixPat.Search().Add(1).Get<matrix4x4**>();
		*matrix = {
			{ 1, 0, 0, 0 },
			{ 0, 1, 0, 0 },
			{ 0, 0, 1, 0 },
			{ pos.x, pos.y, pos.z, 1 },
		};
		
		static constexpr Memory::Pattern pat("E8 ? ? ? ? 83 C4 ? 68 ? ? ? ? 68 ? ? ? ? 68 ? ? ? ? 68 ? ? ? ? E8 ? ? ? ? 83 C4 ? E8 ? ? ? ? 6A");
		static auto fn = pat.Search().GoToNearCall().Get<int (__cdecl *)(matrix4x4*)>();
		fn(matrix);
	}

	void Graphics::ResetRenderTransform()
	{
		SetRenderTransform({ 0, 0, 0 });
	}

	void Graphics::AddToLua(LuaContext & context) {
		context.writeModuleVariable("graphics", LuaContext::Table{});
		context.writeModuleVariable("graphics", "setRenderAsset", std::function([](std::variant<game::Asset*, std::nullptr_t> asset) {
			std::visit([&](auto&& visited) {
				SetRenderAsset(visited);
			}, asset);
		}));
		context.writeModuleVariable("graphics", "setTextColor", SetTextColor);
		context.writeModuleVariable("graphics", "setRenderProjection", SetRenderProjection);
		context.writeModuleVariable("graphics", "resetRenderProjection", ResetRenderProjection);
		context.writeModuleVariable("graphics", "setRenderTransform", SetRenderTransform);
		context.writeModuleVariable("graphics", "resetRenderTransform", ResetRenderTransform);
		context.writeModuleVariable("graphics", "renderText", RenderText);
		context.writeModuleVariable("graphics", "render", std::function([](vector2 coords, vector2 size, tl::optional<rect> uv, tl::optional<rgba> color) {
			Render(coords, size, uv ? *uv : rect { 0, 0, 1, 1 }, color ? *color : rgba { 255, 255, 255, 255 });
		}));
	}
}
