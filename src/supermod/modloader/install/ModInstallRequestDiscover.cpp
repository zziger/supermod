#include <supermod/modloader/install/ModInstallRequestDiscover.hpp>
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
