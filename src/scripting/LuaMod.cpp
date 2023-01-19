#include "LuaMod.h"

#include "luaassets.h"
#include "Utils.h"
#include "sdk/Game.h"

void LuaMod::OnLoad() {
    if (info.luaScript == "") throw Error("LuaMod был заинициализирован, но скрипт не был найден");

    const auto fullPath = info.basePath / info.luaScript;
    if (!exists(fullPath)) throw Error(std::format("Файл {} не найден", fullPath.generic_string()));

    lua = new LuaContext(true);

    lua->appendPath((info.basePath / "?.lua").generic_string());
    lua->appendCpath((info.basePath / "?.dll").generic_string());
    lua->writeVariable("MODULENAME", utils::get_module_name()); // useful for FFI
    lua->writeFunction("logDebug", [](std::string str) {
        Log::Debug << str << Log::Endl;
    });
    
    lua->writeFunction("wait", [](const float time) {
        std::this_thread::sleep_for(std::chrono::milliseconds((int) (time * 1000)));
    });
    lua->writeFunction("findPattern", [](const std::string pat) {
        return Memory::Pattern(pat.c_str(), pat.size()).Search().Get<int32_t>();
    });

    lua->executeModule("imguicdecl", *utils::read_resource(LUA_IMGUI_CDECL));
    lua->executeModule("imgui", *utils::read_resource(LUA_IMGUI_WRAPPER));
    lua->executeModule("memory", *utils::read_resource(LUA_MEMORY));
    sdk::Game::AddToLua(*lua);
    
    auto stream = std::ifstream{ fullPath };
    lua->executeCode(stream);
}

void LuaMod::OnUnload() {
    delete lua;
    lua = nullptr;
}

void LuaMod::RenderUI() {
    if (!lua) return;
    try {
        auto fn = lua->readVariable<tl::optional<std::function<void()>>>("render");
        if (fn) (*fn)();
    } catch (std::exception& e) {
        Log::Error << "Ошибка рендера из LUA скрипта: " << e.what() << Log::Endl;
    }
    // todo move error handling to outer scope
}