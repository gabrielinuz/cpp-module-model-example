/**
 * @file LanguageManagerModuleTest.hpp
 * @author Gabriel Ferreira (gferreiragabriel@abc.gob.ar)
 * @brief Header of Reader of Language Manager Module Example
 * @version 0.1
 * @date 2022-10-26
 * 
 * @copyright Copyright (c) 2022 Released under the MIT license
 * @link https://opensource.org/licenses/MIT @endlink
 * 
 */

#ifndef LANGUAGE_MANAGER_MODULE_TEST_H
#define LANGUAGE_MANAGER_MODULE_TEST_H

#ifndef __DEBUG__
    #define __DEBUG__
#endif

#include <iostream>
#include <memory>
#include <ILanguageManagerTest.hpp>
#include <LangReader.hpp>
using namespace std;

class LanguageManagerModuleTest : public ILanguageManagerTest
{
    public:
        LanguageManagerModuleTest();
        ~LanguageManagerModuleTest();
        void setLanguageFilePath(string filePath);
        void setLanguage(string language);
        string translate(string key);
    private:
        shared_ptr<LangReader> _langReader;
        string _languageFilePath;
        string _language;
};

extern "C" shared_ptr<ILanguageManagerTest> getInstanceOf(string typeId);
#endif