// Copyright (C) Microsoft Corporation. All rights reserved.

#include "TestAppPch.h"

#ifndef DISABLE_PLAYFABCLIENT_API

#include <playfab/PlayFabClientInstanceApi.h>
#include <playfab/PlayFabSettings.h>
#include "TestContext.h"
#include "PlayFabTestMultiUserInstance.h"

using namespace PlayFab;
using namespace ClientModels;

namespace PlayFabUnit
{
    /// <summary>
    /// CLIENT API
    /// Try to log in two users simultaneously using instance APIs.
    /// </summary>
    void PlayFabTestMultiUserInstance::MultiUserLogin1Success(const LoginResult& result, void* customData)
    {
        GetPlayerProfileRequest profileRequest;
        profileRequest.authenticationContext = result.authenticationContext;

        const auto& user1ProfileSuccess = std::bind(&PlayFabTestMultiUserInstance::MultiUserProfile1Success, this, std::placeholders::_1, std::placeholders::_2);
        const auto& user1ProfileFailure = std::bind(&PlayFabTestMultiUserInstance::MultiUserProfile1Failure, this, std::placeholders::_1, std::placeholders::_2);
        multiUser1ClientApi->GetPlayerProfile(profileRequest, user1ProfileSuccess, user1ProfileFailure, customData);
    }
    void PlayFabTestMultiUserInstance::MultiUserLogin1Failure(const PlayFabError& error, void* /*customData*/)
    {
        multiUser1Error = "Failed to log in user 1: " + error.GenerateErrorReport();
        thread1Complete = true;
    }
    void PlayFabTestMultiUserInstance::MultiUserProfile1Success(const GetPlayerProfileResult& /*result*/, void* /*customData*/)
    {
        thread1Complete = true;
    }
    void PlayFabTestMultiUserInstance::MultiUserProfile1Failure(const PlayFabError& error, void* /*customData*/)
    {
        multiUser1Error = "Failed to get user 1 profile: " + error.GenerateErrorReport();
        thread1Complete = true;
    }

    void PlayFabTestMultiUserInstance::MultiUserLogin2Success(const LoginResult& result, void* customData)
    {
        GetPlayerProfileRequest profileRequest;
        profileRequest.authenticationContext = result.authenticationContext;

        const auto& user2ProfileSuccess = std::bind(&PlayFabTestMultiUserInstance::MultiUserProfile2Success, this, std::placeholders::_1, std::placeholders::_2);
        const auto& user2ProfileFailure = std::bind(&PlayFabTestMultiUserInstance::MultiUserProfile2Failure, this, std::placeholders::_1, std::placeholders::_2);
        multiUser2ClientApi->GetPlayerProfile(profileRequest, user2ProfileSuccess, user2ProfileFailure, customData);
    }
    void PlayFabTestMultiUserInstance::MultiUserLogin2Failure(const PlayFabError& error, void* /*customData*/)
    {
        multiUser2Error = "Failed to log in user 2: " + error.GenerateErrorReport();
        thread2Complete = true;
    }
    void PlayFabTestMultiUserInstance::MultiUserProfile2Success(const GetPlayerProfileResult& /*result*/, void* /*customData*/)
    {
        thread2Complete = true;
    }
    void PlayFabTestMultiUserInstance::MultiUserProfile2Failure(const PlayFabError& error, void* /*customData*/)
    {
        multiUser2Error = "Failed to get user 2 profile: " + error.GenerateErrorReport();
        thread2Complete = true;
    }

    void PlayFabTestMultiUserInstance::MultiUserLogin(TestContext& testContext)
    {
        // Step 1: Log in two Users simultaneously.
        LoginWithCustomIDRequest user1LoginRequest;
        user1LoginRequest.CustomId = "test_MultiInstance1";
        user1LoginRequest.CreateAccount = true;

        const auto& user1LoginSuccess = std::bind(&PlayFabTestMultiUserInstance::MultiUserLogin1Success, this, std::placeholders::_1, std::placeholders::_2);
        const auto& user1LoginFailure = std::bind(&PlayFabTestMultiUserInstance::MultiUserLogin1Failure, this, std::placeholders::_1, std::placeholders::_2);
        multiUser1ClientApi->LoginWithCustomID(user1LoginRequest, user1LoginSuccess, user1LoginFailure, &testContext);

        LoginWithCustomIDRequest user2LoginRequest;
        user2LoginRequest.CustomId = "test_MultiInstance2";
        user2LoginRequest.CreateAccount = true;

        const auto& user2LoginSuccess = std::bind(&PlayFabTestMultiUserInstance::MultiUserLogin2Success, this, std::placeholders::_1, std::placeholders::_2);
        const auto& user2LoginFailure = std::bind(&PlayFabTestMultiUserInstance::MultiUserLogin2Failure, this, std::placeholders::_1, std::placeholders::_2);
        multiUser2ClientApi->LoginWithCustomID(user2LoginRequest, user2LoginSuccess, user2LoginFailure, &testContext);
    }

    void PlayFabTestMultiUserInstance::AddTests()
    {
        AddTest("MultiUserLoginInstance", &PlayFabTestMultiUserInstance::MultiUserLogin);
    }

    void PlayFabTestMultiUserInstance::ClassSetUp()
    {
        settings2 = std::make_shared<PlayFab::PlayFabApiSettings>();
        settings2->titleId = testTitleData.titleId;

        // Create API handles for all users.
        multiUser1ClientApi = std::make_shared<PlayFabClientInstanceAPI>();
        multiUser2ClientApi = std::make_shared<PlayFabClientInstanceAPI>(settings2); // also test explicit API settings
    }

    void PlayFabTestMultiUserInstance::SetUp(TestContext& /*testContext*/)
    {
        PlayFab::PlayFabSettings::staticSettings->titleId = testTitleData.titleId;

        // Make sure PlayFab state is clean.
        PlayFabSettings::ForgetAllCredentials();

        // Reset state variables.
        multiUser1Error.clear();
        multiUser2Error.clear();
        thread1Complete = false;
        thread2Complete = false;
    }

    void PlayFabTestMultiUserInstance::Tick(TestContext& testContext)
    {
        // Wait for both threads to stop
        if (!thread1Complete || !thread2Complete)
        {
            return;
        }

        // Once retrieved, each user should have a unique ID.
        if (!multiUser1Error.empty() || !multiUser2Error.empty())
        {
            testContext.Fail(multiUser1Error + multiUser2Error);
            return;
        }

        std::string multiUser1PlayFabId = multiUser1ClientApi->GetAuthenticationContext()->playFabId;
        std::string multiUser2PlayFabId = multiUser2ClientApi->GetAuthenticationContext()->playFabId;

        if (multiUser1PlayFabId == multiUser2PlayFabId)
        {
            testContext.Fail("User 1 PlayFabId (" + multiUser1PlayFabId + ") should not match User 2 PlayFabId (" + multiUser2PlayFabId + ")");
        }
        else
        {
            testContext.Pass();
        }
    }

    void PlayFabTestMultiUserInstance::TearDown(TestContext& /*testContext*/)
    {
        // Clean up PlayFab state for next TestCase.
        PlayFab::PlayFabSettings::staticSettings->titleId.clear();
        PlayFabSettings::ForgetAllCredentials();
        multiUser1ClientApi->ForgetAllCredentials();
        multiUser2ClientApi->ForgetAllCredentials();
    }

    void PlayFabTestMultiUserInstance::ClassTearDown()
    {
        // Release API handles for all users.
        multiUser1ClientApi.reset();
        settings2.reset();
        multiUser2ClientApi.reset();
    }
}

#endif
