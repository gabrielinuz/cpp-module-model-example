/**
 * @file ErrorLoggerModule.hpp
 * @author Gabriel Ferreira (gferreiragabriel@abc.gob.ar)
 * @brief ErrorLoggerModule Pure Abstract Class
 * @version 0.1
 * @date 2024-04-26
 * 
 * @copyright Copyright (c) 2022 Released under the MIT license
 * @link https://opensource.org/licenses/MIT @endlink
 * 
 */

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
        void displayLastLogAndExit();

    private:
        string _filePath;
        string _getFormattedTime(std::time_t time) const;
        void _displayExitConsoleError(string message);
};

extern "C" shared_ptr<Logger> getInstanceOf(string typeId);



#endif