#pragma once
#include "lua.hpp"
#include <supermod/data.hpp>

void registerLuaTypes(sol::table lua)
{
    lua.new_usertype<vector2>("vector2", sol::call_constructor, sol::constructors<vector2(float, float)>(), "x",
                              &vector2::x, "y", &vector2::y);

    lua.new_usertype<vector3>("vector3", sol::call_constructor, sol::constructors<vector3(float, float, float)>(), "x",
                              &vector3::x, "y", &vector3::y, "z", &vector3::z);

    lua.new_usertype<rect>("rect", sol::call_constructor, sol::constructors<rect(float, float, float, float)>(), "left",
                           &rect::left, "top", &rect::top, "right", &rect::right, "bottom", &rect::bottom);

    lua.new_usertype<rgba>("rgba", sol::call_constructor, sol::constructors<rgba(uint8_t, uint8_t, uint8_t, uint8_t)>(),
                           "r", &rgba::r, "g", &rgba::g, "b", &rgba::b, "a", &rgba::a);
}