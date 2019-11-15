// Copyright (C) Microsoft Corporation. All rights reserved.

#include "TestAppPch.h"
#include "TestApp.h"

#include <playfab/PlayFabApiSettings.h>
#include <playfab/PlayFabAuthenticationContext.h>

// Win32 Entry Point
int main()
{
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

    // Context
    PlayFab::PlayFabAuthenticationContext* testPtrContext = new PlayFab::PlayFabAuthenticationContext();
    testPtrContext->entityId = "this should succeed";
#ifndef DISABLE_PLAYFABCLIENT_API
    testPtrContext->playFabId = "this is conditional";
#endif
    delete testPtrContext;

    std::shared_ptr<PlayFab::PlayFabAuthenticationContext> testMSPContext = std::make_shared<PlayFab::PlayFabAuthenticationContext>();
    testMSPContext->entityId = "this should succeed";
#ifndef DISABLE_PLAYFABCLIENT_API
    testMSPContext->playFabId = "this is conditional";
#endif
    testMSPContext.reset();

    std::shared_ptr<PlayFab::PlayFabAuthenticationContext> testNSpContext = std::shared_ptr<PlayFab::PlayFabAuthenticationContext>(new PlayFab::PlayFabAuthenticationContext());
    testNSpContext->entityId = "this should succeed";
#ifndef DISABLE_PLAYFABCLIENT_API
    testNSpContext->playFabId = "this is conditional";
#endif
    testNSpContext.reset();

    PlayFabUnit::TestApp testApp;
    return testApp.Main();
}
