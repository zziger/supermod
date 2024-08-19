#pragma once
#include <async/awaitable_get.h>
#include <async/task.h>

namespace sm::modloader
{
class ModSourceProvider
{
public:
    enum class Type
    {
        REGISTRY,
        ZIP
    };

    virtual ~ModSourceProvider() = default;
    virtual async::task<void> DiscoverMods(std::stop_token stopToken) = 0;
    [[nodiscard]] virtual std::string GetName() const = 0;
    [[nodiscard]] virtual Type GetType() const = 0;

    virtual bool Compare(const std::shared_ptr<ModSourceProvider>& other)
    {
        return this->GetType() == other->GetType() && this->GetName() == other->GetName();
    }
};
} // namespace sm::modloader