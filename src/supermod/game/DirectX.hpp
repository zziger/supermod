#pragma once
#include <supermod/pch.hpp>

#include <d3d8/d3d8.hpp>
#include <d3d9.h>
#include <sol/table.hpp>
#include <supermod/memory/Memory.hpp>

namespace sm::game
{
class DirectX
{
public:
    static inline IDirect3DDevice8** d3dDevice = nullptr;
    static constexpr Memory::Pattern resetD3dDevicePat{"55 8B EC 83 EC ? E8 ? ? ? ? A1"};
    static constexpr Memory::Pattern deviceWasResetPat{
        "C6 05 ? ? ? ? ? 0F B6 0D ? ? ? ? 85 C9 75 ? 83 3D"}; // mov deviceWasReset, 1

    static void Init();
    static void RequestDeviceReset();
    static void EnsureDeviceReady();

    static void RemoveTexture(IDirect3DTexture8* texture);

    static IDirect3DDevice8* GetD3D8();
    static IDirect3DDevice9* GetD3D9();

    static void AddToLua(sol::table table, sol::state& lua);

private:
    static inline std::vector<IDirect3DTexture8*> removedTextures;
    static void ReleaseRemovedTextures();
};
} // namespace sm::game