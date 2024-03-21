#pragma once
#include <optional>

class RenderUnfocusedModule {
public:
    bool state = true;

    std::optional<uint32_t> windowEventHandler;

    void Init();
    void Render();

private:
    void OnLoad();
    void OnUnload();
};
