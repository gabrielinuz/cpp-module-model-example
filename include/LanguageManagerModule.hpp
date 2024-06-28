/**
 * @file LanguageManagerModule.hpp
 * @author Gabriel Ferreira (gferreiragabriel@abc.gob.ar)
 * @brief Header of Reader of Language Manager Module Example
 * @version 0.1
 * @date 2022-10-26
 * 
 * @copyright Copyright (c) 2022 Released under the MIT license
 * @link https://opensource.org/licenses/MIT @endlink
 * 
 */

#ifndef LANGUAGE_MANAGER_MODULE_H
#define LANGUAGE_MANAGER_MODULE_H
#pragma once

#include <iostream>
#include <string>
#include <memory>
#include <ConfigurableLanguageManager.hpp>

using namespace std;

class LanguageManagerModule : public ConfigurableLanguageManager
{
    public:
        LanguageManagerModule();
        ~LanguageManagerModule();
        void setLanguageFilePath(string filePath);
        void setLanguage(string language);
        string translate(string key);

        //Configurable:
        void setConfigReader(shared_ptr<ConfigReader> configReader);
        
    private:
        string _languageFilePath;
        string _language;

        shared_ptr<ConfigReader> _configReader;
};

extern "C" shared_ptr<ConfigurableLanguageManager> getInstanceOf(string typeId);
#endif