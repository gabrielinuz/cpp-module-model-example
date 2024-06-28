#!/bin/bash

##Borro el directorio si ya existiera
if [ -d "./build" ];
	then rm -r ./build;
fi

##Preparo directorios y recursos
mkdir ./build
mkdir ./build/lib

cp ./test/libtest/readme.txt ./build/lib
cp ./test/libtest/libtest.sh ./build/lib
cp -r ./resources/lang/ ./build/