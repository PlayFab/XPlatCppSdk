// Copyright (C) Microsoft Corporation. All rights reserved.

#include "TestAppPch.h"

#if !defined(DISABLE_PLAYFABCLIENT_API)

#include <playfab/PlayFabApiSettings.h>
#include <playfab/PlayFabSettings.h>

#include <playfab/PlayFabClientInstanceApi.h>

#include "PlatformLoginTest.h"

using namespace PlayFab;
using namespace ClientModels;

namespace PlayFabUnit
{
    void PlatformLoginTest::OnErrorSharedCallback(const PlayFabError& error, void* customData)
    {
        TestContext* testContext = static_cast<TestContext*>(customData);
        testContext->Fail("Unexpected error: " + error.GenerateErrorReport());
    }

    // CLIENT API
    // Attempt a successful login
    void PlatformLoginTest::PlatformLogin(TestContext& testContext)
    {
        LoginWithCustomIDRequest request;
        request.CustomId = PlayFabSettings::buildIdentifier;
        request.CreateAccount = true;

        clientApi->LoginWithCustomID(request,
            Callback(&PlatformLoginTest::OnPlatformLogin),
            Callback(&PlatformLoginTest::OnErrorSharedCallback),
            &testContext);
    }
    void PlatformLoginTest::OnPlatformLogin(const LoginResult& /*result*/, void* customData)
    {
        TestContext* testContext = static_cast<TestContext*>(customData);
        testContext->Pass();
    }

    // Add test calls to this method, after implementation
    void PlatformLoginTest::AddTests()
    {
        AddTest("PlatformLogin", &PlatformLoginTest::PlatformLogin);
    }

    void PlatformLoginTest::ClassSetUp()
    {
        clientApi = std::make_shared<PlayFabClientInstanceAPI>(PlayFabSettings::staticPlayer);

        // Make sure PlayFab state is clean.
        PlayFabSettings::ForgetAllCredentials();

        PlayFabSettings::staticSettings->titleId = testTitleData.titleId;
    }

    void PlatformLoginTest::Tick(TestContext& /*testContext*/)
    {
        // No work needed, async tests will end themselves
    }

    void PlatformLoginTest::ClassTearDown()
    {
        // Clean up any PlayFab state for next TestCase.
        PlayFabSettings::ForgetAllCredentials();
    }
}

#endif
