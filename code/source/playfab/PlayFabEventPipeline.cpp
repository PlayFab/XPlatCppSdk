#include <stdafx.h>

#ifndef DISABLE_PLAYFABENTITY_API

#include <chrono>
#include <playfab/PlayFabEventPipeline.h>
#include <playfab/PlayFabEventsApi.h>

namespace PlayFab
{
    static const int defaultBufferSize = 256;
    static const int defaultMaxItemsInBatch = 5;
    static const int defaultMaxBatchWaitTimeInSeconds = 3;
    static const int defaultMaxBatchesInFlight = 16;
    static const int defaultReadBufferWaitTimeInMs = 10;

    PlayFabEventPipelineSettings::PlayFabEventPipelineSettings() :
        bufferSize(defaultBufferSize),
        maximalNumberOfItemsInBatch(defaultMaxItemsInBatch),
        maximalBatchWaitTime(defaultMaxBatchWaitTimeInSeconds),
        maximalNumberOfBatchesInFlight(defaultMaxBatchesInFlight),
        readBufferWaitTime(defaultReadBufferWaitTimeInMs),
        authenticationContext(nullptr),
        emitType(PlayFabEventPipelineType::PlayFabPlayStream)
    {
    }

    PlayFabEventPipelineSettings::PlayFabEventPipelineSettings(PlayFabEventPipelineType type) :
        bufferSize(defaultBufferSize),
        maximalNumberOfItemsInBatch(defaultMaxItemsInBatch),
        maximalBatchWaitTime(defaultMaxBatchWaitTimeInSeconds),
        maximalNumberOfBatchesInFlight(defaultMaxBatchesInFlight),
        readBufferWaitTime(defaultReadBufferWaitTimeInMs),
        authenticationContext(nullptr),
        emitType(type)
    {
    }

    PlayFabEventPipeline::PlayFabEventPipeline(const std::shared_ptr<PlayFabEventPipelineSettings>& settings) :
        buffer(settings->bufferSize),
        isWorkerThreadRunning(false)
    {
        this->settings = settings;
        this->batch.reserve(this->settings->maximalNumberOfItemsInBatch);
        this->batchesInFlight.reserve(this->settings->maximalNumberOfBatchesInFlight);
        this->Start();
    }

    PlayFabEventPipeline::~PlayFabEventPipeline()
    {
        // stop worker thread
        this->isWorkerThreadRunning = false;
        if (this->workerThread.joinable())
        {
            this->workerThread.join();
        }
    }

    void PlayFabEventPipeline::Start()
    {
        // start worker thread
        this->isWorkerThreadRunning = true;
        if (!this->workerThread.joinable())
        {
            this->workerThread = std::thread(&PlayFabEventPipeline::WorkerThread, this);
        }
    }

    std::shared_ptr<PlayFabEventPipelineSettings> PlayFabEventPipeline::GetSettings() const
    {
        return this->settings;
    }

