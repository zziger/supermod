#include "AssetPool.h"

#include "modloader/mods/ModManager.h"
#include "modloader/mods/files/ModFileResolver.h"
#include "sdk/Game.h"
#include "textures/JpgLoader.h"
#include "textures/PngLoader.h"
#include "textures/TgaLoader.h"

namespace game
{
    void Asset::ReplaceTexture(IDirect3DTexture8* tex) {
        texture->Release();
        texture = tex;
    }

    LPDIRECT3DTEXTURE8 AssetPool::LoadTexture(const std::filesystem::path& path, vector2ui& size, bool& alpha, vector2 canvasSizeMultiplier)
    {
        sdk::DirectX::EnsureDeviceReady();
        alpha = false;
        auto ext = path.extension().string();
        std::ranges::transform(ext, ext.begin(), tolower);

        if (ext == ".jpg" || ext == ".jpeg")
        {
            alpha = path.filename().string().starts_with("_a_");
            return JpgLoader::LoadJpga(path, size, canvasSizeMultiplier, alpha);
        }

        if (ext == ".tga")
        {
            alpha = true;
            return TgaLoader::LoadTga(path, size, canvasSizeMultiplier);
        }

        if (ext == ".png")
        {
            alpha = true;
            return PngLoader::LoadPng(path, size, canvasSizeMultiplier);
        }

        Log::Error << "Unknown texture extension " << ext << Log::Endl;
        return nullptr;
    }

    LPDIRECT3DTEXTURE8 AssetPool::TryLoadTexture(const std::filesystem::path& dir, const std::string& key, bool alpha, vector2ui& size, vector2 canvasSizeMultiplier)
    {
        sdk::DirectX::EnsureDeviceReady();
        if (dir.empty()) return nullptr;
        
        if (alpha)
        {
            if (const auto tex = JpgLoader::LoadJpga(dir / ("_a_" + key + ".jpg"), size, canvasSizeMultiplier, true)) return tex;
            if (const auto tex = JpgLoader::LoadJpga(dir / ("_a_" + key + ".jpeg"), size, canvasSizeMultiplier, true)) return tex;
            if (const auto tex = TgaLoader::LoadTga(dir / (key + ".tga"), size, canvasSizeMultiplier)) return tex;
            if (const auto tex = PngLoader::LoadPng(dir / (key + ".png"), size, canvasSizeMultiplier)) return tex;
        }

        if (const auto tex = JpgLoader::LoadJpga(dir / (key + ".jpg"), size, canvasSizeMultiplier, false)) return tex;
        if (const auto tex = JpgLoader::LoadJpga(dir / (key + ".jpeg"), size, canvasSizeMultiplier, false)) return tex;

        return nullptr;
    }

    LPDIRECT3DTEXTURE8 AssetPool::TryLoadTextureFromMods(const std::filesystem::path& dir, const std::string& name, bool alpha, vector2ui& size, std::string& modName, vector2 canvasSizeMultiplier)
    {
        sdk::DirectX::EnsureDeviceReady();
        modName = "";
        IDirect3DTexture8* tex = nullptr;
        
        auto mods = ModManager::GetMods();
        for (auto el = mods.rbegin(); el != mods.rend(); ++el)
        {
            if (!(*el)->IsEnabled()) continue;
            tex = TryLoadTexture(ModFileResolver::GetModFilePath(*el, dir), name, alpha, size, canvasSizeMultiplier);
            
            if (tex)
            {
                modName = (*el)->info.id;
                break;
            }
        }
        
        if (!tex) tex = TryLoadTexture(dir, name, alpha, size, canvasSizeMultiplier);
        
        return tex;
    }

