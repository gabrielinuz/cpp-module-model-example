#!/bin/bash
##Borro el directorio si ya existiera
if [ -d "./build" ];
	then rm -r ./build;
fi

##Preparo directorios y recursos
mkdir ./build
mkdir ./build/lib

cp -r ../resources/lang/ ./build/

## Compilo código objeto
##LanguageManagerModule:
g++ -Wall -std=c++14 -fPIC -I../include/ -c ../src/LangReader.cpp
g++ -Wall -std=c++14 -fPIC -I../include/ -c ../src/LanguageManagerModule.cpp
g++ -shared -Wall -std=c++14 -fPIC -I../include/ LangReader.o LanguageManagerModule.o -o ./build/lib/LanguageManagerModule.so


## Compilo el Binario
g++ -Wall -std=c++14 -ldl LanguageManagerModuleUnitTest.cpp -o ./build/LanguageManagerModuleUnitTest.bin \
-I../include -I../include/vendors/catch -I../include/vendors/cppset/


# ##LanguageManagerModule:
chmod +x ./build/LanguageManagerModuleUnitTest.bin

## Limpio los códigos objeto
rm ./*.o

# ##LanguageManagerModule:
## Ejecuto el binario:
cd build/
./LanguageManagerModuleUnitTest.bin