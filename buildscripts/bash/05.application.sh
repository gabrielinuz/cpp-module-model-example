#!/bin/bash

# ## Compilo el Binario
g++ -Wall -std=c++14 -ldl -I./include -I./include/vendors/cppset/ main.cpp -o ./build/app.bin 

# ## Permisos de Ejecución para el binario
chmod +x ./build/app.bin
