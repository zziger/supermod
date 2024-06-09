#pragma once
#include <supermod/pch.hpp>

#include <supermod/modloader/mod/impl/ModImpl.hpp>
#include <supermod/modloader/mod/info/ModInfo.hpp>
#include <supermod/modloader/mod/states/ModState.hpp>

namespace modloader
{
class Mod
{
public:
    enum class Flag : uint8_t
    {
        ENABLED = 0b1 << 0,
        REMOVAL_SCHEDULED = 0b1 << 1,
        REMOVE_WITH_FILES = 0b1 << 2,
        INTERNAL = 0b1 << 3,
        EXISTS = 0b1 << 4,
        UPDATE_SCHEDULED = 0b1 << 5
    };

private:
    std::shared_ptr<ModInfo> info;
    const std::unique_ptr<ModImpl> impl;

    uint8_t flags = 0;
    std::unique_ptr<ModState> state;
    std::chrono::time_point<std::chrono::steady_clock> creationTime = std::chrono::steady_clock::now();
    std::chrono::time_point<std::chrono::steady_clock> lastStateUpdate = std::chrono::steady_clock::now();
    std::string loadingError;

public:
    explicit Mod(std::shared_ptr<ModInfo> info, std::unique_ptr<ModImpl>&& impl);

    [[nodiscard]] bool IsActive() const { return state->IsActive(); }
    [[nodiscard]] std::shared_ptr<ModInfo> GetInfo() const { return info; }
    [[nodiscard]] const std::unique_ptr<ModState>& GetState() const { return state; }
    [[nodiscard]] std::chrono::duration<double, std::micro> GetTimeSinceUpdate() const
    {
        return std::chrono::steady_clock::now() - lastStateUpdate;
    }
    [[nodiscard]] const std::unique_ptr<ModImpl>& GetImpl() const { return impl; }
    [[nodiscard]] std::string GetID() const { return info->GetID(); }

    void SetInfo(const std::shared_ptr<ModInfo>& newInfo);
    void SetState(std::unique_ptr<ModState>&& state);

    template <typename T, typename... Args>
    void SetState(Args&&... args)
    {
        SetState(std::make_unique<T>(std::forward<Args>(args)...));
    }

    void SetLoadingError(const std::string& err) { loadingError = err; }
    [[nodiscard]] std::string GetLoadingError() const { return loadingError; }

    void SetFlag(Flag flag, const bool value = true)
    {
        if (value)
            flags |= static_cast<uint8_t>(flag);
        else
            flags &= ~static_cast<uint8_t>(flag);
    }
    void ClearFlag(const Flag flag) { SetFlag(flag, false); }
    [[nodiscard]] bool HasFlag(const Flag flag) const { return (flags & static_cast<uint8_t>(flag)) != 0; }

    [[nodiscard]] bool IsEnabled() const { return HasFlag(Flag::ENABLED); }
    void Toggle(const bool value);

    void Update();
    void Tick() const;
};
} // namespace modloader