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