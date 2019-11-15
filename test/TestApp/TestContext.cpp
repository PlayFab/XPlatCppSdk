// Copyright (C) Microsoft Corporation. All rights reserved.

#include "TestAppPch.h"
#include "TestContext.h"
#include "TestUtils.h"

namespace PlayFabUnit
{
    void TestContext::EndTest(TestFinishState state, std::string resultMsg)
    {
        if (finishState == TestFinishState::PENDING) // This means that we finish successfully
        {
            endTime = TestTimeNow();
            testResultMsg = resultMsg;
            finishState = state;
            activeState = TestActiveState::READY;
        }
        else if (finishState == TestFinishState::PASSED)
        {
            switch (state)
            {
            case PlayFabUnit::TestFinishState::PASSED:
                testResultMsg += "Tests should not attempt to pass twice.";
                break;
            case PlayFabUnit::TestFinishState::FAILED:
                testResultMsg += "Test try to Fail after Passing. " + resultMsg;
                break;
            case PlayFabUnit::TestFinishState::SKIPPED:
                testResultMsg += "Test try to be Skipped after Passing.";
                break;
            case PlayFabUnit::TestFinishState::TIMEDOUT:
                testResultMsg += "Test try to Timeout after Passing.";
                break;
            default:
                testResultMsg += "How are you switching back to a Pending state from Passing.";
                break;
            }
        }
        else if (finishState == TestFinishState::FAILED)
        {
            switch (state)
            {
            case PlayFabUnit::TestFinishState::PASSED:
                testResultMsg += "Test try to Pass after Failing.";
                break;
            case PlayFabUnit::TestFinishState::FAILED:
                testResultMsg += "Test try to Fail twice. " + resultMsg;
                break;
            case PlayFabUnit::TestFinishState::SKIPPED:
                testResultMsg += "Test try to be Skipped after Failing.";
                break;
            case PlayFabUnit::TestFinishState::TIMEDOUT:
                testResultMsg += "Test try to Timeout after Failing.";
                break;
            default:
                testResultMsg += "How are you switching back to a Pending state from Failing.";
                break;
            }
        }
        else if (finishState == TestFinishState::SKIPPED)
        {
            switch (state)
            {
            case PlayFabUnit::TestFinishState::PASSED:
                testResultMsg += "Test try to Pass after being Skipped.";
                break;
            case PlayFabUnit::TestFinishState::FAILED:
                testResultMsg += "Test try to Fail after being Skipped. " + resultMsg;
                break;
            case PlayFabUnit::TestFinishState::SKIPPED:
                testResultMsg += "Test try to be Skipped twice.";
                break;
            case PlayFabUnit::TestFinishState::TIMEDOUT:
                testResultMsg += "Test try to Timeout after being Skipped.";
                break;
            default:
                testResultMsg += "How are you switching back to a Pending state from Skipping.";
                break;
            }
        }
        else
        {
            switch (state)
            {
            case PlayFabUnit::TestFinishState::PASSED:
                testResultMsg += "Test try to Pass after being Timeout.";
                break;
            case PlayFabUnit::TestFinishState::FAILED:
                testResultMsg += "Test try to Fail after being Timeout.";
                break;
            case PlayFabUnit::TestFinishState::SKIPPED:
                testResultMsg += "Test try to be Skipped after being Timeout.";
                break;
            case PlayFabUnit::TestFinishState::TIMEDOUT:
                testResultMsg += "Test try to Timeout twice.";
                break;
            default:
                testResultMsg += "How are you switching back to a Pending state from Timing Out.";
                break;
            }
        }
    }

    void TestContext::Pass(std::string message)
    {
        EndTest(TestFinishState::PASSED, message);
    }

    void TestContext::Fail(std::string message)
    {
        if (message.empty())
        {
            message = "fail";
        }
        
        EndTest(TestFinishState::FAILED, message);
        // TODO: Throw "assert" exception
    }

    void TestContext::Skip(std::string message)
    {
        EndTest(TestFinishState::SKIPPED, message);
        // TODO: Throw "test skipped" exception
    }
}
