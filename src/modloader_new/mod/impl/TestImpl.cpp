#include "TestImpl.h"

#include <Log.h>

void modloader::TestImpl::OnEnabled()
{
    Log::Info << "On enabled Impl" << Log::Endl;
}

void modloader::TestImpl::OnDisabled()
{
    Log::Info << "On disabled Impl" << Log::Endl;
}

void modloader::TestImpl::OnTick()
{
    Log::Info << "On tick" << Log::Endl;
}
