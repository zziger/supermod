#pragma once
#include <supermod/pch.hpp>

#include <supermod/modloader/mod/impl/ModImpl.hpp>
#include <supermod/modloader/mod/info/ModInfo.hpp>

#include <supermod/modloader/mod/impl/lua/LuaScriptRuntime.hpp>

namespace modloader
{
class ModImplLua final : public ModImpl
{
    std::shared_ptr<ModInfo> info;
    std::shared_ptr<spdlog::logger> logger;
    std::optional<sol::protected_function> tick = std::nullopt;

public:
    explicit ModImplLua(std::shared_ptr<ModInfo> info) : info(std::move(info)) {}

    std::shared_ptr<LuaScriptRuntime::ModPackage> package = nullptr;

    void OnEnabled() override;

    void OnDisabled() override;

    void RenderUI() override;

    void Render() override;

    uint64_t lastMs = 0;
};
} // namespace modloader