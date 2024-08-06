// Replaces game's asset pool with a custom one from SuperMod
// This fixes and improves texture loading and resolving
// Asset pool entries are now forced to have lowercase name,
// names don't have _a_ or file extension anymore.
// Transparent textures (.png, _a_.jp(e)g, .tga) have # at the end of the name
// filename.jpg -> filename
// _a_filename.jpg or filename.tga -> filename#

#include <supermod/pch.hpp>

#include <queue>
#include <supermod/Utils.hpp>
#include <supermod/events/EventManager.hpp>
#include <supermod/events/ResolveFileEvent.hpp>
#include <supermod/game/AssetPool.hpp>
#include <supermod/game/Graphics.hpp>
#include <supermod/memory/HookManager.hpp>
#include <supermod/modloader/ModManager.hpp>
#include <supermod/modloader/files/ModFileResolver.hpp>

using namespace sm;

static float squarify_dimensions_algorithm(const int a1)
{
    float v3 = 1;
    for (auto i = 2; i < 18; i++)
    { // 12 in original fn
        v3 *= 2;
        if (a1 <= v3)
            return v3;
    }
    return 0;
}

game::Asset*(__thiscall* read_const_jpg_orig)(game::AssetPool* this_, char* name, int width, int height) = nullptr;
game::Asset* __fastcall read_const_jpg(game::AssetPool* this_, void* ecx_, char* name, int width, int height)
{
    return this_->LoadGameAsset(name, true,
                                {squarify_dimensions_algorithm(width) / static_cast<float>(width),
                                 squarify_dimensions_algorithm(height) / static_cast<float>(height)});
}

game::Asset*(__thiscall* read_const_surface_orig)(game::AssetPool* this_, char* name, int width, int height) = nullptr;
game::Asset* __fastcall read_const_surface(game::AssetPool* this_, void*, char* name, int width, int height)
{
    return this_->LoadGameAsset(name, true,
                                {squarify_dimensions_algorithm(width) / static_cast<float>(width),
                                 squarify_dimensions_algorithm(height) / static_cast<float>(height)});
}

game::Asset*(__thiscall* load_texture_orig)(game::AssetPool* this_, char* name, char critical, char useARGB,
                                            int mipLevels) = nullptr;
game::Asset* __fastcall load_texture(game::AssetPool* this_, void*, char* name, char critical, char useARGB, int mip)
{
    return this_->LoadGameAsset(name, critical != 0);
}

game::Asset*(__thiscall* get_asset_by_name_orig)(game::AssetPool* this_, const char* name) = nullptr;
game::Asset* __fastcall get_asset_by_name(game::AssetPool* this_, void*, const char* name)
{
    return get_asset_by_name_orig(this_, game::AssetPool::CreateAssetKey(name).c_str());
}

game::AssetPool*(__thiscall* remove_asset_orig)(game::AssetPool* this_, game::Asset* asset) = nullptr;
game::AssetPool* __fastcall remove_asset(game::AssetPool* this_, void*, game::Asset* asset)
{
    if (asset == nullptr)
        return this_;
    const auto origMeta = asset->meta;
    const auto name = asset->name;
    const auto count = this_->assetCount;
    remove_asset_orig(this_, asset);
    if (this_->assetCount != count)
    {
        delete origMeta;
        if (game::AssetPool::ownedAssets.contains(asset))
        {
            const auto ownedAsset = game::AssetPool::ownedAssets[asset];
            if (!ownedAsset.expired())
                ownedAsset.lock()->Reset();
            game::AssetPool::ownedAssets.erase(asset);
        }
    }
    else
        spdlog::error("Failed to free asset {} from asset pool", name);
    return this_;
}

HOOK_FN_CONV(int, set_texture, ARGS(game::Asset* asset), __cdecl)
{
    if (asset)
        return set_texture_orig(asset);
    static auto fallback = game::AssetPool::Instance()->GetSharedUnknownAsset();
    return set_texture_orig(fallback);
}

