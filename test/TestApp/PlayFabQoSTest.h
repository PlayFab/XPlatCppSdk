// Copyright (C) Microsoft Corporation. All rights reserved.

#pragma once

#if defined(PLAYFAB_PLATFORM_WINDOWS) || defined(PLAYFAB_PLATFORM_XBOX)

#include <string>
#include "TestCase.h"

namespace PlayFabUnit
{
    struct TestContext;

    // A wrapper around TestEvents, so we can track it back to the test that launched the event
    class TestEvent : public PlayFab::PlayFabEvent
    {
    public:
        TestContext* testContext;
    };

    class PlayFabQoSTest : public PlayFabApiTestCase
    {
    private:

        void QosResultApi(TestContext& testContext);

    protected:
        void AddTests() override;

    public:
        void ClassSetUp() override;
        void SetUp(TestContext& /*testContext*/) override;
        void Tick(TestContext& testContext) override;
        void TearDown(TestContext& /*testContext*/) override;
        void ClassTearDown() override;
    };
}

#endif //defined(PLAYFAB_PLATFORM_WINDOWS) || defined(PLAYFAB_PLATFORM_XBOX)
