#pragma once
#include <modloader_new/mod/ModImpl.h>

namespace modloader
{
    class TestImpl final : public ModImpl {
    public:
        void OnEnabled() override;
        void OnDisabled() override;
        void OnTick() override;
    };
}