    void PlayFabEventPipeline::IntakeEvent(std::shared_ptr<const IPlayFabEmitEventRequest> request)
    {
        try
        {
            using Result = PlayFabEventBuffer::EventProducingResult;
            EmitEventResult emitResult;

            // put event into buffer
            switch (this->buffer.TryPut(request))
            {
            case Result::Success:
                return;

            case Result::Overflow:
            {
                emitResult = EmitEventResult::Overflow;
                LOG_PIPELINE("Buffer overflow");
            }
            break;

            case Result::Disabled:
            {
                emitResult = EmitEventResult::Disabled;
            }
            break;

            default:
            {
                emitResult = EmitEventResult::NotSupported;
                LOG_PIPELINE("TryPut returned an unknown type of result");
            }
            break;
            }

            // pipeline failed to intake the event, create a response
            std::shared_ptr<const PlayFabEmitEventRequest> playFabEmitRequest = std::dynamic_pointer_cast<const PlayFabEmitEventRequest>(request);
            auto playFabEmitEventResponse = std::make_shared<PlayFabEmitEventResponse>();
            playFabEmitEventResponse->emitEventResult = emitResult;

            std::shared_ptr<PlayFabError> emitEventError = std::make_shared<PlayFabError>();

            emitEventError->ErrorName = "PlayFabEventPipeline IntakeEvent Error";
            emitEventError->ErrorMessage = "PlayFabEventPipeline did not accept the event. Please see ErrorDetails for more information.";

            emitEventError->HttpCode = 0;
            emitEventError->HttpStatus = "None";

            if (emitResult == EmitEventResult::Overflow)
            {
                emitEventError->ErrorDetails = "PlayFabEventPipeline was unable to take the event due to memory limits. Please wait for batching to complete before retrying or increase the PlayFabEventBuffer size (see its constructor)";
            }
            else if (emitResult == EmitEventResult::Disabled)
            {
                emitEventError->ErrorDetails = "PlayFabEventPipeline was unable to take the event due to being disabled. Please enable the pipeline before attempting to add events.";
            }
            else
            {
                emitEventError->ErrorDetails = "PlayFabEventPipeline was unable to take the event due to an unknown reason.";
            }

            playFabEmitEventResponse->playFabError = emitEventError;

            // call an emit event callback
            CallbackRequest(playFabEmitRequest, std::move(playFabEmitEventResponse));
        }
        catch (...)
        {
            LOG_PIPELINE("An exception was caught in PlayFabEventPipeline::IntakeEvent method");
        }
    }

    void PlayFabEventPipeline::SetExceptionCallback(ExceptionCallback ex)
    {
        { // LOCK userCallbackMutex
            std::unique_lock<std::mutex> lock(userExceptionCallbackMutex);
            userExceptionCallback = ex;
        } // UNLOCK userCallbackMutex
    }

    void PlayFabEventPipeline::WorkerThread()
    {
        using clock = std::chrono::steady_clock;
        using Result = PlayFabEventBuffer::EventConsumingResult;
        std::shared_ptr<const IPlayFabEmitEventRequest> request;
        size_t batchCounter = 1; // used to track uniqueness of batches in the map
        std::chrono::steady_clock::time_point momentBatchStarted; // used to track when a currently assembled batch got its first event

        while (this->isWorkerThreadRunning)
        {
            try
            {
                // Process events in the loop
                if (this->batchesInFlight.size() >= this->settings->maximalNumberOfBatchesInFlight)
                {
                    // do not take new events from buffer if batches currently in flight are at the maximum allowed number
                    // and are not sent out (or received an error) yet
                    std::this_thread::sleep_for(std::chrono::milliseconds(this->settings->readBufferWaitTime)); // give some time for batches in flight to deflate
                    continue;
                }

                switch (this->buffer.TryTake(request))
                {
                case Result::Success:
                {
                    // add an event to batch
                    this->batch.push_back(std::move(request));

                    // if batch is full
                    if (this->batch.size() >= this->settings->maximalNumberOfItemsInBatch)
                    {
                        this->SendBatch(batchCounter);
                    }
                    else if (this->batch.size() == 1)
                    {
                        // if it is the first event in an incomplete batch then set the batch creation moment
                        momentBatchStarted = clock::now();
                    }

                    continue; // immediately check if there is next event in buffer
                }
                break;

                case Result::Disabled:
                case Result::Empty:
                default:
                    break;
                }

                // if batch was started
                if (this->batch.size() > 0)
                {
                    // check if the batch wait time expired
                    std::chrono::seconds batchAge = std::chrono::duration_cast<std::chrono::seconds>(clock::now() - momentBatchStarted);
                    if (batchAge.count() >= (int32_t)this->settings->maximalBatchWaitTime)
                    {
                        // batch wait time expired, send incomplete batch
                        this->SendBatch(batchCounter);
                        continue; // immediately check if there is next event in buffer
                    }
                }

                // event buffer is disabled or empty, and batch is not ready to be sent yet
                // give some time back to CPU, don't starve it without a good reason
                std::this_thread::sleep_for(std::chrono::milliseconds(this->settings->readBufferWaitTime));
            }
            catch (const std::exception& ex)
            {
                LOG_PIPELINE("An exception was caught in PlayFabEventPipeline::WorkerThread method");
                this->isWorkerThreadRunning = false;

                { // LOCK userCallbackMutex
                    std::unique_lock<std::mutex> lock(userExceptionCallbackMutex);
                    if (userExceptionCallback)
                    {
                        userExceptionCallback(ex);
                    }
                } // UNLOCK userCallbackMutex
            }
            catch (...)
            {
                LOG_PIPELINE("A non std::exception was caught in PlayFabEventPipeline::WorkerThread method");
            }
        }
    }

