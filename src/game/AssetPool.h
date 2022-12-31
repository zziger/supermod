#pragma once
#include <string>

#include "Asset.h"
#include "memory/Memory.h"

namespace game
{
    class AssetPool {
    public:
        virtual ~AssetPool() = default;
        Asset* assets[1024];
        int assetCount;

        Asset* GetByName(const std::string& name) const {
            for (auto i = 0; i < assetCount; i++) {
                if (assets[i]->name == name) return assets[i];
            }
            
            return nullptr;
        }

        static AssetPool* GetInstance() {
            static constexpr Memory::Pattern pat("B9 ? ? ? ? E8 ? ? ? ? 68 ? ? ? ? A1 ? ? ? ? 8B 08"); //  mov ecx, offset AssetPool__instance
            static auto mem = pat.Search();
            return *mem.Get<AssetPool**>(1);
        }
    };
}