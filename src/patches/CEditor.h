#pragma once
#include "CGameApis.h"
#include "Utils.h"
#include "module/IPatch.h"

class CEditor final : public IPatch {
public:
    void Load() override {
        IPatch::Load();
        CGameApis::ToggleEditor(true);
    }

    void Unload() override {
        IPatch::Unload();
        CGameApis::ToggleEditor(false);
    }

    std::string GetName() override {
        return "EDITOR";
    }
};