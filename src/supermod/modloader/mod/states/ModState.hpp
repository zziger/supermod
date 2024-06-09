#pragma once
#include <supermod/pch.hpp>

#include <imgui.h>
#include <supermod/Utils.hpp>

namespace modloader
{
class Mod;

class ModState
{
public:
    virtual ~ModState() = default;

    enum class Type
    {
        DISABLED,
        ENABLED,
        WAITING_DEPENDENCIES_LOAD,
        WAITING_DEPENDENTS_UNLOAD,
    };

    virtual bool IsActive() { return false; }

    virtual void Init(Mod& mod) {}

    virtual Type GetType() = 0;

    virtual std::string GetLabel() = 0;
    virtual std::string GetIcon() = 0;
    virtual ImVec4 GetColor() { return IsActive() ? 0x77EE77FF_color : 0xEE7777FF_color; };

    virtual void Update(Mod& mod) = 0;
};
} // namespace modloader