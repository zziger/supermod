#pragma once
#include <async/awaitable_then.h>
#include <async/task_completion_source.h>
#include <cpr/cpr.h>
#include <memory>
#include <nlohmann/detail/meta/std_fs.hpp>
#include <nlohmann/json.hpp>
#include <supermod/exceptions/Error.hpp>

namespace sm::io
{
class Http
{
public:
    static async::task<std::tuple<nlohmann::json, cpr::Response>> ToJson(async::task<cpr::Response>&& task)
    {
        const auto source =
            std::make_shared<async::task_completion_source<std::tuple<nlohmann::json, cpr::Response>>>();
        async::awaitable_then(std::move(task), [=](async::awaitable_result<cpr::Response> response) {
            try
            {
                const auto value = response();
                if (value.header.contains("Content-Type"))
                {
                    const auto contentType = value.header.at("Content-Type");
                    if (!contentType.starts_with("application/json"))
                    {
                        throw Error("Invalid content-type: " + contentType);
                    }
                }

                source->set_value(std::make_tuple(nlohmann::json::parse(value.text), value));
            }
            catch (...)
            {
                source->set_exception(std::current_exception());
            }
        });
        return source->task();
    }

    template <typename... Ts>
    static async::task<cpr::Response> Download(const std::shared_ptr<std::ofstream>& file, Ts&&... args)
    {
        const auto source = std::make_shared<async::task_completion_source<cpr::Response>>();

        std::thread([=, ... args = std::move(args)]() mutable {
            FillSource(source, cpr::Download<Ts...>(*file, std::move(args)...));
        }).detach();
        return source->task();
    }

    template <typename... Ts>
    static async::task<cpr::Response> Get(Ts&&... args)
    {
        const auto source = std::make_shared<async::task_completion_source<cpr::Response>>();

        std::thread([=] { FillSource(source, cpr::Get(args...)); }).detach();
        return source->task();
    }

    template <typename... Ts>
    static async::task<std::tuple<nlohmann::json, cpr::Response>> GetJson(Ts&&... args)
    {
        return ToJson(Get(std::forward<Ts>(args)...));
    }

    template <typename... Ts>
    static async::task<cpr::Response> Post(Ts&&... args)
    {
        const auto source = std::make_shared<async::task_completion_source<cpr::Response>>();

        std::thread([=] { FillSource(source, cpr::Post(args...)); }).detach();
        return source->task();
    }

    template <typename... Ts>
    static async::task<std::tuple<nlohmann::json, cpr::Response>> PostJson(Ts&&... args)
    {
        return ToJson(Post(std::forward<Ts>(args)...));
    }

private:
    static void FillSource(const std::shared_ptr<async::task_completion_source<cpr::Response>>& source,
                           const cpr::Response& response)
    {
        if (response.status_code / 100 == 2)
            source->set_value(response);
        else
            source->set_exception(std::make_exception_ptr(
                NetworkError(response.status_code, response.text.empty() ? response.error.message : response.text)));
    }
};
} // namespace sm::io