// Copyright (C) Microsoft Corporation. All rights reserved.

// This file is meant to be compiled into projects that do not have a useful/valid platform specific login.
// When present, add instead the platform specific file, and do NOT add this one

#include "TestAppPch.h"

#if !defined(DISABLE_PLAYFABCLIENT_API)

#include "TestContext.h"
#include <playfab/PlayFabApiSettings.h>
#include <playfab/PlayFabSettings.h>

#include "PlatformLoginTest.h"

using namespace PlayFab;
using namespace ClientModels;

namespace PlayFabUnit
{
    void OnErrorSharedCallback(const PlayFabError& error, void* customData)
    {
        TestContext* testContext = static_cast<TestContext*>(customData);
        testContext->Fail("Unexpected error: " + error.GenerateErrorReport());
    }

    void OnPlatformLogin(const LoginResult& result, void* customData)
    {
        TestContext* testContext = static_cast<TestContext*>(customData);
        testContext->Pass("Custom: " + result.PlayFabId);
    }

    // CLIENT API
    // Attempt a successful login
    void PlatformLoginTest::TestPlatformSpecificLogin(TestContext& testContext)
    {
        LoginWithCustomIDRequest request;
        request.CustomId = PlayFabSettings::buildIdentifier;
        request.CreateAccount = true;

        clientApi->LoginWithCustomID(request,
            OnPlatformLogin,
            OnErrorSharedCallback,
            &testContext);

    }

    void PlatformLoginTest::AddTests()
    {
        AddTest("TestPlatformSpecificLogin", &PlatformLoginTest::TestPlatformSpecificLogin);
        // Make sure PlayFab state is clean.
        PlayFabSettings::ForgetAllCredentials();
        PlayFabSettings::staticSettings->titleId = testTitleData.titleId;
    }

    void PlatformLoginTest::ClassSetUp()
    {
        clientApi = std::make_shared<PlayFabClientInstanceAPI>(PlayFabSettings::staticPlayer);
    }

    void PlatformLoginTest::SetUp(TestContext&)
    {
    }

    void PlatformLoginTest::Tick(TestContext&)
    {
    }

    void PlatformLoginTest::TearDown(TestContext&)
    {
    }

    void PlatformLoginTest::ClassTearDown()
    {
        // Clean up any PlayFab state for next TestCase.
        PlayFabSettings::ForgetAllCredentials();
    }
}

#endif
