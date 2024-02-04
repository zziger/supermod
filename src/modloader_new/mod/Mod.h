#pragma once

#include "states/ModState.h"
#include "ModImpl.h"
#include "info/ModInfo.h"
#include "info/ModInfoFilesystem.h"

namespace modloader
{
    class Mod {
        const std::shared_ptr<ModInfo> info;
        const std::unique_ptr<ModImpl> impl;

        bool enabled = false;
        std::unique_ptr<ModState> state;

    public:
        explicit Mod(std::shared_ptr<ModInfo> info, std::unique_ptr<ModImpl>&& impl);

        [[nodiscard]] bool IsEnabled() const { return enabled; }
        [[nodiscard]] bool IsActive() const { return state->IsActive(*this); }
        [[nodiscard]] std::shared_ptr<ModInfo> GetInfo() const { return info; }
        [[nodiscard]] const std::unique_ptr<ModState>& GetState() const { return state; }
        [[nodiscard]] const std::unique_ptr<ModImpl>& GetImpl() const { return impl; }

        void Toggle(const bool value) { enabled = value; }
        void SetState(std::unique_ptr<ModState>&& state);

        template <typename T>
        void SetState() { SetState(std::make_unique<T>()); }

        void Tick();
    };
}