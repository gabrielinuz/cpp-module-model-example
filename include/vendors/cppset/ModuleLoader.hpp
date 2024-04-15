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
        shared_ptr<SharedLibraryLoader> libraryLoader;
        bool isLoaded;

        void showError(string message, string message2 = "")
        {
            cerr << message << ' ' << message2 << endl;
            exit(EXIT_FAILURE);
        }        
    
    public:
        ModuleLoader()
        {
            libraryLoader = make_shared<SharedLibraryLoader>();////NOT NEW
        }
        
        /**
         * @brief Construct a new Module Loader object
         * with parameter const char* to able the syntax
         * ModuleLoader ml = "./path/to/library" 
         * 
         * @param filePath 
         */
        ModuleLoader(const char* filePath)
        {
            libraryLoader = make_shared<SharedLibraryLoader>();////NOT NEW
            isLoaded = libraryLoader->load(filePath);
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
                        showError("Error: The return type of module is not the same as the one requested!");
                        cout << endl;
                    } 
                }
                else
                {
                    showError("Error: Function \"getInstanceOf(string)\" name does not exist in symbol table!");
                }
            }
            else
            {
                showError("Error: Library is not loaded, can't get instance");
            }
            
            return obj;        
        }
};

// typedef ModuleLoader import;
using import = ModuleLoader;

#endif // MODULE_LOADER_HPP