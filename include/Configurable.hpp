/**
 * @file Configurable.hpp
 * @author Gabriel Ferreira (gferreiragabriel@abc.gob.ar)
 * @brief Configurable Role Pure Abstract Class
 * @version 0.1
 * @date 2024-04-26
 * 
 * @copyright Copyright (c) 2022 Released under the MIT license
 * @link https://opensource.org/licenses/MIT @endlink
 * 
 */

#ifndef CONFIGURABLE_H
#define CONFIGURABLE_H
#pragma once

#include<iostream>
#include<memory>
#include<ConfigReader.hpp>

using namespace std;

class Configurable
{
    public:
        virtual void setConfigReader(shared_ptr<ConfigReader> configReader) = 0;
};

#endif