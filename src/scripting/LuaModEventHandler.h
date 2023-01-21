#pragma once
#include <unordered_set>
#include "exceptions/Error.h"
#include "modloader/mods/Mod.h"
#include "thirdparty/LuaContext.h"

class LuaMod final : public Mod {
public:
    explicit LuaMod(LuaContext*) : lua(nullptr) {}

    LuaContext* lua;
};
