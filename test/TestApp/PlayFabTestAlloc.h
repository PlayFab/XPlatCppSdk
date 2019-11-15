// Copyright (C) Microsoft Corporation. All rights reserved.

#pragma once

#include "TestCase.h"

namespace PlayFabUnit
{
    class PlayFabTestAlloc : public TestCase
    {
    private:
        void TestApiSettingsAlloc(TestContext& testContext);
        void TestAuthContextAlloc(TestContext& testContext);

    protected:
        void AddTests() override;

    public:
        void Tick(TestContext& testContext) override;
    };
}
