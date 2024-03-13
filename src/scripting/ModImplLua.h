#pragma once
#include <unordered_set>
#include <modloader_new/mod/impl/ModImpl.h>
#include <modloader_new/mod/info/ModInfo.h>

#include "exceptions/Error.h"
#include "thirdparty/LuaContext.h"

namespace modloader
{
    class ModImplLua final : public ModImpl {
        std::shared_ptr<ModInfo> info;

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