// Always returning checkerboard for unknown textures breaks object loading
// When loading objects game expects that some textures are nullptr, and then looks in a
// sprites/ folder trying to load SpriteAnim
game::Asset* __fastcall load_texture_obj(game::AssetPool* this_, void*, char* name, char critical, char useARGB,
                                         int mip)
{
    const auto firstTex = this_->LoadGameAsset(name, false);
    if (firstTex)
        return firstTex;

    // If texture exists in sprites/ then return nullptr, so game can try to load it as a SpriteAnim
    const auto cwd = std::filesystem::current_path();
    current_path(game::Game::GetDataPath() / "sprites");
    const auto secondTex = this_->LoadGameAsset(name, false);
    current_path(cwd);
    if (secondTex)
    {
        this_->RemoveAsset(secondTex);
        return nullptr;
    }

    bool dummy;
    const auto key = game::AssetPool::TrimFileName(name, dummy);
    const auto dirPath = std::filesystem::path("sprites") / key;
    if (const auto fullDirPath = game::Game::GetDataPath() / dirPath; exists(fullDirPath) && is_directory(fullDirPath))
        return nullptr;

    const auto mods = modloader::ModManager::GetMods();
    for (const auto& mod : mods)
    {
        auto path = modloader::ModFileResolver::GetGameFileInMod(mod, dirPath);
        if (path.has_value() && exists(*path) && is_directory(*path))
            return nullptr;
    }

    spdlog::error("Texture for object {} was not found", name);
    return this_->LoadUnknownAsset(game::AssetPool::CreateAssetKey(name));
}

HOOK_FN_CONV(int, render_border, ARGS(int* a1), __cdecl)
{
    static game::Asset* white = nullptr;
    if (!white)
        white = game::AssetPool::Instance()->GetByName("white");
    game::Graphics::SetRenderAsset(white);
    return render_border_orig(a1);
}

inline EventManager::Ready $asset_pool_patch([] {
    HookManager::RegisterHook("55 8B EC 83 EC ? 89 4D ? 8B 45 ? 50 8B 4D ? E8 ? ? ? ? 89 45 ? 83 7D ? ? 74 ? 8B 45 ? "
                              "E9 ? ? ? ? 6A ? 6A ? 8B 4D",
                              HOOK_REF_FORCE(read_const_jpg));
    HookManager::RegisterHook(
        "55 8B EC 83 EC ? 89 4D ? 8B 45 ? 50 8B 4D ? E8 ? ? ? ? 89 45 ? 83 7D ? ? 74 ? 8B 45 ? E9 ? ? ? ? C7 45",
        HOOK_REF_FORCE(read_const_surface));
    HookManager::RegisterHookExclusive("55 8B EC 81 EC ? ? ? ? A1 ? ? ? ? 89 45 ? 89 8D ? ? ? ? 8B 45 ? 50",
                                       HOOK_REF_FORCE(load_texture));
    HookManager::RegisterHook(Memory::Pattern("E8 ? ? ? ? 89 45 ? 83 7D ? ? 74 ? 8B 45 ? E9 ? ? ? ? 68 ? ? ? ? 8B 4D")
                                  .Search()
                                  .GoToNearCall(),
                              HOOK_REF_FORCE(get_asset_by_name));
    HookManager::RegisterHook(
        Memory::Pattern("E8 ? ? ? ? C7 05 ? ? ? ? ? ? ? ? 68 ? ? ? ? FF 15").Search().GoToNearCall(),
        HOOK_REF_FORCE(remove_asset));

    HookManager::RegisterHook("55 8B EC 83 7D ? ? 74 ? 8B 45 ? 8B 88", HOOK_REF(set_texture));

    static constexpr Memory::Pattern pat("E8 ? ? ? ? 8B 4D ? 89 41 ? 8B 55 ? 83 7A ? ? 0F 85 ? ? ? ? 68 ? ? ? ? E8");
    pat.Search().NearCall(static_cast<void*>(load_texture_obj));

    // patches editor triangle render texture problem
    static constexpr Memory::Pattern pat2(
        "83 C4 ? 6A ? E8 ? ? ? ? 83 C4 ? 8D 4D ? E8 ? ? ? ? 8D 4D ? E8 ? ? ? ? 8D 4D");
    pat2.Search().Nop(10);

    // patches editor border render texture problems
    static constexpr Memory::Pattern pat3("55 8B EC 83 EC ? 6A ? E8 ? ? ? ? 83 C4 ? 8D 4D ? E8 ? ? ? ? 8D 4D");
    static auto mem = pat3.Search();
    (mem + 6).Nop(7);
    HookManager::RegisterHook(mem, HOOK_REF(render_border));
});