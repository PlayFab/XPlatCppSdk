#include <stdafx.h>

#ifndef DISABLE_PLAYFABENTITY_API

#include <playfab/PlayFabEventPipeline.h>
#include <playfab/PlayFabEventsInstanceApi.h>
#include <playfab/PlayFabSettings.h>

#include <chrono>

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
        eventsApi = std::make_shared<PlayFabEventsInstanceAPI>(PlayFabSettings::staticPlayer);

        this->settings = settings;
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

    // NOTE: settings are expected to be set prior to calling PlayFabEventPipeline::Start()
    // changing them after PlayFabEventPipeline::Start() may cause threading issues
    // users should not expect changes made to settings to take effect after ::Start is called unless the pipeline is destroyed and re-created
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
        uintptr_t batchCounter = 1; // used to track uniqueness of batches in the map
        std::chrono::steady_clock::time_point momentBatchStarted; // used to track when a currently assembled batch got its first event
        
        std::vector<std::shared_ptr<const IPlayFabEmitEventRequest>> batch;

        try
        {
            batch.reserve(this->settings->maximalNumberOfItemsInBatch);
        
            while (this->isWorkerThreadRunning)
            {
                size_t sizeOfBatchesInFlight = 0;

                { // LOCK batchesInFlight mutex
                    std::unique_lock<std::mutex> lock(inFlightMutex);
                    sizeOfBatchesInFlight = this->batchesInFlight.size();
                } // UNLOCK batchesInFlight

                // Process events in the loop
                if (sizeOfBatchesInFlight >= this->settings->maximalNumberOfBatchesInFlight)
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
                    batch.push_back(std::move(request));

                    // if batch is full
                    if (batch.size() >= this->settings->maximalNumberOfItemsInBatch)
                    {
                        this->SendBatch(batch, batchCounter);
                    }
                    else if (batch.size() == 1)
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
                if (batch.size() > 0)
                {
                    // check if the batch wait time expired
                    std::chrono::seconds batchAge = std::chrono::duration_cast<std::chrono::seconds>(clock::now() - momentBatchStarted);
                    if (batchAge.count() >= (int32_t)this->settings->maximalBatchWaitTime)
                    {
                        // batch wait time expired, send incomplete batch
                        this->SendBatch(batch, batchCounter);
                        continue; // immediately check if there is next event in buffer
                    }
                }

                // event buffer is disabled or empty, and batch is not ready to be sent yet
                // give some time back to CPU, don't starve it without a good reason
                std::this_thread::sleep_for(std::chrono::milliseconds(this->settings->readBufferWaitTime));
            }
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

    void PlayFabEventPipeline::SendBatch(std::vector<std::shared_ptr<const IPlayFabEmitEventRequest>>& batch, uintptr_t& batchCounter)
    {
        // create a WriteEvents API request to send the batch
        EventsModels::WriteEventsRequest batchReq;
        if (this->settings->authenticationContext != nullptr)
        {
            batchReq.authenticationContext = this->settings->authenticationContext;
        }

        for (const auto& eventEmitRequest : batch)
        {
            const auto& playFabEmitRequest = std::dynamic_pointer_cast<const PlayFabEmitEventRequest>(eventEmitRequest);
            batchReq.Events.push_back(playFabEmitRequest->event->eventContents);
        }

        // add batch to flight tracking map
        void* customData = reinterpret_cast<void*>(batchCounter); // used to track batches across asynchronous Events API

        { // LOCK batchesInFlight mutex
            std::unique_lock<std::mutex> lock(inFlightMutex);
            this->batchesInFlight[customData] = std::move(batch);
        } // UNLOCK batchesInFlight
        
        batchCounter++;

        batch.clear(); // batch vector will be reused
        batch.reserve(this->settings->maximalNumberOfItemsInBatch);
        if (this->settings->emitType == PlayFabEventPipelineType::PlayFabPlayStream)
        {
            // call Events API to send the batch
            eventsApi->WriteEvents(
                batchReq,
                std::bind(&PlayFabEventPipeline::WriteEventsApiCallback, this, std::placeholders::_1, std::placeholders::_2),
                std::bind(&PlayFabEventPipeline::WriteEventsApiErrorCallback, this, std::placeholders::_1, std::placeholders::_2),
                customData);
        }
        else
        {
            // call Events API to send the batch, bypassing Playstream
            eventsApi->WriteTelemetryEvents(
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
            std::vector<std::shared_ptr<const IPlayFabEmitEventRequest>> batchWritten;
            if(TryGetBatchOutOfFlight(customData, &batchWritten))
            {
                auto requestBatchPtr = std::make_shared<std::vector<std::shared_ptr<const IPlayFabEmitEventRequest>>>(std::move(batchWritten));
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
                    playFabEmitEventResponse->batchNumber = static_cast<size_t>(reinterpret_cast<uintptr_t>(customData));

                    // call an emit event callback
                    CallbackRequest(playFabEmitRequest, std::move(playFabEmitEventResponse));
                }
            }
            else
            {
                LOG_PIPELINE("After a valid PlayFabEventPipeline write call, the requested return Batch did not appear in our known flighted batches, there is no trustworthy data we can return to the user");
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
            std::vector<std::shared_ptr<const IPlayFabEmitEventRequest>> batchWritten;
            if(TryGetBatchOutOfFlight(customData, &batchWritten))
            {
                auto requestBatchPtr = std::make_shared<std::vector<std::shared_ptr<const IPlayFabEmitEventRequest>>>(std::move(batchWritten));
                // call individual emit event callbacks
                for (const auto& eventEmitRequest : *requestBatchPtr)
                {
                    std::shared_ptr<const PlayFabEmitEventRequest> playFabEmitRequest = std::dynamic_pointer_cast<const PlayFabEmitEventRequest>(eventEmitRequest);
                    auto playFabEmitEventResponse = std::shared_ptr<PlayFabEmitEventResponse>(new PlayFabEmitEventResponse());
                    playFabEmitEventResponse->emitEventResult = EmitEventResult::Success;
                    playFabEmitEventResponse->playFabError = std::shared_ptr<PlayFabError>(new PlayFabError(error));
                    playFabEmitEventResponse->batch = requestBatchPtr;
                    playFabEmitEventResponse->batchNumber = static_cast<size_t>(reinterpret_cast<uintptr_t>(customData));

                    // call an emit event callback
                    CallbackRequest(playFabEmitRequest, std::move(playFabEmitEventResponse));
                }
            }
            else
            {
                LOG_PIPELINE("After an invalid PlayFabEventPipeline write call error was being raised to the user, the requeted return Batch did not appear in our known flighted batches, there is no trustworthy data we can return to the user");
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

    bool PlayFabEventPipeline::TryGetBatchOutOfFlight(void* customData, std::vector<std::shared_ptr<const IPlayFabEmitEventRequest>>* batchReturn)
    {
        // LOCK batchesInFlight mutex
        std::unique_lock<std::mutex> lock(inFlightMutex);
        auto iter = this->batchesInFlight.find(customData);
        if (iter == this->batchesInFlight.end())
        {
            // not finding the batch in the queue is a bug
            LOG_PIPELINE("Untracked batch was returned to EventsAPI.WriteEvents callback");
            return false;
            // UNLOCK batchesInFlight
        }

        *batchReturn = std::move(iter->second);
        this->batchesInFlight.erase(iter);
        return true;
        // UNLOCK batchesInFlight
    }
}

#endif
