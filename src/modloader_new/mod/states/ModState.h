#pragma once
#include <memory>
#include <string>

namespace modloader
{
    class Mod;

    class ModState {
    public:
        virtual ~ModState() = default;

        enum class Type
        {
            DISABLED,
            ENABLED,
            WAITING_DEPENDENCIES_LOAD,
            WAITING_DEPENDANTS_UNLOAD,
        };

        virtual bool IsActive(const Mod& mod)
        {
            return false;
        }

        virtual void Init(Mod& mod)
        {
        }

        virtual Type GetType() = 0;

        virtual std::string GetLabel() = 0;

        virtual void Update(Mod& mod) = 0;
    };
}