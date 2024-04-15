/**
 * @file ILanguageManagerTest.hpp
 * @author Gabriel Ferreira (gferreiragabriel@abc.gob.ar)
 * @brief ILanguageManagerTest Pure Abstract Class
 * @version 0.1
 * @date 2022-10-26
 * 
 * @copyright Copyright (c) 2022 Released under the MIT license
 * @link https://opensource.org/licenses/MIT @endlink
 * 
 */

#ifndef I_LANGUAGE_MANAGER_TEST_HPP
#define I_LANGUAGE_MANAGER_TEST_HPP

#include <iostream>
#include <string>
using namespace std;

class ILanguageManagerTest
{
    public:
        /**
         * @brief BEFORE! Destroy the ILanguageManagerTest object
         * 
         */
        //virtual ~ILanguageManagerTest() {}
        
        virtual void setLanguageFilePath(string filePath) = 0;
        virtual void setLanguage(string language) = 0;
        virtual string translate(string key) = 0;
};

#endif // I_LANGUAGE_MANAGER_TEST_HPP