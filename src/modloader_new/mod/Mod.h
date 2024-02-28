#pragma once

#include "states/ModState.h"
#include "ModImpl.h"
#include "info/ModInfo.h"
#include "info/ModInfoFilesystem.h"

namespace modloader
{
    class Mod {
    public:
        enum class Flag : uint8_t
        {
            ENABLED = 0b1 << 0,
            REMOVAL_SCHEDULED = 0b1 << 1,
            REMOVE_WITH_FILES = 0b1 << 2
        };

    private:

        const std::shared_ptr<ModInfo> info;
        const std::unique_ptr<ModImpl> impl;

        uint8_t flags = 0;
        std::unique_ptr<ModState> state;

    public:
        explicit Mod(std::shared_ptr<ModInfo> info, std::unique_ptr<ModImpl>&& impl);

        [[nodiscard]] bool IsActive() const { return state->IsActive(*this); }
        [[nodiscard]] std::shared_ptr<ModInfo> GetInfo() const { return info; }
        [[nodiscard]] const std::unique_ptr<ModState>& GetState() const { return state; }
        [[nodiscard]] const std::unique_ptr<ModImpl>& GetImpl() const { return impl; }
        [[nodiscard]] std::string GetID() const { return info->GetID(); }

        void SetState(std::unique_ptr<ModState>&& state);

        template <typename T>
        void SetState() { SetState(std::make_unique<T>()); }

        void SetFlag(Flag flag, const bool value = true)
        {
            if (value) flags |= static_cast<uint8_t>(flag);
            else flags &= ~static_cast<uint8_t>(flag);
        }
        void ClearFlag(const Flag flag) { SetFlag(flag, false); }
        [[nodiscard]] bool HasFlag(const Flag flag) const { return (flags & static_cast<uint8_t>(flag)) != 0; }

        [[nodiscard]] bool IsEnabled() const { return HasFlag(Flag::ENABLED); }
        void Toggle(const bool value) { SetFlag(Flag::ENABLED, value); }

        void Tick();
    };
}