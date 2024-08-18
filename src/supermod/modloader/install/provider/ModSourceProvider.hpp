#pragma once
#include <async/awaitable_get.h>
#include <async/task.h>

namespace sm::modloader
{
class ModSourceProvider
{
public:
    virtual ~ModSourceProvider() = default;
    virtual async::task<void> DiscoverMods(std::stop_token stopToken) = 0;
    virtual std::string GetName() = 0;
};
} // namespace sm::modloader