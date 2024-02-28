#pragma once
#include <modloader_new/mod/info/ModInfo.h>
#include <modloader_new/mod/ModImpl.h>


namespace modloader
{
    class TestImpl final : public ModImpl {
        std::shared_ptr<ModInfo> info;

    public:
        explicit TestImpl(std::shared_ptr<ModInfo> info) : info(std::move(info)) {}

        void OnEnabled() override;
        void OnDisabled() override;
        void OnTick() override;
    };
}
