/**
 * @file LangReaderModule.hpp
 * @author Gabriel Ferreira (gferreiragabriel@abc.gob.ar)
 * @brief Header of Reader of .lang files
 * @version 0.1
 * @date 2022-10-26
 * 
 * @copyright Copyright (c) 2022 Released under the MIT license
 * @link https://opensource.org/licenses/MIT @endlink
 * 
 */
#ifndef LANG_READER_HPP
#define LANG_READER_HPP

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

//FOR TRIM LAMBDA FUNCTION
#include <algorithm> 

#include <LoggeableConfigReader.hpp>
#include <Logger.hpp>

using namespace std;

// class LangReaderModule : public ConfigFileReader, public Loggeable
class LangReaderModule : public LoggeableConfigReader
{
    public:
        LangReaderModule();
        ~LangReaderModule();
        bool open( string filePath );
        string getValueOf( string key );

        /**
         * @brief Set the Logger object, required by Loggeable
         */
        void setLogger(shared_ptr<Logger> logger);

    private:
        ifstream _fileInput;
        string _bufferData ;

        void _readFile();
        void _close();
        void _trim(std::string &s);

        bool hasLangExtension(const string& filePath);

        shared_ptr<Logger> _logger;
};

extern "C" shared_ptr<LoggeableConfigReader> getInstanceOf(string typeId);

#endif // LANG_READER_HPP