    void PlayFabEventPipeline::SendBatch(size_t& batchCounter)
    {
        // create a WriteEvents API request to send the batch
        EventsModels::WriteEventsRequest batchReq;
        if (this->settings->authenticationContext != nullptr)
        {
            batchReq.authenticationContext = this->settings->authenticationContext;
        }

        for (const auto& eventEmitRequest : this->batch)
        {
            const auto& playFabEmitRequest = std::dynamic_pointer_cast<const PlayFabEmitEventRequest>(eventEmitRequest);
            batchReq.Events.push_back(playFabEmitRequest->event->eventContents);
        }

        // add batch to flight tracking map
        void* customData = reinterpret_cast<void*>(batchCounter); // used to track batches across asynchronous Events API
        this->batchesInFlight[customData] = std::move(this->batch);
        batchCounter++;

        this->batch.clear(); // batch vector will be reused
        this->batch.reserve(this->settings->maximalNumberOfItemsInBatch);
        if (this->settings->emitType == PlayFabEventPipelineType::PlayFabPlayStream)
        {
            // call Events API to send the batch
            PlayFabEventsAPI::WriteEvents(
                batchReq,
                std::bind(&PlayFabEventPipeline::WriteEventsApiCallback, this, std::placeholders::_1, std::placeholders::_2),
                std::bind(&PlayFabEventPipeline::WriteEventsApiErrorCallback, this, std::placeholders::_1, std::placeholders::_2),
                customData);
        }
        else
        {
            // call Events API to send the batch, bypassing Playstream
            PlayFabEventsAPI::WriteTelemetryEvents(
                batchReq,
                std::bind(&PlayFabEventPipeline::WriteEventsApiCallback, this, std::placeholders::_1, std::placeholders::_2),
                std::bind(&PlayFabEventPipeline::WriteEventsApiErrorCallback, this, std::placeholders::_1, std::placeholders::_2),
                customData);
        }
    }

