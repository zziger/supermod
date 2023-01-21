#pragma once
#include <unordered_set>
#include "exceptions/Error.h"
#include "modloader/mods/Mod.h"
#include "thirdparty/LuaContext.h"

class LuaMod final : public Mod {
public:
    explicit LuaMod(ModInfo info) : Mod(std::move(info)) {}

    std::shared_ptr<LuaContext> lua;

    void OnLoad() override;

    void OnUnload() override;

    void RenderUI() override;

    void Render() override;
    
    int lastMs;
};
