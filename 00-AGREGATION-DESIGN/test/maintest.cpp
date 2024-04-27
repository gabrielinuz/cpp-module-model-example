#include <iostream>
#include <string>
#include <fstream>
#include <memory>

//cppset:
#include <TestEvaluator.hpp>
#include <ModuleLoader.hpp>

//Modules interfaces:
#include <Logger.hpp>
#include <LoggeableConfigReader.hpp>
#include <ConfigurableLanguageManager.hpp>

using namespace std;

auto te = make_unique<TestEvaluator>();
auto ml = make_unique<ModuleLoader>();
    
////////////////////////////////////////ErrorLogger Tests://////////////////////////////////////
/**
 * @brief Common ErrorLogger arange of unit test
 * 
 */
auto arrangeErrorLogger()
{
    //Arange
    ml->load("./lib/ErrorLoggerModule");
    return ml->getInstanceAs<shared_ptr<Logger>>();
}

void errorLoggerTest1()
{
    // Arrange:
    // te->setName("Correct creation of log file 1.");
    auto errorLogger = arrangeErrorLogger();

    // Act:
    errorLogger->log("test log message 1"); 
    ifstream logFile("./error.log");

    //Assert:
    te->evaluate("Correct creation of log file 1.", logFile.is_open() == true);
    // te->evaluate(logFile.is_open() == true, "Correct creation of log file 1.");
}

void errorLoggerTest2()
{
    // Arrange:
    auto errorLogger = arrangeErrorLogger();

    // Act
    errorLogger->log("test log message 2"); 
    ifstream logFile("./error.log");

    // Assert
    te->evaluate("Correct creation of log file 2.", logFile.is_open() == true);
}

void errorLoggerTest3()
{
    // Arrange:
    auto errorLogger = arrangeErrorLogger();

    // Act:
    errorLogger->log("test log message 3");
    size_t found = errorLogger->getLastLog().find("test log message 3");

    // Assert:
    te->evaluate("Successful addition of last log message.", found != string::npos);
}

////////////////////////////////////////LangReader Tests://////////////////////////////////////
auto arrangeLangReader()
{
    ml->load("./lib/LangReaderModule");
    auto langReader = ml->getInstanceAs<shared_ptr<LoggeableConfigReader>>();
    langReader->setLogger(arrangeErrorLogger());
    return langReader;
}

void langReaderTest1()
{
    // Arrange:
    auto langReader = arrangeLangReader();

    // Act:
    langReader->open("./lang/default.lang");
    string result = langReader->getValueOf("HELLO_WORLD");

    // Assert:
    te->evaluate("Correct get value of lang file.", result == "¡Hola Mundo!");
}

void langReaderTest2()
{
    // Arrange:
    auto langReader = arrangeLangReader();
    auto errorLogger = arrangeErrorLogger();

    // Act:
    langReader->open("./lang/corrupt.lang");
    size_t found = errorLogger->getLastLog().find("Error opening lang file: ");

    // Assert:
    te->evaluate("Correct validation of corrupt lang file", found != string::npos);
}

void langReaderTest3()
{
    // Arrange:
    auto langReader = arrangeLangReader();
    auto errorLogger = arrangeErrorLogger();

    // Act:
    langReader->open("./lang/jeringoso.pepe");

    //Error Message: "Error: the file: ./lang/jeringoso.pepe, does not have a .lang extension"
    string lastLog = errorLogger->getLastLog();
    size_t found = lastLog.find_last_of(",");
    string message = lastLog.substr(found);

    // Assert:
    te->evaluate("Correct validation of not valid extension", message == ", Error opening lang file: ./lang/jeringoso.pepe" );    
}

////////////////////////////////////////LanguageManager Tests://////////////////////////////////////
auto arrangeLanguageManager()
{
    ml->load("./lib/LanguageManagerModule");
    auto languageManager = ml->getInstanceAs<shared_ptr<ConfigurableLanguageManager>>();
    languageManager->setConfigReader(arrangeLangReader());
    return languageManager;
}

void languageManagerTest1()
{
    // Arrange:
    auto languageManager = arrangeLanguageManager();
    // Act
    string translation = languageManager->translate("HELLO_WORLD");
    // Assert:
    te->evaluate("Correct translation into default language", translation == "¡Hola Mundo!" );
} 

void languageManagerTest2()
{
    // Arrange:
    auto languageManager = arrangeLanguageManager();
    // Act:
    languageManager->setLanguage("esAR");
    string translation = languageManager->translate("HELLO_WORLD");
    // Assert:
    te->evaluate("Correct translation into Spanish", translation == "¡Hola Mundo!" );
}

void languageManagerTest3()
{
    // Arrange:
    auto languageManager = arrangeLanguageManager();
    // Act:
    languageManager->setLanguage("frFR");
    string translation = languageManager->translate("HELLO_WORLD");
    // Assert:
    te->evaluate("Correct translation into French", translation == "¡Salut monde!" );
} 

void languageManagerTest4()
{
    // Arrange:
    auto languageManager = arrangeLanguageManager();
    // Act:
    languageManager->setLanguage("enUS");
    string translation = languageManager->translate("HELLO_WORLD");
    // Assert:
    te->evaluate("Correct translation into English", translation == "¡Hello World!" );
} 


//////////////////////////////////////////MAIN:///////////////////////////////////////////////

int main()
{
    /**
     * @brief ErrorLogger Tests
     */
    te->title("ErrorLogger Tests:");
    errorLoggerTest1();
    errorLoggerTest2();
    errorLoggerTest3();

    /**
     * @brief LangReader Tests
     */
    te->title("LangReader Tests:");
    langReaderTest1(); 
    langReaderTest2(); 
    langReaderTest3(); 

    /**
     * @brief LanguageManager Tests
     */
    te->title("LanguageManager Tests:");
    languageManagerTest1(); 
    languageManagerTest2(); 
    languageManagerTest3(); 

    /**
     * @brief Mock Failed Test
     */
    te->title("Mock Test:");
    te->evaluate("Mock Failed Test", true == false);

    /**
     * @brief Print Tests Summary.
     */
    te->summary();
    return 0;
}
