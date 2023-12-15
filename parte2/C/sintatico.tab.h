/* A Bison parser, made by GNU Bison 2.7.  */

/* Bison interface for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2012 Free Software Foundation, Inc.
   
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

#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     programa = 258,
     fimProg = 259,
     numero = 260,
     numeroReal = 261,
     inteiro = 262,
     real = 263,
     mensagem = 264,
     virgula = 265,
     abreParenteses = 266,
     fechaParenteses = 267,
     opLogicoNeg = 268,
     listaInt = 269,
     listaReal = 270,
     atribuicao = 271,
     se = 272,
     entao = 273,
     senao = 274,
     fimse = 275,
     leia = 276,
     escreva = 277,
     enquanto = 278,
     faca = 279,
     fimEnq = 280,
     variavel = 281,
     variavelVetor = 282,
     op = 283,
     opLogico = 284,
     opRelacional = 285
   };
#endif
/* Tokens.  */
#define programa 258
#define fimProg 259
#define numero 260
#define numeroReal 261
#define inteiro 262
#define real 263
#define mensagem 264
#define virgula 265
#define abreParenteses 266
#define fechaParenteses 267
#define opLogicoNeg 268
#define listaInt 269
#define listaReal 270
#define atribuicao 271
#define se 272
#define entao 273
#define senao 274
#define fimse 275
#define leia 276
#define escreva 277
#define enquanto 278
#define faca 279
#define fimEnq 280
#define variavel 281
#define variavelVetor 282
#define op 283
#define opLogico 284
#define opRelacional 285



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
