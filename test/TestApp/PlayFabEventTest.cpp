// Copyright (C) Microsoft Corporation. All rights reserved.

#include "TestAppPch.h"
#include <thread>
#include <chrono>
#include <playfab/PlayFabClientApi.h>
#include <playfab/PlayFabEventsApi.h>
#include <playfab/PlayFabSettings.h>
#include <playfab/QoS/PlayFabQoSApi.h>
#include "PlayFabEventTest.h"
#include "TestContext.h"
#include "TestDataTypes.h"

using namespace PlayFab;
using namespace ClientModels;
using namespace EventsModels;

namespace PlayFabUnit
{
#if (!UNITY_IOS && !UNITY_ANDROID) && (!defined(PLAYFAB_PLATFORM_IOS) && !defined(PLAYFAB_PLATFORM_ANDROID))
    /// QoS API
    void PlayFabEventTest::QosResultApi(TestContext& testContext)
    {
        QoS::PlayFabQoSApi api;

        auto result = api.GetQoSResult(5, 200);

        if (result.errorCode == 0)
            testContext.Pass();
        else
            testContext.Fail("Error Code:" + std::to_string(result.errorCode));
    }
#endif

    /// EVENTS API
    /// Test that sends heavyweight events as a whole batch.
    static EventContents CreateEventContents(const std::string& eventName, int i)
    {
        PlayFab::EventsModels::EventContents event;
        std::stringstream name;
        name << eventName << i;
        event.Name = name.str();
        event.EventNamespace = "com.playfab.events.default";
        event.Payload["PropA"] = "prop-value-a";
        event.Payload["PropB"] = "prop-value-b";
        return event;
    }
    void PlayFabEventTest::EventsApi(TestContext& testContext)
    {
        if (!PlayFabClientAPI::IsClientLoggedIn())
        {
            testContext.Skip("Earlier tests failed to log in");
            return;
        }

        EventsModels::WriteEventsRequest request;

        // send several events
        for (int i = 0; i < 2; i++)
        {
            request.Events.push_back(CreateEventContents("event_A_", i));
            request.Events.push_back(CreateEventContents("event_B_", i));
        }

        PlayFabEventsAPI::WriteEvents(request,
            Callback(&PlayFabEventTest::OnEventsApiSucceeded),
            Callback(&PlayFabEventTest::OnEventsApiFailed),
            &testContext);
    }
    void PlayFabEventTest::OnEventsApiSucceeded(const PlayFab::EventsModels::WriteEventsResponse&, void* customData)
    {
        TestContext* testContext = reinterpret_cast<TestContext*>(customData);
        testContext->Pass();
    }
    void PlayFabEventTest::OnEventsApiFailed(const PlayFab::PlayFabError& error, void* customData)
    {
        TestContext* testContext = reinterpret_cast<TestContext*>(customData);
        testContext->Fail(error.GenerateErrorReport());
    }

    /// EVENTS API
    /// Shared functions & data
    std::shared_ptr<TestContext*> PlayFabEventTest::eventTestContext;
    size_t PlayFabEventTest::eventBatchMax;
    int PlayFabEventTest::eventPassCount;
    int PlayFabEventTest::eventFailCount;
    std::string PlayFabEventTest::eventFailLog;

    void PlayFabEventTest::NonStaticEmitEventCallback(std::shared_ptr<const PlayFab::IPlayFabEvent> event, std::shared_ptr<const PlayFab::IPlayFabEmitEventResponse> response)
    {
        (*eventTestContext)->Pass("Private member called back!");
    }
    
