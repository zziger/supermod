#pragma once
#include <supermod/pch.hpp>

#include <d3d8/d3d8helpers.h>
#include <map>
#include <supermod/data.hpp>
#include <supermod/memory/Memory.hpp>
#include <supermod/modloader/mod/impl/lua/lua.hpp>

namespace game
{
struct AssetMeta
{
    bool notFound = false;
    std::filesystem::path origDir = "";
    std::string origName = "";
    vector2 canvasSizeMultiplier = {1, 1};
    bool loadedManually = false;

    static void RegisterLuaType(sol::state& state)
    {
        state.new_usertype<AssetMeta>(sol::no_constructor, "notFound", &AssetMeta::notFound, "origDir",
                                      &AssetMeta::origDir, "origName", &AssetMeta::origName, "canvasSizeMultiplier",
                                      &AssetMeta::canvasSizeMultiplier, "loadedManually", &AssetMeta::loadedManually);
    }
};

struct Asset
{
    char name[124]; // originally name has length of 128, i take 4 bytes for custom meta ptr
    AssetMeta* meta;
    uint32_t width;
    uint32_t height;
    IDirect3DTexture8* texture;
    byte hasAlpha;
    byte isPoolDefault;
    D3DFORMAT format;

    void ReplaceTexture(IDirect3DTexture8* tex);

    static void RegisterLuaType(sol::state& state)
    {
        AssetMeta::RegisterLuaType(state);

        state.new_usertype<Asset>(sol::no_constructor, "name",
                                  sol::property([](const Asset& asset) { return std::string(asset.name); },
                                                [](Asset& asset, std::string name) {
                                                    if (name.length() > 123)
                                                        throw std::runtime_error("Asset name is too long");
                                                    std::ranges::copy(name, asset.name);
                                                    asset.name[name.length()] = '\0';
                                                }),
                                  "meta", &Asset::meta, "width", &Asset::width, "height", &Asset::height, "texture",
                                  sol::property_reinterpret_cast<intptr_t>(&Asset::texture), "hasAlpha",
                                  &Asset::hasAlpha, "isPoolDefault", &Asset::isPoolDefault, "format", &Asset::format);
    }
};

struct OwnedAsset
{
    explicit OwnedAsset(Asset* asset) : asset(asset) {}
    ~OwnedAsset();

    Asset* asset;

    explicit operator bool() const { return asset != nullptr; }

    void Reset() { asset = nullptr; }
};

class AssetPool
{
public:
    virtual ~AssetPool() = default;
    AssetPool() = delete;

    Asset* assets[1024];
    int assetCount;
    static inline std::map<Asset*, std::weak_ptr<OwnedAsset>> ownedAssets;

    [[nodiscard]] static LPDIRECT3DTEXTURE8 LoadTexture(const std::filesystem::path& path, vector2ui& size, bool& alpha,
                                                        vector2 canvasSizeMultiplier = {1, 1});
    [[nodiscard]] static LPDIRECT3DTEXTURE8 TryLoadTexture(const std::filesystem::path& dir, const std::string& key,
                                                           bool alpha, vector2ui& size, vector2 canvasSizeMultiplier);
    [[nodiscard]] LPDIRECT3DTEXTURE8 TryLoadTextureFromMods(const std::filesystem::path& dir, const std::string& name,
                                                            bool alpha, vector2ui& size, std::string& modName,
                                                            vector2 canvasSizeMultiplier);

    Asset* LoadGameAsset(const std::filesystem::path& path, bool loadFallback = true,
                         vector2 canvasSizeMultiplier = {1, 1});
    Asset* LoadGameAssetFromData(const std::filesystem::path& path, bool loadFallback = true,
                                 vector2 canvasSizeMultiplier = {1, 1});
    bool ReloadGameAsset(const std::string& filename);
    Asset* LoadAsset(LPDIRECT3DTEXTURE8 tex, std::string key, bool alpha, vector2ui size);
    Asset* LoadAsset(const std::filesystem::path& path, std::string key, bool loadFallback = true,
                     vector2 canvasSizeMultiplier = {1, 1});
    Asset* LoadUnknownAsset(const std::string& key);
    [[nodiscard]] Asset* GetSharedUnknownAsset();

    Asset* AllocateAsset(const std::string& key);
    void RemoveAsset(Asset* asset);
    void FreeAsset(Asset* asset);
    std::shared_ptr<OwnedAsset> MakeOwned(Asset* asset);

    static inline std::vector<IDirect3DTexture8*> removedTextures;
    static inline std::vector<Asset*> removedAssets;
    void FreeRemovedAssets();

    [[nodiscard]] Asset* GetByName(const std::string& name) const;

    static AssetPool* Instance();
    static void Init();

    [[nodiscard]] std::string MakeAssetKeyUnique(const std::string& key) const;
    [[nodiscard]] static std::string TrimFileName(std::string name, bool& alpha);
    [[nodiscard]] static std::string CreateAssetKey(const std::string& name, bool& alpha);
    [[nodiscard]] static std::string CreateAssetKey(const std::string& name);

    static void AddToLua(sol::table table)
    {
        using fspath = std::filesystem::path;
        using string = std::string;

        auto inst = Instance();

        table["getAssets"] = [inst] { return std::vector<Asset*>{inst->assets, inst->assets + inst->assetCount}; };
        table["getAssetByName"] = sol::bind_instance(&AssetPool::GetByName, inst);
        table["getUnknownAsset"] = sol::bind_instance(&AssetPool::GetSharedUnknownAsset, inst);
        table["removeAsset"] = sol::bind_instance(&AssetPool::RemoveAsset, inst);

        table["loadGameAsset"] =
            sol::overload_conv<Asset*(const fspath&, bool, vector2), Asset*(const string&, bool, vector2),
                               Asset*(const fspath&, bool), Asset*(const string&, bool), Asset*(const fspath&),
                               Asset*(const string&)>([inst](auto... args) { return inst->LoadGameAsset(args...); });

        table["loadGameAssetFromData"] =
            sol::overload_conv<Asset*(const fspath&, bool, vector2), Asset*(const string&, bool, vector2),
                               Asset*(const fspath&, bool), Asset*(const string&, bool), Asset*(const fspath&),
                               Asset*(const string&)>(
                [inst](auto... args) { return inst->LoadGameAssetFromData(args...); });

        table["loadAsset"] =
            sol::overload_conv<Asset*(const fspath&, string, bool, vector2),
                               Asset*(const string&, string, bool, vector2), Asset*(const fspath&, string, bool),
                               Asset*(const string&, string, bool), Asset*(const fspath&, string),
                               Asset*(const string&, string)>(
                [inst](auto... args) { return inst->LoadAsset(args...); });
    }
};
} // namespace game
