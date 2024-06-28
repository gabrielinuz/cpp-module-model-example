#!/bin/bash
##Borro el directorio si ya existiera
if [ -d "./build" ];
	then rm -r ./build;
fi

##Preparo directorios y recursos
mkdir ./build
mkdir ./build/lib

cp -r ../resources/lang/ ./build/