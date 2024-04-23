#!/bin/bash
g++ -Wall -std=c++14 -fPIC -I./include/ -c ./src/LanguageManagerModuleTest.cpp
g++ -shared -Wall -std=c++14 -fPIC -I./include/ LanguageManagerModuleTest.o -o ./build/lib/LanguageManagerModuleTest.so