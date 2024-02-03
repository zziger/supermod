#pragma once
#include <memory>
#include <string>

namespace modloader
{
    class Mod;

    class ModState {
    public:
        virtual ~ModState() = default;

        virtual bool IsActive(const Mod& mod)
        {
            return false;
        }

        virtual void Init(Mod& mod)
        {
        }

        virtual std::string GetLabel() = 0;

        virtual void Update(Mod& mod) = 0;
    };
}