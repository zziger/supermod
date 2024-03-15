#include "InternalMod.h"

#include <events/D3dInitEvent.h>
#include <game/textures/PngLoader.h>
#include <modloader_new/mod/Mod.h>

void ModImplInternal::OnEnabled()
{
    adaptive_resolution_module.Init();
}

void ModImplInternal::OnDisabled()
{
}

void ModImplInternal::OnTick()
{
}

void ModImplInternal::RenderUI()
{
    adaptive_resolution_module.Render();
}

std::shared_ptr<modloader::Mod> ModImplInternal::CreateMod()
{
    auto info = std::make_shared<modloader::ModInfo>("$internal");
    info->title = "SuperMod";
    info->author = "zziger";
    info->version = VERSION;
    info->description = "Встроенные в мод патчи игры";

    EventManager::On<D3dInitEvent>([info]
    {
        const auto iconData = *utils::read_resource(RES_LOGO);
        std::vector<byte> iconBuf(iconData.begin(), iconData.end());
        vector2ui iconSize {};
        if (const auto iconTex = PngLoader::LoadPngBuf(iconBuf, iconSize, { 1, 1 }))
        {
            const auto assetPool = game::AssetPool::Instance();
            const auto asset = assetPool->LoadAsset(iconTex, "$mod:icon:$internal", false, iconSize);
            info->icon = modloader::ModIcon(assetPool->MakeOwned(asset));
        }
    });

    auto mod = std::make_shared<modloader::Mod>(info, std::make_unique<ModImplInternal>());
    mod->SetFlag(modloader::Mod::Flag::INTERNAL);
    mod->Toggle(true);
    mod->Update();

    return mod;
}


