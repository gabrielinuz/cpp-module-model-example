/**
* Copyright (c) 2022 Gabriel Nicolás González Ferreira. All rights reserved.
* This file is part of CPPSET tools.
* Released under the MIT license
* https://opensource.org/licenses/MIT
**/

#ifndef SHARED_LIBRARY_LOADER_HPP
#define SHARED_LIBRARY_LOADER_HPP

#ifdef __unix__
    #define RTLD_LAZY   1
    #define RTLD_NOW    2
    #define RTLD_GLOBAL 4
    #include <vendors/dlopen/dlfcn.h>
#elif __APPLE__
    #include <vendors/dlopen/dlfcnMac.h>
#elif defined(_WIN32) || defined(WIN32)
    #include <windows.h>
#endif // defined

#include <string>
#include <iostream>

using namespace std;

class SharedLibraryLoader
{
    private:
        void* library;
        void* symbol;
        bool isFree;
        bool isLoaded;

        void displayFatalError(string message, string message2 = "")
        {
            cerr << message << ' ' << message2 << endl;
            exit(EXIT_FAILURE);
        }

    public:
        SharedLibraryLoader()
        {           
            library = nullptr;
            symbol = nullptr;
            isLoaded = false;
            isFree = false;
        }

        SharedLibraryLoader(string filePath)
        {
            isLoaded = false;
            isFree = false;
            load(filePath);
            symbol = nullptr;
        }

        virtual ~SharedLibraryLoader()
        {
            freeLibrary();
        }

        void* load(string filePath)
        {        
            #ifdef __unix__
                filePath += ".so";
                library = dlopen(filePath.c_str(), RTLD_NOW);
            #elif __APPLE__
                filePath += ".dylib";
                library = dlopen(filePath.c_str(), RTLD_LOCAL|RTLD_LAZY);
            #elif defined(_WIN32) || defined(WIN32)
                filePath += ".dll";
                library = (void*) LoadLibrary(filePath.c_str());
            #endif // defined

            //LEER DOCUMENTACION DE MICROSOFT
            (library) ? isLoaded = true : isLoaded = false;
            if(!isLoaded) displayFatalError("Error: The library "+filePath+" could not be loaded!");     
            
            return library;
        }

        void* getExternSymbol(string name)
        {
            if(isLoaded)
            {
                #ifdef __unix__
                    symbol = dlsym(library, name.c_str());
                #elif __APPLE__
                    symbol = dlsym(library, name.c_str());
                #elif defined(_WIN32) || defined(WIN32)
                    symbol = (void*) GetProcAddress((HINSTANCE)library, name.c_str());
                #endif // defined        
                if(!symbol) displayFatalError("Error: Library symbol does not exist or cannot be obtained!");        
            }
            else
            {
                displayFatalError("Error: Library is not loaded, can't get symbol");
            }
            

            return symbol;
        }

        /**
         * @brief Free the shared library handler. dlclose no return boolean value
         */
        bool freeLibrary()
        {
            if(isLoaded)
            {
                #ifdef __unix__
                    isLoaded = dlclose(library);
                    isLoaded ? isFree = false : isFree = true; 
                #elif __APPLE__
                    isLoaded = dlclose(library);
                    isLoaded ? isFree = false : isFree = true; 
                #elif defined(_WIN32) || defined(WIN32)
                    isFree = FreeLibrary((HINSTANCE)library);
                    isFree ? isLoaded = false : isLoaded = true; 
                #endif // defined
            }
            return isFree;
        }
};

#endif // SHARED_LIBRARY_LOADER_HPP