    Asset* AssetPool::LoadGameAsset(const std::filesystem::path& path, bool loadFallback, vector2 canvasSizeMultiplier)
    {
        sdk::DirectX::EnsureDeviceReady();
        bool alpha;
        const auto key = CreateAssetKey(path.filename().string(), alpha);
        const auto previousAsset = GetByName(key);
        if (previousAsset && !(previousAsset->meta && previousAsset->meta->notFound)) return previousAsset;

        const auto name = TrimFileName(path.filename().string(), alpha);
        const auto dir = std::filesystem::current_path() / path.parent_path();

        vector2ui size { 256, 256 };
        std::string modName;
        IDirect3DTexture8* tex = TryLoadTextureFromMods(dir, name, alpha, size, modName, canvasSizeMultiplier);
        bool found = true;
        
        if (!tex && !loadFallback) return nullptr;
        
        if (!tex) 
        {
            Log::Error << "Game texture " << path << " not found" << Log::Endl;
            
            found = false;
            size = { 256, 256 };
            tex = TextureLoader::LoadUnknown(*sdk::DirectX::d3dDevice, size, canvasSizeMultiplier);
        }
        
        const auto asset = previousAsset ? previousAsset : AllocateAsset(key);
        if (asset->texture) asset->texture->Release();
        delete asset->meta;
        
        asset->texture = tex;
        asset->width = size.x;
        asset->height = size.y;
        asset->format = D3DFMT_A8R8G8B8;
        asset->isPoolDefault = false;
        asset->hasAlpha = alpha;
        asset->meta = new AssetMeta;
        asset->meta->notFound = !found;
        asset->meta->canvasSizeMultiplier = canvasSizeMultiplier;
        asset->meta->origDir = relative(dir, sdk::Game::GetDataPath());
        asset->meta->origName = name;

        if (found && !modName.empty())
            Log::Warn << "Loaded " << name << " from mod " << modName << Log::Endl;
        
        return asset;
    }
    
    Asset* AssetPool::LoadGameAssetFromData(const std::filesystem::path& path, bool loadFallback, vector2 canvasSizeMultiplier)
    {
        sdk::DirectX::EnsureDeviceReady();
        const auto oldCwd = std::filesystem::current_path();
        current_path(sdk::Game::GetDataPath());
        const auto asset = LoadGameAsset(path, loadFallback, canvasSizeMultiplier);
        current_path(oldCwd);
        return asset;
    }

    void AssetPool::ReloadGameAsset(const std::string& filename)
    {
        auto key = CreateAssetKey(filename);
        const auto asset = GetByName(key);
        if (!asset) return;

        if (asset->meta->loadedManually)
        {
            Log::Warn << "Перезагрузка текстуры " << filename << " невозможна, так как она была загружена вручную" << Log::Endl;
            return;
        }

        if (asset->meta->origDir.empty() || asset->meta->origName.empty())
        {
            Log::Warn << "Перезагрузка текстуры " << filename << " невозможна, так как она была загружена из неизвестного места" << Log::Endl;
            return;
        }

        vector2ui size;
        std::string modName;
        auto texture = TryLoadTextureFromMods(asset->meta->origDir, asset->meta->origName, asset->hasAlpha, size, modName, asset->meta->canvasSizeMultiplier);
        if (!texture)
        {
            size = { 256, 256 };
            texture = TextureLoader::LoadUnknown(*sdk::DirectX::d3dDevice, size, asset->meta->canvasSizeMultiplier);
            Log::Error << "Не удалось перезагрузить текстуру " << filename << " (" + key + ")" << Log::Endl;
        }

        asset->texture->Release();
        asset->texture = texture;
        asset->width = size.x;
        asset->height = size.y;

        Log::Info << "Текстура " << filename << " (" + key + ") перезагружена" << Log::Endl;
    }
    
    Asset* AssetPool::LoadAsset(LPDIRECT3DTEXTURE8 tex, std::string key, bool alpha, vector2ui size) {
        sdk::DirectX::EnsureDeviceReady();
        const auto previousAsset = GetByName(key);
        if (previousAsset && !(previousAsset->meta && previousAsset->meta->notFound))
        {
            tex->Release();
            return previousAsset;
        }
        
        const auto asset = previousAsset ? previousAsset : AllocateAsset(key);
        if (asset->texture) asset->texture->Release();
        delete asset->meta;
        
        asset->texture = tex;
        asset->width = size.x;
        asset->height = size.y;
        asset->format = D3DFMT_A8R8G8B8;
        asset->isPoolDefault = false;
        asset->hasAlpha = alpha;
        asset->meta = new AssetMeta;
        asset->meta->loadedManually = true;
        
        return asset;
    }

