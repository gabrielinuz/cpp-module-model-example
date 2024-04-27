#!/bin/bash
## Compilo el Binario
g++ -Wall -std=c++14 -ldl maintest.cpp -o ./build/maintest.bin \
-I../include -I../include/vendors/cppset/


# ##ErrorLoggerModule:
chmod +x ./build/maintest.bin

# ##ErrorLoggerModule:
## Ejecuto el binario:
cd build/
./maintest.bin