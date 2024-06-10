#pragma once
#include <supermod/builtin/ModImplBuiltin.hpp>
#include <supermod/pch.hpp>

#include <supermod/DirectXUtils.hpp>
#include <supermod/builtin/modules/ForwardGameLogsModule.hpp>
#include <supermod/modloader/mod/Mod.hpp>
#include <supermod/modloader/mod/impl/ModImpl.hpp>

namespace sm::builtin
{
class ModImplBuiltin final : public modloader::ModImpl
{
    ForwardGameLogsModule forward_game_logs_module;

public:
    void OnEnabled() override;
    void OnDisabled() override;
    void OnTick() override;
    void RenderUI() override;

    static std::shared_ptr<modloader::Mod> CreateMod();
};
} // namespace sm::builtin