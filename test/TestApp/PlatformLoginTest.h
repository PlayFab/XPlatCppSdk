// Copyright (C) Microsoft Corporation. All rights reserved.

#pragma once

#if !defined(DISABLE_PLAYFABCLIENT_API)

#include <memory>

#include <playfab/PlayFabPlatformUtils.h>
#include <playfab/PlayFabClientInstanceApi.h>

#include "TestContext.h"
#include "TestCase.h"

namespace PlayFab
{
    struct PlayFabError;

    namespace ClientModels
    {
        struct LoginResult;
    }
}

namespace PlayFabUnit
{
    struct TestTitleData;

    class PlatformLoginTest : public PlayFabApiTestCase
    {
    private:
        // Api instances
        std::shared_ptr<PlayFab::PlayFabClientInstanceAPI> clientApi;

        void OnErrorSharedCallback(const PlayFab::PlayFabError& error, void* customData);

        // CLIENT API
        // Attempt a successful login using the context-relevant platform
        void PlatformLogin(TestContext& testContext);
        void OnPlatformLogin(const PlayFab::ClientModels::LoginResult& result, void* customData);

        // Utility
        template<typename T> std::function<void(const T&, void*)> Callback(void(PlatformLoginTest::* func)(const T&, void*))
        {
            return std::bind(func, this, std::placeholders::_1, std::placeholders::_2);
        }

    protected:
        void AddTests() override;

    public:
        void ClassSetUp() override;
        void Tick(TestContext& testContext) override;
        void ClassTearDown() override;
    };
}

#endif
