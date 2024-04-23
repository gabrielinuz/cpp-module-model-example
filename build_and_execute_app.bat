::##Preparo directorios y recursos
MD .\build\
MD .\build\lib\
COPY .\test\libtest\readme.txt .\build\lib
COPY .\test\libtest\libtest.sh .\build\lib
XCOPY /e /k /h /i .\resources\lang\ .\build\lang\

::Compilo las librerías
g++ -Wall -std=c++14 -I.\include\ -c .\src\LangReader.cpp
g++ -Wall -std=c++14 -I.\include\ -c .\src\LanguageManagerModule.cpp
g++ -Wall -std=c++14 -I.\include\ -c .\src\LanguageManagerModuleTest.cpp
g++ -shared -Wall -std=c++14 -I.\include\ LangReader.o LanguageManagerModule.o -o .\build\lib\LanguageManagerModule.dll
g++ -shared -Wall -std=c++14 -I.\include\ LangReader.o LanguageManagerModuleTest.o -o .\build\lib\LanguageManagerModuleTest.dll
:: Compilo el Binario
g++ -Wall -std=c++14 -I.\include -I.\include\vendors\cppset\ main.cpp -o .\build\app.exe

::Borrar .o
DEL .\*.o

::Ejecuto el binario:
CD build
app.exe