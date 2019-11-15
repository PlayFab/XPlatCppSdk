// Copyright (C) Microsoft Corporation. All rights reserved.

#include "TestAppPch.h"

#ifndef DISABLE_PLAYFABCLIENT_API

#include <playfab/PlayFabClientApi.h>
#include <playfab/PlayFabSettings.h>
#include "TestContext.h"
#include "PlayFabTestMultiUserStatic.h"

using namespace PlayFab;
using namespace ClientModels;

namespace PlayFabUnit
{
    /// <summary>
    /// CLIENT API
    /// Try to log in two users simultaneously using static APIs.
    /// </summary>
    void PlayFabTestMultiUserStatic::MultiUserLogin1Success(const LoginResult& result, void* customData)
    {
        GetPlayerProfileRequest profileRequest;
        profileRequest.authenticationContext = result.authenticationContext;

        const auto& user1ProfileSuccess = std::bind(&PlayFabTestMultiUserStatic::MultiUserProfile1Success, this, std::placeholders::_1, std::placeholders::_2);
        const auto& user1ProfileFailure = std::bind(&PlayFabTestMultiUserStatic::MultiUserProfile1Failure, this, std::placeholders::_1, std::placeholders::_2);
        PlayFabClientAPI::GetPlayerProfile(profileRequest, user1ProfileSuccess, user1ProfileFailure, customData);
    }
    void PlayFabTestMultiUserStatic::MultiUserLogin1Failure(const PlayFabError& error, void* /*customData*/)
    {
        multiUser1Error = "Failed to log in user 1: " + error.GenerateErrorReport();
        thread1Complete = true;
    }
    void PlayFabTestMultiUserStatic::MultiUserProfile1Success(const GetPlayerProfileResult& /*result*/, void* /*customData*/)
    {
        thread1Complete = true;
    }
    void PlayFabTestMultiUserStatic::MultiUserProfile1Failure(const PlayFabError& error, void* /*customData*/)
    {
        multiUser1Error = "Failed to get user 1 profile: " + error.GenerateErrorReport();
        thread1Complete = true;
    }

    void PlayFabTestMultiUserStatic::MultiUserLogin2Success(const LoginResult& result, void* customData)
    {
        GetPlayerProfileRequest profileRequest;
        profileRequest.authenticationContext = result.authenticationContext;

        const auto& user2ProfileSuccess = std::bind(&PlayFabTestMultiUserStatic::MultiUserProfile2Success, this, std::placeholders::_1, std::placeholders::_2);
        const auto& user2ProfileFailure = std::bind(&PlayFabTestMultiUserStatic::MultiUserProfile2Failure, this, std::placeholders::_1, std::placeholders::_2);
        PlayFabClientAPI::GetPlayerProfile(profileRequest, user2ProfileSuccess, user2ProfileFailure, customData);
    }
    void PlayFabTestMultiUserStatic::MultiUserLogin2Failure(const PlayFabError& error, void* /*customData*/)
    {
        multiUser2Error = "Failed to log in user 2: " + error.GenerateErrorReport();
        thread2Complete = true;
    }
    void PlayFabTestMultiUserStatic::MultiUserProfile2Success(const GetPlayerProfileResult& /*result*/, void* /*customData*/)
    {
        thread2Complete = true;
    }
    void PlayFabTestMultiUserStatic::MultiUserProfile2Failure(const PlayFabError& error, void* /*customData*/)
    {
        multiUser2Error = "Failed to get user 2 profile: " + error.GenerateErrorReport();
        thread2Complete = true;
    }

    void PlayFabTestMultiUserStatic::MultiUserLogin(TestContext& testContext)
    {
        // Step 1: Log in two Users simultaneously.
        LoginWithCustomIDRequest user1LoginRequest;
        user1LoginRequest.CustomId = "test_MultiStatic1";
        user1LoginRequest.CreateAccount = true;

        const auto& user1LoginSuccess = std::bind(&PlayFabTestMultiUserStatic::MultiUserLogin1Success, this, std::placeholders::_1, std::placeholders::_2);
        const auto& user1LoginFailure = std::bind(&PlayFabTestMultiUserStatic::MultiUserLogin1Failure, this, std::placeholders::_1, std::placeholders::_2);
        PlayFabClientAPI::LoginWithCustomID(user1LoginRequest, user1LoginSuccess, user1LoginFailure, &testContext);

        LoginWithCustomIDRequest user2LoginRequest;
        user2LoginRequest.CustomId = "test_MultiStatic2";
        user2LoginRequest.CreateAccount = true;
        user2LoginRequest.authenticationContext = multiUser2Context;

        const auto& user2LoginSuccess = std::bind(&PlayFabTestMultiUserStatic::MultiUserLogin2Success, this, std::placeholders::_1, std::placeholders::_2);
        const auto& user2LoginFailure = std::bind(&PlayFabTestMultiUserStatic::MultiUserLogin2Failure, this, std::placeholders::_1, std::placeholders::_2);
        PlayFabClientAPI::LoginWithCustomID(user2LoginRequest, user2LoginSuccess, user2LoginFailure, &testContext);
    }

    void PlayFabTestMultiUserStatic::AddTests()
    {
        AddTest("MultiUserLoginStatic", &PlayFabTestMultiUserStatic::MultiUserLogin);
    }

    void PlayFabTestMultiUserStatic::ClassSetUp()
    {
        // Ref or create contexts for players
        multiUser1Context = PlayFabSettings::staticPlayer;
        multiUser2Context = std::make_shared<PlayFabAuthenticationContext>();
    }

    void PlayFabTestMultiUserStatic::SetUp(TestContext& /*testContext*/)
    {
        // Make sure PlayFab state is clean.
        PlayFabSettings::ForgetAllCredentials();

        // Reset state variables.
        multiUser1Error.clear();
        multiUser2Error.clear();
        thread1Complete = false;
        thread2Complete = false;
    }

    void PlayFabTestMultiUserStatic::Tick(TestContext& testContext)
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

        std::string multiUser1PlayFabId = multiUser1Context->playFabId;
        std::string multiUser2PlayFabId = multiUser2Context->playFabId;

        if (multiUser1PlayFabId == multiUser2PlayFabId)
        {
            testContext.Fail("User 1 PlayFabId (" + multiUser1PlayFabId + ") should not match User 2 PlayFabId (" + multiUser2PlayFabId + ")");
        }
        else
        {
            testContext.Pass();
        }
    }

    void PlayFabTestMultiUserStatic::TearDown(TestContext& /*testContext*/)
    {
        // Clean up PlayFab state for next TestCase.
        PlayFabSettings::ForgetAllCredentials();
    }

    void PlayFabTestMultiUserStatic::ClassTearDown()
    {
        // Release contexts
        multiUser1Context = nullptr; // This one isn't destroyed because it's PlayFabSettings::staticPlayer
        multiUser2Context = nullptr;
    }
}

#endif
