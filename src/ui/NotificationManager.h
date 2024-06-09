#pragma once
#include <functional>
#include <imgui.h>
#include <memory>
#include <mutex>
#include <string>
#include <vector>

namespace ui
{
struct Notification
{
    enum Type
    {
        INFO,
        WARN,
        ERR
    };

    int id;
    Type level = INFO;
    std::string message;
    std::string header;
    float state = 0.0f;
    std::function<void()> onClick;

    [[nodiscard]] std::string GetHeaderText() const;
    [[nodiscard]] std::tuple<std::string, ImVec4> GetIcon() const;
};

class NotificationManager
{
    static constexpr int MAX_NOTIFICATIONS = 5;
    static inline std::mutex mutex{};
    static inline std::vector<std::shared_ptr<Notification>> notifications{};
    static inline int lastId = 0;
    static inline float duration = 5.0f;

    static void Update(int updateCount);

public:
    static void Render();
    static void Notify(const std::string& message, Notification::Type level = Notification::ERR,
                       const std::string& header = "");
};
} // namespace ui
