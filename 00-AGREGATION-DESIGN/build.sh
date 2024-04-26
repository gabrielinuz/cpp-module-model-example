#!/bin/bash

##Preparo proyecto:
./buildscripts/bash/00.prepare.sh

# ##Compilo las librerías:
./buildscripts/bash/01.errorlogger.sh
./buildscripts/bash/02.langreader.sh
./buildscripts/bash/03.languagemanager.sh
./buildscripts/bash/04.mockmodule.sh

# ## Compilo el Binario
./buildscripts/bash/05.application.sh

# ## Ejecuto el binario:
./buildscripts/bash/06.execute.sh