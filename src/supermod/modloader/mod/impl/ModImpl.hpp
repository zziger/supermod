#pragma once

namespace sm::modloader
{
class ModImpl
{
public:
    virtual ~ModImpl() = default;

    virtual void OnEnabled() {}
    virtual void OnDisabled() {}
    virtual void OnTick() {}
    virtual void RenderUI() {}
    virtual void Render() {}
};
} // namespace sm::modloader