#include <async/task_completion_source.h>
#include <supermod/io/Async.hpp>

#include <supermod/events/EventManager.hpp>
#include <supermod/events/TickEvent.hpp>

void sm::io::Async::Initialize()
{
    mainThreadId = std::this_thread::get_id();
    EventManager::On<TickEvent>(Tick);
}

void sm::io::Async::Tick()
{
    std::queue<std::function<void()>> localQueue;

    {
        std::lock_guard lock(mutex);
        std::swap(localQueue, queue);
    }

    while (!localQueue.empty())
    {
        localQueue.front()();
        localQueue.pop();
    }
}

void sm::io::Async::Schedule(const std::function<void()>& callback)
{
    std::lock_guard lock(mutex);
    queue.push(callback);
}

void sm::io::Async::Schedule(std::function<void()>&& callback)
{
    std::lock_guard lock(mutex);
    queue.push(std::move(callback));
}

async::task<void> sm::io::Async::ToMain()
{
    const auto source = std::make_shared<async::task_completion_source<void>>();
    Schedule([=] { source->set_value(); });
    return source->task();
}

async::task<void> sm::io::Async::ToBackground()
{
    const auto source = std::make_shared<async::task_completion_source<void>>();
    std::thread([=] { source->set_value(); }).detach();
    return source->task();
}
async::task<void> sm::io::Async::Delay(std::chrono::milliseconds duration)
{
    const auto source = std::make_shared<async::task_completion_source<void>>();

    std::thread([=] {
        try
        {
            Sleep(duration.count());
            source->set_value();
        }
        catch (...)
        {
            source->set_exception(std::current_exception());
        }
    }).detach();

    return source->task();
}

bool sm::io::Async::IsMainThread()
{
    return std::this_thread::get_id() == mainThreadId;
}