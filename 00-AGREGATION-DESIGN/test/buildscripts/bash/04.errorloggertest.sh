#!/bin/bash
## Compilo el Binario
g++ -Wall -std=c++14 -ldl ErrorLoggerModuleUnitTest.cpp -o ./build/ErrorLoggerModuleUnitTest.bin \
-I../include -I../include/vendors/catch -I../include/vendors/cppset/


# ##ErrorLoggerModule:
chmod +x ./build/ErrorLoggerModuleUnitTest.bin

# ##ErrorLoggerModule:
## Ejecuto el binario:
cd build/
./ErrorLoggerModuleUnitTest.bin