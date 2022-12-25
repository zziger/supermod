#pragma once
#include "modloader/mods/ModInfo.h"
#include "modloader/mixins/EventUser.h"
#include "modloader/mixins/HookUser.h"

class Module : public HookUser, public EventUser {
    bool _loaded = false;
    
protected:
    Module(std::string id, std::string name, bool defaultLoaded = false);

    virtual void OnLoad() {}
    virtual void OnUnload() {}
    
public:
    std::string fullId;
    const std::string id;
    const std::string name;
    const bool defaultLoaded;

    virtual void RenderUI() {}
    
    void Load(bool manual);
    void Unload(bool manual);
    bool IsLoaded() const;
    bool ShouldBeLoaded() const;

    ModInfo owner {};
    void SetOwner(ModInfo);
};
