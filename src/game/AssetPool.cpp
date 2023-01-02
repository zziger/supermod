#include "AssetPool.h"

namespace game
{
    void Asset::Anonymize() const {
        const_cast<char*>(name)[0] = '\0';
    }

    void Asset::ReplaceTexture(IDirect3DTexture8* tex) {
        texture->Release();
        texture = tex;
    }

    Asset* AssetPool::GetByName(const std::string& name) const {
        for (auto i = 0; i < assetCount; i++) {
            if (assets[i]->name == name) return assets[i];
        }
            
        return nullptr;
    }

    AssetPool* AssetPool::GetInstance() {
        static constexpr Memory::Pattern pat("B9 ? ? ? ? E8 ? ? ? ? 68 ? ? ? ? A1 ? ? ? ? 8B 08"); //  mov ecx, offset AssetPool__instance
        static auto mem = pat.Search();
        return *mem.Get<AssetPool**>(1);
    }
}