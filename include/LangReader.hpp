/**
 * @file LangReader.hpp
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

using namespace std;

class LangReader
{
    public:
        LangReader();
        virtual ~LangReader();
        bool open( string fileName);
        string getValueOf( string key );

    private:
        ifstream _fileInput;
        string _bufferData ;

        void _readFile();
        void _close();
        void _trim(std::string &s);
        void _log(string message, string filePath = "log.txt");
        void _error(string message, string message2 = "");
};

#endif // LANG_READER_HPP
