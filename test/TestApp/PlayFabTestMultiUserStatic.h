// Copyright (C) Microsoft Corporation. All rights reserved.

#pragma once

#ifndef DISABLE_PLAYFABCLIENT_API

#include "TestCase.h"

namespace PlayFab
{
    namespace ClientModels
    {
        struct GetPlayerProfileResult;
        struct LoginResult;
    }

    struct PlayFabError;
}

namespace PlayFabUnit
{
    class PlayFabTestMultiUserStatic : public PlayFabApiTestCase
    {
    private:
        /// <summary>
        /// CLIENT API
        /// Try to log in two users simultaneously using static APIs.
        /// </summary>
        std::shared_ptr<PlayFab::PlayFabAuthenticationContext> multiUser1Context;
        std::shared_ptr<PlayFab::PlayFabAuthenticationContext> multiUser2Context;
        std::string multiUser1Error, multiUser2Error;
        bool thread1Complete, thread2Complete;

        void MultiUserLogin1Success(const PlayFab::ClientModels::LoginResult& result, void* customData);
        void MultiUserLogin1Failure(const PlayFab::PlayFabError& error, void* customData);
        void MultiUserProfile1Success(const PlayFab::ClientModels::GetPlayerProfileResult& result, void* customData);
        void MultiUserProfile1Failure(const PlayFab::PlayFabError& error, void* customData);
        void MultiUserLogin2Success(const PlayFab::ClientModels::LoginResult& result, void* customData);
        void MultiUserLogin2Failure(const PlayFab::PlayFabError& error, void* customData);
        void MultiUserProfile2Success(const PlayFab::ClientModels::GetPlayerProfileResult& result, void* customData);
        void MultiUserProfile2Failure(const PlayFab::PlayFabError& error, void* customData);
        void MultiUserLogin(TestContext& testContext);

    protected:
        void AddTests() override;

    public:
        void ClassSetUp() override;
        void SetUp(TestContext& testContext) override;
        void Tick(TestContext& testContext) override;
        void TearDown(TestContext& testContext) override;
        void ClassTearDown() override;
    };
}

#endif
