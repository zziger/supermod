#include <d3dx9shader.h>
#include <supermod/game/DirectX.hpp>
#include <supermod/pch.hpp>

#include <d3d8/d3d8to9.hpp>
#include <supermod/events/EventManager.hpp>
#include <supermod/events/TickEvent.hpp>
#include <supermod/exceptions/Error.hpp>

namespace sm::game
{
void DirectX::Init()
{
    constexpr Memory::Pattern pushD3dDevicePointer("68 ? ? ? ? 68 ? ? ? ? 6A ? 8B 4D 08");
    d3dDevice = *pushD3dDevicePointer.Search().Get<IDirect3DDevice8***>(1);

    EventManager::On<AfterTickEvent>([] { ReleaseRemovedTextures(); });
}

static inline bool deviceResetRequested = false;
void DirectX::RequestDeviceReset()
{
    if (deviceResetRequested)
        return;
    deviceResetRequested = true;
    static auto reset = resetD3dDevicePat.Search();
    static auto wasReset = deviceWasResetPat.Search();
    EventManager::Once<EarlyTickEvent>([] {
        reset.Call();
        **wasReset.Get<byte**>(2) = 1;
        deviceResetRequested = false;
    });
}

void DirectX::EnsureDeviceReady()
{
    if (!d3dDevice || !*d3dDevice)
        throw Error("Устройство DirectX ещё не готово к работе");
}

void DirectX::RemoveTexture(IDirect3DTexture8* texture)
{
    if (!texture)
        return;
    if (std::ranges::find(removedTextures, texture) != removedTextures.end())
        return;
    removedTextures.push_back(texture);
}

IDirect3DDevice8* DirectX::GetD3D8()
{
    assert(*d3dDevice && "D3D is not initialized yet");
    return dynamic_cast<Direct3DDevice8*>(*d3dDevice);
}

IDirect3DDevice9* DirectX::GetD3D9()
{
    assert(*d3dDevice && "D3D is not initialized yet");
    auto d3d8 = dynamic_cast<Direct3DDevice8*>(*d3dDevice);
    assert(d3d8 && "Failed to get proxied D3D9 instance");
    return d3d8->GetProxyInterface();
}

void DirectX::AddToLua(sol::table table, sol::state& lua)
{
    table["getD3D9"] = [&lua] {
        if (!*d3dDevice)
            throw std::runtime_error("DirectX is not initialized yet");
        const sol::function castFn = get_packages(lua)["ffi"]["cast"];
        return castFn("IDirect3DDevice9*", reinterpret_cast<intptr_t>(GetD3D9()));
    };
    table["getD3D8"] = [&lua] {
        if (!*d3dDevice)
            throw std::runtime_error("DirectX is not initialized yet");
        const sol::function castFn = get_packages(lua)["ffi"]["cast"];
        return castFn("IDirect3DDevice8*", reinterpret_cast<intptr_t>(GetD3D8()));
    };

    {
        const sol::function castFn = get_packages(lua)["ffi"]["cast"];
        auto d3dx9 = table.create_named("d3dx9");

#define D3DX_EXPOSE(fn) d3dx9[#fn] = castFn(#fn, reinterpret_cast<uintptr_t>(reinterpret_cast<void*>(fn)))
        D3DX_EXPOSE(D3DXCompileShaderFromFileA);
        D3DX_EXPOSE(D3DXCompileShaderFromFileW);
        D3DX_EXPOSE(D3DXCreateEffectFromFileA);
        D3DX_EXPOSE(D3DXCreateEffectFromFileW);
    }
}

void DirectX::ReleaseRemovedTextures()
{
    if (removedTextures.empty())
        return;
    const auto scheduledTextures = removedTextures;
    removedTextures = {};
    for (const auto texture : scheduledTextures)
    {
        texture->Release();
    }
}
} // namespace sm::game
