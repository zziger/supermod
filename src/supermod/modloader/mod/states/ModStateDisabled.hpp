#pragma once
#include <IconsMaterialDesign.h>
#include <supermod/modloader/mod/states/ModState.hpp>

namespace sm::modloader
{
class ModStateDisabled final : public ModState
{
public:
    void Init(Mod& mod) override;
    void Update(Mod& mod) override;
    Type GetType() override { return Type::DISABLED; }
    std::string GetLabel() override { return "Выключен"; }
    std::string GetIcon() override { return ICON_MD_RADIO_BUTTON_UNCHECKED; }
};
} // namespace sm::modloader