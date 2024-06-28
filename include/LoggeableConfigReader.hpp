#ifndef LOGGEABLECONFIGREADER_H
#define LOGGEABLECONFIGREADER_H
#pragma once

#include <iostream>

#include <ConfigReader.hpp>
#include <Loggeable.hpp>

using namespace std;

class LoggeableConfigReader : public ConfigReader, public Loggeable 
{
    //
};

#endif