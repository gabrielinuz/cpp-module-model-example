#ifndef ERROR_LOGGER_TEST_HPP
#define ERROR_LOGGER_TEST_HPP

#pragma once

#include <iostream>

//cppset:
#include <TestEvaluator.hpp>
#include <ModuleLoader.hpp>

//Modules interfaces:
#include <Logger.hpp>

using namespace std;

auto te = make_unique<TestEvaluator>();
auto ml = make_unique<ModuleLoader>();
////////////////////////////////////////ErrorLogger Tests://////////////////////////////////////
/**
 * @brief Common ErrorLogger arange of unit test
 * 
 */
auto arrange_error_logger()
{
    //Arange
    ml->load("./lib/ErrorLoggerModule");
    return ml->getInstanceAs<shared_ptr<Logger>>();
}

void ErrorLoggerTest1()
{
    // Arrange:
    // te->setName("Correct creation of log file 1.");
    auto errorLogger = arrange_error_logger();

    // Act:
    errorLogger->log("test log message 1"); 
    ifstream logFile("./error.log");

    //Assert:
    te->evaluate("Correct creation of log file 1.", logFile.is_open() == true);
    // te->evaluate(logFile.is_open() == true, "Correct creation of log file 1.");
}

void ErrorLoggerTest2()
{
    // Arrange:
    auto errorLogger = arrange_error_logger();

    // Act
    errorLogger->log("test log message 2"); 
    ifstream logFile("./error.log");

    // Assert
    te->evaluate("Correct creation of log file 2.", logFile.is_open() == true);
}

void ErrorLoggerTest3()
{
    // Arrange:
    auto errorLogger = arrange_error_logger();

    // Act
    errorLogger->log("test log message 3");
    size_t found = errorLogger->getLastLog().find("test log message 3");

    // Assert
    te->evaluate("Successful addition of last log message.", found != string::npos);
}
#endif