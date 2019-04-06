%option noyywrap
%{
	#include "../include/parser.tab.h"
	int f(char*);
	int lc=0;
%}

whitespace [ \t]
linefeed \n
%%

"+"	{return TOPLA;} 
"-" {return CIKAR;} 
"*" {return CARP;} 
"/"	{return BOL;}
"%" {return MOD;}

"="	{return ESIT;}

"++" {return ARTTIR;} 
"--" {return AZALT;}

"==" {return ESIT_MI;}
"!=" {return ESITDEGIL_MI;}

">" {return GT;}
"<" {return LT;}

">=" {return GTE;}
"<=" {return LTE;}


"||" {return VEYA;}
"&&" {return VE;}
"!" {return DEGIL;}
"|" {return B_OR;}
"&" {return B_AND;}
"^" {return B_XOR;}

"(" {return SOLPARANTEZ;}
")" {return SAGPARANTEZ;}

"[" {return KOSELISOLPAR;}
"]" {return KOSELISAGPAR;}

"{" {return SOLSUSLUPAR;}
"}" {return SAGSUSLUPAR;}

"," {return VIRGUL;}
";" {return NOKTALIVIRGUL;}
"." {return NOKTA; }
":" {return IKINOKTA;}




("int") {yylval.type_val=0;return DATATYPE;}
("char") {yylval.type_val=1;return DATATYPE;}

"void main" {return MAIN;}
"cout" {return COUT;}
"for" {yylval.type_val=lc++;return FOR;}
"while" {yylval.type_val=lc++;return WHILE;}
"if" {yylval.type_val=lc++;return IF;}
"eif" {yylval.type_val=lc++;return EIF;}
"else" {return ELSE;}


[ \t]+ { }

\"[^\"\n]*\" {return STRING_CONSTANT;}
\'[^\"\n]*\' {strcpy(yylval.str,yytext);return KARAKTER;} //[a-zA-Z] char 
[a-zA-Z][a-zA-Z0-9_]* {strcpy(yylval.str,yytext);return ID;}
[0-9]+ {strcpy(yylval.str,yytext);return SAYI;}


{linefeed}  {++yylineno;}
.	{return ERROR;}

%%

