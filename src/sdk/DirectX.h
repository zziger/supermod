#pragma once

#include <d3d9.h>
#include <d3d8/d3d8.hpp>
#include "memory/Memory.h"

namespace sdk
{
    class DirectX {
    public:
        static inline IDirect3DDevice8** d3dDevice = nullptr;
        static constexpr Memory::Pattern resetD3dDevicePat{ "55 8B EC 83 EC ? E8 ? ? ? ? A1" };
        static constexpr Memory::Pattern deviceWasResetPat{ "C6 05 ? ? ? ? ? 0F B6 0D ? ? ? ? 85 C9 75 ? 83 3D" }; // mov deviceWasReset, 1

        static void Init();
        static void RequestDeviceReset();
        static void EnsureDeviceReady();

        static void RemoveTexture(IDirect3DTexture8* texture);

        static IDirect3DDevice9* GetDx9();
        
    private:
        static inline std::vector<IDirect3DTexture8*> removedTextures;
        static void ReleaseRemovedTextures();
    };
}