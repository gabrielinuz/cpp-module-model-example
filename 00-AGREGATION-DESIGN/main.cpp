/**
 * @file main.cpp
 * @author Gabriel Ferreira (gferreiragabriel@abc.gob.ar)
 * @brief Language Manager Module Example (Prototype)
 * @version 0.1
 * @date 2022-10-26
 * 
 * @copyright Copyright (c) 2022 Released under the MIT license
 * @link https://opensource.org/licenses/MIT @endlink
 * 
 */
#include <iostream>
#include <ModuleLoader.hpp>
#include <ConfigurableLanguageManager.hpp>
#include <Logger.hpp>
#include <LoggeableConfigReader.hpp>

using namespace std;

int main()
{
    auto ml = make_unique<ModuleLoader>();

    ml->load("./lib/ErrorLoggerModule");
    auto errorLogger = ml->getInstanceAs<shared_ptr<Logger>>();

    ml->load("./lib/LangReaderModule");
    auto langReader = ml->getInstanceAs<shared_ptr<LoggeableConfigReader>>();
    langReader->setLogger(errorLogger);

    ml->load("./lib/LanguageManagerModule");
    auto languageManager = ml->getInstanceAs<shared_ptr<ConfigurableLanguageManager>>();
    languageManager->setConfigReader(langReader);
    
     
    /**
     * @brief Test Good Module
     * 
     */
    cout << endl;
    cout << "-------------------------------------GOOD MODULE------------------------------------------" << endl;
    cout << "Default LANG, HELLO_WORLD: " << languageManager->translate("HELLO_WORLD") << endl;
    cout << endl;
    cout << "----------------------------------------MOCK MODULE---------------------------------------" << endl;

    /**
     * @brief Test Wrong Module
     * @attention ./lib/MockLanguageManagerModule is not a LanguageManager
     * @attention is a MockLanguageManager.
     * @endcode
     */
    ml->load("./lib/MockModule");
    auto mockModule = ml->getInstanceAs<shared_ptr<ConfigurableLanguageManager>>();

    return EXIT_SUCCESS;
}