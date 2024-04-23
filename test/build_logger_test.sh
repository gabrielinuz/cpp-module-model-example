#!/bin/bash
##Borro el directorio si ya existiera
if [ -d "./build" ];
	then rm -r ./build;
fi

##Preparo directorios y recursos
mkdir ./build
mkdir ./build/lib

## Compilo código objeto
##ErrorLoggerModule:
g++ -Wall -std=c++14 -fPIC -I../include/ -c ../src/ErrorLoggerModule.cpp
g++ -shared -Wall -std=c++14 -fPIC -I../include/ ErrorLoggerModule.o -o ./build/lib/ErrorLoggerModule.so


## Compilo el Binario
g++ -Wall -std=c++14 -ldl ErrorLoggerModuleUnitTest.cpp -o ./build/ErrorLoggerModuleUnitTest.bin \
-I../include -I../include/vendors/catch -I../include/vendors/cppset/


# ##ErrorLoggerModule:
chmod +x ./build/ErrorLoggerModuleUnitTest.bin

## Limpio los códigos objeto
rm ./*.o

# ##ErrorLoggerModule:
## Ejecuto el binario:
cd build/
./ErrorLoggerModuleUnitTest.bin