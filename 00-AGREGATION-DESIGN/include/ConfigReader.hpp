/**
 * @file ConfigReader.hpp
 * @author Gabriel Ferreira (gferreiragabriel@abc.gob.ar)
 * @brief ConfigReader Pure Abstract Class
 * @version 0.1
 * @date 2024-04-26
 * 
 * @copyright Copyright (c) 2022 Released under the MIT license
 * @link https://opensource.org/licenses/MIT @endlink
 * 
 */
#ifndef CONFIGREADER_H
#define CONFIGREADER_H

#pragma once

#include <iostream>
using namespace std;

class ConfigReader
{
    public:
        virtual bool open( string filePath ) = 0;
        virtual string getValueOf( string key ) = 0;
};

#endif