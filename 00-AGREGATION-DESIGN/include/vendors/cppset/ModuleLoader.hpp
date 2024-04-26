/**
* Copyright (c) 2022 Gabriel Nicolás González Ferreira. All rights reserved.
* This file is part of CPPSET tools.
* Released under the MIT license
* https://opensource.org/licenses/MIT
**/

#ifndef MODULE_LOADER_HPP
#define MODULE_LOADER_HPP

#include <string>
#include <iostream>
#include <memory>
#include <SharedLibraryLoader.hpp>

using namespace std;

class ModuleLoader
{
    private:
        unique_ptr<SharedLibraryLoader> libraryLoader;
        bool isLoaded;

        void _displayFatalError(string message, string message2 = "")
        {
            cerr << message << ' ' << message2 << endl;
            cout << endl;
            exit(EXIT_FAILURE);
        }        
    
    public:
        ModuleLoader()
        {
            libraryLoader = make_unique<SharedLibraryLoader>();
        }

        ~ModuleLoader()
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

#endif // MODULE_LOADER_HPP