#pragma once
#include <modloader/mod/Mod.h>
#include <modloader/mod/impl/ModImpl.h>

#include "DirectXUtils.h"
#include "assets/assets.h"
#include "modules/AdaptiveResolutionModule.h"
#include "modules/ForwardGameLogsModule.h"
#include "modules/RenderUnfocusedModule.h"

class ModImplInternal final : public modloader::ModImpl {
    AdaptiveResolutionModule adaptive_resolution_module;
    ForwardGameLogsModule forward_game_logs_module;
    RenderUnfocusedModule render_unfocused_module;

public:
    void OnEnabled() override;
    void OnDisabled() override;
    void OnTick() override;
    void RenderUI() override;

    static std::shared_ptr<modloader::Mod> CreateMod();
};
