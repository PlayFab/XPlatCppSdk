#include <stdafx.h>

#if defined (PLAYFAB_PLATFORM_WINDOWS) || defined (PLAYFAB_PLATFORM_XBOX)
#include <cstdint>

#include <playfab/QoS/QoS.h>
#include <playfab/QoS/PingResult.h>
#include <playfab/QoS/PlayFabQoSApi.h>

#include <playfab/PlayFabMultiplayerInstanceApi.h>
#include <playfab/PlayFabMultiplayerDataModels.h>
#include <playfab/PlayFabEventsInstanceApi.h>
#include <playfab/PlayFabEventsDataModels.h>
#include <playfab/PlayFabSettings.h>
#include <playfab/PlayFabPluginManager.h>

using namespace std;
using namespace PlayFab::MultiplayerModels;
using namespace PlayFab::EventsModels;

namespace PlayFab
{
    namespace QoS
    {
        static const size_t MaxWaitForFuturesLoopCounts = 300;
        PlayFabQoSApi::PlayFabQoSApi()
        {
            eventsApi = std::make_shared<PlayFabEventsInstanceAPI>(PlayFabSettings::staticPlayer);
            multiplayerApi = std::make_shared<PlayFabMultiplayerInstanceAPI>(PlayFabSettings::staticPlayer);
        }

        bool ValidateResult(PlayFabResultCommon& resultCommon, const CallRequestContainer& container)
        {
            if (container.errorWrapper.HttpCode == 200)
            {
                resultCommon.FromJson(container.errorWrapper.Data);
                resultCommon.Request = container.errorWrapper.Request;
                return true;
            }
            else // Process the error case
            {
                if (PlayFabSettings::globalErrorHandler != nullptr)
                {
                    PlayFabSettings::globalErrorHandler(container.errorWrapper, container.GetCustomData());
                }

                if (container.errorCallback != nullptr)
                {
                    container.errorCallback(container.errorWrapper, container.GetCustomData());
                }
                return false;
            }
        }

        std::future<QoSResult> PlayFabQoSApi::GetQoSResultAsync(unsigned int numThreads, unsigned int timeoutMs)
        {
            return async(launch::async, [&, numThreads, timeoutMs]() { return GetQoSResult(numThreads, timeoutMs); });
        }

        QoSResult PlayFabQoSApi::GetQoSResult(unsigned int numThreads, unsigned int timeoutMs)
        {
            QoSResult result(GetResult(numThreads, timeoutMs));

            if (result.errorCode != static_cast<int>(QoSErrorCode::Success))
            {
                return result;
            }

            SendResultsToPlayFab(result);
            return result;
        }

        QoSResult PlayFabQoSApi::GetResult(unsigned int numThreads, unsigned int timeoutMs)
        {
            QoSResult result;

            if (!PlayFabSettings::staticPlayer->IsClientLoggedIn())
            {
                LOG_QOS("Client is not logged in" << endl);
                result.errorCode = static_cast<int>(QoSErrorCode::NotLoggedIn);
                return result;
            }

            listQosServersCompleted = false;

            // get region map (call thunderhead)
            PingThunderheadForServerList();

            // Wait for the PlayFabMultiplayerAPI::ListQosServers api to complete
            while (!listQosServersCompleted)
            {
                this_thread::sleep_for(threadWaitTimespan);
            }

            size_t serverCount = regionMap.size(); // call thunderhead to get a list of all the data centers
            if (serverCount <= 0)
            {
                result.errorCode = static_cast<int>(QoSErrorCode::FailedToRetrieveServerList);
                return result;
            }

            // get a list of region pings that need to be done
            result.regionResults.reserve(serverCount);
            vector<std::string> pings = GetPingList(static_cast<unsigned int>(serverCount));

            // initialize accumulated results with empty (zeroed) ping results
            unordered_map<std::string, PingResult> accumulatedPingResults;
            accumulatedPingResults.reserve(regionMap.size());
            InitializeAccumulatedPingResults(accumulatedPingResults);

            // Sockets that would be used to ping
            vector<shared_ptr<QoSSocket>> sockets;
            result.errorCode = SetupSockets(sockets, numThreads, timeoutMs);

            // If no sockets were initialized, return as we cant do anything. The errorCode must already be set at this point
            // Update the numThreads as well since if we have n sockets, we can only use n threads
            if ((numThreads = static_cast<unsigned int>(sockets.size())) == 0)
            {
                LOG_QOS("No socket could be created. " << std::endl);
                return result;
            }

            // initialize the async ping results
            vector<future<PingResult>> asyncPingResults(numThreads);
            InitializeAsyncPingResults(asyncPingResults);

            // ping servers
            PingServers(pings, asyncPingResults, sockets, accumulatedPingResults, timeoutMs);

            // set results with averages for individual servers
            for (auto it = accumulatedPingResults.begin(); it != accumulatedPingResults.end(); ++it)
            {
                // Calculate the latency
                int latency = (it->second.pingCount == 0) ? INT32_MAX : it->second.latencyMs / it->second.pingCount;
                result.regionResults.push_back(RegionResult(it->first, latency, it->second.errorCode));
            }

            bool allTimedOut = true;
            for(auto& regionRes: result.regionResults)
            {
                if(regionRes.latencyMs != timeoutMs)
                {
                    allTimedOut = false;
                    break;
                }
            }

            if(allTimedOut)
            {
                result.errorCode = static_cast<int>(QoSErrorCode::Timeout);;
            }

            std::sort(result.regionResults.begin(), result.regionResults.end(), [](const RegionResult& first, const RegionResult& second) -> bool {return first.latencyMs < second.latencyMs; });

            return result;
        }

