#!/bin/bash
## Compilo el binario del test
g++ -Wall -std=c++14 -ldl LangReaderModuleUnitTest.cpp -o ./build/LangReaderModuleUnitTest.bin \
-I../include -I../include/vendors/catch -I../include/vendors/cppset/


# ##LangReaderModule:
chmod +x ./build/LangReaderModuleUnitTest.bin

## Ejecuto el binario:
cd build/
./LangReaderModuleUnitTest.bin