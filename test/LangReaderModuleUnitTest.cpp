#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include <iostream>
#include <fstream>
#include <string>
#include <memory>

#include <catch.hpp>

#include <Logger.hpp>
#include <LoggeableConfigReader.hpp>

#include <ModuleLoader.hpp>
#include <LangReaderModule.hpp>

using namespace std;

// Global Arrange
auto ml = make_unique<ModuleLoader>();

// TEST_CASE( "Correct creation of LangReader and get value of lang file", "[LangReader getValueOf method]" ) 
// {
//     //Arange
//     ml->load("./lib/ErrorLoggerModule");
//     auto errorLogger = ml->getInstanceAs<shared_ptr<Logger>>();

//     ml->load("./lib/LangReaderModule");
//     auto langReader = ml->getInstanceAs<shared_ptr<ConfigFileReader>>();
//     auto langReaderLoggeable = dynamic_pointer_cast<Loggeable>(langReader);

//     langReaderLoggeable->setLogger(errorLogger);

//     // Act
//     // HELLO_WORLD = ¡Hola Mundo!;
//     langReader->open("./lang/default.lang");
//     string result = langReader->getValueOf("HELLO_WORLD");

//     // Assert
//     REQUIRE( result =="¡Hola Mundo!" );
// }

TEST_CASE( "Correct validation of corrupt lang file", "[LangReader getValueOf method]" ) 
{
    //Arange
    ml->load("./lib/ErrorLoggerModule");
    auto errorLogger = ml->getInstanceAs<shared_ptr<Logger>>();

    ml->load("./lib/LangReaderModule");
    auto langReader = ml->getInstanceAs<shared_ptr<LoggeableConfigReader>>();

    langReader->setLogger(errorLogger);

    // Act
    // HELLO_WORLD = ¡Hola Mundo!;
    // langReader->open("./lang/corrupt.lang");
    langReader->open("./lang/corrupt.lang");
    size_t found = errorLogger->getLastLog().find("Error opening lang file: ");

    // Assert
    REQUIRE( found != string::npos );
}