#pragma once
#include <modloader/mod/Mod.h>
#include <modloader/mod/impl/ModImpl.h>

#include "DirectXUtils.h"
#include "assets/assets.h"
#include "modules/ForwardGameLogsModule.h"

class ModImplInternal final : public modloader::ModImpl {
    ForwardGameLogsModule forward_game_logs_module;

public:
    void OnEnabled() override;
    void OnDisabled() override;
    void OnTick() override;
    void RenderUI() override;

    static std::shared_ptr<modloader::Mod> CreateMod();
};
