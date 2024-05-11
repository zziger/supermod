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

namespace modloader {
    class LuaScriptRuntime : public std::enable_shared_from_this<LuaScriptRuntime>
    {
    public:
        class ModPackage
        {
            std::optional<sol::protected_function> eventHandler = std::nullopt;
            std::shared_ptr<LuaScriptRuntime> runtime;
            std::set<std::string> enabledEvents;

        public:
            ModPackage(std::string id, const std::filesystem::path& root, const std::shared_ptr<LuaScriptRuntime>& runtime) :
                runtime(runtime),
                id(std::move(id)),
                fenv(runtime->GetLua(), sol::create, runtime->GetLua().globals()),
                loaded(runtime->GetLua(), sol::create),
                builtin(runtime->GetLua(), sol::create),
                module(std::nullopt),
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
            std::optional<sol::object> module;
            std::string path;
            std::string cpath;

            void Finalize();

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

                auto& lua = runtime->GetLua();
                if (!sol::is_usertype_registered<T>(lua))
                    event.RegisterLuaType(lua);

                eventHandler->call(eventName, event);
                // todo error handling
            }

            static void RegisterLuaType(sol::state& lua);
        };

        LuaScriptRuntime()
        {
            spdlog::info("Initializing Lua script runtime");
            lua.open_libraries();
            luaPackages = lua.create_table();
            Init();
        }

    private:

        void Init();

        sol::state lua {};
        sol::table luaPackages;
        std::map<std::string, std::shared_ptr<ModPackage>> packages;

    public:
        sol::state& GetLua()
        {
            return lua;
        }

        std::shared_ptr<ModPackage> CreatePackage(const std::string& id, const std::filesystem::path& root);

        void RemovePackage(const std::string& id);

        void AddIntrinsics(const std::shared_ptr<ModPackage>& package);

        static void RemoveIntrinsics(const std::shared_ptr<ModPackage>& package);

        template <class T>
        static void DispatchEvent(const std::string eventName, T& event)
        {
            if (instance.expired()) return;
            for (const auto& package : Get()->packages | std::views::values)
            {
                package->HandleEvent(eventName, event);
            }
        }

        static std::shared_ptr<LuaScriptRuntime> Get()
        {
            std::shared_ptr<LuaScriptRuntime> inst = instance.lock();
            if (!inst)
            {
                inst = std::make_shared<LuaScriptRuntime>();
                instance = inst;
            }

            return inst;
        }

    private:
        static inline std::weak_ptr<LuaScriptRuntime> instance;
    };
}
