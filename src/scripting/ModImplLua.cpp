#include "ModImplLua.h"

#include <modloader_new/mod/info/ModInfoFilesystem.h>

#include "Config.h"
#include "assets/assets.h"
#include "Utils.h"
#include "events/TickEvent.h"
#include "events/WindowEvent.h"
#include "sdk/Game.h"
#include "sdk/Graphics.h"

namespace modloader
{
    void ModImplLua::OnEnabled() {
        assert(info->scriptType == ModInfo::ScriptType::LUA && "ModImplLua::OnEnabled called for non-lua mod");

        const auto infoFs = std::dynamic_pointer_cast<ModInfoFilesystem>(info);
        assert(infoFs && "ModImplLua::OnEnabled called for non-filesystem mod");

        auto scriptPath = info->scriptMain;

        const auto fullPath = infoFs->basePath / scriptPath;
        if (!exists(fullPath) || is_directory(fullPath)) throw Error(std::format("Скрипт {} не найден", fullPath.generic_string()));

        lua = std::make_shared<LuaContext>(true);

        lua->appendPath((infoFs->basePath / "?.lua").generic_string());
        lua->appendPath((infoFs->basePath / "?.dll").generic_string());
        lua->appendCpath((infoFs->basePath / "?.dll").generic_string());
        lua->appendCpath((infoFs->basePath / "loadall.dll").generic_string());
        lua->writeVariable("CURRENT_DLL_PATH", utils::get_module_name()); // useful for FFI
        lua->writeVariable("MOD_PATH", infoFs->basePath.string() + "\\");

        lastMs = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();

        lua->writeFunction("wait", [](const float time) {
            std::this_thread::sleep_for(std::chrono::milliseconds((int) (time * 1000)));
        });
        lua->writeFunction("currentTimestamp", []() {
            return std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        });
        lua->writeFunction("findPattern", [](const bool cache, const std::string pat) {
            return Memory::Pattern(pat.c_str(), pat.size()).Search(cache).Get<int32_t>();
        });

        // info.RegisterLuaType(lua.get());
        // lua->writeVariable("currentMod", info);
        // TODO: currentMod

        Log::AddToLua(*lua);
        sdk::Game::AddDataToLua(*lua);
        sdk::Game::AddToLua(*lua);
        game::AssetPool::AddToLua(*lua);
        sdk::Graphics::AddToLua(*lua);
        Config::AddToLua(*lua, info->GetID());
        HookManager::AddToLua(*lua);

        lua->executeCode(*utils::read_resource(LUA_BASE_MODULE), "internal");

        lua->RegisterEventMethods();
        lua->executeModule("events", *utils::read_resource(LUA_MODULE_EVENTS));
        lua->HideEventMethods();

        lua->executeModule("imguicdecl", *utils::read_resource(LUA_MODULE_IMGUI_CDECL));
        lua->executeModule("imgui", *utils::read_resource(LUA_MODULE_IMGUI));
        lua->executeModule("memory", *utils::read_resource(LUA_MODULE_MEMORY));
        lua->executeModule("timers", *utils::read_resource(LUA_MODULE_TIMERS));
        lua->executeModule("config", *utils::read_resource(LUA_MODULE_CONFIG));

        lua->writeVariable("safecall",  std::function([this](const std::function<void()> cb) {
            if (!lua) return;
            try
            {
                cb();
            }
            catch(const std::exception& e)
            {
                Log::Error << "SAFECALL resulted in a C++ exception: " << e.what() << Log::Endl;
            }
            catch(...)
            {
                Log::Error << "SAFECALL resulted in an unknown exception." << Log::Endl;
                std::cout << "LUA stack:" << std::endl;
                lua->dumpstack(lua->getState());
            }
        }));

        auto stream = std::ifstream{ fullPath };
        lua->executeCode(stream, fullPath.filename().generic_string().c_str());
    }

    struct LuaUnloadEvent : IEvent<"_unload", LuaUnloadEvent> {};

    void ModImplLua::OnDisabled() {
        if (!lua) return;
        auto event = LuaUnloadEvent{};
        lua->EmitEvent("_unload", event);
        lua = nullptr;
    }

    void ModImplLua::RenderUI() {
        if (!lua) return;
        try {
            auto fn = lua->readVariable<tl::optional<std::function<void()>>>("renderUi");
            if (fn) (*fn)();
        } catch (std::exception& e) {
            Log::Error << "Ошибка рендера UI в моде " << info->GetID() << " :" << e.what() << Log::Endl;
        }
    }

    void ModImplLua::Render() {
        if (!lua) return;
        const int currMs = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();

        if (currMs != lastMs) {
            lastMs = currMs;
            try {
                if (auto fn = lua->readVariable<tl::optional<std::function<void()>>>("__tick"))
                    (*fn)();
            } catch (std::exception& e) {
                Log::Error << "Ошибка обработки таймеров " << info->GetID() << " :" << e.what() << Log::Endl;
            }
        }

        try {
            auto fn = lua->readVariable<tl::optional<std::function<void()>>>("render");
            if (fn) (*fn)();
        } catch (std::exception& e) {
            Log::Error << "Ошибка рендера в моде " << info->GetID() << " :" << e.what() << Log::Endl;
        }
    }
}