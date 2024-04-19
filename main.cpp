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
#include <LanguageManager.hpp>
#include <ModuleLoader.hpp>

using namespace std;

int main()
{
    auto ml = make_unique<ModuleLoader>();
    
    /**
     * @brief Test Good Module
     * 
     */
    ml->load("./lib/LanguageManagerModule");
    auto lm = ml->getInstanceAs<shared_ptr<LanguageManager>>(); 
    cout << "Default LANG, HELLO_WORLD: " << lm->translate("HELLO_WORLD") << endl;
    cout << endl;
    cout << "-------------------------------------------------------------------------------" << endl;
    cout << endl;

    /**
     * @brief Test Wrong Module
     * @attention ./lib/LanguageManagerModuleTest is not a LanguageManager
     * @attention is a LanguageManagerTest.
     * @endcode
     */
    ml->load("./lib/LanguageManagerModuleTest");
    auto lmtest = ml->getInstanceAs<shared_ptr<LanguageManager>>();
    cout << "Default LANG, HELLO_WORLD: " << lmtest->translate("HELLO_WORLD") << endl;   
   
    /**
     * @brief Another use cases
     */
    // lm->setLanguageFilePath("./lang/esAR.lang");
    // cout << "FilePath ./lang/esAR.lang, HELLO_WORLD: " << lm->translate("HELLO_WORLD") << endl;
    
    // lm->setLanguage("esAR");
    // cout << "Language esAR, HELLO_WORLD: " << lm->translate("HELLO_WORLD") << endl;
    // cout << "Language esAR, HELLO_TODO: " << lm->translate("HELLO_TODO") << endl;
    // cout << "Language esAR, HELLO_NADA: "<< lm->translate("HELLO_NADA") << endl;
    
    // lm->setLanguage("enUS");
    // cout << "Language enUS, with spaces, , HELLO_WORLD: "  << lm->translate("HELLO_WORLD") << endl;
   
    // lm->setLanguage("frFR");
    // cout << "Language frFR, with abuse of semicolons: " << lm->translate("HELLO_WORLD") << endl;
    
    // lm->setLanguage("rusRUS");
    // cout << "Language rusRUS, null language: " << lm->translate("HELLO_WORLD") << endl;

    // lm->setLanguageFilePath("./lang/esES.lang");
    // cout << "Language esES, null language file: " << lm->translate("HELLO_WORLD") << endl;
    
    return EXIT_SUCCESS;
}