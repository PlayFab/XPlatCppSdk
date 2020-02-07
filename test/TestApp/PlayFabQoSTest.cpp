// Copyright (C) Microsoft Corporation. All rights reserved.

#include "TestAppPch.h"

#if defined(PLAYFAB_PLATFORM_WINDOWS) || defined(PLAYFAB_PLATFORM_XBOX)

#include <thread>
#include <chrono>
#include <playfab/PlayFabClientDataModels.h>
#include <playfab/PlayFabClientInstanceApi.h>
#include <playfab/PlayFabEventsDataModels.h>
#include <playfab/PlayFabEventsInstanceApi.h>
#include <playfab/PlayFabSettings.h>
#include <playfab/QoS/PlayFabQoSApi.h>
#include "PlayFabQoSTest.h"
#include "TestContext.h"
#include "TestDataTypes.h"

using namespace PlayFab;
using namespace ClientModels;
using namespace EventsModels;

namespace PlayFabUnit
{
#if (!UNITY_IOS && !UNITY_ANDROID) && (!defined(PLAYFAB_PLATFORM_IOS) && !defined(PLAYFAB_PLATFORM_ANDROID) && !defined(PLAYFAB_PLATFORM_SWITCH))
    /// QoS API
    void PlayFabQoSTest::QosResultApi(TestContext& testContext)
    {
        QoS::PlayFabQoSApi api;

        QoS::QoSResult result = api.GetQoSResult(5, 200);

        if (result.errorCode == 0)
        {
            testContext.Pass();
        }
        else
        {
            testContext.Fail("Error Code:" + std::to_string(result.errorCode));
        }
    }
#endif

    void PlayFabEventTest::AddTests()
    {
        // It is not appropriate for this test to block infinitely until the QoS result is returned
        // Not the least of which is because it frequently blocks forever
        // This needs to switch to the async mechanism, and allow the test to time out if QoS never completes
        // AddTest("QosResultApi", &PlayFabEventTest::QosResultApi);
    }

    void PlayFabEventTest::ClassSetUp()
    {
        // Make sure PlayFab state is clean.
        PlayFabSettings::ForgetAllCredentials();
    }

    void PlayFabEventTest::SetUp(TestContext& /*testContext*/)
    {
        PlayFabSettings::staticSettings->titleId = testTitleData.titleId;
    }

    void PlayFabEventTest::Tick(TestContext& /*testContext*/)
    {
        // No work needed, async tests will end themselves
    }

    void PlayFabEventTest::TearDown(TestContext& /*testContext*/)
    {
        // nothing to tear down
    }

    void PlayFabEventTest::ClassTearDown()
    {
        // Clean up any PlayFab state for next TestCase.
        PlayFabSettings::ForgetAllCredentials();
    }
}
#endif //defined(PLAYFAB_PLATFORM_WINDOWS) || defined(PLAYFAB_PLATFORM_XBOX)
