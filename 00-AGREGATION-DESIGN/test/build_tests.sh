#!/bin/bash

##Preparo proyecto:
./buildscripts/bash/00.prepare.sh

# ##Compilo las librerías:
./buildscripts/bash/01.errorlogger.sh
./buildscripts/bash/02.langreader.sh
./buildscripts/bash/03.languagemanager.sh


## Compilo y ejecuto el binario de LangReaderTest
./buildscripts/bash/04.errorloggertest.sh
./buildscripts/bash/05.langreadertest.sh
./buildscripts/bash/06.languagemanagertest.sh
