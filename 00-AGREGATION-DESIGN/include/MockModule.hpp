/**
 * @file MockModule.hpp
 * @author Gabriel Ferreira (gferreiragabriel@abc.gob.ar)
 * @brief Header of MockModule
 * El objeto simulado o, en otras palabras, “mock”, 
 * es una función que reemplaza e imita un objeto o función real 
 * que opera dentro del programa. El propósito de esto es que, 
 * al probar el programa, se utilice el mock en vez del objeto real.
 * @version 0.1
 * @date 2022-04-26
 * 
 * @copyright Copyright (c) 2022 Released under the MIT license
 * @link https://opensource.org/licenses/MIT @endlink
 * 
 */

#ifndef MOCK_MODULE_H
#define MOCK_MODULE_H
#pragma once

#include <iostream>
#include <memory>
#include <MockInterface.hpp>
using namespace std;

class MockModule : public MockInterface
{
    public:
        MockModule();
        ~MockModule();
        void setLanguageFilePath(string filePath);
        void setLanguage(string language);
        string translate(string key);
    private:
        // shared_ptr<LangReader> _langReader;
        string _languageFilePath;
        string _language;
};

extern "C" shared_ptr<MockInterface> getInstanceOf(string typeId);
#endif