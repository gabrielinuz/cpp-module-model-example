#!/bin/bash
g++ -Wall -std=c++14 -fPIC -I./include/ -c ./src/LangReaderModule.cpp
g++ -shared -Wall -std=c++14 -fPIC -I./include/ LangReaderModule.o -o ./build/lib/LangReaderModule.so

## Limpio los códigos objeto
rm ./LangReaderModule.o
