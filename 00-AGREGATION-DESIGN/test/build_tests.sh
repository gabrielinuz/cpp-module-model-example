#!/bin/bash

##Preparo proyecto:
./buildscripts/bash/00.prepare.sh

# ##Compilo las bibliotecas:
./buildscripts/bash/01.errorlogger.sh
./buildscripts/bash/02.langreader.sh
./buildscripts/bash/03.languagemanager.sh


## Compilo y ejecuto el binario de maintest:
./buildscripts/bash/04.maintest.sh
