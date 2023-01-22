#include "EventManager.h"

#include "modloader/mods/ModManager.h"
#include "scripting/LuaMod.h"

std::vector<std::shared_ptr<LuaContext>> EventManager::GetLuaContexts() {
    std::vector<std::shared_ptr<LuaContext>> vec;
    
    for (auto mod : ModManager::GetLuaMods()) {
        if (!mod->IsEnabled()) continue;
        if (!mod->lua) continue;
        vec.push_back(mod->lua);
    }

    return vec;
}