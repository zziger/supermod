#include <supermod/modloader/install/ModInstallRequestDiscover.hpp>

namespace sm::modloader
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
} // namespace sm::modloader