    void PlayFabEventTest::EmitEventCallback(std::shared_ptr<const PlayFab::IPlayFabEvent> event, std::shared_ptr<const PlayFab::IPlayFabEmitEventResponse> response)
    {
        auto pfEvent = std::dynamic_pointer_cast<const PlayFab::PlayFabEvent>(event);
        auto pfResponse = std::dynamic_pointer_cast<const PlayFab::PlayFabEmitEventResponse>(response);

        if (pfResponse->playFabError != nullptr)
        {
            // Handle successful event delivery.
            if (PlayFab::PlayFabErrorCode::PlayFabErrorSuccess == pfResponse->playFabError->ErrorCode)
            {
                ++eventPassCount;
                eventFailLog += pfEvent->GetName() + " was sent successfully " +
                    "in the batch #" + std::to_string(pfResponse->batchNumber) + " "
                    "of " + std::to_string(pfResponse->batch->size()) + " events. "
                    "HTTP code: " + std::to_string(pfResponse->playFabError->HttpCode) +
                    ", app error code: " + std::to_string(static_cast<int>(pfResponse->playFabError->ErrorCode)) + "\n";

                // Keep track of the highest batch number.
                eventBatchMax = (pfResponse->batchNumber > eventBatchMax) ? pfResponse->batchNumber : eventBatchMax;
            }
            // Handle failed event delivery.
            else
            {
                ++eventFailCount;
                eventFailLog += pfEvent->GetName() + " received an error back " +
                    "in the batch #" + std::to_string(pfResponse->batchNumber) + " "
                    "of " + std::to_string(pfResponse->batch->size()) + " events. "
                    "HTTP code: " + std::to_string(pfResponse->playFabError->HttpCode) +
                    ", app error code: " + std::to_string(static_cast<int>(pfResponse->playFabError->ErrorCode)) +
                    ", HTTP status: " + pfResponse->playFabError->HttpStatus +
                    ", Message: " + pfResponse->playFabError->ErrorMessage +
                    "\n";
            }
        }
        else 
        {
            (*eventTestContext)->Fail("EmitEventCallback received an error");
        }

        // Complete the test once all events have been processed.
        const int eventCount = eventPassCount + eventFailCount;
        if (eventCount >= eventEmitCount)
        {
            if (eventBatchMax >= eventEmitCount)
                (*eventTestContext)->Fail("Events did not batch:\n" + eventFailLog);
            else if (eventFailCount > 0)
                (*eventTestContext)->Fail("Events failed delivery:\n" + eventFailLog);
            else
                (*eventTestContext)->Pass();
        }
    }

    void PlayFabEventTest::EmitEvents(PlayFab::PlayFabEventType eventType, int maxBatchWaitTime, int maxItemsInBatch, int maxBatchesInFlight)
    {
        std::shared_ptr<PlayFabEventAPI*> api = SetupEventTest(maxBatchWaitTime, maxItemsInBatch, maxBatchesInFlight);
        // Emit several events quickly.
        // They will be batched up according to pipeline's settings
        for (int i = 0; i < eventEmitCount; i++)
        {
            auto event = MakeEvent(i, eventType);
            (*api)->EmitEvent(std::move(event), EmitEventCallback);
        }
    }

    /// EVENTS API
    /// PlayFab heavyweight events (emitted individually
    ///   and processed in a background thread using event pipeline (router, batching, etc))
    void PlayFabEventTest::HeavyweightEvents(TestContext& testContext)
    {
        eventTestContext = std::make_shared<TestContext*>(&testContext);

        int maxBatchWaitTime = 4;
        int maxItemsInBatch = 4;
        int maxBatchesInFlight = 3;

        EmitEvents(PlayFab::PlayFabEventType::Heavyweight, maxBatchWaitTime, maxItemsInBatch, maxBatchesInFlight);
    }

    /// EVENTS API
    /// non-PlayStream lightweight events (emitted individually
    ///   and processed in a background thread using event pipeline (router, batching, etc))
    void PlayFabEventTest::LightweightEvents(TestContext& testContext)
    {
        eventTestContext = std::make_shared<TestContext*>(&testContext);

        EmitEvents(PlayFab::PlayFabEventType::Lightweight);
    }

    void PlayFabEventTest::LambdaCallbackTest(TestContext& testContext)
    {
        eventTestContext = std::make_shared<TestContext*>(&testContext);

        std::shared_ptr<PlayFabEventAPI*> api = SetupEventTest();

        (*api)->EmitEvent(MakeEvent(0, PlayFabEventType::Default),
            [&testContext]
            (std::shared_ptr<const IPlayFabEvent>, std::shared_ptr<const IPlayFabEmitEventResponse>)
            { if(testContext.activeState != TestActiveState::COMPLETE){ testContext.Pass("Lambda Function Callback Succeeded.");}});
    }

    void PlayFabEventTest::PrivateMemberCallbackTest(TestContext& testContext)
    {
        eventTestContext = std::make_shared<TestContext*>(&testContext);

        std::shared_ptr<PlayFabEventAPI*> api = SetupEventTest();

        (*api)->EmitEvent(MakeEvent(0, PlayFabEventType::Default),
        std::bind(&PlayFabEventTest::NonStaticEmitEventCallback, this, std::placeholders::_1, std::placeholders::_2));
    }

