#!/bin/bash
##Borro el directorio si ya existiera
if [ -d "./build" ];
	then rm -r ./build;
fi

##Preparo directorios y recursos
mkdir ./build
mkdir ./build/lib

cp -r ../resources/lang/ ./build/

## Compilo las bibliotecas
g++ -Wall -std=c++14 -fPIC -I../include/ -c ../src/ErrorLoggerModule.cpp
g++ -shared -Wall -std=c++14 -fPIC -I../include/ ErrorLoggerModule.o -o ./build/lib/ErrorLoggerModule.so

g++ -Wall -std=c++14 -fPIC -I../include/ -c ../src/LangReaderModule.cpp
g++ -shared -Wall -std=c++14 -fPIC -I../include/ LangReaderModule.o -o ./build/lib/LangReaderModule.so


## Compilo el Binario
g++ -Wall -std=c++14 -ldl LangReaderModuleUnitTest.cpp -o ./build/LangReaderModuleUnitTest.bin \
-I../include -I../include/vendors/catch -I../include/vendors/cppset/


# ##LangReaderModule:
chmod +x ./build/LangReaderModuleUnitTest.bin

## Limpio los códigos objeto
rm ./*.o

# ##LangReaderModule:
## Ejecuto el binario:
cd build/
./LangReaderModuleUnitTest.bin