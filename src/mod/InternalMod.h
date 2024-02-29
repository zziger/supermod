#pragma once
#include <modloader_new/mod/Mod.h>
#include <modloader_new/mod/ModImpl.h>

#include "DirectXUtils.h"
#include "assets/assets.h"
#include "modloader/mods/Mod.h"
#include "modules/AdaptiveResolutionModule.h"
#include "modules/ForwardGameLogsModule.h"
#include "modules/FpsLimitModule.h"
#include "modules/LevelBackRenderFixModule.h"
#include "modules/RenderUnfocusedModule.h"

class ModImplInternal final : public modloader::ModImpl {
    AdaptiveResolutionModule adaptive_resolution_module;

public:
    void OnEnabled() override;
    void OnDisabled() override;
    void OnTick() override;
    void RenderUI() override;

    static std::shared_ptr<modloader::Mod> CreateMod();
};
