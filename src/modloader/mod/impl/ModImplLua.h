#pragma once
#include <unordered_set>
#include <modloader/mod/impl/ModImpl.h>
#include <modloader/mod/info/ModInfo.h>
#include <spdlog/spdlog.h>

#include "exceptions/Error.h"
#include "thirdparty/LuaContext.h"

namespace modloader
{
    class ModImplLua final : public ModImpl {
        std::shared_ptr<ModInfo> info;
        std::shared_ptr<spdlog::logger> logger;

    public:
        explicit ModImplLua(std::shared_ptr<ModInfo> info) : info(std::move(info)) {}

        std::shared_ptr<LuaContext> lua;

        void OnEnabled() override;

        void OnDisabled() override;

        void RenderUI() override;

        void Render() override;

        int lastMs = 0;
    };
}