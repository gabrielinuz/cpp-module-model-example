#!/bin/bash
## Compilo el binario del test
g++ -Wall -std=c++14 -ldl LanguageManagerModuleUnitTest.cpp -o ./build/LanguageManagerModuleUnitTest.bin \
-I../include -I../include/vendors/catch -I../include/vendors/cppset/


# ##LanguageManagerModule:
chmod +x ./build/LanguageManagerModuleUnitTest.bin

## Ejecuto el binario:
cd build/
./LanguageManagerModuleUnitTest.bin