        void PlayFabQoSApi::SendResultsToPlayFab(const QoSResult& result)
        {
            Json::Value value;
            value["ErrorCode"] = Json::Value(result.errorCode);

            Json::Value each_regionCenterResult;
            for (int i = 0; i < result.regionResults.size(); ++i)
            {
                Json::Value dcResult;

                dcResult["Region"] = Json::Value(result.regionResults[i].region);
                dcResult["LatencyMs"] = Json::Value(result.regionResults[i].latencyMs);
                dcResult["ErrorCode"] = Json::Value(result.regionResults[i].errorCode);

                each_regionCenterResult[i] = dcResult;
            }

            value["RegionResults"] = each_regionCenterResult;

            PlayFab::EventsModels::WriteEventsRequest request;
            PlayFab::EventsModels::EventContents eventContents;

            eventContents.Name = "qos_result";
            eventContents.EventNamespace = "playfab.servers";
            eventContents.Payload = value;
            request.Events.push_back(eventContents);

            eventsApi->WriteTelemetryEvents(request, WriteEventsSuccessCallBack, WriteEventsFailureCallBack);
        }

        void PlayFabQoSApi::WriteEventsSuccessCallBack(const WriteEventsResponse&, void*)
        {
            LOG_QOS("QoSResult successfully sent to PlayFab");
        }

        void PlayFabQoSApi::WriteEventsFailureCallBack(const PlayFabError&, void*)
        {
            LOG_QOS("Failed to QoSResult sent to PlayFab");
        }

        void PlayFabQoSApi::PingThunderheadForServerList()
        {
            if (regionMap.size() > 0)
            {
                // If the regionMap is already initialized, return
                listQosServersCompleted = true;
                return;
            }

            ListQosServersForTitleRequest request;
            multiplayerApi->ListQosServersForTitle(request, ListQosServersForTitleSuccessCallBack, ListQosServersForTitleFailureCallBack, reinterpret_cast<void*>(this));
        }

        void PlayFabQoSApi::ListQosServersForTitleSuccessCallBack(const ListQosServersForTitleResponse& result, void* customData)
        {
            // Custom data received is a pointer to our api object
            PlayFabQoSApi* api = reinterpret_cast<PlayFabQoSApi*>(customData);

            for (const QosServer& server : result.QosServers)
            {
                api->regionMap[server.Region] = server.ServerUrl;
            }

            api->listQosServersCompleted = true;
        }

        void PlayFabQoSApi::ListQosServersForTitleFailureCallBack(const PlayFabError&, void* customData)
        {
            // Custom data received is a pointer to our api object
            PlayFabQoSApi* api = reinterpret_cast<PlayFabQoSApi*>(customData);

            // Log the error and return
            LOG_QOS("Could not get the server list from thunderhead\n Error : " << error.ToJson() << endl);
            api->listQosServersCompleted = true;
        }

        vector<std::string> PlayFabQoSApi::GetPingList(unsigned int serverCount)
        {
            vector<std::string> pingList;
            pingList.reserve(numOfPingIterations * serverCount);

            // Round Robin
            for (int i = 0; i < numOfPingIterations; ++i)
            {
                for (unordered_map<std::string, string>::iterator it = regionMap.begin();
                    it != regionMap.end();
                    ++it)
                {
                    pingList.push_back(it->first);
                }
            }

            return pingList;
        }

        void PlayFabQoSApi::InitializeAccumulatedPingResults(unordered_map<std::string, PingResult>& accumulatedPingResults)
        {
            for (auto it = regionMap.begin();
                it != regionMap.end();
                ++it)
            {
                accumulatedPingResults[it->first] = PingResult(0, 0, 0);
            }
        }

        int PlayFabQoSApi::SetupSockets(vector<shared_ptr<QoSSocket>>& sockets, unsigned int numThreads, unsigned int timeoutMs)
        {
            int lastErrorCode = 0;

            sockets.reserve(numThreads);

            // Setup sockets based on the number of threads
            for (unsigned int i = 0; i < numThreads; ++i)
            {
                shared_ptr<QoSSocket> socket = make_shared<QoSSocket>();

                int errorCode;
                if ((errorCode = socket->ConfigureSocket(timeoutMs)) == 0)
                {
                    sockets.push_back(socket);
                }
                else
                {
                    lastErrorCode = errorCode;
                }
            }

            return lastErrorCode;
        }

