#pragma once

namespace modloader
{
    class ModImpl {
    public:
        virtual ~ModImpl() = default;

        virtual void OnEnabled() = 0;
        virtual void OnDisabled() = 0;
        virtual void OnTick() = 0;
    };
}