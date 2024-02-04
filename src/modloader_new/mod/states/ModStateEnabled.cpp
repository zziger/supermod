#include "ModStateEnabled.h"

#include <Log.h>

#include "ModStateDisabled.h"
#include "ModStateWaitingDependantsUnload.h"
#include "../Mod.h"

void modloader::ModStateEnabled::Init(Mod& mod)
{
    mod.GetImpl()->OnEnabled();
}

void modloader::ModStateEnabled::Update(Mod& mod)
{
    if (mod.IsEnabled()) return;
    mod.SetState<ModStateWaitingDependantsUnload>();
}
