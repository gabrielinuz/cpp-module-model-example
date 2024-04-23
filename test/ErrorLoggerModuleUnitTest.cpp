#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include <iostream>
#include <fstream>
#include <string>
#include <memory>

#include <catch.hpp>

#include <ModuleLoader.hpp>
#include <Logger.hpp>

using namespace std;

// Global Arrange
auto ml = make_unique<ModuleLoader>();

TEST_CASE( "Correct creation of error log file", "[ErrorLoggerModule log method]" ) 
{
    //Arange
    ml->load("./lib/ErrorLoggerModule");
    auto errorLogger = ml->getInstanceAs<shared_ptr<Logger>>();

    // Act
    errorLogger->log("test log message 1"); 
    ifstream logFile("./error.log");

    // Assert
    REQUIRE( logFile.is_open() == true );
}

TEST_CASE( "Correct creation of error log file 2", "[ErrorLoggerModule log method 2]" ) 
{
    //Arange
    ml->load("./lib/ErrorLoggerModule");
    auto errorLogger = ml->getInstanceAs<shared_ptr<Logger>>();

    // Act
    errorLogger->log("test log message 2"); 
    ifstream logFile("./error.log");

    // Assert
    REQUIRE( logFile.is_open() == true );
}

TEST_CASE( "Correct show last logfile message", "[ErrorLoggerModule showLastMsg]" ) 
{
    //Arange
    ml->load("./lib/ErrorLoggerModule");
    auto errorLogger = ml->getInstanceAs<shared_ptr<Logger>>();

    // Act
    errorLogger->log("test log message 3");
    size_t found = errorLogger->getLastLog().find("test log message 3");

    // Assert
    REQUIRE( found != string::npos );
}