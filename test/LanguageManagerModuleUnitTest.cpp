#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include <LanguageManager.hpp>
#include <ModuleLoader.hpp>
#include <catch.hpp>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

auto ml = make_unique<ModuleLoader>();
 
TEST_CASE( "LanguageManager create instance", "[LanguageManager new]" ) 
{
    // Arrange
    ml->load("./lib/LanguageManagerModule");
    auto lm = ml->getInstanceAs<shared_ptr<LanguageManager>>();
    
    // Act
    bool isILanguageManager = ( dynamic_pointer_cast<shared_ptr<LanguageManager>> (lm) != nullptr );

    // Assert
    REQUIRE( isILanguageManager == true );
}

TEST_CASE( "Correct translation into default language", "[LanguageManager getTranslation]" )
{
    // Arrange
    ml->load("./lib/LanguageManagerModule");
    auto lm = ml->getInstanceAs<shared_ptr<LanguageManager>>();
 
    // Act
    string translation = lm->translate("HELLO_WORLD");
        
    // Assert
    REQUIRE( translation == "¡Hola Mundo!" );
}

TEST_CASE( "Correct translation into Spanish", "[LanguageManager getTranslation]" )
{
    // Arrange
    ml->load("./lib/LanguageManagerModule");
    auto lm = ml->getInstanceAs<shared_ptr<LanguageManager>>();
 
    // Act
    lm->setLanguage("esAR");
    string translation = lm->translate("HELLO_WORLD");
        
    // Assert
    REQUIRE( translation == "¡Hola Mundo!" );
}

TEST_CASE( "Correct translation into English", "[LanguageManager getTranslation]" )
{
    // Arrange
    ml->load("./lib/LanguageManagerModule");
    auto lm = ml->getInstanceAs<shared_ptr<LanguageManager>>();
 
    // Act
    lm->setLanguage("enUS");
    string translation = lm->translate("HELLO_WORLD");
        
    // Assert
    REQUIRE( translation == "¡Hello World!" );
}

TEST_CASE( "Correct translation into French", "[LanguageManager getTranslation]" )
{
    // Arrange
    ml->load("./lib/LanguageManagerModule");
    auto lm = ml->getInstanceAs<shared_ptr<LanguageManager>>();
 
    // Act
    lm->setLanguage("frFR");
    string translation = lm->translate("HELLO_WORLD");
        
    // Assert
    REQUIRE( translation == "¡Salut monde!" );
}