// Copyright (C) Microsoft Corporation. All rights reserved.

#pragma once

#include <string>
#include <chrono>

namespace PlayFabUnit
{
    struct TestTitleData
    {
        std::string titleId;
        std::string developerSecretKey;
        std::string userEmail;
        std::string connectionString;
    };

    enum class TestActiveState
    {
        PENDING, // Not started
        ACTIVE, // Currently testing
        READY, // An answer is sent by the (potentially) alternate thread, but the main thread hasn't finalized the test yet
        COMPLETE, // Test is finalized and recorded
        ABORTED // todo
    };

    enum class TestFinishState
    {
        PENDING,
        PASSED,
        FAILED,
        SKIPPED,
        TIMEDOUT
    };
    static const char* TestFinishStateToString[] = { "PENDING", "PASSED", "FAILED", "SKIPPED", "TIMEDOUT" };
}
