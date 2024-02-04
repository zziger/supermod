#include "ModStateDisabled.h"

#include <Log.h>

#include "ModStateEnabled.h"
#include "ModStateWaitingDependenciesLoad.h"
#include "../Mod.h"

void modloader::ModStateDisabled::Init(Mod& mod)
{
    mod.GetImpl()->OnDisabled();
}

void modloader::ModStateDisabled::Update(Mod& mod)
{
    if (!mod.IsEnabled()) return;
    mod.SetState<ModStateWaitingDependenciesLoad>();
}
