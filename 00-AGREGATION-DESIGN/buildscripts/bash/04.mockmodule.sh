#!/bin/bash
g++ -Wall -std=c++14 -fPIC -I./include/ -c ./src/MockModule.cpp
g++ -shared -Wall -std=c++14 -fPIC -I./include/ MockModule.o -o ./build/lib/MockModule.so

## Limpio los códigos objeto
rm ./MockModule.o