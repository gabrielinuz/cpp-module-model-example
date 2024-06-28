#!/bin/bash
g++ -Wall -std=c++14 -fPIC -I./include/ -c ./src/ErrorLoggerModule.cpp
g++ -shared -Wall -std=c++14 -fPIC -I./include/ ErrorLoggerModule.o -o ./build/lib/ErrorLoggerModule.so

## Limpio los códigos objeto
rm ./ErrorLoggerModule.o
