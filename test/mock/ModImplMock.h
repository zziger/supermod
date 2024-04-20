#pragma once
#include <gmock/gmock.h>

class ModImplMock : public modloader::ModImpl {
public:
    MOCK_METHOD(void, OnEnabled, (), (override));
    MOCK_METHOD(void, OnDisabled, (), (override));
    MOCK_METHOD(void, OnTick, (), (override));
};
