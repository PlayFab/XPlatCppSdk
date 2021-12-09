// Copyright (C) Microsoft Corporation. All rights reserved.

#pragma once

#if !defined(DISABLE_PLAYFABCLIENT_API)

#include <functional>
#include <string>
#include <playfab/PlayFabEventApi.h>
#include "TestCase.h"

namespace PlayFab
{
    struct PlayFabError;

    namespace EventsModels
    {
        struct TelemetryIngestionConfigResponse;
        struct WriteEventsResponse;
    }
}

namespace PlayFabUnit
{
    struct TestContext;

    // A wrapper around TestEvents, so we can track it back to the test that launched the event
    class TestConnectionStringEvent : public PlayFab::PlayFabEvent
    {
    public:
        TestContext* testContext;
    };

    class PlayFabConnectionStringTest : public PlayFabApiTestCase
    {
    private:
        std::shared_ptr<PlayFab::PlayFabClientInstanceAPI> clientApi;
        std::shared_ptr<PlayFab::PlayFabEventsInstanceAPI> eventsApi;

        // Initial Login
        void OnErrorSharedCallback(const PlayFab::PlayFabError& error, void* customData);
        void BasicLogin(TestContext& testContext);
        void OnLogin(const PlayFab::ClientModels::LoginResult& result, void* customData);

        /// EVENTS API
        /// Test that sends heavyweight events as a whole batch.
        void EventsApi(TestContext& testContext);
        void OnEventsApiSucceeded(const PlayFab::EventsModels::WriteEventsResponse&, void* customData);
        void OnEventsApiFailed(const PlayFab::PlayFabError& error, void* customData);

        /// EVENTS API
        /// PlayFab heavyweight events (emitted individually
        ///   and processed in a background thread using event pipeline (router, batching, etc))
        void HeavyweightEvents(TestContext& testContext);

        /// EVENTS API
        /// Non-PlayStream, lightweight events (emitted individually
        ///   and processed in a background thread using event pipeline (router, batching, etc))
        void LightweightEvents(TestContext& testContext);

        void LambdaCallbackTest(TestContext& testContext);
        void PrivateMemberCallbackTest(TestContext& testContext);

        // We need to make sure these are able to pass within TEST_TIMEOUT_DURATION
        void BasicMultiThreadedTest(TestContext& testContext);
        void ManyThreadsLowEventsPerTest(TestContext& testContext);
        void FewThreadsHighEventsPerTest(TestContext& testContext);

        void GenericMultiThreadedTest(TestContext& testContext, uint32_t pNumThreads, uint32_t pNumEventsPerThread);

        void TestQueueBeforeLogin(TestContext& testContext);
        void OnQueingTestLogin(const PlayFab::ClientModels::LoginResult& result, void* customData);

        // State
        const int eventEmitCount = 6;
        size_t eventBatchMax;
        int eventPassCount;
        int eventFailCount;
        std::string eventFailLog;
        std::vector<std::thread> testThreadPool;
        std::vector<std::shared_ptr<PlayFab::PlayFabEventAPI>> eventApiPool;
        std::atomic<uint32_t> eventCounter;
        std::atomic<uint32_t> queueTestCount;
        const uint32_t c_numQueueTestEvents = 4;

        // Utility
        void EmitEvents(TestContext& testContext, PlayFab::PlayFabEventType eventType, int maxBatchWaitTime = 2, int maxItemsInBatch = 3, int maxBatchesInFlight = 10);
        void EmitEventCallback(std::shared_ptr<const PlayFab::IPlayFabEvent> event, std::shared_ptr<const PlayFab::IPlayFabEmitEventResponse> response);
        void NonStaticEmitEventCallback(std::shared_ptr<const PlayFab::IPlayFabEvent> event, std::shared_ptr<const PlayFab::IPlayFabEmitEventResponse> response);
        void QueueTestCallback(std::shared_ptr<const PlayFab::IPlayFabEvent> event, std::shared_ptr<const PlayFab::IPlayFabEmitEventResponse> response);

        template<typename T> std::function<void(const T&, void*)> ApiCallback(void(PlayFabConnectionStringTest::* func)(const T&, void*))
        {
            return std::bind(func, this, std::placeholders::_1, std::placeholders::_2);
        }
        std::function<void(std::shared_ptr<const PlayFab::IPlayFabEvent>, std::shared_ptr<const PlayFab::IPlayFabEmitEventResponse>)> EmitCallback(void(PlayFabConnectionStringTest::* func)(std::shared_ptr<const PlayFab::IPlayFabEvent>, std::shared_ptr<const PlayFab::IPlayFabEmitEventResponse>))
        {
            return std::bind(func, this, std::placeholders::_1, std::placeholders::_2);
        }

        std::shared_ptr<PlayFab::PlayFabEventAPI> SetupEventTest(int maxBatchWaitTime = 2, int maxItemSinBatch = 3, int maxBatchesInFlight = 10);
        std::unique_ptr<PlayFab::PlayFabEvent> MakeEvent(TestContext& testContext, PlayFab::PlayFabEventType eventType);

    protected:
        void AddTests() override;

    public:
        void ClassSetUp() override;
        void SetUp(TestContext& /*testContext*/) override;
        void Tick(TestContext& testContext) override;
        void TearDown(TestContext& /*testContext*/) override;
        void ClassTearDown() override;
    };
}

#endif

