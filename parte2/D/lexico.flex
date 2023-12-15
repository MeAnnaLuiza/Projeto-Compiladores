

%option noyywrap
%option yylineno

%{
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include "simbolo.h"
    #include "sintatico.tab.h"
    extern FILE *yyin;
    extern FILE *yyout;

    int lineno = 1;

    void yyerror();
%}

numero [0-9]+
numeroReal {numero}+"."{numero}+
letra [a-zA-Z]
espacos " "*
virgula ","
especial [\t\n\r]*
ignorar {especial}|{comentario}*|{espacos}
comentario "{"(.*|{especial})"}"
mensagem "'"[^"'"\n]*"'"
programa "PROGRAMA"
fimProg "FIMPROG"
inteiro "INTEIRO"
real "REAL"
listaInt "LISTAINT"
listaReal "LISTAREAL"
leia "LEIA"
escreva "ESCREVA"
se "SE"
entao "ENTAO"
senao "SENAO"
fimSe "FIMSE"
enquanto "ENQUANTO"
faca "FACA"
fimEnq "FIMENQ"
op "+"|"-"|"*"|"/"|"%"
opLogico ".OU."|".E."
opLogicoNeg ".NAO."
opRelacional ".MAQ."|".MAI."|".MEQ."|".MEI."|".IGU."|".DIF."
var {variavel}
variavel {letra}({letra}|{numero}){0,7}
varLista {variavelVetor}
variavelVetor {variavel}"["({letra}+|{numero}+)"]"
/*areaDeclaracao "{"{espacos}"DECLARACOES"{espacos}"}"
areaAlgoritmo "{ALGORITMO}"*/
atribuicao ":="
abreParenteses "("
fechaParenteses ")"
erro {numero}{letra}({letra}|{numero}){0,7}|({letra}|{numero}){9,}

%%

{programa}          { return programa; }
{fimProg}           { return fimProg; }
{numero}            { return numero; }
{numeroReal}        { return numeroReal; }
{inteiro}           { return inteiro; }
{real}              { return real; }
{listaInt}          { return listaInt; }
{listaReal}         { return listaReal; }
{atribuicao}        { return atribuicao; }
{se}                { return se; }
{entao}             { return entao; }
{senao}             { return senao; }
{fimSe}             { return fimse; }
{leia}              { return leia; }
{escreva}           { return escreva; }
{enquanto}          { return enquanto; }
{faca}              { return faca; }
{fimEnq}            { return fimEnq; }
{variavel}          {
                    insert(yytext, strlen(yytext), indefinido, lineno);
                    return variavel;
                    }
{variavelVetor}     {
                    insert(yytext, strlen(yytext), indefinido, lineno);
                    return variavelVetor;
                    }
{op}                { return op; }
{opLogico}          { return opLogico; }
{opRelacional}      { return opRelacional; }
{mensagem}          { return mensagem; }
{virgula}     		{ return virgula; }
{abreParenteses}    { return abreParenteses; }
{fechaParenteses}   { return fechaParenteses; }
{opLogicoNeg}       { return opLogicoNeg; }
"\n"                { lineno += 1; }
{ignorar}
%%