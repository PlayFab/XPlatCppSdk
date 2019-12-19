// Copyright (C) Microsoft Corporation. All rights reserved.

#include "TestAppPch.h"
#include <thread>
#include <playfab/PlayFabSettings.h>
#include "TestCase.h"
#include "TestContext.h"
#include "TestRunner.h"
#include "TestUtils.h"

namespace PlayFabUnit
{
    static const Int64 TEST_TIMEOUT_MILLISECONDS = 15000;

    TestRunner::TestRunner() :
        suiteState(TestActiveState::PENDING),
        suiteTestCase(nullptr),
        suiteTestReport(PlayFab::PlayFabSettings::buildIdentifier)
    {
        PlayFab::PlayFabSettings::threadedCallbacks = true;
    }

    void TestRunner::Add(TestCase& testCase)
    {
        if (TestActiveState::PENDING != suiteState)
        {
            return;
        }

        // Add the tests from the given test case.
        std::shared_ptr<TestList> testCaseTests = testCase.GetTests();
        suiteTests.splice(suiteTests.end(), *testCaseTests);
    }

    void TestRunner::Run()
    {
        // Mark the test suite as active.
        if (TestActiveState::PENDING == suiteState)
        {
            suiteState = TestActiveState::ACTIVE;
        }

        // Run the tests.
        for (auto& test : suiteTests)
        {
            // Handle transitions between TestCases.
            ManageTestCase(test->testCase, suiteTestCase);

            // Start the test.
            test->startTime = PlayFab::GetMilliTicks();
            test->activeState = TestActiveState::ACTIVE;
            suiteTestReport.TestStarted();

            test->testCase->SetUp(*test);
            if (TestActiveState::ACTIVE == test->activeState)
            {
                test->testFunc(*test);
            }

            // Tick the test.
            while (TestActiveState::ACTIVE == test->activeState)
            {
                Int64 timeNow = PlayFab::GetMilliTicks();
                bool timeExpired = (timeNow - test->startTime) > TEST_TIMEOUT_MILLISECONDS;

                if ((TestActiveState::READY != test->activeState) && !timeExpired) // Not finished & not timed out
                {
                    test->testCase->Tick(*test);

                    // Allow worker threads a chance to run (important for platforms with conservative thread management).
                    std::this_thread::yield();

                    continue;
                }
                else if ((TestActiveState::ACTIVE == test->activeState) && timeExpired)
                {
                    test->EndTest(TestFinishState::TIMEDOUT, "Test duration exceeded maximum");
                }

                // Update the test summary.
                suiteTestSummary = GenerateTestSummary();
            }

            // Tear down the test.
            test->endTime = PlayFab::GetMilliTicks();
            test->testCase->TearDown(*test);
            test->activeState = TestActiveState::COMPLETE;
            // printf("\n%s\n", suiteTestSummary.c_str()); // If we're debugging EventTests, it's nice to see each test as it happens...

            // Update the report.
            Int64 testDurationMs = test->endTime - test->startTime;
            suiteTestReport.TestComplete(test->testName, test->finishState, testDurationMs, test->testResultMsg);
        }

        suiteState = TestActiveState::READY;
        ManageTestCase(nullptr, suiteTestCase); // Ensure that the final TestCase is cleaned up.

        // Generate the final test summary.
        suiteTestSummary = GenerateTestSummary();

        // Mark the test suite as having completed.
        suiteState = TestActiveState::COMPLETE;
    }

    std::string TestRunner::GenerateTestSummary()
    {
        std::stringstream summaryStream;

        Int64 timeNow = PlayFab::GetMilliTicks();
        Int64 testStartTime, testEndTime;
        size_t testsFinishedCount = 0, testsPassedCount = 0, testsFailedCount = 0, testsSkippedCount = 0;

        for (auto& test : suiteTests)
        {
            // Count tests
            if (TestActiveState::COMPLETE == test->activeState)
            {
                testsFinishedCount += 1;

                testStartTime = test->startTime;
                testEndTime = test->endTime;

                if (TestFinishState::PASSED == test->finishState)
                {
                    testsPassedCount += 1;
                }
                else if (TestFinishState::SKIPPED == test->finishState)
                {
                    testsSkippedCount += 1;
                }
                else
                {
                    testsFailedCount += 1;
                }
            }
            else
            {
                testStartTime = (TestActiveState::PENDING == test->activeState) ? timeNow : test->startTime;
                testEndTime = timeNow;
            }

            // Line for each test report
            Int64 testDurationMs = testEndTime - testStartTime;
            summaryStream << std::setw(10) << testDurationMs << " ms";
            summaryStream << " - " << ToString(test->finishState);
            summaryStream << " - " << test->testName;
            if (!test->testResultMsg.empty())
            {
                summaryStream << " - " << test->testResultMsg;
            }
            summaryStream << "\n";
        }

        summaryStream << " - Testing complete:  ";
        summaryStream << testsFinishedCount << "/" << suiteTests.size() << " tests run, ";
        summaryStream << testsPassedCount << " tests passed, ";
        summaryStream << testsFailedCount << " tests failed, ";
        summaryStream << testsSkippedCount << " tests skipped.";

        return summaryStream.str();
    }

    void TestRunner::ManageTestCase(TestCase* newTestCase, TestCase* oldTestCase)
    {
        if (newTestCase == oldTestCase)
        {
            return;
        }

        if (nullptr != oldTestCase)
        {
            oldTestCase->ClassTearDown();
        }

        if (nullptr != newTestCase)
        {
            newTestCase->ClassSetUp();
        }

        suiteTestCase = newTestCase;
    }

    bool TestRunner::AllTestsPassed()
    {
        return suiteTestReport.AllTestsPassed();
    }
}
