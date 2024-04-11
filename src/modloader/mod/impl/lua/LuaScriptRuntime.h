#pragma once
#include <ranges>
#include <utility>
#include <Utils.h>
#include <set>
#include <assets/assets.h>
#include <sdk/Game.h>
#include <game/AssetPool.h>
#include <modloader/mod/info/ModInfo.h>
#include <modloader/mod/info/ModInfoFilesystem.h>

#include "lua.h"
#include "luaDataTypes.h"
#include "luaFilesystem.h"

namespace modloader {
    class LuaScriptRuntime
    {
    public:
        class ModPackage
        {
            std::optional<sol::protected_function> eventHandler = std::nullopt;
            sol::state& lua;
            std::set<std::string> enabledEvents;

        public:
            ModPackage(std::string id, const std::filesystem::path& root, sol::state& lua) :
                lua(lua),
                id(std::move(id)),
                fenv(lua, sol::create, lua.globals()),
                loaded(lua, sol::create),
                builtin(lua, sol::create),
                module(sol::nil),
                path((root / "?.lua").string() + LUA_PATHSEP + (root / "?" / "init.lua").string()),
                cpath(".\?.dll;" + (root / "?.dll").string() + LUA_PATHSEP + (root / "loadall.dll").string())
            {
                spdlog::debug("Loaded Lua mod package {}", this->id);
            }

            ~ModPackage()
            {
                spdlog::debug("Unloaded Lua mod package {}", this->id);
            }

            std::string id;
            sol::environment fenv;
            sol::table loaded;
            sol::table builtin;
            sol::reference module;
            std::string path;
            std::string cpath;

            void Finalize()
            {
                eventHandler = fenv["__handleEvent"];
                fenv["__handleEvent"] = sol::lua_nil;
            }

            void EnableEvent(const std::string& eventName)
            {
                enabledEvents.insert(eventName);
            }

            void DisableEvent(const std::string& eventName)
            {
                enabledEvents.erase(eventName);
            }

            template <class T>
            void HandleEvent(const std::string& eventName, T& event)
            {
                if (!eventHandler.has_value()) return;
                if (!enabledEvents.contains(eventName)) return;

                if (!sol::is_usertype_registered<T>(lua))
                    event.RegisterLuaType(lua);

                eventHandler->call(eventName, event);
                // todo error handling
            }

            static void RegisterLuaType(sol::state& lua)
            {
                lua.new_usertype<ModPackage>(sol::no_constructor,
                    "id", sol::readonly(&ModPackage::id),
                    "fenv", sol::readonly(&ModPackage::fenv),
                    "loaded", sol::readonly(&ModPackage::loaded),
                    "builtin", sol::readonly(&ModPackage::builtin),
                    "module", sol::readonly(&ModPackage::module),
                    "path", sol::readonly(&ModPackage::path),
                    "cpath", sol::readonly(&ModPackage::cpath));
            }
        };
    private:

        static inline bool initialized = false;
        LuaScriptRuntime()
        {
            spdlog::info("Initializing Lua script runtime");
            lua.open_libraries();
            luaPackages = lua.create_table();
            Init();
        }

        void Init()
        {
            lua.set_panic([](lua_State* L) -> int {
                std::cout << "Lua panic" << std::endl;
                const std::string str = lua_type(L, -1) != LUA_TSTRING ? "no panic message" : lua_tostring(L, -1);
                lua_pop(L, 1);
                MessageBoxW(nullptr, utils::str_to_wstr(str).c_str(), L"Lua panic", MB_OK | MB_ICONERROR);
                assert(false && "lua_atpanic triggered");
                exit(0);
            });

            registerLuaTypes(lua.globals());
            registerLuaFilesystem(lua.globals());
            ModPackage::RegisterLuaType(lua);
            game::Asset::RegisterLuaType(lua);
            ModInfo::RegisterLuaType(lua);
            ModInfoFilesystem::RegisterLuaType(lua);

            lua.globals()["require"]("ffi"); // preload FFI

            const auto sdk = utils::read_zip_resource(LUA_SDK_ZIP);
            lua.registry()["_LOADED"]["util"] = lua.script(sdk->read("library/util.lua"), "built-in util", sol::load_mode::text);
            lua.script(sdk->read("library/imguicdecl.lua"), "imgui cdef", sol::load_mode::text);
            lua.registry()["_LOADED"]["imgui"] = lua.script(sdk->read("library/imgui.lua"), "built-in imgui", sol::load_mode::text);

            lua.globals()["require"] = sol::lua_nil; // We reimplement require in fenvs. Having it in global scope might lead to some weird nondebuggable bugs
        }

        sol::state lua {};
        sol::table luaPackages;
        std::map<std::string, std::shared_ptr<ModPackage>> packages;

    public:
        sol::state& GetLua()
        {
            return lua;
        }

        std::shared_ptr<ModPackage> CreatePackage(const std::string& id, const std::filesystem::path& root)
        {
            assert(!packages.contains(id) && "Package with this id already exists");

            auto package = std::make_shared<ModPackage>(id, root, lua);
            luaPackages[id] = package;
            packages[id] = package;
            AddIntrinsics(package);
            return package;
        }

        void RemovePackage(const std::string& id)
        {
            luaPackages[id] = sol::lua_nil;
            packages.erase(id);
        }

        void AddIntrinsics(const std::shared_ptr<ModPackage>& package)
        {
            auto env = package->fenv;

            env["__modPackages"] = luaPackages;
            env["__currentModId"] = package->id;
            env["__enableEvent"] = sol::bind_instance(&ModPackage::EnableEvent, package);
            env["__disableEvent"] = sol::bind_instance(&ModPackage::DisableEvent, package);
        }

        static void RemoveIntrinsics(const std::shared_ptr<ModPackage>& package)
        {
            auto env = package->fenv;

            env["__modPackages"] = sol::nil;
            env["__currentModId"] = sol::nil;
            env["__enableEvent"] = sol::nil;
            env["__disableEvent"] = sol::nil;
        }

        template <class T>
        static void DispatchEvent(const std::string eventName, T& event)
        {
            if (!initialized) return;
            for (const auto& package : Get().packages | std::views::values)
            {
                package->HandleEvent(eventName, event);
            }
        }

        static LuaScriptRuntime& Get()
        {
            static LuaScriptRuntime instance;
            initialized = true;
            return instance;
        }
    };
}
