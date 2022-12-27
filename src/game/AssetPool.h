#pragma once
#include <string>

#include "Asset.h"

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
            return (AssetPool*) 0x1423CF8;
        }
    };
}