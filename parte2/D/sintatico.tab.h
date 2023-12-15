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
     listaInt = 264,
     listaReal = 265,
     atribuicao = 266,
     se = 267,
     entao = 268,
     senao = 269,
     fimse = 270,
     leia = 271,
     escreva = 272,
     enquanto = 273,
     faca = 274,
     fimEnq = 275,
     variavel = 276,
     variavelVetor = 277,
     op = 278,
     opLogico = 279,
     opRelacional = 280,
     mensagem = 281,
     virgula = 282,
     abreParenteses = 283,
     fechaParenteses = 284,
     opLogicoNeg = 285
   };
#endif
/* Tokens.  */
#define programa 258
#define fimProg 259
#define numero 260
#define numeroReal 261
#define inteiro 262
#define real 263
#define listaInt 264
#define listaReal 265
#define atribuicao 266
#define se 267
#define entao 268
#define senao 269
#define fimse 270
#define leia 271
#define escreva 272
#define enquanto 273
#define faca 274
#define fimEnq 275
#define variavel 276
#define variavelVetor 277
#define op 278
#define opLogico 279
#define opRelacional 280
#define mensagem 281
#define virgula 282
#define abreParenteses 283
#define fechaParenteses 284
#define opLogicoNeg 285



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
