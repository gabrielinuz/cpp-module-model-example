/**
 * @file LangReaderModule.cpp
 * @author Gabriel Ferreira (gferreiragabriel@abc.gob.ar)
 * @brief Source of Reader of .lang files
 * @version 0.1
 * @date 2022-10-26
 * 
 * @copyright Copyright (c) 2022 Released under the MIT license
 * @link https://opensource.org/licenses/MIT @endlink
 * 
 */
#include <LangReaderModule.hpp>

LangReaderModule::LangReaderModule()
{
    //ctor
}

LangReaderModule::~LangReaderModule()
{
    _close();
}

bool LangReaderModule::open( string fileName )
{
    _fileInput.open(fileName.c_str());
    bool isCorruptFile = (!_fileInput.is_open() || !_fileInput.good()); 
    if (isCorruptFile) _error("Error opening lang file");
    return  !_fileInput ? false : true;
}

string LangReaderModule::getValueOf(string key)
{
    string value;
    _readFile();
    size_t pos = _bufferData.find(key);

    if (( pos == string::npos ) || ( _bufferData == "" ))
    {
        value = "";
    }
    else
    {
        int posValue = (_bufferData.find_first_of("=",pos) + 1);
        int posEndValue = _bufferData.find_first_of(";",posValue);
        size_t sizeOfString = posEndValue-posValue;

        value = _bufferData.substr(posValue,sizeOfString);
    }
    _trim(value);
    return value ;
}

void LangReaderModule::_close()
{
    _fileInput.close();
}

void LangReaderModule::_readFile()
{
    while( !_fileInput.eof())
    {
        string _buffer;

       _fileInput >> _buffer;
       _bufferData += " " + string(_buffer);
    }
}

void LangReaderModule::_log(string message, string filePath)
{
    ofstream logFile;
    logFile.open(filePath, ofstream::app);
    logFile << message << endl;
    logFile.close();
}

void LangReaderModule::_error(string message, string message2)
{
    cerr << message << ' ' << message2 << endl;
    exit(EXIT_FAILURE);
}

/**
 * @brief Trim function with lambda
 * @link https://stackoverflow.com/questions/216823/how-to-trim-an-stdstring @endlink
 * @param s 
 */
void LangReaderModule::_trim(std::string &s)
{
    s.erase(s.begin(), std::find_if(s.begin(), s.end(),
            std::not1(std::ptr_fun<int, int>(std::isspace))));
    s.erase(std::find_if(s.rbegin(), s.rend(),
            std::not1(std::ptr_fun<int, int>(std::isspace))).base(), s.end());  
}

shared_ptr<ConfigFileReader> getInstanceOf(string typeId) 
{
    return typeid(shared_ptr<ConfigFileReader>).name() == typeId ?
                 make_shared<LangReaderModule>() : nullptr;    
}