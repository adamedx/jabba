del c:\data\source\semantic\parser.tab.h
del c:\data\source\semantic\parser.tab.c
rem C:\data\source\yacc\BISON-A2.6\bison.exe -t -l -d -v -oc:\data\source\semantic\parser.c c:\data\source\semantic\parser.y
C:\data\source\yacc\BISON-A2.6\bison.exe -d -l -v -t c:\data\source\semantic\parser.y
rem rename c:\data\source\semantic\parser.tab.h parser.h 
c:\data\source\flex\flex.exe -L -oc:\data\source\semantic\lexout.c < c:\data\source\semantic\lexer.l


