#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include <catch.hpp>
#include <iostream>
#include <fstream>
#include <string>

#include <ModuleLoader.hpp>
#include <LoggeableConfigReader.hpp>
#include <ConfigurableLanguageManager.hpp>


using namespace std;

/**
 * @brief Common Arrange
 * 
 * @return auto 
 */
auto ml = make_unique<ModuleLoader>();

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

auto initLanguageManager()
{
    ml->load("./lib/LanguageManagerModule");
    auto languageManager = ml->getInstanceAs<shared_ptr<ConfigurableLanguageManager>>();
    return languageManager;
}

TEST_CASE( "Correct translation into default language", "[LanguageManager getTranslation]" )
{
    /**
     * @brief Arrange
     */
    auto errorLogger = initErrorLogger();
    auto langReader = initLangReader();
    langReader->setLogger(errorLogger);

    auto languageManager = initLanguageManager();
    languageManager->setConfigReader(langReader);
 
    // Act
    string translation = languageManager->translate("HELLO_WORLD");
        
    // Assert
    REQUIRE( translation == "¡Hola Mundo!" );
}

TEST_CASE( "Correct translation into Spanish", "[LanguageManager getTranslation]" )
{
    /**
     * @brief Arrange
     */
    auto errorLogger = initErrorLogger();
    auto langReader = initLangReader();
    langReader->setLogger(errorLogger);

    auto languageManager = initLanguageManager();
    languageManager->setConfigReader(langReader);
 
    // Act
    languageManager->setLanguage("esAR");
    string translation = languageManager->translate("HELLO_WORLD");
        
    // Assert
    REQUIRE( translation == "¡Hola Mundo!" );
}

TEST_CASE( "Correct translation into English", "[LanguageManager getTranslation]" )
{
    /**
     * @brief Arrange
     */
    auto errorLogger = initErrorLogger();
    auto langReader = initLangReader();
    langReader->setLogger(errorLogger);

    auto languageManager = initLanguageManager();
    languageManager->setConfigReader(langReader);
 
    // Act
    languageManager->setLanguage("enUS");
    string translation = languageManager->translate("HELLO_WORLD");
        
    // Assert
    REQUIRE( translation == "¡Hello World!" );
}

TEST_CASE( "Correct translation into French", "[LanguageManager getTranslation]" )
{
    /**
     * @brief Arrange
     */
    auto errorLogger = initErrorLogger();
    auto langReader = initLangReader();
    langReader->setLogger(errorLogger);

    auto languageManager = initLanguageManager();
    languageManager->setConfigReader(langReader);
 
    // Act
    languageManager->setLanguage("frFR");
    string translation = languageManager->translate("HELLO_WORLD");
        
    // Assert
    REQUIRE( translation == "¡Salut monde!" );
}