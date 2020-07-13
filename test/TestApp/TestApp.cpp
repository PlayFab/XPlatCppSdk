// Copyright (C) Microsoft Corporation. All rights reserved.

#include "TestAppPch.h"

#include <cstdarg>
#include <functional>
#include <thread>

#include "TestApp.h"
#include "TestRunner.h"
#include "TestReport.h"

#if !defined(DISABLE_PLAYFABCLIENT_API)
#include <playfab/PlayFabSettings.h>

#include "PlatformLoginTest.h"
#include "PlayFabApiTest.h"
#include "PlayFabEventTest.h"
#include "PlayFabTestMultiUserStatic.h"
#include "PlayFabTestMultiUserInstance.h"
#include "PlayFabPlatformSpecificTest.h"
#endif

#include <playfab/PlayFabJsonHeaders.h>

#include "PlayFabTestAlloc.h"

namespace PlayFabUnit
{
    // Time out if waiting for the final cloudscript submission longer than this
    constexpr int CLOUDSCRIPT_TIMEOUT_MS = 30000;

    void TestApp::Log(const char* format, ...)
    {
        static char message[4096];

        va_list args;
        va_start(args, format);
#if defined(PLAYFAB_PLATFORM_PLAYSTATION)
        vsnprintf_s(message, sizeof(message), format, args);
#elif defined(PLAYFAB_PLATFORM_IOS) || defined(PLAYFAB_PLATFORM_ANDROID) || defined(PLAYFAB_PLATFORM_LINUX) || defined(PLAYFAB_PLATFORM_SWITCH)
        vsnprintf(message, sizeof(message), format, args);
#else
        _vsnprintf_s(message, sizeof(message), format, args);
#endif
        va_end(args);

        // Output the message in a platform-dependent way.
        LogPut(message);
    }

    int TestApp::Main()
    {
        // Load the TestTitleData
        TestTitleData testTitleData;
        bool loadSuccessful = LoadTitleData(testTitleData);

        // If the title data fails to load, and you want to use custom hard-coded data, you can
        // comment out the return statement and fill out the TestTitleData fields manually.
        if (!loadSuccessful)
        {
            printf("Failed to load testTitleData\n");
            return 1;

            // TODO: POPULATE THIS SECTION WITH REAL INFORMATION (or set up a testTitleData file, and set your PF_TEST_TITLE_DATA_JSON to the path for that file)
            //testTitleData.titleId = ""; // The titleId for your title, found in the "Settings" section of PlayFab Game Manager
            //testTitleData.userEmail = ""; // This is the email for a valid user (test tries to log into it with an invalid password, and verifies error result)
        }

        // Initialize the test runner/test data.
        TestRunner testRunner;

        PlayFabTestAlloc allocTest;
        testRunner.Add(allocTest);

#if !defined(DISABLE_PLAYFABCLIENT_API)
        // Set this up for use when the tests finish
        this->clientApi = std::make_shared<PlayFab::PlayFabClientInstanceAPI>(PlayFab::PlayFabSettings::staticPlayer);

#if !defined(PLAYFAB_PLATFORM_IOS) // IOS isn't implemented yet
        // Add PlayFab API tests.
        PlatformLoginTest loginTest;
        loginTest.SetTitleInfo(testTitleData);
        testRunner.Add(loginTest);
#endif

        // Add PlayFab API tests.
        PlayFabApiTest pfApiTest;
        pfApiTest.SetTitleInfo(testTitleData);
        testRunner.Add(pfApiTest);

#if defined(PLAYFAB_PLATFORM_SWITCH) // TODO: hook this up to all the platforms with a platform-specific login
        PlayFabPlatformSpecificTest platformSpecificTest;
        platformSpecificTest.SetTitleInfo(testTitleData);
        testRunner.Add(platformSpecificTest);
#endif

#if false // These tests are still too unstable, and despite passing nearly 100% in debug, still fail 100% in release
        PlayFabEventTest pfEventTest;
        pfEventTest.SetTitleInfo(testTitleData);
        testRunner.Add(pfEventTest);
#endif

        PlayFabTestMultiUserStatic pfMultiUserStaticTest;
        pfMultiUserStaticTest.SetTitleInfo(testTitleData);
        testRunner.Add(pfMultiUserStaticTest);

        PlayFabTestMultiUserInstance pfMultiUserInstanceTest;
        pfMultiUserInstanceTest.SetTitleInfo(testTitleData);
        testRunner.Add(pfMultiUserInstanceTest);
#endif

        // Run the tests (blocks until all tests have finished).
        testRunner.Run();

        // Publish the test summary to STDOUT.
        Log("%s\n", testRunner.suiteTestSummary.c_str());

#if !defined(DISABLE_PLAYFABCLIENT_API)
        // Publish the test report via cloud script (and wait for it to finish).
        PlayFab::PlayFabSettings::staticSettings->titleId = testTitleData.titleId;

        PlayFab::ClientModels::LoginWithCustomIDRequest request;
        request.CustomId = PlayFab::PlayFabSettings::buildIdentifier;
        request.CreateAccount = true;
        this->clientApi->LoginWithCustomID(request,
            std::bind(&TestApp::OnPostReportLogin, this, std::placeholders::_1, std::placeholders::_2),
            std::bind(&TestApp::OnPostReportError, this, std::placeholders::_1, std::placeholders::_2),
            &testRunner.suiteTestReport);

        // Wait for CloudResponse
        {
            std::unique_lock<std::mutex> lk(cloudResponseMutex);
            cloudResponseConditionVar.wait_until(lk, std::chrono::system_clock::now() + std::chrono::milliseconds(CLOUDSCRIPT_TIMEOUT_MS), [this] {return !this->cloudResponse.empty(); });
            lk.unlock();
        }

        // Publish the cloud script response to STDOUT.
        Log("Cloud Response: %s\n", cloudResponse.c_str());
#endif

        // Return 0 (success) if all tests passed. Otherwise, return 1 (error).
        return testRunner.AllTestsPassed()
#if !defined(DISABLE_PLAYFABCLIENT_API)
            && !cloudResponse.empty() ? 0 : 1
#endif
            ;
    }

    bool TestApp::LoadTitleData(TestTitleData& titleData)
    {
        // Load JSON string in a platform-dependent way.
        std::shared_ptr<char*> titleJsonPtr;
        size_t size;
        const bool loadedSuccessfully = LoadTitleDataJson(titleJsonPtr, size);

        if (!loadedSuccessfully)
        {
            return false;
        }

        // Parse JSON string into output TestTitleData.
        Json::CharReaderBuilder jsonReaderFactory;
        Json::CharReader* jsonReader(jsonReaderFactory.newCharReader());
        JSONCPP_STRING jsonParseErrors;
        Json::Value titleDataJson;
        const bool parsedSuccessfully = jsonReader->parse(*titleJsonPtr, *titleJsonPtr + size + 1, &titleDataJson, &jsonParseErrors);

        if (parsedSuccessfully)
        {
            titleData.titleId = titleDataJson["titleId"].asString();
            titleData.userEmail = titleDataJson["userEmail"].asString();
            titleData.developerSecretKey = titleDataJson["developerSecretKey"].asString();
        }

        return parsedSuccessfully;
    }

#if !defined(DISABLE_PLAYFABCLIENT_API)
    void TestApp::OnPostReportLogin(const PlayFab::ClientModels::LoginResult& result, void* customData)
    {
        // Prepare a JSON value as a param for the remote cloud script.
        Json::Value cloudReportJson;
        cloudReportJson["customId"] = result.PlayFabId;

        // The expected format is a list of TestSuiteReports, but this framework only submits one
        cloudReportJson["testReport"];
        Json::Value arrayInit(Json::arrayValue);
        cloudReportJson["testReport"].swapPayload(arrayInit);

        // Encode the test report as JSON.
        TestReport* testReport = static_cast<TestReport*>(customData);
        testReport->internalReport.ToJson(cloudReportJson["testReport"][0]);

        // Save the test results via cloud script.
        PlayFab::ClientModels::ExecuteCloudScriptRequest request;
        request.FunctionName = "SaveTestData";
        request.FunctionParameter = cloudReportJson;
        request.GeneratePlayStreamEvent = true;
        this->clientApi->ExecuteCloudScript(request,
            std::bind(&TestApp::OnPostReportComplete, this, std::placeholders::_1, std::placeholders::_2),
            std::bind(&TestApp::OnPostReportError, this, std::placeholders::_1, std::placeholders::_2));
    }

    void TestApp::OnPostReportComplete(const PlayFab::ClientModels::ExecuteCloudScriptResult& result, void* /*customData*/)
    {
        if (result.Error.isNull())
        {
            cloudResponse = "Test report submitted via cloud script: " + PlayFab::PlayFabSettings::buildIdentifier + ", " + PlayFab::PlayFabSettings::staticPlayer->playFabId;
        }
        else
        {
            cloudResponse += "Error executing test report cloud script:\n" + result.Error->Error + ": " + result.Error->Message;
        }
        cloudResponseConditionVar.notify_one();
    }

    void TestApp::OnPostReportError(const PlayFab::PlayFabError& error, void* /*customData*/)
    {
        cloudResponse = "Failed to report results via cloud script: " + error.GenerateErrorReport();
        cloudResponseConditionVar.notify_one();
    }
#endif
}
