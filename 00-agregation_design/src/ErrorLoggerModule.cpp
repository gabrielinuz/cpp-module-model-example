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
        _displayExitConsoleError("Error openning " + _filePath + " for reading");
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
        _displayExitConsoleError("Error openning " + _filePath + " for reading");
    }
}

string ErrorLoggerModule::getLastLog()
{
    ifstream fin(_filePath); // Abrir el archivo en modo de lectura
    string lastLog;
    if (fin.is_open()) 
    {
        string line;
        while (getline(fin, line)) { // Leer el archivo línea por línea
            lastLog = line; // Almacenar la última línea leída
        }
        fin.close(); // Cerrar el archivo
    } 
    else 
    {
        _displayExitConsoleError("Error openning " + _filePath + " for reading");
    }
    return lastLog; // Devolver la última línea leída
}

void ErrorLoggerModule::displayLastLog()
{
    cerr << "Last log: " << getLastLog() << endl;
}

void ErrorLoggerModule::displayLastLogAndExit()
{
    _displayExitConsoleError(getLastLog());
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

void ErrorLoggerModule::_displayExitConsoleError(string message)
{
    cerr << "EXIT! - FATAL ERROR!: " << message << endl;
    exit(EXIT_FAILURE);
}

shared_ptr<Logger> getInstanceOf(string typeId) 
{
    return typeid(shared_ptr<Logger>).name() == typeId ?
                 make_shared<ErrorLoggerModule>() : nullptr;    
}


