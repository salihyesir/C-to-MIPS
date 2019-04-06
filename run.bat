cd bison_flex
win_bison.exe -d -v ../bisonFiles/parser.y
win_flex.exe ../bisonFiles/lexer.l
move .\parser.tab.c ..\src\
move .\lex.yy.c ..\src\
move .\parser.tab.h ..\include\
move .\parser.output ..\lib\
cd ..\src
 
g++ parser.tab.c lex.yy.c -o compiler.exe
move .\compiler.exe ..\bin\

cd ..\bin

compiler.exe  < ..\test\input
cd ..