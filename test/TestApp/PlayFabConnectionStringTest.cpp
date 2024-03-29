// Copyright (C) Microsoft Corporation. All rights reserved.

#include "TestAppPch.h"

#if !defined(DISABLE_PLAYFABCLIENT_API)

#include <thread>
#include <chrono>
#include <playfab/PlayFabClientDataModels.h>
#include <playfab/PlayFabClientInstanceApi.h>
#include <playfab/PlayFabEventsDataModels.h>
#include <playfab/PlayFabEventsInstanceApi.h>
#include <playfab/PlayFabSettings.h>
#include "PlayFabConnectionStringTest.h"
#include "TestContext.h"
#include "TestDataTypes.h"

using namespace PlayFab;
using namespace ClientModels;
using namespace EventsModels;

namespace PlayFabUnit
{
    void PlayFabConnectionStringTest::OnErrorSharedCallback(const PlayFab::PlayFabError& error, void* customData)
    {
        TestContext* testContext = static_cast<TestContext*>(customData);
        testContext->Fail(error.GenerateErrorReport());
    }

    void PlayFabConnectionStringTest::BasicLogin(TestContext& testContext)
    {
        LoginWithCustomIDRequest request;
        request.CustomId = PlayFabSettings::buildIdentifier + "ConnectionStringTest";
        request.CreateAccount = true;

        clientApi->LoginWithCustomID(request,
            ApiCallback(&PlayFabConnectionStringTest::OnLogin),
            ApiCallback(&PlayFabConnectionStringTest::OnErrorSharedCallback),
            &testContext);
    }

    void PlayFabConnectionStringTest::OnLogin(const PlayFab::ClientModels::LoginResult& /*result*/, void* customData)
    {
        TestContext* testContext = static_cast<TestContext*>(customData);
        testContext->Pass();
    }

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

    void PlayFabConnectionStringTest::EventsApi(TestContext& testContext)
    {
        if (!PlayFabSettings::staticPlayer->IsClientLoggedIn())
        {
            testContext.Skip("Earlier tests failed to log in");
            return;
        }

        EventsModels::WriteEventsRequest request;

        // TODO: Bug 38165 automated builds either time out here or tests will never complete.
        // send several events
        for (int i = 0; i < 2; i++)
        {
            request.Events.push_back(CreateEventContents("event_A_", 0));
            request.Events.push_back(CreateEventContents("event_B_", i));
        }

        eventsApi->WriteEvents(request,
            ApiCallback(&PlayFabConnectionStringTest::OnEventsApiSucceeded),
            ApiCallback(&PlayFabConnectionStringTest::OnEventsApiFailed),
            &testContext);
    }

    void PlayFabConnectionStringTest::OnEventsApiSucceeded(const PlayFab::EventsModels::WriteEventsResponse&, void* customData)
    {
        TestContext* testContext = static_cast<TestContext*>(customData);
        testContext->Pass();
    }

    void PlayFabConnectionStringTest::OnEventsApiFailed(const PlayFab::PlayFabError& error, void* customData)
    {
        TestContext* testContext = static_cast<TestContext*>(customData);
        testContext->Fail(error.GenerateErrorReport());
    }

    void PlayFabConnectionStringTest::NonStaticEmitEventCallback(std::shared_ptr<const PlayFab::IPlayFabEvent> event, std::shared_ptr<const PlayFab::IPlayFabEmitEventResponse> /*response*/)
    {
        auto pfEvent = std::dynamic_pointer_cast<const TestConnectionStringEvent>(event);
        pfEvent->testContext->Pass("Private member called back!");
    }

    void PlayFabConnectionStringTest::QueueTestCallback(std::shared_ptr<const PlayFab::IPlayFabEvent> event, std::shared_ptr<const PlayFab::IPlayFabEmitEventResponse> /*response*/)
    {
        queueTestCount++;

        if(queueTestCount >= c_numQueueTestEvents)
        {
            auto pfEvent = std::dynamic_pointer_cast<const TestConnectionStringEvent>(event);
            pfEvent->testContext->Pass("Private member called back!");
        }
    }

