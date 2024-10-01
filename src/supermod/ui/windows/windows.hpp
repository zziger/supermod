#pragma once

namespace sm::ui::windows
{
void DropTarget();
void Installer();
void Boot();
void Watermark();
void Main();
void TextureViewer();
void AnimationViewer();
void ModelViewer();
void PublishMod();

struct WindowsState
{
    static inline std::string publishModID = "";
    static inline bool publishModOpened = false;
};
} // namespace sm::ui::windows