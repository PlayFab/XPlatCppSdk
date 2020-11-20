// Copyright (C) Microsoft Corporation. All rights reserved.

#include "TestAppPch.h"

#if defined(PLAYFAB_PLATFORM_WINDOWS) || defined(PLAYFAB_PLATFORM_XBOX)

#include <thread>
#include <chrono>
#include <playfab/PlayFabClientApi.h>
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
    void PlayFabQoSTest::QoSResultApi(TestContext& testContext)
    {
        LoginWithCustomIDRequest request;
        request.CustomId = PlayFabSettings::buildIdentifier;
        request.CreateAccount = true;

        std::atomic_bool isLoggedIn = false;

        PlayFabClientAPI::LoginWithCustomID(request,
            [&isLoggedIn](const LoginResult& loginResult, void*) {
                PlayFabSettings::staticPlayer->clientSessionTicket = loginResult.SessionTicket;
                isLoggedIn.exchange(true);
            },
            [&isLoggedIn](const PlayFabError&, void*) {
                isLoggedIn.exchange(true);
            },
                &testContext);

        while (!isLoggedIn) 
        {
            std::this_thread::sleep_for(std::chrono::milliseconds(1));
        }

        QoS::PlayFabQoSApi api;

        QoS::QoSResult result = api.GetQoSResult(5);

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

    void PlayFabQoSTest::AddTests()
    {
        // It is not appropriate for this test to block infinitely until the QoS result is returned
        // Not the least of which is because it frequently blocks forever if called within a callback.
        // TODO: This test cannot switch to an async mechanism until QoS is re-architected to allow such a calling scheme.
        AddTest("QosResultApi", &PlayFabQoSTest::QoSResultApi);
    }

    void PlayFabQoSTest::ClassSetUp()
    {
        // Make sure PlayFab state is clean.
        PlayFabSettings::ForgetAllCredentials();
    }

    void PlayFabQoSTest::SetUp(TestContext& /*testContext*/)
    {
        PlayFabSettings::staticSettings->titleId = testTitleData.titleId;
    }

    void PlayFabQoSTest::Tick(TestContext& /*testContext*/)
    {
        // No work needed, async tests will end themselves
    }

    void PlayFabQoSTest::TearDown(TestContext& /*testContext*/)
    {
        // nothing to tear down
    }

    void PlayFabQoSTest::ClassTearDown()
    {
        // Clean up any PlayFab state for next TestCase.
        PlayFabSettings::ForgetAllCredentials();
    }
}
#endif //defined(PLAYFAB_PLATFORM_WINDOWS) || defined(PLAYFAB_PLATFORM_XBOX)
