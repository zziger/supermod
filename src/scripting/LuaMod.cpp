#include "LuaMod.h"

#include "luaassets.h"
#include "Utils.h"
#include "events/TickEvent.h"
#include "events/WindowEvent.h"
#include "sdk/Game.h"

void LuaMod::OnEnable() {
    if (info.luaScript == "") throw Error("LuaMod был заинициализирован, но скрипт не был найден");

    const auto fullPath = info.basePath / info.luaScript;
    if (!exists(fullPath)) throw Error(std::format("Файл {} не найден", fullPath.generic_string()));

    lua = std::make_shared<LuaContext>(true);

    lua->appendPath((info.basePath / "?.lua").generic_string());
    lua->appendPath((info.basePath / "?.dll").generic_string());
    lua->appendCpath((info.basePath / "?.dll").generic_string());
    lua->appendCpath((info.basePath / "loadall.dll").generic_string());
    lua->writeVariable("CURRENT_DLL_PATH", utils::get_module_name()); // useful for FFI
    lua->writeVariable("MOD_PATH", info.basePath.generic_string() + "/");
 
    lastMs = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
    
    lua->writeFunction("wait", [](const float time) {
        std::this_thread::sleep_for(std::chrono::milliseconds((int) (time * 1000)));
    });
    lua->writeFunction("currentTimestamp", []() {
        return std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
    });
    lua->writeFunction("findPattern", [](const std::string pat) {
        return Memory::Pattern(pat.c_str(), pat.size()).Search().Get<int32_t>();
    });

    Log::AddToLua(*lua);
    lua->executeModule("imguicdecl", *utils::read_resource(LUA_MODULE_IMGUI_CDECL));
    lua->executeModule("imgui", *utils::read_resource(LUA_MODULE_IMGUI));
    lua->executeModule("memory", *utils::read_resource(LUA_MODULE_MEMORY));
    lua->executeModule("timers", *utils::read_resource(LUA_MODULE_TIMERS));
    
    lua->RegisterEventMethods();
    lua->executeModule("events", *utils::read_resource(LUA_MODULE_EVENTS));
    lua->HideEventMethods();
    
    sdk::Game::AddToLua(*lua);
    
    auto stream = std::ifstream{ fullPath };
    lua->executeCode(stream, fullPath.filename().generic_string().c_str());
}

struct LuaUnloadEvent : IEvent<"_unload", LuaUnloadEvent> {};

void LuaMod::OnDisable() {
    if (!lua) return;
    auto event = LuaUnloadEvent{};
    lua->EmitEvent("_unload", event);
    lua = nullptr;
}

void LuaMod::RenderUI() {
    if (!lua) return;
    try {
        auto fn = lua->readVariable<tl::optional<std::function<void()>>>("renderUi");
        if (fn) (*fn)();
    } catch (std::exception& e) {
        Log::Error << "Ошибка рендера UI в моде " << info.id << " :" << e.what() << Log::Endl;
    }
}

void LuaMod::Render() {
    if (!lua) return;
    const int currMs = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
    
    if (currMs != lastMs) {
        lastMs = currMs;
        try {
            if (auto fn = lua->readVariable<tl::optional<std::function<void()>>>("__tick"))
                (*fn)();
        } catch (std::exception& e) {
            Log::Error << "Ошибка обработки таймеров " << info.id << " :" << e.what() << Log::Endl;
        }
    }
    
    try {
        auto fn = lua->readVariable<tl::optional<std::function<void()>>>("render");
        if (fn) (*fn)();
    } catch (std::exception& e) {
        Log::Error << "Ошибка рендера в моде " << info.id << " :" << e.what() << Log::Endl;
    }
}