    void PlayFabConnectionStringTest::EmitEventCallback(std::shared_ptr<const PlayFab::IPlayFabEvent> event, std::shared_ptr<const PlayFab::IPlayFabEmitEventResponse> response)
    {
        auto pfEvent = std::dynamic_pointer_cast<const TestConnectionStringEvent>(event);
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
            pfEvent->testContext->Fail("EmitEventCallback received an error");
        }

        // Complete the test once all events have been processed.
        const int eventCount = eventPassCount + eventFailCount;
        if (eventCount >= eventEmitCount)
        {
            if (eventBatchMax >= eventEmitCount)
            {
                pfEvent->testContext->Fail("Events did not batch:\n" + eventFailLog);
            }
            else if (eventFailCount > 0)
            {
                pfEvent->testContext->Fail("Events failed delivery:\n" + eventFailLog);
            }
            else
            {
                pfEvent->testContext->Pass();
            }
        }
    }

    void PlayFabConnectionStringTest::EmitEvents(TestContext& testContext, PlayFab::PlayFabEventType eventType, int maxBatchWaitTime, int maxItemsInBatch, int maxBatchesInFlight)
    {
        std::shared_ptr<PlayFabEventAPI> api = SetupEventTest(maxBatchWaitTime, maxItemsInBatch, maxBatchesInFlight);
        // Emit several events quickly.
        // They will be batched up according to pipeline's settings
        for (int i = 0; i < eventEmitCount; i++)
        {
            std::unique_ptr<PlayFab::PlayFabEvent> event = MakeEvent(testContext, eventType);
            api->EmitEvent(std::move(event), EmitCallback(&PlayFabConnectionStringTest::EmitEventCallback));
        }
    }

    /// EVENTS API
    /// PlayFab heavyweight events (emitted individually
    ///   and processed in a background thread using event pipeline (router, batching, etc))
    void PlayFabConnectionStringTest::HeavyweightEvents(TestContext& testContext)
    {
        int maxBatchWaitTime = 4;
        int maxItemsInBatch = 4;
        int maxBatchesInFlight = 3;

        EmitEvents(testContext, PlayFab::PlayFabEventType::Heavyweight, maxBatchWaitTime, maxItemsInBatch, maxBatchesInFlight);
    }

    /// EVENTS API
    /// non-PlayStream lightweight events (emitted individually
    ///   and processed in a background thread using event pipeline (router, batching, etc))
    void PlayFabConnectionStringTest::LightweightEvents(TestContext& testContext)
    {
        EmitEvents(testContext, PlayFab::PlayFabEventType::Lightweight);
    }

    void PlayFabConnectionStringTest::LambdaCallbackTest(TestContext& testContext)
    {
        std::shared_ptr<PlayFabEventAPI> api = SetupEventTest();

        api->EmitEvent(MakeEvent(testContext, PlayFabEventType::Default),
            [&testContext]
        (std::shared_ptr<const IPlayFabEvent>, std::shared_ptr<const IPlayFabEmitEventResponse>)
        {
            if (testContext.activeState != TestActiveState::COMPLETE)
            {
                testContext.Pass("Lambda Function Callback Succeeded.");
            }
        });
    }

    void PlayFabConnectionStringTest::PrivateMemberCallbackTest(TestContext& testContext)
    {
        std::shared_ptr<PlayFabEventAPI> eventApi = SetupEventTest();

        eventApi->EmitEvent(MakeEvent(testContext, PlayFabEventType::Default), EmitCallback(&PlayFabConnectionStringTest::NonStaticEmitEventCallback));
    }

    void PlayFabConnectionStringTest::GenericMultiThreadedTest(TestContext& testContext, uint32_t pNumThreads, uint32_t pNumEventsPerThread)
    {
        uint32_t totalEvents = pNumThreads * pNumEventsPerThread;
        std::atomic<int> eventsRemaining(totalEvents);
        for (uint32_t thread = 0; thread < pNumThreads; ++thread)
        {
            std::shared_ptr<PlayFabEventAPI> api = SetupEventTest();
            testThreadPool.emplace_back(
                [&testContext, api, &eventsRemaining, totalEvents, pNumEventsPerThread, this]()
            {
                try
                {
                    for (uint32_t i = 0; i < pNumEventsPerThread; ++i)
                    {
                        api->EmitEvent(MakeEvent(testContext, PlayFabEventType::Default),
                            [&testContext, &eventsRemaining, totalEvents]
                        (std::shared_ptr<const PlayFab::IPlayFabEvent>, std::shared_ptr<const PlayFab::IPlayFabEmitEventResponse>)
                        {
                            if (--eventsRemaining <= 0)
                            {
                                testContext.Pass("Threaded callback Received all events Emitted.");
                            }
                            else
                            {
                                testContext.SetInterrimMessage(std::to_string(eventsRemaining) + "/" + std::to_string(totalEvents) + " events remaining...");
                            }
                        }
                        );
                    }
                    std::this_thread::yield();
                }
                catch (std::exception ex)
                {
                    testContext.Fail(ex.what());
                }
            }
            );
        }
    }

    void PlayFabConnectionStringTest::BasicMultiThreadedTest(TestContext& testContext)
    {
        uint32_t numThreads = 6;
        uint32_t numEventsPerThread = 5;
        GenericMultiThreadedTest(testContext, numThreads, numEventsPerThread);
    }

    void PlayFabConnectionStringTest::ManyThreadsLowEventsPerTest(TestContext& testContext)
    {
        // NOTE: Some platforms have hard limits on the maximum number of threads (this number found to be experimentally safe)
        uint32_t numThreads = 30;
        uint32_t numEventsPerThread = 2;
        GenericMultiThreadedTest(testContext, numThreads, numEventsPerThread);
    }

    void PlayFabConnectionStringTest::FewThreadsHighEventsPerTest(TestContext& testContext)
    {
        uint32_t numThreads = 2;
        uint32_t numEventsPerThread = 15;
        GenericMultiThreadedTest(testContext, numThreads, numEventsPerThread);
    }

    void PlayFabConnectionStringTest::TestQueueBeforeLogin(TestContext& testContext)
    {
        queueTestCount = 0;
        std::shared_ptr<PlayFabEventAPI> eventApi = SetupEventTest();

        // Queue 2 events to PlayFabEventPipeline
        eventApi->EmitEvent(MakeEvent(testContext, PlayFabEventType::Default), EmitCallback(&PlayFabConnectionStringTest::QueueTestCallback));
        eventApi->EmitEvent(MakeEvent(testContext, PlayFabEventType::Default), EmitCallback(&PlayFabConnectionStringTest::QueueTestCallback));

        // Login
        LoginWithCustomIDRequest request;
        request.CustomId = PlayFabSettings::buildIdentifier;
        request.CreateAccount = true;

        clientApi->LoginWithCustomID(request,
            ApiCallback(&PlayFabConnectionStringTest::OnQueingTestLogin),
            ApiCallback(&PlayFabConnectionStringTest::OnErrorSharedCallback),
            &testContext);

        // when we see all 4 events come in, we pass, otherwise we time out and fail
    }

    void PlayFabConnectionStringTest::OnQueingTestLogin(const PlayFab::ClientModels::LoginResult& /*result*/, void* customData)
    {
        std::shared_ptr<PlayFabEventAPI> eventApi = SetupEventTest();
        TestContext* testContext = static_cast<TestContext*>(customData);

        // Queue 2 more events
        eventApi->EmitEvent(MakeEvent(*testContext, PlayFabEventType::Default), EmitCallback(&PlayFabConnectionStringTest::QueueTestCallback));
        eventApi->EmitEvent(MakeEvent(*testContext, PlayFabEventType::Default), EmitCallback(&PlayFabConnectionStringTest::QueueTestCallback));
    }

    void PlayFabConnectionStringTest::AddTests()
    {
        AddTest("BasicLogin", &PlayFabConnectionStringTest::BasicLogin);
        AddTest("EventsApi", &PlayFabConnectionStringTest::EventsApi);
        AddTest("HeavyweightEvents", &PlayFabConnectionStringTest::HeavyweightEvents);
        AddTest("LightweightEvents", &PlayFabConnectionStringTest::LightweightEvents);
        AddTest("LambdaCallback", &PlayFabConnectionStringTest::LambdaCallbackTest);
        AddTest("PrivateMemberCallback", &PlayFabConnectionStringTest::PrivateMemberCallbackTest);
        AddTest("BasicMultiThreadedTest", &PlayFabConnectionStringTest::BasicMultiThreadedTest);
        AddTest("ManyThreadsLowEventsPerTest", &PlayFabConnectionStringTest::ManyThreadsLowEventsPerTest);
        AddTest("FewThreadsHighEventsPerTest", &PlayFabConnectionStringTest::FewThreadsHighEventsPerTest);
        AddTest("TestQueueBeforeLogin", &PlayFabConnectionStringTest::TestQueueBeforeLogin);
    }

    void PlayFabConnectionStringTest::ClassSetUp()
    {
        PlayFabSettings::staticSettings->connectionString = testTitleData.connectionString;
        clientApi = std::make_shared<PlayFabClientInstanceAPI>(PlayFabSettings::staticSettings, PlayFabSettings::staticPlayer);
        eventsApi = std::make_shared<PlayFabEventsInstanceAPI>(PlayFabSettings::staticSettings, PlayFabSettings::staticPlayer);

        // Make sure PlayFab state is clean.
        PlayFabSettings::ForgetAllCredentials();
    }

    void PlayFabConnectionStringTest::SetUp(TestContext& /*testContext*/)
    {
        // PlayFabSettings::staticSettings->titleId = testTitleData.titleId;
        // Reset event test values.
        eventBatchMax = 0;
        eventPassCount = 0;
        eventFailCount = 0;
        eventFailLog = "";
    }

    void PlayFabConnectionStringTest::Tick(TestContext& /*testContext*/)
    {
        // No work needed, async tests will end themselves
    }

    void PlayFabConnectionStringTest::TearDown(TestContext& /*testContext*/)
    {
        for (auto& thread : testThreadPool)
        {
            thread.join();
        }
        testThreadPool.clear();
        eventApiPool.clear();
    }

    void PlayFabConnectionStringTest::ClassTearDown()
    {
        // Clean up any PlayFab state for next TestCase.
        PlayFabSettings::ForgetAllCredentials();
    }

    std::shared_ptr<PlayFabEventAPI> PlayFabConnectionStringTest::SetupEventTest(int maxBatchWaitTime, int maxItemsInBatch, int maxBatchesInFlight)
    {
        // test custom event API (it uses event pipeline (router, batching, etc))
        auto api = std::make_shared<PlayFabEventAPI>(); // create Event API instance

        // adjust some pipeline settings
        auto pipeline = std::dynamic_pointer_cast<PlayFab::PlayFabEventPipeline>(api->GetEventRouter()->GetPipelines().at(PlayFab::EventPipelineKey::PlayFabTelemetry)); // get non-playstream pipeline
        std::shared_ptr<PlayFab::PlayFabEventPipelineSettings>  settings = pipeline->GetSettings(); // get pipeline's settings
        settings->maximalBatchWaitTime = maxBatchWaitTime; // incomplete batch expiration in seconds
        settings->maximalNumberOfItemsInBatch = maxItemsInBatch; // number of events in a batch
        settings->maximalNumberOfBatchesInFlight = maxBatchesInFlight; // maximal number of batches processed simultaneously by a transport plugin before taking next events from the buffer

        eventApiPool.push_back(api);
        return api;
    }

    std::unique_ptr<PlayFab::PlayFabEvent> PlayFabConnectionStringTest::MakeEvent(TestContext& testContext, PlayFab::PlayFabEventType eventType)
    {
        auto testEvent = new TestConnectionStringEvent();
        testEvent->testContext = &testContext;
        auto event = std::unique_ptr<PlayFab::PlayFabEvent>(testEvent);

        int i = eventCounter.fetch_add(1);

        // user can specify whether it's
        // - lightweight (goes to WriteTelemetryEvents),
        // - heavyweight (goes to WriteEvents),
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

#endif
