#include "DirectX.h"

#include "events/EventManager.h"
#include "events/TickEvent.h"
#include "exceptions/Error.h"

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
    void DirectX::ResetDevice() {
        if (deviceResetRequested) return;
        deviceResetRequested = true;
        static auto reset = resetD3dDevicePat.Search();
        static auto wasReset = deviceWasResetPat.Search();
        EventManager::Once<AfterTickEvent>([] {
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
    
    void DirectX::ReleaseRemovedTextures() {
        if (removedTextures.empty()) return;
        const auto scheduledTextures = removedTextures;
        removedTextures = {};
        for (const auto texture : scheduledTextures) {
            texture->Release();
        }
    }
}
