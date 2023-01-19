#pragma once
#include <lua.hpp>

inline int lua_absindex (lua_State* L, int i) {
    if (i < 0 && i > LUA_REGISTRYINDEX)
        i += lua_gettop(L) + 1;
    return i;
}

inline int luaL_getsubtable (lua_State* L, int i, const char *name) {
    int abs_i = lua_absindex(L, i);
    luaL_checkstack(L, 3, "not enough stack slots");
    lua_pushstring(L, name);
    lua_gettable(L, abs_i);
    if (lua_istable(L, -1))
        return 1;
    lua_pop(L, 1);
    lua_newtable(L);
    lua_pushstring(L, name);
    lua_pushvalue(L, -2);
    lua_settable(L, abs_i);
    return 0;
}
    
inline void requiref (lua_State* L, const char *modname,
                                 lua_CFunction openf, int glb) {
    luaL_checkstack(L, 3, "not enough stack slots available");
    luaL_getsubtable(L, LUA_REGISTRYINDEX, "_LOADED");
    lua_getfield(L, -1, modname);
    if (lua_type(L, -1) == LUA_TNIL) {
        lua_pop(L, 1);
        lua_pushcfunction(L, openf);
        lua_pushstring(L, modname);
        lua_call(L, 1, 1);
        lua_pushvalue(L, -1);
        lua_setfield(L, -3, modname);
    }
    if (glb) {
        lua_pushvalue(L, -1);
        lua_setglobal(L, modname);
    }
    lua_replace(L, -2);
}