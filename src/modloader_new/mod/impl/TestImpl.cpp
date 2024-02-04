#include "TestImpl.h"

#include <Log.h>

void modloader::TestImpl::OnEnabled()
{
    Log::Info << "On enabled Impl " << info->id << Log::Endl;
}

void modloader::TestImpl::OnDisabled()
{
    Log::Info << "On disabled Impl" << info->id << Log::Endl;
}

void modloader::TestImpl::OnTick()
{
    Log::Info << "On tick" << info->id << Log::Endl;
}
