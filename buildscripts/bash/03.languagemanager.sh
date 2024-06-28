#!/bin/bash
g++ -Wall -std=c++14 -fPIC -I./include/ -c ./src/LanguageManagerModule.cpp
g++ -shared -Wall -std=c++14 -fPIC -I./include/ LanguageManagerModule.o -o ./build/lib/LanguageManagerModule.so


## Limpio los códigos objeto
rm ./LanguageManagerModule.o
