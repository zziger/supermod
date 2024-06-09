#include "ModInstallRequestDiscover.h"

namespace modloader
{
void ModInstallRequestDiscover::Install()
{
    mod->Toggle(true);
    finished = true;
}

void ModInstallRequestDiscover::Cancel()
{
    finished = true;
}
} // namespace modloader
