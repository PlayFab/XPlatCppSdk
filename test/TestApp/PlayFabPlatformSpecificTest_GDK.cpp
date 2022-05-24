// Copyright (C) Microsoft Corporation. All rights reserved.

#include "TestAppPch.h"

#include <playfab/PlayFabApiSettings.h>
#include <playfab/PlayFabAuthenticationContext.h>
#include <playfab/PlayFabClientApi.h>
#include <playfab/PlayFabClientDataModels.h>
#include <playfab/PlayFabSettings.h>

#include "TestContext.h"
#include "PlayFabPlatformSpecificTest.h"

// TODO: we SHOULD NOT NEED ANY includes for our work
//    this is a placeholder file for GDK testing.

namespace PlayFabUnit
{

    void OnSharedFailure(const PlayFab::PlayFabError& error, void* customData)
    {
        TestContext* testContext = static_cast<TestContext*>(customData);
        testContext->Fail(error.GenerateErrorReport());
    }

    void OnLoginSuccess(const PlayFab::ClientModels::LoginResult& result, void* customData)
    {
        TestContext* testContext = static_cast<TestContext*>(customData);
        testContext->Pass(result.PlayFabId);
    }

    void PlayFabPlatformSpecificTest::TestPlatformSpecificLogin(TestContext& testContext)
    {
        PlayFab::ClientModels::LoginWithCustomIDRequest loginRequest;
        loginRequest.CreateAccount = true;
        loginRequest.CustomId = "TestGdkLogin"; //TODO: can we pull some info directly from the test device?
        PlayFab::PlayFabClientAPI::LoginWithCustomID(loginRequest, OnLoginSuccess, OnSharedFailure, &testContext);
    }

    void PlayFabPlatformSpecificTest::AddTests()
    {
        AddTest("TestPlatformSpecificLogin", &PlayFabPlatformSpecificTest::TestPlatformSpecificLogin);
    }

    void PlayFabPlatformSpecificTest::ClassSetUp()
    {
        // TODO: should not need any set up for GDK (but are there any configurations we should be able to test?)
    }

    void PlayFabPlatformSpecificTest::SetUp(TestContext& /*testContext*/)
    {
        PlayFab::PlayFabSettings::staticSettings->titleId = testTitleData.titleId;
    }

    void PlayFabPlatformSpecificTest::Tick(TestContext& /*testContext*/)
    {
    }

    void PlayFabPlatformSpecificTest::TearDown(TestContext& /*testContext*/)
    {
        PlayFab::PlayFabSettings::staticSettings->titleId.clear();
    }

    void PlayFabPlatformSpecificTest::ClassTearDown()
    {
    }
}
