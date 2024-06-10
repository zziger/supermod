#include <supermod/ui/NotificationManager.hpp>

#include <IconsMaterialDesign.h>
#include <imgui.h>
#include <imgui_internal.h>
#include <spdlog/spdlog.h>
#include <supermod/ui/Ui.hpp>

namespace sm::ui
{
std::string Notification::GetHeaderText() const
{
    if (!header.empty())
        return header;

    switch (level)
    {
    case ERR:
        return "Ошибка";
    case WARN:
        return "Внимание";
    default:
        return "Информация";
    }
}

std::tuple<std::string, ImVec4> Notification::GetIcon() const
{
    switch (level)
    {
    case ERR:
        return std::tuple{ICON_MD_ERROR_OUTLINE, ImVec4(1.0f, 0.0f, 0.0f, 1.0f)};
    case WARN:
        return std::tuple{ICON_MD_WARNING, ImVec4(1.0f, 1.0f, 0.0f, 1.0f)};
    default:
        return std::tuple{ICON_MD_INFO_OUTLINE, ImVec4(0.5f, 0.5f, 1.0f, 1.0f)};
    }
}

void NotificationManager::Update(const int updateCount)
{
    for (auto i = 0; i < updateCount; i++)
        notifications[i]->state += ImGui::GetIO().DeltaTime;

    notifications.erase(
        std::ranges::remove_if(notifications, [](const auto& notification) { return notification->state >= duration; })
            .begin(),
        notifications.end());
}

void NotificationManager::Render()
{
    std::lock_guard lock(mutex);

    static constexpr float VERTICAL_PADDING = 10.f;
    static constexpr float HORIZONTAL_PADDING = 15.f;

    const auto viewport = ImGui::GetMainViewport();
    bool hovered = false;
    bool clicked = false;
    float y = viewport->Pos.y + viewport->Size.y - Ui::ScaledPx(VERTICAL_PADDING);

    int i = 0;
    for (; i < notifications.size(); i++)
    {
        if (y - viewport->Pos.y < Ui::ScaledPx(100))
            break;

        auto notification = notifications[i];
        auto width = Ui::ScaledPx(250);

        auto windowName = std::format("Уведомление###Notification {}", i);
        ImGui::SetNextWindowSize({width, 0}, ImGuiCond_Always);
        ImGui::SetNextWindowPos({viewport->Pos.x + viewport->Size.x - Ui::ScaledPx(HORIZONTAL_PADDING), y},
                                ImGuiCond_Always, {1, 1});
        ImGui::Begin(windowName.c_str(), nullptr,
                     ImGuiWindowFlags_NoDecoration | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoResize |
                         ImGuiWindowFlags_AlwaysAutoResize | ImGuiWindowFlags_NoSavedSettings |
                         ImGuiWindowFlags_NoFocusOnAppearing | ImGuiWindowFlags_NoNav | ImGuiWindowFlags_NoDocking);
        {
            ImGui::BringWindowToDisplayFront(ImGui::GetCurrentWindow());
            auto startPos = ImGui::GetCursorPosX();
            auto [icon, color] = notification->GetIcon();
            ImGui::TextColored(color, "%s", icon.c_str());
            ImGui::SameLine();
            auto iconWidth = ImGui::GetCursorPosX() - startPos;
            ImGui::PushTextWrapPos(width - iconWidth - startPos * 2);
            ImGui::Text(notification->GetHeaderText().c_str());
            ImGui::PopTextWrapPos();

            ImGui::Spacing();
            ImGui::Separator();
            ImGui::Spacing();
            ImGui::PushTextWrapPos(width - startPos * 2);
            ImGui::Text(notification->message.c_str());
            ImGui::PopTextWrapPos();

            auto lineHeight = Ui::ScaledPx(2);
            const auto fill = notification->state / duration;
            const auto borderSize = ImGui::GetStyle().WindowBorderSize;
            ImGui::Dummy({1, lineHeight});
            auto min = ImVec2(borderSize, ImGui::GetWindowSize().y - lineHeight) + ImGui::GetWindowPos();
            auto max =
                ImGui::GetWindowSize() * ImVec2(fill, 1) + ImGui::GetWindowPos() - ImVec2(borderSize, borderSize);
            ImGui::PushClipRect(min, max, false);
            const auto drawList = ImGui::GetWindowDrawList();
            drawList->AddRectFilled(min, max, IM_COL32(255, 255, 255, 255));
            ImGui::PopClipRect();

            y -= ImGui::GetWindowHeight() + VERTICAL_PADDING;
            if (ImGui::IsWindowHovered())
                hovered = true;
            if (ImGui::IsWindowHovered() && ImGui::IsMouseClicked(ImGuiMouseButton_Left))
            {
                if (notification->onClick)
                    notification->onClick();
                notification->state = duration;
                clicked = true;
            }
        }
        ImGui::End();
    }

    if (!hovered || clicked)
        Update(i);
}

void NotificationManager::Notify(const std::string& message, const Notification::Type level, const std::string& header)
{
    std::lock_guard lock(mutex);
    notifications.push_back(std::make_shared<Notification>(Notification{lastId++, level, message, header}));

    auto logLevel = spdlog::level::info;
    if (level == Notification::ERR)
        logLevel = spdlog::level::err;
    else if (level == Notification::WARN)
        logLevel = spdlog::level::warn;
    spdlog::log(logLevel, "Notification: {} {}", message, !header.empty() ? std::format("({})", header) : "");
}
} // namespace sm::ui
