#include <supermod/modloader/mod/impl/ModImplLua.hpp>
#include <supermod/pch.hpp>

#include <assets/assets.h>
#include <supermod/Config.hpp>
#include <supermod/Utils.hpp>
#include <supermod/events/WindowEvent.hpp>
#include <supermod/logs/Console.hpp>
#include <supermod/modloader/mod/impl/lua/LuaScriptRuntime.hpp>
#include <supermod/modloader/mod/info/ModInfoFilesystem.hpp>
#include <supermod/sdk/Game.hpp>
#include <supermod/sdk/Graphics.hpp>
#include <supermod/ui/NotificationManager.hpp>

namespace modloader
{
void ModImplLua::OnEnabled()
{
    assert(info->scriptType == ModInfo::ScriptType::LUA && "ModImplLua::OnEnabled called for non-Lua mod");

    const auto infoFs = std::dynamic_pointer_cast<ModInfoFilesystem>(info);
    assert(infoFs && "ModImplLua::OnEnabled called for non-filesystem mod");

    if (package)
        OnDisabled();
    auto scriptPath = info->scriptMain;

    const auto fullPath = infoFs->basePath / scriptPath;
    if (!exists(fullPath) || is_directory(fullPath))
        throw Error(std::format("Скрипт {} не найден", fullPath.generic_string()));

    logger = Console::mainLogger->clone("mod " + info->GetID());
    const auto runtime = LuaScriptRuntime::Get();
    auto& lua = runtime->GetLua();
    auto sdk = utils::read_zip_resource(LUA_SDK_ZIP);

    package = runtime->CreatePackage(info->GetID(), infoFs->basePath);

    package->fenv["MOD_PATH"] = infoFs->basePath.string() + "\\";
    package->fenv["wait"] = sol::as_function([](const float time) {
        std::this_thread::sleep_for(std::chrono::milliseconds(static_cast<int>(time * 1000)));
    });

    package->fenv["currentTimestamp"] = sol::as_function([] {
        return std::chrono::duration_cast<std::chrono::milliseconds>(
                   std::chrono::system_clock::now().time_since_epoch())
            .count();
    });

    package->fenv["findPattern"] =
        sol::as_function([](const bool cache, const std::string& pat) // todo: depreacate?
                         { return Memory::Pattern(pat.c_str(), pat.size()).Search(cache).Get<int32_t>(); });

    package->fenv["safecall"] =
        sol::as_function([this](const sol::protected_function& f, sol::variadic_args va) -> sol::variadic_results {
            auto res = f(va);
            if (!res.valid())
            {
                const sol::error err = res;
                logger->error("safecall resulted in error: {}", err.what());
                return {};
            }

            return res;
        });

    try
    {

        Console::AddToLua(logger, package->fenv);
        auto game = package->fenv.create("game");
        sdk::Game::AddToLua(game); // todo: deprecate?

        {
            const auto assetPool = package->builtin.create("assetPool");
            game::AssetPool::AddToLua(assetPool);
        }

        {
            const auto graphics = package->builtin.create("graphics");
            sdk::Graphics::AddToLua(graphics);
        }

        lua.script(sdk->read("internal/bootstrapper.lua"), package->fenv, sol::script_throw_on_error, "bootstrapper");
        lua.script(sdk->read("library/base.lua"), package->fenv, sol::script_throw_on_error, "internal");

        package->fenv["currentMod"] = infoFs;

        package->builtin["events"] =
            lua.script(sdk->read("library/events.lua"), package->fenv, sol::script_throw_on_error, "built-in events");
        package->builtin["timers"] =
            lua.script(sdk->read("library/timers.lua"), package->fenv, sol::script_throw_on_error, "built-in timers");

        HookManager::AddLuaIntrinsics(package->fenv);
        package->builtin["memory"] =
            lua.script(sdk->read("library/memory.lua"), package->fenv, sol::script_throw_on_error, "built-in memory");
        HookManager::RemoveLuaIntrinsics(package->fenv);

        Config::AddLuaIntrinsics(package->fenv, info->GetID());
        package->builtin["config"] =
            lua.script(sdk->read("library/config.lua"), package->fenv, sol::script_throw_on_error, "built-in config");
        Config::RemoveLuaIntrinsics(package->fenv);

        LuaScriptRuntime::RemoveIntrinsics(package);
    }
    catch (std::exception& e)
    {
        logger->error("Failed to initialize Lua script base: {}", e.what());
        throw;
    }

    try
    {
        package->module = lua.script_file(fullPath.generic_string(), package->fenv, sol::script_throw_on_error);
    }
    catch (std::exception& e)
    {
        logger->error("Error in Lua script: {}", e.what());
        throw;
    }

    package->Finalize();

    lastMs = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch())
                 .count();
}

struct LuaUnloadEvent : IEvent<"_unload", LuaUnloadEvent>
{
};

void ModImplLua::OnDisabled()
{
    if (!package)
        return;

    auto runtime = LuaScriptRuntime::Get();
    auto& lua = runtime->GetLua();
    auto event = LuaUnloadEvent{};
    package->HandleEvent(LuaUnloadEvent::eventId, event);

    package->fenv.clear();
    runtime->RemovePackage(package->id);

    std::weak_ptr weak = package;
    package = nullptr;
    tick = std::nullopt;

    lua.collect_gc();
    lua.collect_gc();

    if (!weak.expired())
    {
        spdlog::error("Failed to unload Lua package {}. It still has {} references.", info->GetID(), weak.use_count());
        spdlog::error("To resolve this issue, make sure that your Lua script does not leave any subscribed "
                      "functions/values after unloading.");
        spdlog::error("When needed, unsubscribe values in an '_unload' event. See docs for more info.");
        ui::NotificationManager::Notify(
            std::format("Мод {} не был выгружен полностью. См. консоль для подробностей", info->GetID()));
    }
}

void ModImplLua::RenderUI()
{
    if (!package)
        return;
    try
    {
        auto render = package->fenv["renderUi"];
        if (render.is<sol::protected_function>())
            auto _ = render();
    }
    catch (std::exception& e)
    {
        logger->error("UI render error: {}", e.what());
    }
}

void ModImplLua::Render()
{
    if (!package)
        return;

    const uint64_t currMs =
        std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch())
            .count();

    if (currMs != lastMs && tick.has_value())
    {
        lastMs = currMs;
        try
        {
            auto _ = tick->call();
        }
        catch (std::exception& e)
        {
            logger->error("Timer error: {}", e.what());
        }
    }

    try
    {
        auto render = package->fenv["render"];
        if (render.is<sol::protected_function>())
            auto _ = render();
    }
    catch (std::exception& e)
    {
        logger->error("Render error: {}", e.what());
    }
}
} // namespace modloader
