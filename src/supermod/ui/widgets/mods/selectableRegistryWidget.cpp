#include <supermod/pch.hpp>
#include <supermod/ui/widgets/widgets.hpp>

#include <imgui_internal.h>
#include <supermod/Utils.hpp>
#include <supermod/modloader/mod/states/ModState.hpp>
#include <supermod/ui/Ui.hpp>

bool sm::ui::widgets::mods::SelectableRegistry(const modloader::ModInfoRegistry& info, bool selected)
{

    ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(6, 6) * Ui::GetScalingFactor());
    ImGui::PushStyleVar(ImGuiStyleVar_ItemSpacing, ImVec2(6, 4) * Ui::GetScalingFactor());

    ImGui::PushID(info.GetID().c_str());

    const auto frameStart = ImGui::GetCursorScreenPos();
    const auto frameSize = ImVec2{0, 50 * Ui::GetScalingFactor()};

    const auto val =
        ImGui::Selectable("", selected, ImGuiSelectableFlags_NoPadWithHalfSpacing, {0, 50 * Ui::GetScalingFactor()});

    // if (ImGui::BeginPopupContextItem())
    {
        // ContextMenu(mod);
        // ImGui::EndPopup();
    }

    ImGui::SetCursorScreenPos(frameStart);

    // TODO: tooltips
    ImGui::BeginChild("Mod frame", ImGui::GetItemRectSize(), ImGuiChildFlags_AlwaysUseWindowPadding,
                      ImGuiWindowFlags_NoInputs);
    {
        const auto childStart = ImGui::GetCursorScreenPos();
        const auto drawList = ImGui::GetWindowDrawList();
        auto limitX = childStart.x + ImGui::GetContentRegionAvail().x;

        {
            ImGui::BeginGroup();
            {
                Ui::PushFont(20);

                // Removal pending icon
                if (!info.verified)
                {
                    const auto icon = ICON_MD_SAFETY_CHECK;
                    const auto iconSize = ImGui::CalcTextSize(icon);
                    limitX -= iconSize.x;
                    ImGui::SetCursorScreenPos({limitX, frameStart.y + (frameSize.y - iconSize.y) / 2.f});
                    ImGui::TextColored(0xeebe77FF_color, "%s", icon);

                    limitX -= 3 * Ui::GetScalingFactor();
                }

                Ui::PopFont();
            }
            ImGui::EndGroup();
        }

        // Mod icon
        ImGui::SetCursorScreenPos(childStart);
        ImGui::Dummy({Ui::ScaledPx(38), Ui::ScaledPx(38)});
        ImGui::GetWindowDrawList()->AddRectFilled(ImGui::GetItemRectMin(), ImGui::GetItemRectMax(), 0x22FFFFFF);
        if (info.icon)
            info.icon->Draw(ImGui::GetWindowDrawList(), ImGui::GetItemRectMin(), ImGui::GetItemRectMax(), 0xFFFFFFFF);
        ImGui::SameLine(0, Ui::ScaledPx(10));

        ImGui::BeginGroup();
        {
            auto versionStr = info.version.str();

            const auto lowerLine = utils::trim(versionStr + " " + info.author);
            if (lowerLine.empty())
                ImGui::Dummy({Ui::ScaledPx(1), Ui::ScaledPx(6)});

            // Mod label
            Ui::PushFont(18);
            {
                const auto lh = ImGui::GetTextLineHeight();
                const auto min = ImGui::GetCursorScreenPos();
                const auto max = ImVec2(limitX, min.y + lh * 1.5f);
                ImGui::RenderTextEllipsis(drawList, min, max, max.x, max.x, info.title.c_str(), nullptr, nullptr);
                ImGui::Text("");
                Tooltip(info.title.c_str(), ImGuiHoveredFlags_DelayNormal);
            }
            Ui::PopFont();

            // Mod version and author
            if (!lowerLine.empty())
            {
                Ui::PushFont(16);
                {
                    const auto lh = ImGui::GetTextLineHeight();
                    const auto min = ImGui::GetCursorScreenPos();
                    const auto max = ImVec2(limitX, min.y + lh * 1.5f);
                    ImGui::RenderTextEllipsis(drawList, min, max, max.x, max.x, lowerLine.c_str(), nullptr, nullptr);
                    ImGui::Text(" ");
                    widgets::Tooltip(lowerLine.c_str(), ImGuiHoveredFlags_DelayNormal);
                }
                Ui::PopFont();
            }
        }
        ImGui::EndGroup();
    }
    ImGui::EndChild();

    ImGui::PopID();
    ImGui::PopStyleVar(2);

    return val;
}