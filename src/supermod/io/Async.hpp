#pragma once
#include <supermod/pch.hpp>

#include <async/task.h>
#include <queue>

namespace sm::io
{
class Async
{
    static inline std::mutex mutex{};
    static inline std::queue<std::function<void()>> queue{};
    static inline std::thread::id mainThreadId{};
    static void Tick();

public:
    static void Initialize();

    static void Schedule(const std::function<void()>& callback);
    static void Schedule(std::function<void()>&& callback);

    static async::task<void> ToMain();
    static async::task<void> ToBackground();
    static async::task<void> Delay(std::chrono::milliseconds duration);

    static bool IsMainThread();
};
} // namespace sm::io