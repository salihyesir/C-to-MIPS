/* A Bison parser, made by GNU Bison 3.3.1.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2019 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

#ifndef YY_YY_PARSER_TAB_H_INCLUDED
# define YY_YY_PARSER_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    TOPLA = 258,
    CIKAR = 259,
    CARP = 260,
    BOL = 261,
    MOD = 262,
    ESIT = 263,
    ARTTIR = 264,
    AZALT = 265,
    ESIT_MI = 266,
    ESITDEGIL_MI = 267,
    GT = 268,
    LT = 269,
    GTE = 270,
    LTE = 271,
    VEYA = 272,
    VE = 273,
    DEGIL = 274,
    B_OR = 275,
    B_AND = 276,
    B_XOR = 277,
    SOLPARANTEZ = 278,
    SAGPARANTEZ = 279,
    KOSELISOLPAR = 280,
    KOSELISAGPAR = 281,
    SOLSUSLUPAR = 282,
    SAGSUSLUPAR = 283,
    VIRGUL = 284,
    NOKTALIVIRGUL = 285,
    NOKTA = 286,
    IKINOKTA = 287,
    ELSE = 288,
    ERROR = 289,
    STRING_CONSTANT = 290,
    TIRNAK = 291,
    SAYI = 292,
    ID = 293,
    KARAKTER = 294,
    DATATYPE = 295,
    MAIN = 296,
    FOR = 297,
    WHILE = 298,
    IF = 299,
    EIF = 300,
    COUT = 301
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 55 "../bisonFiles/parser.y" /* yacc.c:1921  */

	struct Node
	{
		int reg;
		int type;
	}node;
	int type_val;
	char str[500];//sayı id char,,

#line 115 "parser.tab.h" /* yacc.c:1921  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */
