// Copyright (C) Microsoft Corporation. All rights reserved.

#include "TestAppPch.h"

#if !defined(DISABLE_PLAYFABCLIENT_API)

#include <chrono>

#include <playfab/PlayFabApiSettings.h>
#include <playfab/PlayFabSettings.h>

#include <playfab/PlayFabAuthenticationInstanceApi.h>
#include <playfab/PlayFabClientInstanceApi.h>
#include <playfab/PlayFabDataInstanceApi.h>

#include "PlayFabApiTest.h"
#include "TestContext.h"

using namespace PlayFab;
using namespace ClientModels;
using namespace AuthenticationModels;
using namespace DataModels;

namespace PlayFabUnit
{
    const std::string PlayFabApiTest::TEST_DATA_KEY = "testCounter";
    const std::string PlayFabApiTest::TEST_STAT_NAME = "str";

    void PlayFabApiTest::OnErrorSharedCallback(const PlayFabError& error, void* customData)
    {
        TestContext* testContext = static_cast<TestContext*>(customData);
        testContext->Fail("Unexpected error: " + error.GenerateErrorReport());
    }

    // CLIENT API
    // Try to deliberately cause a client-side validation error
    // THIS TEST CORRUPTS THE PlayFabSettings::staticSettings->titleId, because validTitleId leaves scope before it can be restored
    //void PlayFabApiTest::InvalidSettings(TestContext& testContext)
    //{
    //    LoginWithCustomIDRequest request;
    //    request.CustomId = PlayFabSettings::buildIdentifier;
    //    request.CreateAccount = true;

    //    // store current (valid) title id
    //    const std::string validTitleId = PlayFabSettings::staticSettings->titleId;

    //    // set invalid title id
    //    PlayFabSettings::staticSettings->titleId = "";

    //    clientApi->LoginWithCustomID(request,
    //        [&validTitleId](const LoginResult&, void* customData)
    //    {
    //        PlayFabSettings::staticSettings->titleId = validTitleId;
    //        TestContext* testContext = static_cast<TestContext*>(customData);
    //        testContext->Fail("Expected API call to fail on the client side");
    //    },
    //        [&validTitleId](const PlayFabError& error, void* customData)
    //    {
    //        PlayFabSettings::staticSettings->titleId = validTitleId;
    //        TestContext* testContext = static_cast<TestContext*>(customData);
    //        if (error.HttpCode == 0
    //            && error.HttpStatus == "Client-side validation failure"
    //            && error.ErrorCode == PlayFabErrorCode::PlayFabErrorInvalidParams
    //            && error.ErrorName == error.HttpStatus)
    //            testContext->Pass();
    //        else
    //            testContext->Fail("Returned error is different from expected");
    //    },
    //        &testContext);
    //}

    // CLIENT API
    // Try to deliberately log in with an inappropriate password,
    //   and verify that the error displays as expected.
    void PlayFabApiTest::InvalidLogin(TestContext& testContext)
    {
        LoginWithEmailAddressRequest request;
        request.Email = USER_EMAIL;
        request.Password = "INVALID";

        clientApi->LoginWithEmailAddress(request,
            Callback(&PlayFabApiTest::LoginCallback),
            Callback(&PlayFabApiTest::LoginFailedCallback),
            &testContext);
    }
    void PlayFabApiTest::LoginCallback(const LoginResult&, void* customData)
    {
        TestContext* testContext = static_cast<TestContext*>(customData);
        testContext->Fail("Expected login to fail");
    }
    void PlayFabApiTest::LoginFailedCallback(const PlayFabError& error, void* customData)
    {
        TestContext* testContext = static_cast<TestContext*>(customData);

        // TODO: Bug 45560 - remove this platform specific check when fixed.
#if !defined(PLAYFAB_PLATFORM_IOS) && !defined(PLAYFAB_PLATFORM_GDK)
        if (error.RequestId.empty())
        {
            testContext->Fail("The requestId should be set on a failure.");
        }
#endif
        if (error.ErrorMessage.find("password") != -1)
        {
            testContext->Pass(error.RequestId);
        }
        else
        {
            testContext->Fail("Password error message not found: " + error.GenerateErrorReport());
        }
    }

    // CLIENT API
    // Test that a lambda error callback can be successfully invoked
    void PlayFabApiTest::InvalidLoginLambda(TestContext& testContext)
    {
        LoginWithEmailAddressRequest request;
        request.Email = USER_EMAIL;
        request.Password = "INVALID";

        clientApi->LoginWithEmailAddress(request,
            nullptr,
            [](const PlayFabError& error, void* customData) { TestContext* testContext = static_cast<TestContext*>(customData); if (error.ErrorMessage.find("password") != -1) testContext->Pass(); },
            &testContext);
    }

    // CLIENT API
    // Try to deliberately register a user with an invalid email and password
    //   Verify that errorDetails are populated correctly.
    void PlayFabApiTest::InvalidRegistration(TestContext& testContext)
    {
        RegisterPlayFabUserRequest request;
        request.Username = "x";
        request.Email = "x";
        request.Password = "x";

        clientApi->RegisterPlayFabUser(request,
            Callback(&PlayFabApiTest::InvalidRegistrationSuccess),
            Callback(&PlayFabApiTest::InvalidRegistrationFail),
            &testContext);
    }
    void PlayFabApiTest::InvalidRegistrationSuccess(const RegisterPlayFabUserResult&, void* customData)
    {
        TestContext* testContext = static_cast<TestContext*>(customData);
        testContext->Fail("Expected registration to fail");
    }
    void PlayFabApiTest::InvalidRegistrationFail(const PlayFabError& error, void* customData)
    {
        bool foundEmailMsg, foundPasswordMsg;
        std::string expectedEmailMsg = "Email address is not valid.";
        std::string expectedPasswordMsg = "Password must be between";
        std::string errorReport = error.GenerateErrorReport();

        foundEmailMsg = (errorReport.find(expectedEmailMsg) != -1);
        foundPasswordMsg = (errorReport.find(expectedPasswordMsg) != -1);

        TestContext* testContext = static_cast<TestContext*>(customData);
        if (foundEmailMsg && foundPasswordMsg)
        {
            testContext->Pass();
        }
        else
        {
            testContext->Fail("All error details: " + errorReport);
        }
    }

    // CLIENT API
    // Attempt a successful login
    void PlayFabApiTest::LoginOrRegister(TestContext& testContext)
    {
        LoginWithCustomIDRequest request;
        request.CustomId = PlayFabSettings::buildIdentifier;
        request.CreateAccount = true;

        clientApi->LoginWithCustomID(request,
            Callback(&PlayFabApiTest::OnLoginOrRegister),
            Callback(&PlayFabApiTest::OnErrorSharedCallback),
            &testContext);
    }
    void PlayFabApiTest::OnLoginOrRegister(const LoginResult& /*result*/, void* customData)
    {
        TestContext* testContext = static_cast<TestContext*>(customData);
        testContext->Pass();
    }

    // CLIENT API
    // Test a sequence of calls that modifies saved data,
    //   and verifies that the next sequential API call contains updated data.
    // Verify that the data is correctly modified on the next call.
    // Parameter types tested: string, Dictionary<string, string>
    void PlayFabApiTest::UserDataApi(TestContext& testContext)
    {
        if (!clientApi->IsClientLoggedIn())
        {
            testContext.Skip("Earlier tests failed to log in");
            return;
        }

        GetUserDataRequest request;
        clientApi->GetUserData(request,
            Callback(&PlayFabApiTest::OnUserDataApiGet1),
            Callback(&PlayFabApiTest::OnErrorSharedCallback),
            &testContext);
    }
    void PlayFabApiTest::OnUserDataApiGet1(const GetUserDataResult& result, void* customData)
    {
        auto it = result.Data.find(TEST_DATA_KEY);
        testMessageInt = (it == result.Data.end()) ? 1 : atoi(it->second.Value.c_str());
        // testMessageTime = it->second.LastUpdated; // Don't need the first time

        testMessageInt = (testMessageInt + 1) % 100;
        UpdateUserDataRequest updateRequest;

        std::string temp = std::to_string(testMessageInt);

        updateRequest.Data[TEST_DATA_KEY] = temp;
        clientApi->UpdateUserData(updateRequest,
            Callback(&PlayFabApiTest::OnUserDataApiUpdate),
            Callback(&PlayFabApiTest::OnErrorSharedCallback),
            customData);
    }
    void PlayFabApiTest::OnUserDataApiUpdate(const UpdateUserDataResult&, void* customData)
    {
        GetUserDataRequest request;
        clientApi->GetUserData(request,
            Callback(&PlayFabApiTest::OnUserDataApiGet2),
            Callback(&PlayFabApiTest::OnErrorSharedCallback),
            customData);
    }
    void PlayFabApiTest::OnUserDataApiGet2(const GetUserDataResult& result, void* customData)
    {
        auto it = result.Data.find(TEST_DATA_KEY);
        int actualDataValue = (it == result.Data.end()) ? -1 : atoi(it->second.Value.c_str());

        TestContext* testContext = static_cast<TestContext*>(customData);
        if (it == result.Data.end())
        {
            testContext->Fail("Expected user data not found.");
        }
        else if (testMessageInt != actualDataValue)
        {
            testContext->Fail("User data not updated as expected.");
        }
        else
        {
            testContext->Pass();
        }
    }

    // CLIENT API
    // Verify that the timestamp returned is within 5 minutes of the time according to the local timezone for the current machine.
    // Parameter types tested: DateTime
    void PlayFabApiTest::GetServerTime(TestContext& testContext)
    {
        TimePoint nowTP = GetTimePointNow();
        tm timeInfoTP = TimePointToUtcTm(nowTP);
        int actualYearTP = timeInfoTP.tm_year + 1900; // Definition of tm_year is "years since 1900"
        if (!(2019 <= actualYearTP && actualYearTP <= 2025))
        {
            testContext.Fail("Suspicious year associated with \"GetTimePointNow\" in PlayFab time library: " + std::to_string(actualYearTP));
            return;
        }

        time_t nowTT = GetTimeTNow();
        tm timeInfoTT = TimeTToUtcTm(nowTT);
        int actualYearTT = timeInfoTT.tm_year + 1900; // Definition of tm_year is "years since 1900"
        if (!(2019 <= actualYearTT && actualYearTT <= 2025))
        {
            testContext.Fail("Suspicious year associated with \"GetTimeTNow\" in PlayFab time library: " + std::to_string(actualYearTT));
            return;
        }

        if (!clientApi->IsClientLoggedIn())
        {
            testContext.Skip("Earlier tests failed to log in");
            return;
        }

        GetTimeRequest request;
        clientApi->GetTime(request,
            Callback(&PlayFabApiTest::OnGetServerTime),
            Callback(&PlayFabApiTest::OnErrorSharedCallback),
            &testContext);
    }
    void PlayFabApiTest::OnGetServerTime(const GetTimeResult& result, void* customData)
    {
        testMessageTime = TimeTToTimePoint(result.Time);

        TimePoint now = GetTimePointNow();
        TimePoint minTime = now - std::chrono::minutes(5);
        TimePoint maxTime = now + std::chrono::minutes(5);

        TestContext* testContext = static_cast<TestContext*>(customData);

        // BUG 41168 - GetServerTime relies on the client device configurations,
        // leading to a lot of build failures especially when moving to other platforms
        // when we have the time, we can revisit this test and replace it with something more reliable.
        if (minTime > testMessageTime)
            testContext->Pass(" WARNING: Expected DateTime is too early. ExpectedNowMin:" + TimePointToIso8601String(minTime) + " > actualServer:" + TimePointToIso8601String(testMessageTime) + ", From Original server: " + TimeTToIso8601String(result.Time));
        else if (testMessageTime > maxTime)
            testContext->Pass(" WARNING: Expected DateTime too late. ExpectedNowMax:" + TimePointToIso8601String(maxTime) + " < actualServer:" + TimePointToIso8601String(testMessageTime) + ", From Original server: " + TimeTToIso8601String(result.Time));
        else
            testContext->Pass(TimeTToIso8601String(result.Time));
    }

    // CLIENT API
    // Test a sequence of calls that modifies saved data,
    //   and verifies that the next sequential API call contains updated data.
    // Verify that the data is saved correctly, and that specific types are tested
    // Parameter types tested: Dictionary<string, int>
    void PlayFabApiTest::PlayerStatisticsApi(TestContext& testContext)
    {
        if (!clientApi->IsClientLoggedIn())
        {
            testContext.Skip("Earlier tests failed to log in");
            return;
        }

        GetPlayerStatisticsRequest request;
        clientApi->GetPlayerStatistics(request,
            Callback(&PlayFabApiTest::OnPlayerStatisticsApiGet1),
            Callback(&PlayFabApiTest::OnErrorSharedCallback),
            &testContext);
    }
    void PlayFabApiTest::OnPlayerStatisticsApiGet1(const GetPlayerStatisticsResult& result, void* customData)
    {
        testMessageInt = 0;
        for (auto it = result.Statistics.begin(); it != result.Statistics.end(); ++it)
        {
            if (it->StatisticName == TEST_STAT_NAME)
            {
                testMessageInt = it->Value;
            }
        }

        testMessageInt = (testMessageInt + 1) % 100;
        // testMessageTime = it->second.LastUpdated; // Don't need the first time

        UpdatePlayerStatisticsRequest updateRequest;
        StatisticUpdate updateStat;
        updateStat.StatisticName = TEST_STAT_NAME;
        updateStat.Value = testMessageInt;
        updateRequest.Statistics.insert(updateRequest.Statistics.end(), updateStat);

        clientApi->UpdatePlayerStatistics(updateRequest,
            Callback(&PlayFabApiTest::OnPlayerStatisticsApiUpdate),
            Callback(&PlayFabApiTest::OnErrorSharedCallback),
            customData);
    }

    void PlayFabApiTest::OnPlayerStatisticsApiUpdate(const UpdatePlayerStatisticsResult&, void* customData)
    {
        GetPlayerStatisticsRequest request;
        clientApi->GetPlayerStatistics(request,
            Callback(&PlayFabApiTest::OnPlayerStatisticsApiGet2),
            Callback(&PlayFabApiTest::OnErrorSharedCallback),
            customData);
    }

    void PlayFabApiTest::OnPlayerStatisticsApiGet2(const GetPlayerStatisticsResult& result, void* customData)
    {
        int actualStatValue = -1000; // A value that is never expected to appear
        for (auto it = result.Statistics.begin(); it != result.Statistics.end(); ++it)
        {
            if (it->StatisticName == TEST_STAT_NAME)
            {
                actualStatValue = it->Value;
            }
        }

        TestContext* testContext = static_cast<TestContext*>(customData);
        if (actualStatValue == -1000)
        {
            testContext->Fail("Expected user statistic not found.");
        }
        else if (testMessageInt != actualStatValue)
        {
            testContext->Fail("User statistic not updated as expected.");
        }
        else
        {
            testContext->Pass();
        }
    }

    // CLIENT API
    // Get or create the given test character for the given user
    // Parameter types tested: Contained-Classes, string
    void PlayFabApiTest::UserCharacter(TestContext& testContext)
    {
        if (!clientApi->IsClientLoggedIn())
        {
            testContext.Skip("Earlier tests failed to log in");
            return;
        }

        ListUsersCharactersRequest request;
        clientApi->GetAllUsersCharacters(request,
            Callback(&PlayFabApiTest::OnUserCharacter),
            Callback(&PlayFabApiTest::OnErrorSharedCallback),
            &testContext);
    }
    void PlayFabApiTest::OnUserCharacter(const ListUsersCharactersResult&, void* customData)
    {
        // We aren't adding a character to this account, so there's nothing really to test here
        TestContext* testContext = static_cast<TestContext*>(customData);
        testContext->Pass();
    }

    // CLIENT API
    // Test that leaderboard results can be requested
    // Parameter types tested: List of contained-classes
    void PlayFabApiTest::LeaderBoard(TestContext& testContext)
    {
        if (!clientApi->IsClientLoggedIn())
        {
            testContext.Skip("Earlier tests failed to log in");
            return;
        }

        testMessageInt = 0;
        GetLeaderboardRequest clientRequest;
        clientRequest.MaxResultsCount = 3;
        clientRequest.StatisticName = TEST_STAT_NAME;

        clientApi->GetLeaderboard(clientRequest,
            Callback(&PlayFabApiTest::OnClientLeaderBoard),
            Callback(&PlayFabApiTest::OnErrorSharedCallback),
            &testContext);
    }
    void PlayFabApiTest::OnClientLeaderBoard(const GetLeaderboardResult& result, void* customData)
    {
        TestContext* testContext = static_cast<TestContext*>(customData);
        if (result.Leaderboard.size() > 0) // We added too many users and stats to test for a specific user, so we just have to test for "any number of results" now
        {
            testContext->Pass();
        }
        else
        {
            testContext->Fail("Leaderboard entry not found.");
        }
    }

    // CLIENT API
    // Test that AccountInfo can be requested
    // Parameter types tested: List of enum-as-strings converted to list of enums
    void PlayFabApiTest::AccountInfo(TestContext& testContext)
    {
        if (!clientApi->IsClientLoggedIn())
        {
            testContext.Skip("Earlier tests failed to log in");
            return;
        }

        GetAccountInfoRequest request;
        clientApi->GetAccountInfo(request,
            Callback(&PlayFabApiTest::OnAccountInfo),
            Callback(&PlayFabApiTest::OnErrorSharedCallback),
            &testContext);
    }
    void PlayFabApiTest::OnAccountInfo(const GetAccountInfoResult& result, void* customData)
    {
        TestContext* testContext = static_cast<TestContext*>(customData);
        // Enums-by-name can't really be tested in C++, the way they can in other languages
        if (result.AccountInfo.isNull() || result.AccountInfo->TitleInfo.isNull() || result.AccountInfo->TitleInfo->Origination.isNull())
        {
            testContext->Fail("The Origination data is not present");
        }
        else // Received data-format as expected
        {
            testContext->Pass();
        }
    }

    // CLIENT API
    // Test that CloudScript can be properly set up and invoked
    void PlayFabApiTest::CloudScript(TestContext& testContext)
    {
        if (!PlayFabSettings::staticPlayer->IsClientLoggedIn())
        {
            testContext.Skip("Earlier tests failed to log in");
            return;
        }

        ExecuteCloudScriptRequest request;
        request.FunctionName = "helloWorld";

        clientApi->ExecuteCloudScript(request,
            Callback(&PlayFabApiTest::OnHelloWorldCloudScript),
            Callback(&PlayFabApiTest::OnErrorSharedCallback),
            &testContext);
    }
    void PlayFabApiTest::OnHelloWorldCloudScript(const ExecuteCloudScriptResult& result, void* customData)
    {
        TestContext* testContext = static_cast<TestContext*>(customData);
        std::string cloudScriptLogReport = "";
        if (result.Error.notNull())
        {
            cloudScriptLogReport = result.Error->Error + ": " + result.Error->Message;
        }

        for (auto it = result.Logs.begin(); it != result.Logs.end(); ++it)
        {
            cloudScriptLogReport += "\n" + (*it).Message;
        }

        bool success = (cloudScriptLogReport.find("Hello " + PlayFabSettings::staticPlayer->playFabId + "!") != -1);
        if (!success)
        {
            testContext->Fail(cloudScriptLogReport);
        }
        else
        {
            testContext->Pass();
        }
    }

    // CLIENT API
    // Test that a lambda success callback can be successfully invoked
    void PlayFabApiTest::CloudScriptLambda(TestContext& testContext)
    {
        ExecuteCloudScriptRequest hwRequest;
        hwRequest.FunctionName = "helloWorld";

        clientApi->ExecuteCloudScript(hwRequest,
            [&](const ExecuteCloudScriptResult& constResult, void* customData) { OnHelloWorldCloudScript(constResult, customData); },
            Callback(&PlayFabApiTest::OnErrorSharedCallback),
            &testContext);
    }

    // CLIENT API
    // Test that CloudScript errors can be deciphered
    void PlayFabApiTest::CloudScriptError(TestContext& testContext)
    {
        if (!clientApi->IsClientLoggedIn())
        {
            testContext.Skip("Earlier tests failed to log in");
            return;
        }

        ExecuteCloudScriptRequest request;
        request.FunctionName = "throwError";

        clientApi->ExecuteCloudScript(request,
            Callback(&PlayFabApiTest::OnCloudScriptError),
            Callback(&PlayFabApiTest::OnErrorSharedCallback),
            &testContext);
    }
    void PlayFabApiTest::OnCloudScriptError(const ExecuteCloudScriptResult& result, void* customData)
    {
        TestContext* testContext = static_cast<TestContext*>(customData);
        bool success = true;
        success &= result.FunctionResult.isNull();
        success &= result.Error.notNull();
        success &= result.Error->Error.compare("JavascriptException") == 0;
        if (!success)
        {
            testContext->Fail("Expected Cloud Script error was not present.");
        }
        else
        {
            testContext->Pass();
        }
    }

    // CLIENT API
    // Test that the client can publish custom PlayStream events
    void PlayFabApiTest::WriteEvent(TestContext& testContext)
    {
        if (!clientApi->IsClientLoggedIn())
        {
            testContext.Skip("Earlier tests failed to log in");
            return;
        }

        WriteClientPlayerEventRequest request;
        request.EventName = "ForumPostEvent";
        request.Body["Subject"] = "My First Post";
        request.Body["Body"] = "My mega-sweet body text for my first post!";

        clientApi->WritePlayerEvent(request,
            Callback(&PlayFabApiTest::OnWritePlayerEvent),
            Callback(&PlayFabApiTest::OnErrorSharedCallback),
            &testContext);
    }
    void PlayFabApiTest::OnWritePlayerEvent(const WriteEventResponse&, void* customData)
    {
        TestContext* testContext = static_cast<TestContext*>(customData);
        testContext->Pass();
    }

    // ENTITY API
    // Verify that a client login can be converted into an entity token
    void PlayFabApiTest::GetEntityToken(TestContext& testContext)
    {
        if (!clientApi->IsClientLoggedIn())
        {
            testContext.Skip("Earlier tests failed to log in");
            return;
        }

        GetEntityTokenRequest request;
        authApi->GetEntityToken(request,
            Callback(&PlayFabApiTest::OnGetEntityToken),
            Callback(&PlayFabApiTest::OnErrorSharedCallback),
            &testContext);
    }
    void PlayFabApiTest::OnGetEntityToken(const GetEntityTokenResponse& result, void* customData)
    {
        TestContext* testContext = static_cast<TestContext*>(customData);

        if (result.Entity->Type != "title_player_account")
        {
            testContext->Fail("entityType unexpected: " + result.Entity->Type);
        }
        else if (result.Entity->Id.length() == 0)
        {
            testContext->Fail("EntityID was empty");
        }
        else
        {
            testContext->Pass();
        }
    }

    // ENTITY API
    // Test a sequence of calls that modifies entity objects,
    //   and verifies that the next sequential API call contains updated information.
    // Verify that the object is correctly modified on the next call.
    void PlayFabApiTest::ObjectApi(TestContext& testContext)
    {
        if (!clientApi->IsClientLoggedIn())
        {
            testContext.Skip("Earlier tests failed to log in");
            return;
        }

        GetObjectsRequest request;
        request.Entity.Id = PlayFabSettings::staticPlayer->entityId;
        request.Entity.Type = PlayFabSettings::staticPlayer->entityType;
        request.EscapeObject = true;
        dataApi->GetObjects(request,
            Callback(&PlayFabApiTest::OnGetObjects1),
            Callback(&PlayFabApiTest::OnErrorSharedCallback),
            &testContext);
    }
    void PlayFabApiTest::OnGetObjects1(const GetObjectsResponse& result, void* customData)
    {
        testMessageInt = 0;
        auto found = result.Objects.find(TEST_DATA_KEY);
        if (found != result.Objects.end())
        {
            testMessageInt = atoi(found->second.EscapedDataObject.c_str());
        }

        testMessageInt = (testMessageInt + 1) % 100;

        SetObjectsRequest request;
        request.Entity.Id = PlayFabSettings::staticPlayer->entityId;
        request.Entity.Type = PlayFabSettings::staticPlayer->entityType;

        SetObject updateObj;
        updateObj.ObjectName = TEST_DATA_KEY;
        updateObj.DataObject = testMessageInt;
        request.Objects.push_back(updateObj);

        dataApi->SetObjects(request,
            Callback(&PlayFabApiTest::OnSetObjects),
            Callback(&PlayFabApiTest::OnErrorSharedCallback),
            customData);
    }
    void PlayFabApiTest::OnSetObjects(const SetObjectsResponse&, void* customData)
    {
        GetObjectsRequest request;
        request.Entity.Id = PlayFabSettings::staticPlayer->entityId;
        request.Entity.Type = PlayFabSettings::staticPlayer->entityType;
        request.EscapeObject = true;

        dataApi->GetObjects(request,
            Callback(&PlayFabApiTest::OnGetObjects2),
            Callback(&PlayFabApiTest::OnErrorSharedCallback),
            customData);
    }
    void PlayFabApiTest::OnGetObjects2(const GetObjectsResponse& result, void* customData)
    {
        TestContext* testContext = static_cast<TestContext*>(customData);

        int actualDataValue = -1000;
        auto found = result.Objects.find(TEST_DATA_KEY);
        if (found != result.Objects.end())
        {
            actualDataValue = atoi(found->second.EscapedDataObject.c_str());
        }
        else
        {
            testContext->Fail("Object saved in SetObjects cannot be found in GetObjects.");
        }

        if (testMessageInt != actualDataValue)
        {
            testContext->Fail("User data not updated as expected.");
        }
        else
        {
            testContext->Pass();
        }
    }

    //
    //
    // Add test calls to this method, after implementation
    //
    //
    void PlayFabApiTest::AddTests()
    {
        // AddTest("InvalidSettings", &PlayFabApiTest::InvalidSettings);
        AddTest("InvalidLogin", &PlayFabApiTest::InvalidLogin);
        AddTest("InvalidLoginLambda", &PlayFabApiTest::InvalidLoginLambda);
        AddTest("InvalidRegistration", &PlayFabApiTest::InvalidRegistration);
        AddTest("LoginOrRegister", &PlayFabApiTest::LoginOrRegister);
        AddTest("UserDataApi", &PlayFabApiTest::UserDataApi);
        AddTest("PlayerStatisticsApi", &PlayFabApiTest::PlayerStatisticsApi);
        AddTest("GetServerTime", &PlayFabApiTest::GetServerTime);
        AddTest("UserCharacter", &PlayFabApiTest::UserCharacter);
        AddTest("LeaderBoard", &PlayFabApiTest::LeaderBoard);
        AddTest("AccountInfo", &PlayFabApiTest::AccountInfo);
        AddTest("CloudScript", &PlayFabApiTest::CloudScript);
        AddTest("CloudScriptLambda", &PlayFabApiTest::CloudScriptLambda);
        AddTest("CloudScriptError", &PlayFabApiTest::CloudScriptError);
        AddTest("WriteEvent", &PlayFabApiTest::WriteEvent);
        AddTest("GetEntityToken", &PlayFabApiTest::GetEntityToken);
        AddTest("ObjectApi", &PlayFabApiTest::ObjectApi);
    }

    void PlayFabApiTest::ClassSetUp()
    {
        authApi = std::make_shared<PlayFabAuthenticationInstanceAPI>(PlayFabSettings::staticPlayer);
        clientApi = std::make_shared<PlayFabClientInstanceAPI>(PlayFabSettings::staticPlayer);
        dataApi = std::make_shared<PlayFabDataInstanceAPI>(PlayFabSettings::staticPlayer);

        PlayFabSettings::staticSettings->titleId = testTitleData.titleId;
        USER_EMAIL = testTitleData.userEmail;

        // Verify all the inputs won't cause crashes in the tests
        TITLE_INFO_SET = !PlayFabSettings::staticSettings->titleId.empty() && !USER_EMAIL.empty();

        // Make sure PlayFab state is clean.
        PlayFabSettings::ForgetAllCredentials();

        testMessageInt = 0;
        testMessageTime = PlayFab::GetTimePointNow();
    }

    void PlayFabApiTest::SetUp(TestContext& testContext)
    {
        if (!TITLE_INFO_SET)
        {
            testContext.Skip(); // We cannot do client tests if the titleId is not given
        }
    }

    void PlayFabApiTest::Tick(TestContext& /*testContext*/)
    {
        // No work needed, async tests will end themselves
    }

    void PlayFabApiTest::ClassTearDown()
    {
        // Clean up any PlayFab state for next TestCase.
        PlayFabSettings::ForgetAllCredentials();
    }
}

#endif