        void PlayFabQoSApi::InitializeAsyncPingResults(vector<future<PingResult>>& asyncPingResults)
        {
            for (int i = 0; i < asyncPingResults.size(); ++i)
            {
                asyncPingResults[i] = future<PingResult>(); // create a fake future
            }
        }

        void PlayFabQoSApi::PingServers(const vector<std::string>& pings, vector<future<PingResult>>& asyncPingResults, const std::vector<std::shared_ptr<QoSSocket>>& sockets, unordered_map<std::string, PingResult>& accumulatedPingResults, unsigned int timeoutMs)
        {
            int pingItr = 0;
            size_t numThreads = asyncPingResults.size();
            size_t numPings = pings.size();
            vector<std::string> pingedServers(numThreads); // remember the server for which a ping is started
            while (pingItr < numPings)
            {
                // Iterate over all the threads and servers that need to be pinged
                for (size_t i = 0; i < numThreads && pingItr < numPings; ++i)
                {
                    // NOTE: the very first ping result might be a fake future
                    for (size_t futuresCount = 0; futuresCount < MaxWaitForFuturesLoopCounts; ++futuresCount)
                    {
                        if(!asyncPingResults[i].valid())
                        {
                            continue;
                        }
                        future_status status = asyncPingResults[i].wait_for(threadWaitTimespan);
                        if (status == future_status::ready)
                        {
                            // Get the result
                            PingResult thisResult(asyncPingResults[i].get());

                            // Update the result for the previous socket ping
                            UpdateAccumulatedPingResult(thisResult, pingedServers[i], accumulatedPingResults, timeoutMs);
                        }
                        else if (status == future_status::timeout)
                        {
                            // this ping is not complete yet, check the next one
                            continue;
                        }
                        else
                        {
                            LOG_QOS("Unexpected future status (deferred)");
                            // TODO: decide how to bubble this error up (if needed)
                            // Normally, this should never happen as we are not using futures of futures
                        }
                    }

                    int errorCode = 0;

                    // Update the socket address and start another ping
                    // [NOTE] Order of the following checks is imp since we can loop around and j might be out of bound
                    while (pingItr < numPings && (errorCode = sockets[i]->SetAddress(regionMap[pings[pingItr]].c_str())) != 0)
                    {
                        // If an error code is seen, save it
                        if (errorCode != 0)
                        {
                            accumulatedPingResults[pings[pingItr]].errorCode = errorCode;
                        }

                        ++pingItr;
                    }

                    // If we have an address that we can ping, start an async thread for the same
                    if (pingItr < numPings)
                    {
                        pingedServers[i] = pings[pingItr];
                        asyncPingResults[i] = async(launch::async, GetQoSResultForRegion, sockets[i]);
                        ++pingItr;
                    }
                }
            }

            // Accumulate final results
            for (size_t i = 0; i < numThreads; ++i)
            {
                // If the result is valid and available
                if (asyncPingResults[i].valid())
                {
                    std::chrono::milliseconds pingWaitTime = std::chrono::milliseconds(timeoutMs);
                    future_status status = asyncPingResults[i].wait_for(pingWaitTime);
                    if (status == future_status::ready)
                    {
                        // Update the result for the previous socket ping
                        PingResult thisResult(asyncPingResults[i].get());
                        UpdateAccumulatedPingResult(thisResult, pingedServers[i], accumulatedPingResults, timeoutMs);
                    }
                }
            }
        }

        // Add the new ping result to the unordered map.
        void PlayFabQoSApi::UpdateAccumulatedPingResult(const PingResult& result, const std::string& region, std::unordered_map<std::string, PingResult>& accumulatedPingResults, unsigned int timeoutMs)
        {
            if (result.errorCode != 0)
            {
                accumulatedPingResults[region].errorCode = result.errorCode;
                return;
            }

            if (static_cast<unsigned int>(result.latencyMs) <= timeoutMs)
            {
                accumulatedPingResults[region].latencyMs += result.latencyMs;
                ++accumulatedPingResults[region].pingCount;
            }
        }

        // Ping one data center and return the address.
        // Parameters : Configured socket to ping
        // Return : The ping result
        // Note that the function eat any exceptions thrown to it.
        PingResult PlayFabQoSApi::GetQoSResultForRegion(shared_ptr<QoSSocket> socket)
        {
            // Ping a data center and return the ping time
            try
            {
                return socket->GetQoSServerLatencyMs();
            }
            catch (...)
            {
                LOG_QOS("Some exception was caught while pinging. Ignore the ping");
                PingResult result(INT32_MAX, EXCEPTION_ERROR_CODE, 0);

                return result;
            }
        }
    }
}
#endif // defined (PLAYFAB_PLATFORM_WINDOWS) || defined (PLAYFAB_PLATFORM_XBOX)