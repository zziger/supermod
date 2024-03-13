#include "EventManager.h"

#include <modloader_new/ModManager.h>
#include <scripting/ModImplLua.h>

#include "modloader/mods/ModManager.h"

std::vector<std::shared_ptr<LuaContext>> EventManager::GetLuaContexts() {
    std::vector<std::shared_ptr<LuaContext>> vec;
    
    for (const auto& mod : modloader::ModManager::GetMods()) {
        if (!mod->IsActive()) continue;
        const auto luaImpl = dynamic_cast<modloader::ModImplLua*>(mod->GetImpl().get());
        if (!luaImpl) continue;
        vec.push_back(luaImpl->lua);
    }

    return vec;
}