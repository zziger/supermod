#pragma once
#include <string>

#include "memory/Memory.h"
#include "thirdparty/directx/d3d8.h"

namespace game
{
    struct AssetMeta
    {
        bool notFound = false;
        std::filesystem::path origDir = "";
        std::string origName = "";
        vector2 canvasSizeMultiplier = { 1, 1 };
        bool loadedManually = false;

        static void RegisterType(LuaContext* ctx);
    };
    
    struct Asset {
        char name[124]; // originally name has length of 128, i take 4 bytes for custom meta ptr
        AssetMeta* meta;
        uint32_t width;
        uint32_t height;
        IDirect3DTexture8* texture;
        byte hasAlpha;
        byte isPoolDefault;
        D3DFORMAT format;

        void ReplaceTexture(IDirect3DTexture8* tex);

        static void RegisterType(LuaContext* ctx);
    };
    
    class AssetPool {
    public:
        virtual ~AssetPool() = default;
        AssetPool() = delete;
        
        Asset* assets[1024];
        int assetCount;

        static LPDIRECT3DTEXTURE8 LoadTexture(const std::filesystem::path & path, vector2ui & size, bool & alpha, vector2 canvasSizeMultiplier = { 1, 1 });
        static LPDIRECT3DTEXTURE8 TryLoadTexture(const std::filesystem::path & dir, const std::string & key, bool alpha, vector2ui & size, vector2 canvasSizeMultiplier);
        LPDIRECT3DTEXTURE8 TryLoadTextureFromMods(const std::filesystem::path & dir, const std::string & name, bool alpha, vector2ui & size, std::string & modName, vector2 canvasSizeMultiplier);

        Asset* LoadGameAsset(const std::filesystem::path & path, bool loadFallback = true, vector2 canvasSizeMultiplier = { 1, 1 });
        Asset* LoadGameAssetFromData(const std::filesystem::path & path, bool loadFallback, vector2 canvasSizeMultiplier);
        void ReloadGameAsset(const std::string & filename);
        Asset* LoadAsset(LPDIRECT3DTEXTURE8 tex, std::string key, bool alpha, vector2ui size);
        Asset* LoadAsset(const std::filesystem::path & path, std::string key, bool loadFallback = true, vector2 canvasSizeMultiplier = { 1, 1 });
        Asset* LoadUnknownAsset(const std::string & key);
        Asset* GetSharedUnknownAsset();
        
        Asset* AllocateAsset(const std::string& key);
        void FreeAsset(Asset * asset);

        [[nodiscard]] Asset* GetByName(const std::string& name) const;

        static AssetPool* Instance();

        static std::string TrimFileName(std::string name, bool& alpha);
        static std::string CreateAssetKey(const std::string& name, bool& alpha);
        static std::string CreateAssetKey(const std::string& name);
        static void AddToLua(LuaContext& ctx);
    };
}