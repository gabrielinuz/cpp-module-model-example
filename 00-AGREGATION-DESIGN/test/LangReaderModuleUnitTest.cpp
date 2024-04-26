#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include <iostream>
#include <fstream>
#include <string>
#include <memory>

#include <catch.hpp>

#include <ModuleLoader.hpp>
#include <LoggeableConfigReader.hpp>

using namespace std;

// Global Arrange
auto ml = make_unique<ModuleLoader>();

/**
 * @brief Common Arrange
 * 
 * @return auto 
 */
auto initErrorLogger()
{
    ml->load("./lib/ErrorLoggerModule");
    auto errorLogger = ml->getInstanceAs<shared_ptr<Logger>>();
    return errorLogger;
}

auto initLangReader()
{
    ml->load("./lib/LangReaderModule");
    auto langReader = ml->getInstanceAs<shared_ptr<LoggeableConfigReader>>();
    return langReader;
}

TEST_CASE( "Correct creation of LangReader and get value of lang file", "[LangReader getValueOf method]" ) 
{
    /**
     * @brief Arrange
     */
    auto errorLogger = initErrorLogger();
    auto langReader = initLangReader();
    langReader->setLogger(errorLogger);

    /**
     * @brief Act
     */
    langReader->open("./lang/default.lang");
    string result = langReader->getValueOf("HELLO_WORLD");

    /**
     * @brief Assert
     */
    REQUIRE( result =="¡Hola Mundo!" );
}

TEST_CASE( "Correct validation of corrupt lang file", "[LangReader getValueOf method]" ) 
{
    /**
     * @brief Arrange
     */
    auto errorLogger = initErrorLogger();
    auto langReader = initLangReader();
    langReader->setLogger(errorLogger);

    /**
     * @brief Act
     */
    langReader->open("./lang/corrupt.lang");
    size_t found = errorLogger->getLastLog().find("Error opening lang file: ");

    /**
     * @brief Assert
     */
    REQUIRE( found != string::npos );
}

TEST_CASE( "Correct validation of not valid extension", "[LangReader getValueOf method]" ) 
{
    /**
     * @brief Arrange
     */
    auto errorLogger = initErrorLogger();
    auto langReader = initLangReader();
    langReader->setLogger(errorLogger);

    /**
     * @brief Act
     */
    langReader->open("./lang/jeringoso.pepe");

    //Error Message: "Error: the file: ./lang/jeringoso.pepe, does not have a .lang extension"
    string lastLog = errorLogger->getLastLog();
    size_t found = lastLog.find_last_of(",");
    string message = lastLog.substr(found);

    /**
     * @brief Assert
     */
    REQUIRE( message == ", Error opening lang file: ./lang/jeringoso.pepe" );
}