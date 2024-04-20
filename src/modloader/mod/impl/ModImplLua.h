#pragma once
#include <filesystem>
#include <unordered_set>
#include <modloader/mod/impl/ModImpl.h>
#include <modloader/mod/info/ModInfo.h>
#include <spdlog/spdlog.h>

#include "exceptions/Error.h"
#include "lua/LuaScriptRuntime.h"

namespace modloader
{
    class ModImplLua final : public ModImpl {
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
}