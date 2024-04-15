:: Compilo código objeto
::LanguageManagerModule:
g++ -Wall -std=c++11 -I..\include\ -c ..\src\LangReader.cpp
g++ -Wall -std=c++11 -I..\include\ -c ..\src\LanguageManagerModule.cpp
g++ -shared -Wall -std=c++11 -I..\include\ LangReader.o LanguageManagerModule.o -o ..\lib\LanguageManagerModule.dll


:: Compilo el Binario
g++ -Wall -std=c++11 LanguageManagerModuleUnitTest.cpp -o LanguageManagerModuleUnitTest.exe -I..\include -I..\include\vendors\catch -I..\include\vendors\cppset\


:: Limpio los códigos objeto
DEL .\*.o

::LanguageManagerModule:
.\LanguageManagerModuleUnitTest.exe