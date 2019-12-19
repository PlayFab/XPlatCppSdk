// Copyright (C) Microsoft Corporation. All rights reserved.

#pragma once

#include <condition_variable>
#include <memory>
#include <mutex>
#include <string>

#include "TestDataTypes.h"

namespace PlayFab
{
    struct PlayFabError;

    namespace ClientModels
    {
        struct ExecuteCloudScriptResult;
        struct LoginResult;
    }
}

namespace PlayFabUnit
{
    class TestApp
    {
    public:
        int Main();
        static void Log(const char* format, ...);
        static void LogPut(const char* message);

    private:
        // Cloud Report
        std::string cloudResponse = "";
        std::string cloudPlayFabId = "";
        std::mutex cloudResponseMutex;
        std::condition_variable cloudResponseConditionVar;

        void OnPostReportLogin(const PlayFab::ClientModels::LoginResult& result, void* customData);
        void OnPostReportComplete(const PlayFab::ClientModels::ExecuteCloudScriptResult& result, void* /*customData*/);
        void OnPostReportError(const PlayFab::PlayFabError& error, void* /*customData*/);

        // Utility
        static bool LoadTitleData(TestTitleData& titleData);

        // Partial class methods
        // Each platform gets its own file and implementation of the following methods, since the logic
        // is likely to be very different on all of them.
        static bool LoadTitleDataJson(std::shared_ptr<char*>& testDataJsonPtr, size_t& testDataJsonLen);
    };
}
