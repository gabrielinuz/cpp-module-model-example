#!/bin/bash

##Preparo proyecto:
./buildscripts/00.prepare.sh

# ##Compilo las librerías:
./buildscripts/01.errorlogger.sh
./buildscripts/02.langreader.sh
# exec ./buildscripts/03.languagemanager.sh ;
# exec ./buildscripts/04.languagemanagertest.sh ;

# ## Compilo el Binario
# g++ -Wall -std=c++14 -ldl -I./include -I./include/vendors/cppset/ main.cpp -o ./build/app.bin 

# ## Borro código objeto
# rm ./*.o

# ## Permisos de Ejecución para el binario
# chmod +x ./build/app.bin

# ## Ejecuto el binario:
# cd build/
# ./app.bin