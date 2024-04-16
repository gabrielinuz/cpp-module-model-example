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
#include <ILanguageManager.hpp>
#include <ModuleLoader.hpp>

using namespace std;
import lmModule = "./lib/LanguageManagerModule";
import lmModuleTest = "./lib/LanguageManagerModuleTest";

int main()
{
    auto lm = lmModule.getInstanceAs<shared_ptr<ILanguageManager>>(); 
    cout << "Default LANG, HELLO_WORLD: " << lm->translate("HELLO_WORLD") << endl;
    cout << endl;
    cout << "-------------------------------------------------------------------------------" << endl;
    cout << endl;

    /**
     * @brief Test Wrong Module
     */
    auto lmtest = lmModuleTest.getInstanceAs<shared_ptr<ILanguageManager>>();
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