    void PlayFabEventTest::AddTests()
    {
        // TODO: Fix whatever limitation causes this test to fail for these platforms
#if !defined(PLAYFAB_PLATFORM_IOS) && !defined(PLAYFAB_PLATFORM_ANDROID) && !defined(PLAYFAB_PLATFORM_PLAYSTATION)
        AddTest("QosResultApi", &PlayFabEventTest::QosResultApi);
#endif
        AddTest("EventsApi", &PlayFabEventTest::EventsApi);
        AddTest("HeavyweightEvents", &PlayFabEventTest::HeavyweightEvents);
        AddTest("LightweightEvents", &PlayFabEventTest::LightweightEvents);
        AddTest("LambdaCallback", &PlayFabEventTest::LambdaCallbackTest);
        AddTest("PrivateMemberCallback", &PlayFabEventTest::PrivateMemberCallbackTest);
    }

    void PlayFabEventTest::ClassSetUp()
    {
        // Make sure PlayFab state is clean.
        PlayFabSettings::ForgetAllCredentials();

        // Log in to use event functions.
        LoginWithCustomIDRequest request;
        request.CustomId = PlayFabSettings::buildIdentifier;
        request.CreateAccount = true;

        loggedIn = false;
        bool loginComplete = false;
        PlayFabClientAPI::LoginWithCustomID(request,
            [&loginComplete](const LoginResult& /*result*/, void* customData)
            {
                *reinterpret_cast<bool*>(customData) = true;
                loginComplete = true;
            },
            [&loginComplete](const PlayFabError /*error*/, void* customData)
            {
                *reinterpret_cast<bool*>(customData) = false;
                loginComplete = true;
            },
            &loggedIn);
        
        // Sleep while waiting for log in to complete.
        while (!loginComplete)
        {
            std::this_thread::sleep_for(TimeValueMs(100));
        }
    }

    void PlayFabEventTest::SetUp(TestContext& testContext)
    {
        if (!loggedIn)
            testContext.Skip("Not logged in to PlayFab"); // Cannot run event tests if not logged in

        // Reset event test values.
        eventBatchMax = 0;
        eventPassCount = 0;
        eventFailCount = 0;
        eventFailLog = "";
    }

    void PlayFabEventTest::Tick(TestContext& /*testContext*/)
    {
        // No work needed, async tests will end themselves
    }

    void PlayFabEventTest::TearDown(TestContext& /*testContext*/)
    {
        eventTestContext = nullptr;
        eventApi = nullptr;
    }

    void PlayFabEventTest::ClassTearDown()
    {
        // Clean up any PlayFab state for next TestCase.
        PlayFabSettings::ForgetAllCredentials();
    }

    std::shared_ptr<PlayFabEventAPI*> PlayFabEventTest::SetupEventTest(int maxBatchWaitTime, int maxItemsInBatch, int maxBatchesInFlight)
    {
        // test custom event API (it uses event pipeline (router, batching, etc))
        std::shared_ptr<PlayFabEventAPI*> api = std::make_shared<PlayFabEventAPI*>(new PlayFabEventAPI()); // create Event API instance

        // adjust some pipeline settings
        auto pipeline = std::dynamic_pointer_cast<PlayFab::PlayFabEventPipeline>((*api)->GetEventRouter()->GetPipelines().at(PlayFab::EventPipelineKey::PlayFabTelemetry)); // get non-playstream pipeline
        auto settings = pipeline->GetSettings(); // get pipeline's settings
        settings->maximalBatchWaitTime = maxBatchWaitTime; // incomplete batch expiration in seconds
        settings->maximalNumberOfItemsInBatch = maxItemsInBatch; // number of events in a batch
        settings->maximalNumberOfBatchesInFlight = maxBatchesInFlight; // maximal number of batches processed simultaneously by a transport plugin before taking next events from the buffer
        return api;
    }

    std::unique_ptr<PlayFab::PlayFabEvent> PlayFabEventTest::MakeEvent(int i, PlayFab::PlayFabEventType eventType)
    {
        auto event = std::unique_ptr<PlayFab::PlayFabEvent>(new PlayFab::PlayFabEvent());

        // user can specify whether it's 
        // - lightweight (goes to 1DS), 
        // - heavyweight (goes to PlayFab's WriteEvents), 
        // - or anything else
        event->eventType = eventType;
        std::stringstream name;
        name << "event_" << i;
        event->SetName(name.str());
        event->SetProperty("prop_A", 123);
        event->SetProperty("prop_B", "hello, world!");
        event->SetProperty("prop_C", true);
        return event;
    }
}