    Asset* AssetPool::LoadAsset(const std::filesystem::path& path, std::string key, bool loadFallback, vector2 canvasSizeMultiplier)
    {
        sdk::DirectX::EnsureDeviceReady();
        if (key.empty()) key = CreateAssetKey(path.filename().string());
        const auto previousAsset = GetByName(key);
        if (previousAsset && !(previousAsset->meta && previousAsset->meta->notFound)) return previousAsset;

        bool alpha;
        vector2ui size { 256, 256 };
        auto tex = LoadTexture(path, size, alpha, canvasSizeMultiplier);
        const auto notFound = !tex;
        if (!tex && !loadFallback) return nullptr;
        if (!tex) tex = TextureLoader::LoadUnknown(*sdk::DirectX::d3dDevice, size, canvasSizeMultiplier);

        if (notFound)
            Log::Error << "Texture " << path << " not found" << Log::Endl;
        
        const auto asset = previousAsset ? previousAsset : AllocateAsset(key);
        if (asset->texture) asset->texture->Release();
        delete asset->meta;
        
        asset->texture = tex;
        asset->width = size.x;
        asset->height = size.y;
        asset->format = D3DFMT_A8R8G8B8;
        asset->isPoolDefault = false;
        asset->hasAlpha = alpha;
        asset->meta = new AssetMeta;
        asset->meta->notFound = notFound;
        asset->meta->loadedManually = true;
        asset->meta->canvasSizeMultiplier = canvasSizeMultiplier;
        
        return asset;
    }

    Asset* AssetPool::LoadUnknownAsset(const std::string& key)
    {
        sdk::DirectX::EnsureDeviceReady();
        const auto tex = TextureLoader::LoadUnknown(*sdk::DirectX::d3dDevice, { 256, 256 }, { 1, 1 });
        const auto asset = AllocateAsset(key);
        
        asset->texture = tex;
        asset->width = 256;
        asset->height = 256;
        asset->format = D3DFMT_A8R8G8B8;
        asset->isPoolDefault = false;
        asset->hasAlpha = false;
        asset->meta = new AssetMeta;
        asset->meta->notFound = true;
        
        return asset;
    }

    Asset* AssetPool::GetSharedUnknownAsset()
    {
        sdk::DirectX::EnsureDeviceReady();
        static Asset* asset = nullptr;
        if (asset) return asset;

        asset = LoadUnknownAsset("unknown");
        asset->meta->notFound = false;
        return asset;
    }

    Asset* AssetPool::AllocateAsset(const std::string& key)
    {
        static constexpr Memory::Pattern pat("E8 ? ? ? ? 89 45 ? 83 7D ? ? 75 ? 6A");
        static auto mem = pat.Search().GoToNearCall();
        return mem.Get<Asset* (__thiscall *)(void*, const char*)>()(static_cast<void*>(this), key.c_str());
    }

    void AssetPool::FreeAsset(Asset * asset)
    {
        static constexpr Memory::Pattern pat("E8 ? ? ? ? C7 05 ? ? ? ? ? ? ? ? 68 ? ? ? ? FF 15");
        static auto mem = pat.Search().GoToNearCall();
        mem.Get<void (__thiscall *)(void*, void*)>()(static_cast<void*>(this), asset);
    }
    
    Asset* AssetPool::GetByName(const std::string& name) const {
        for (auto i = 0; i < assetCount; i++) {
            if (assets[i]->name == name) return assets[i];
        }
            
        return nullptr;
    }

    AssetPool* AssetPool::Instance() {
        static constexpr Memory::Pattern pat("B9 ? ? ? ? E8 ? ? ? ? 68 ? ? ? ? A1 ? ? ? ? 8B 08"); //  mov ecx, offset AssetPool__instance
        static auto mem = pat.Search();
        return *mem.Get<AssetPool**>(1);
    }
    
    std::string AssetPool::TrimFileName(std::string name, bool & alpha)
    {
        std::ranges::transform(name, name.begin(), tolower);
        const auto path = std::filesystem::path(name);
        auto ext = path.extension().string();
        alpha = name.ends_with("#") || ext == ".tga" || ext == ".png" || (path.filename().string().starts_with("_a_") && (ext == ".jpg" || ext == ".jpeg"));
        const auto index = name.find('.');
        if (index != std::string::npos) name = name.substr(0, index);
        if (name.starts_with("_a_")) name = name.substr(3);
        if (name.ends_with("#")) name = name.substr(0, name.size() - 1);
        return name;
    }

    std::string AssetPool::CreateAssetKey(const std::string& name, bool& alpha)
    {
        auto key = TrimFileName(name, alpha);
        if (alpha) return key + "#";
        return key;
    }

    std::string AssetPool::CreateAssetKey(const std::string& name)
    {
        bool alpha;
        return CreateAssetKey(name, alpha);
    }
}
