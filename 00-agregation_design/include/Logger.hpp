#ifndef LOGGER_H
#define LOGGER_H
#pragma once

#include<iostream>
#include <fstream>
#include <chrono>
#include <ctime>
#include <iomanip>
#include <string>

using namespace std;

class Logger
{
    public:
        virtual void setFilePath(string filePath) = 0;
        virtual void log(string detail) = 0;
        virtual void displayLogFile() = 0;
        virtual string getLastLog() = 0;
        virtual void displayLastLog() = 0;
        virtual void displayLastLogAndExit() = 0;
};

#endif