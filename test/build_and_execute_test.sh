#!/bin/bash

## Compilo código objeto
##LanguageManagerModule:
g++ -Wall -std=c++11 -fPIC -I../include/ -c ../src/LangReader.cpp
g++ -Wall -std=c++11 -fPIC -I../include/ -c ../src/LanguageManagerModule.cpp
g++ -shared -Wall -std=c++11 -fPIC -I../include/ LangReader.o LanguageManagerModule.o -o ../lib/LanguageManagerModule.so


## Compilo el Binario
g++ -Wall -std=c++11 -ldl LanguageManagerModuleUnitTest.cpp -o LanguageManagerModuleUnitTest.bin \
-I../include -I../include/vendors/catch -I../include/vendors/cppset/


# ##LanguageManagerModule:
chmod +x ./LanguageManagerModuleUnitTest.bin

## Limpio los códigos objeto
rm ./*.o

# ##LanguageManagerModule:
./LanguageManagerModuleUnitTest.bin