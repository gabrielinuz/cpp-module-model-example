::Compilo las librerías
g++ -Wall -std=c++11 -I.\include\ -c .\src\LangReader.cpp
g++ -Wall -std=c++11 -I.\include\ -c .\src\LanguageManagerModule.cpp
g++ -shared -Wall -std=c++11 -I.\include\ LangReader.o LanguageManagerModule.o -o .\lib\LanguageManagerModule.dll

:: Compilo el Binario
g++ -Wall -std=c++11 -I.\include -I.\include\vendors\cppset\ main.cpp -o .\app.exe

::Borrar .o
DEL .\*.o

::Ejecuto el binario:
app.exe