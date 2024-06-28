/**
 * @file ConfigurableLanguageManager.hpp
 * @author Gabriel Ferreira (gferreiragabriel@abc.gob.ar)
 * @brief ConfigurableLanguageManager Pure Abstract Class
 * @version 0.1
 * @date 2024-04-26
 * 
 * @copyright Copyright (c) 2022 Released under the MIT license
 * @link https://opensource.org/licenses/MIT @endlink
 * 
 */

#ifndef CONFIGURABLE_LANGUAGE_MANAGER_H
#define CONFIGURABLE_LANGUAGE_MANAGER_H
#pragma once

#include <iostream>

#include <LanguageManager.hpp>
#include <Configurable.hpp>

using namespace std;

class ConfigurableLanguageManager : public LanguageManager, public Configurable 
{
    //
};

#endif