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

bool LangReaderModule::open( string filePath )
{

    if (!hasLangExtension(filePath))
    {
        _logger->log("Error: the file: " + filePath + ", does not have a .lang extension");
        // _logger->displayLastLogAndExit();
    }

    _fileInput.open(filePath.c_str());
    bool isCorruptFile = (!_fileInput.is_open() || !_fileInput.good()); 
    if (isCorruptFile)
    {
        _logger->log("Error opening lang file: " + filePath);
        // _logger->displayLastLogAndExit();
    } 
    
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

void LangReaderModule::setLogger(shared_ptr<Logger> logger) 
{
    _logger = logger;    
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

shared_ptr<LoggeableConfigReader> getInstanceOf(string typeId) 
{
    return typeid(shared_ptr<LoggeableConfigReader>).name() == typeId ?
                 make_shared<LangReaderModule>() : nullptr;    
}

bool LangReaderModule::hasLangExtension(const string& filePath) 
{
    bool result = false;
    // Obtener la posición del último punto en la cadena
    size_t dotPos = filePath.find_last_of(".");
    if (dotPos != string::npos) 
    {
        // Obtener la subcadena después del último punto
        string extension = filePath.substr(dotPos);
        // Comparar la subcadena con ".lang"
        result = (extension == ".lang");
    }
    // Si no hay punto en la cadena, no puede tener extensión ".lang"
    return result;    
}
