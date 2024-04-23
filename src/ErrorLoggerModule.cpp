#include <ErrorLoggerModule.hpp>

ErrorLoggerModule::ErrorLoggerModule()
{
    _filePath = "./error.log";
}

ErrorLoggerModule::~ErrorLoggerModule()
{
}

void ErrorLoggerModule::setFilePath(string filePath)
{
    _filePath = filePath;
}

// void ErrorLoggerModule::log(const string& detail) 
void ErrorLoggerModule::log(string detail) 
{
    ofstream outFile(_filePath, ios_base::app);
    if (outFile.is_open()) 
    {
        auto now = chrono::system_clock::now();
        time_t currentTime = chrono::system_clock::to_time_t(now);
        outFile << _getFormattedTime(currentTime) << ", " << detail << endl;
        outFile.close();
    } 
    else 
    {
        cerr << "Error al abrir el archivo " << _filePath << " para escribir." << endl;
    }
}

void ErrorLoggerModule::displayLogFile() 
{
    ifstream inFile(_filePath);
    if (inFile.is_open()) 
    {
        string line;
        while (getline(inFile, line)) 
        {
            cout << line << endl;
        }
        inFile.close();
    } 
    else 
    {
        cerr << "Error al abrir el archivo " << _filePath << " para leer." << endl;
    }
}

string ErrorLoggerModule::getLastLog()
{
    string lastLog;
    ifstream inFile(_filePath);
    if (inFile.is_open()) 
    {
        inFile.seekg(0, ios::end);
        if (inFile.tellg() > 0) 
        {
            inFile.seekg(-1, ios::cur);
            char ch;
            // Skip newline characters until we find the beginning of the last line
            do 
            {
                inFile.seekg(-2, ios::cur);
                inFile.get(ch);
            } while (ch != '\n' && inFile.tellg() > 0);
            // Get the last line
            getline(inFile, lastLog);
        }
        inFile.close();
    } 
    else 
    {
        cerr << "Error al abrir el archivo " << _filePath << " para leer." << endl;
    } 
    return lastLog; 
}

void ErrorLoggerModule::displayLastLog()
{
    cerr << getLastLog() << endl;
}

/**
 * @brief PRIVATE SECTION
 */
string ErrorLoggerModule::_getFormattedTime(time_t time) const 
{
    stringstream ss;
    ss << put_time(localtime(&time), "%F %T");
    return ss.str();
}

void ErrorLoggerModule::_error(string message)
{
    cerr << message << endl;
    exit(EXIT_FAILURE);
}

shared_ptr<Logger> getInstanceOf(string typeId) 
{
    return typeid(shared_ptr<Logger>).name() == typeId ?
                 make_shared<ErrorLoggerModule>() : nullptr;    
}