    void PlayFabEventPipeline::WriteEventsApiCallback(const EventsModels::WriteEventsResponse& result, void* customData)
    {
        try
        {
            // batch was successfully sent out, find it in the batch tracking map using customData pointer as a key
            const auto foundBatchIterator = this->batchesInFlight.find(customData);
            if (foundBatchIterator == this->batchesInFlight.end())
            {
                LOG_PIPELINE("Untracked batch was returned to EventsAPI.WriteEvents callback"); // normally this never happens
            }
            else
            {
                auto requestBatchPtr = std::shared_ptr<const std::vector<std::shared_ptr<const IPlayFabEmitEventRequest>>>(new std::vector<std::shared_ptr<const IPlayFabEmitEventRequest>>(std::move(foundBatchIterator->second)));

                // call individual emit event callbacks
                for (const auto& eventEmitRequest : *requestBatchPtr)
                {
                    std::shared_ptr<const PlayFabEmitEventRequest> playFabEmitRequest = std::dynamic_pointer_cast<const PlayFabEmitEventRequest>(eventEmitRequest);
                    auto playFabEmitEventResponse = std::shared_ptr<PlayFabEmitEventResponse>(new PlayFabEmitEventResponse());
                    playFabEmitEventResponse->emitEventResult = EmitEventResult::Success;
                    auto playFabError = std::make_shared<PlayFabError>();
                    playFabError->HttpCode = 200;
                    playFabError->ErrorCode = PlayFabErrorCode::PlayFabErrorSuccess;
                    playFabEmitEventResponse->playFabError = playFabError;
                    playFabEmitEventResponse->writeEventsResponse = std::shared_ptr<EventsModels::WriteEventsResponse>(new EventsModels::WriteEventsResponse(result));
                    playFabEmitEventResponse->batch = requestBatchPtr;
                    playFabEmitEventResponse->batchNumber = reinterpret_cast<size_t>(customData);

                    // call an emit event callback
                    CallbackRequest(playFabEmitRequest, std::move(playFabEmitEventResponse));
                }

                // remove the batch from tracking map
                this->batchesInFlight.erase(foundBatchIterator->first);
            }
        }
        catch (...)
        {
            LOG_PIPELINE("An exception was caught in PlayFabEventPipeline::WriteEventsApiCallback method");
        }
    }

    void PlayFabEventPipeline::WriteEventsApiErrorCallback(const PlayFabError& error, void* customData)
    {
        try
        {
            // batch wasn't sent out due to an error, find it in the batch tracking map using customData pointer as a key
            const auto foundBatchIterator = this->batchesInFlight.find(customData);
            if (foundBatchIterator == this->batchesInFlight.end())
            {
                LOG_PIPELINE("Untracked batch was returned to EventsAPI.WriteEvents callback"); // normally this never happens
            }
            else
            {
                auto requestBatchPtr = std::shared_ptr<const std::vector<std::shared_ptr<const IPlayFabEmitEventRequest>>>(new std::vector<std::shared_ptr<const IPlayFabEmitEventRequest>>(std::move(foundBatchIterator->second)));

                // call individual emit event callbacks
                for (const auto& eventEmitRequest : *requestBatchPtr)
                {
                    std::shared_ptr<const PlayFabEmitEventRequest> playFabEmitRequest = std::dynamic_pointer_cast<const PlayFabEmitEventRequest>(eventEmitRequest);
                    auto playFabEmitEventResponse = std::shared_ptr<PlayFabEmitEventResponse>(new PlayFabEmitEventResponse());
                    playFabEmitEventResponse->emitEventResult = EmitEventResult::Success;
                    playFabEmitEventResponse->playFabError = std::shared_ptr<PlayFabError>(new PlayFabError(error));
                    playFabEmitEventResponse->batch = requestBatchPtr;
                    playFabEmitEventResponse->batchNumber = reinterpret_cast<size_t>(customData);

                    // call an emit event callback
                    CallbackRequest(playFabEmitRequest, std::move(playFabEmitEventResponse));
                }

                // remove the batch from tracking map
                this->batchesInFlight.erase(foundBatchIterator->first);
            }
        }
        catch (...)
        {
            LOG_PIPELINE("An exception was caught in PlayFabEventPipeline::WriteEventsApiErrorCallback method");
        }
    }

    void PlayFabEventPipeline::CallbackRequest(std::shared_ptr<const IPlayFabEmitEventRequest> request, std::shared_ptr<const IPlayFabEmitEventResponse> response)
    {
        const auto& playFabEmitRequest = std::dynamic_pointer_cast<const PlayFabEmitEventRequest>(request);

        if (playFabEmitRequest->callback != nullptr)
        {
            playFabEmitRequest->callback(playFabEmitRequest->event, response);
        }

        if (playFabEmitRequest->stdCallback != nullptr)
        {
            playFabEmitRequest->stdCallback(playFabEmitRequest->event, response);
        }
    }
}

#endif
