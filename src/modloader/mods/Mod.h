#pragma once
#include <filesystem>

#include "ModInfo.h"
#include "modloader/containers/ModuleContainer.h"
#include "modloader/mixins/EventUser.h"
#include "modloader/mixins/HookUser.h"
#include "modloader/mods/Module.h"

template <class ModuleType>
concept simple_module = std::derived_from<ModuleType, Module> && std::constructible_from<ModuleType> && requires { std::make_shared<ModuleType>(); };

class Mod : public HookUser, public EventUser {
    bool _enabled = false;
    
protected:
    std::shared_ptr<Module> AddModule(std::shared_ptr<Module> module);
    std::shared_ptr<Module> RemoveModule(std::shared_ptr<Module> module);

    template<simple_module... Modules> 
    void AddModules() {
        (AddModule(std::make_shared<Modules>()), ...);
    }
    
    virtual void OnEnable();
    virtual void OnDisable();

public:
    explicit Mod(ModInfo info);

    ModuleContainer modules;
    ModInfo info;
    const bool incompatibleSdk = false;
    std::optional<std::string> loadingError = std::nullopt;
    
    void Enable(bool manual);
    void Disable(bool manual);
    void Reload();
    void UnloadModule();
    bool IsEnabled() const;
    bool ShouldBeEnabled() const;

    virtual void EnsureEventType(const std::type_info* type, IAnyEvent& event) {}
    
    virtual void RenderUI();
    virtual void Render();
};

typedef std::shared_ptr<Mod> (*create_mod_fn)(ModInfo& info);