#include "DirectX.h"

#include "events/EventManager.h"
#include "events/TickEvent.h"
#include "exceptions/Error.h"
#include <d3d8/d3d8to9.hpp>

namespace sdk
{
    void DirectX::Init() {
        constexpr Memory::Pattern pushD3dDevicePointer("68 ? ? ? ? 68 ? ? ? ? 6A ? 8B 4D 08");
        d3dDevice = *pushD3dDevicePointer.Search().Get<IDirect3DDevice8***>(1);

        EventManager::On<AfterTickEvent>([] {
            ReleaseRemovedTextures();
        });
    }

    static inline bool deviceResetRequested = false;
    void DirectX::RequestDeviceReset() {
        if (deviceResetRequested) return;
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
    
    void DirectX::RemoveTexture(IDirect3DTexture8* texture) {
        if (!texture) return;
        if (std::ranges::find(removedTextures, texture) != removedTextures.end()) return;
        removedTextures.push_back(texture);
    }

    IDirect3DDevice9* DirectX::GetDx9()
    {
        assert(*d3dDevice && "Bruh");
        auto d3d8 = dynamic_cast<Direct3DDevice8*>(*d3dDevice);
        assert(d3d8 && "Bruh 2");
        return d3d8->GetProxyInterface();
    }

    void DirectX::ReleaseRemovedTextures() {
        if (removedTextures.empty()) return;
        const auto scheduledTextures = removedTextures;
        removedTextures = {};
        for (const auto texture : scheduledTextures) {
            texture->Release();
        }
    }
}
