/**
* Copyright (c) 2022 Gabriel Nicolás González Ferreira. All rights reserved.
* This file is part of CPPSET tools.
* Released under the MIT license
* https://opensource.org/licenses/MIT
**/

#ifndef MODULE_CONF_READER_HPP
#define MODULE_CONF_READER_HPP

#include <string>
#include <iostream>
#include <memory>

using namespace std;

class ModuleConfReader
{
    private:
        ifstream _fileInput;
        string _bufferData ;

        void _readFile();
        void _close();
        void _trim(std::string &s);

        bool hasConfExtension(const string& filePath);

    public:
        ModuleConfReader();
        ~ModuleConfReader();
        bool open( string filePath );
        string getValueOf( string key );

    private:
        unique_ptr<SharedLibraryLoader> libraryLoader;
        bool isLoaded;

        void _displayFatalError(string message, string message2 = "")
        {
            cerr << message << ' ' << message2 << endl;
            exit(EXIT_FAILURE);
        }        
    
    public:
        ModuleConfReader()
        {
            libraryLoader = make_unique<SharedLibraryLoader>();
        }

        ~ModuleConfReader()
        {
        }

        void load(string filePath)
        {
            isLoaded = libraryLoader->load(filePath);
        }

        template<typename ObjectType> 
        ObjectType getInstanceAs()
        {
            ObjectType obj = nullptr;
            if(isLoaded)
            {
                typedef ObjectType ( *PointerToFunctionType ) (string);
                PointerToFunctionType getInstanceOf = (PointerToFunctionType)libraryLoader->getExternSymbol("getInstanceOf");
                if( getInstanceOf )
                {
                    obj = getInstanceOf(typeid(ObjectType).name());

                    if( obj == nullptr )
                    {
                        _displayFatalError("Module Loader Error: The return type of module is not the same as the one requested => ", string( typeid(ObjectType).name() ) );
                        cout << endl;
                    } 
                }
                else
                {
                    _displayFatalError("Module Loader Error: Function \"getInstanceOf(string)\" name does not exist in symbol table!");
                }
            }
            else
            {
                _displayFatalError("Module Loader Error: Library is not loaded, can't get instance");
            }
            
            return obj;        
        }
};

#endif // MODULE_CONF_READER_HPP