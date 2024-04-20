#include "TestImpl.h"

#include <spdlog/spdlog.h>

void modloader::TestImpl::OnEnabled()
{
    spdlog::debug("ModTestImpl {} was enabled", info->GetID());
}

void modloader::TestImpl::OnDisabled()
{
    spdlog::debug("ModTestImpl {} was disabled", info->GetID());
}

void modloader::TestImpl::OnTick()
{
}
