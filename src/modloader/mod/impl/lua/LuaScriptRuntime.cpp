#include "LuaScriptRuntime.h"

void modloader::LuaScriptRuntime::ModPackage::Finalize()
{
    eventHandler = fenv["__handleEvent"];
    fenv["__handleEvent"] = sol::lua_nil;
}

void modloader::LuaScriptRuntime::ModPackage::RegisterLuaType(sol::state& lua)
{
    lua.new_usertype<ModPackage>(sol::no_constructor, "id", sol::readonly(&ModPackage::id), "fenv",
                                 sol::readonly(&ModPackage::fenv), "loaded", sol::readonly(&ModPackage::loaded),
                                 "builtin", sol::readonly(&ModPackage::builtin), "module",
                                 sol::readonly(&ModPackage::module), "path", sol::readonly(&ModPackage::path), "cpath",
                                 sol::readonly(&ModPackage::cpath));
}

void modloader::LuaScriptRuntime::Init()
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
    VersionRange::RegisterLuaType(lua);
    ModPackage::RegisterLuaType(lua);
    game::Asset::RegisterLuaType(lua);
    ModInfo::RegisterLuaType(lua);
    ModInfoFilesystem::RegisterLuaType(lua);

    lua.globals()["require"]("ffi"); // preload FFI

    const auto sdk = utils::read_zip_resource(LUA_SDK_ZIP);
    get_packages(lua)["util"] = lua.script(sdk->read("library/util.lua"), "built-in util", sol::load_mode::text);
    lua.script(sdk->read("library/imguicdecl.lua"), "imgui cdef", sol::load_mode::text);
    get_packages(lua)["imgui"] = lua.script(sdk->read("library/imgui.lua"), "built-in imgui", sol::load_mode::text);

    lua.globals()["require"] = sol::lua_nil; // We reimplement require in fenvs. Having it in global scope might lead to
                                             // some weird nondebuggable bugs
}

std::shared_ptr<modloader::LuaScriptRuntime::ModPackage> modloader::LuaScriptRuntime::CreatePackage(
    const std::string& id, const std::filesystem::path& root)
{
    assert(!packages.contains(id) && "Package with this id already exists");

    auto package = std::make_shared<ModPackage>(id, root, shared_from_this());
    luaPackages[id] = package;
    packages[id] = package;
    AddIntrinsics(package);
    return package;
}

void modloader::LuaScriptRuntime::RemovePackage(const std::string& id)
{
    luaPackages[id] = sol::lua_nil;
    packages.erase(id);
}

void modloader::LuaScriptRuntime::AddIntrinsics(const std::shared_ptr<ModPackage>& package)
{
    auto env = package->fenv;

    env["__modPackages"] = luaPackages;
    env["__currentModId"] = package->id;
    env["__enableEvent"] = sol::bind_instance(&ModPackage::EnableEvent, package);
    env["__disableEvent"] = sol::bind_instance(&ModPackage::DisableEvent, package);
}

void modloader::LuaScriptRuntime::RemoveIntrinsics(const std::shared_ptr<ModPackage>& package)
{
    auto env = package->fenv;

    env["__modPackages"] = sol::nil;
    env["__currentModId"] = sol::nil;
    env["__enableEvent"] = sol::nil;
    env["__disableEvent"] = sol::nil;
}
