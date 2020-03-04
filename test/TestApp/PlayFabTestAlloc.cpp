// Copyright (C) Microsoft Corporation. All rights reserved.

#include "TestAppPch.h"

#include <playfab/PlayFabApiSettings.h>
#include <playfab/PlayFabAuthenticationContext.h>
#include <playfab/PlayFabAuthenticationInstanceApi.h>
#include "TestContext.h"
#include "PlayFabTestAlloc.h"

namespace PlayFabUnit
{
    void PlayFabTestAlloc::TestApiSettingsAlloc(TestContext& testContext)
    {
        // If anything fails here, it'll be a straight program crash

        // Settings
        PlayFab::PlayFabApiSettings* testPtrSettings = new PlayFab::PlayFabApiSettings();
        testPtrSettings->titleId = "this should succeed";
#if defined(ENABLE_PLAYFABSERVER_API) || defined(ENABLE_PLAYFABADMIN_API)
        testPtrSettings->developerSecretKey = "this is conditional";
#endif
        delete testPtrSettings;

        std::shared_ptr<PlayFab::PlayFabApiSettings> testMSpSettings = std::make_shared<PlayFab::PlayFabApiSettings>();
        testMSpSettings->titleId = "this should succeed";
#if defined(ENABLE_PLAYFABSERVER_API) || defined(ENABLE_PLAYFABADMIN_API)
        testMSpSettings->developerSecretKey = "this is conditional";
#endif
        testMSpSettings.reset();

        std::shared_ptr<PlayFab::PlayFabApiSettings> testNSpSettings = std::shared_ptr<PlayFab::PlayFabApiSettings>(new PlayFab::PlayFabApiSettings());
        testNSpSettings->titleId = "this should succeed";
#if defined(ENABLE_PLAYFABSERVER_API) || defined(ENABLE_PLAYFABADMIN_API)
        testNSpSettings->developerSecretKey = "this is conditional";
#endif
        testNSpSettings.reset();

        testContext.Pass();
    }

    void PlayFabTestAlloc::TestAuthContextAlloc(TestContext& testContext)
    {
        // If anything fails here, it'll be a straight program crash

        // Context
        PlayFab::PlayFabAuthenticationContext* testPtrContext = new PlayFab::PlayFabAuthenticationContext();
        testPtrContext->entityId = "this should succeed";
#if !defined(DISABLE_PLAYFABCLIENT_API)
        testPtrContext->playFabId = "this is conditional";
#endif
        delete testPtrContext;

        std::shared_ptr<PlayFab::PlayFabAuthenticationContext> testMSPContext = std::make_shared<PlayFab::PlayFabAuthenticationContext>();
        testMSPContext->entityId = "this should succeed";
#if !defined(DISABLE_PLAYFABCLIENT_API)
        testMSPContext->playFabId = "this is conditional";
#endif
        testMSPContext.reset();

        std::shared_ptr<PlayFab::PlayFabAuthenticationContext> testNSpContext = std::shared_ptr<PlayFab::PlayFabAuthenticationContext>(new PlayFab::PlayFabAuthenticationContext());
        testNSpContext->entityId = "this should succeed";
#if !defined(DISABLE_PLAYFABCLIENT_API)
        testNSpContext->playFabId = "this is conditional";
#endif
        testNSpContext.reset();

        testContext.Pass();
    }

    void PlayFabTestAlloc::TestApiInstanceAlloc(TestContext& testContext)
    {
        // If anything fails here, it'll be a straight program crash

        // Context
        PlayFab::PlayFabAuthenticationInstanceAPI* testPtrApi = new PlayFab::PlayFabAuthenticationInstanceAPI();
        delete testPtrApi;

        std::shared_ptr<PlayFab::PlayFabAuthenticationInstanceAPI> testSpApi = std::make_shared<PlayFab::PlayFabAuthenticationInstanceAPI>();
        testSpApi.reset();

        std::shared_ptr<PlayFab::PlayFabAuthenticationInstanceAPI> testNSpApi = std::shared_ptr<PlayFab::PlayFabAuthenticationInstanceAPI>(new PlayFab::PlayFabAuthenticationInstanceAPI());
        testNSpApi.reset();

        testContext.Pass();
    }

    void PlayFabTestAlloc::AddTests()
    {
        AddTest("TestApiSettingsAlloc", &PlayFabTestAlloc::TestApiSettingsAlloc);
        AddTest("TestAuthContextAlloc", &PlayFabTestAlloc::TestAuthContextAlloc);
        AddTest("TestApiInstanceAlloc", &PlayFabTestAlloc::TestApiInstanceAlloc);
    }

    void PlayFabTestAlloc::Tick(TestContext& /*testContext*/)
    {
    }
}
