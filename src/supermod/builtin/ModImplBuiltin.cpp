﻿#include <supermod/builtin/ModImplBuiltin.hpp>

#include <assets/assets.h>
#include <supermod/UpdateManager.hpp>
#include <supermod/events/DxInitEvent.hpp>
#include <supermod/game/textures/PngLoader.hpp>
#include <supermod/modloader/mod/Mod.hpp>
#include <supermod/ui/NotificationManager.hpp>
#include <supermod/ui/styles/styles.hpp>

namespace sm::builtin
{
void ModImplBuiltin::OnEnabled()
{
    forward_game_logs_module.Init();
}

void ModImplBuiltin::OnDisabled() {}

void ModImplBuiltin::OnTick() {}

void ModImplBuiltin::RenderUI()
{
    using namespace update;

    auto state = UpdateManager::GetUpdateState();
    if (state.stage != UpdateManager::UpdateState::IDLE)
    {
        ui::styles::warning::BeginPanel("update");
        UpdateManager::RenderMessage();
        ui::styles::warning::EndPanel();
        return;
    }
    ImGui::Spacing();
    ImGui::Separator();
    forward_game_logs_module.Render();
}

std::shared_ptr<modloader::Mod> ModImplBuiltin::CreateMod()
{
    auto info = std::make_shared<modloader::ModInfo>("builtin");
    info->title = "SuperMod";
    info->author = "zziger";
    info->version = semver::version::parse(SUPERMOD_VERSION);
    info->description = "Встроенные в мод патчи игры";

    EventManager::On<DxInitEvent>([info] {
        const auto iconData = *utils::read_resource(RES_LOGO);
        const std::vector<byte> iconBuf(iconData.begin(), iconData.end());
        vector2ui iconSize{};
        if (const auto iconTex = game::loaders::PngLoader::LoadPngBuf(iconBuf, iconSize, {1, 1}))
        {
            const auto assetPool = game::AssetPool::Instance();
            const auto asset = assetPool->LoadAsset(iconTex, "$mod:icon:$internal", false, iconSize);
            info->icon = modloader::ModIcon(assetPool->MakeOwned(asset));
        }
    });

    auto mod = std::make_shared<modloader::Mod>(info, std::make_unique<ModImplBuiltin>());
    mod->SetFlag(modloader::Mod::Flag::INTERNAL);
    mod->Toggle(true);
    mod->Update();

    return mod;
}
} // namespace sm::builtin