#pragma once
#include <gmock/gmock.h>
#include <supermod/modloader/mod/Mod.hpp>

class ModImplMock : public sm::modloader::ModImpl
{
public:
    MOCK_METHOD(void, OnEnabled, (), (override));
    MOCK_METHOD(void, OnDisabled, (), (override));
    MOCK_METHOD(void, OnTick, (), (override));
};
