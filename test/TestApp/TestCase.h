// Copyright (C) Microsoft Corporation. All rights reserved.

#pragma once

#include <list>
#include <memory>
#include <string>
#include <TestContext.h>

namespace PlayFabUnit
{
    struct TestContext;

    typedef std::list<std::shared_ptr<TestContext>> TestList;

    class TestCase
    {
    public:
        TestCase()
        {
            testList = std::make_shared<TestList>();
        }

        /// <summary>
        /// Provide read-only access to the test list.
        /// Will trigger building the test list, if it's not already populated.
        /// <summary>
        std::shared_ptr<TestList> GetTests()
        {
            if (testList->empty())
            {
                AddTests();
            }

            return testList;
        }

        /// <summary>
        /// During testing, this is the first function that will be called for each TestCase.
        /// This is run exactly once for this type.
        /// </summary>
        virtual void ClassSetUp()
        {
        }

        /// <summary>
        /// During testing, this will be called once before every test function.
        /// This is run once for each test.
        /// This is considered part of the active test. A failure or exception in this method will be considered a failure for the active test.
        /// </summary>
        virtual void SetUp(TestContext& /*testContext*/)
        {
        }

        /// <summary>
        /// During testing, this will be called every tick that a test is asynchronous.
        /// This is run every tick until testContext.EndTest() is called, or until the test times out.
        /// This is considered part of the active test. A failure or exception in this method will be considered a failure for the active test.
        /// </summary>
        virtual void Tick(TestContext& /*testContext*/) = 0;

        /// <summary>
        /// During testing, this will be called once after every test function.
        /// This is run once for each test.
        /// This is considered part of the active test. A failure or exception in this method will be considered a failure for the active test.
        /// </summary>
        virtual void TearDown(TestContext& /*testContext*/)
        {
        }

        /// <summary>
        /// During testing, this is the last function that will be called for each TestCase.
        /// This is run exactly once for this type.
        /// It is not considered part of any test. A failure or exception in this method will halt the test framework.
        /// </summary>
        virtual void ClassTearDown()
        {
        }

    protected:
        /// <summary>
        /// Before testing, this function is called to gather the list of tests to run for each TestCase.
        /// It is not considered part of any test.
        /// <summary>
        virtual void AddTests() = 0;

        template <class T> void AddTest(const std::string& name, void(T::* testCaseFunc)(TestContext&))
        {
            T* testCase = static_cast<T*>(this);
            const auto& testFunc = std::bind(testCaseFunc, testCase, std::placeholders::_1);
            std::shared_ptr<TestContext> testContext = std::make_shared<TestContext>(testCase, name, testFunc);

            testList->push_back(testContext);
        }

    private:
        std::shared_ptr<TestList> testList;
    };

    class PlayFabApiTestCase : public TestCase
    {
    protected:
        TestTitleData testTitleData;
    public:
        inline void SetTitleInfo(const TestTitleData& _testTitleData)
        {
            testTitleData = _testTitleData;
        }
    };
}
