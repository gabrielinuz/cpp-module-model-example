#ifndef ERRORLOGGERMODULE_H
#define ERRORLOGGERMODULE_H

#pragma once

#include <iostream>
#include <memory>
#include<Logger.hpp>

using namespace std;

class ErrorLoggerModule : public Logger
{
    public:
        ErrorLoggerModule();
        ~ErrorLoggerModule();
        void setFilePath(string filePath);
        void log(string detail);
        void displayLogFile();
        string getLastLog();
        void displayLastLog();

    private:
        string _filePath;
        string _getFormattedTime(std::time_t time) const;
        void _error(string message);
};

extern "C" shared_ptr<Logger> getInstanceOf(string typeId);



#endif