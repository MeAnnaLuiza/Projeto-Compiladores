
%{
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    FILE *arq;
%}

abreParenteses "("
atribuicao ":="
comentario "{"(.*|{especial})"}"
enquanto "ENQUANTO"
entao "ENTAO"
erro {numero}{letra}({letra}|{numero}){0,7}|({letra}|{numero}){9,}
escreva "ESCREVA"
espacos " "*
especial [\t\n\r]*
faca "FACA"
fechaParenteses ")"
fimEnq "FIMENQ"
fimProg "FIMPROG"
fimSe "FIMSE"
ignorar {especial}|{comentario}*|{espacos}
inteiro "INTEIRO"
leia "LEIA"
letra [a-zA-Z]
listaInt "LISTAINT"
listaReal "LISTAREAL"
mensagem "'"[^"'"\n]*"'"
numero [0-9]+
numeroReal {numero}+","{numero}+
op "+"|"-"|"*"|"/"|"%"
opLogico ".OU."|".E."
opLogicoNeg ".NAO."
opRelacional ".MAQ."|".MAI."|".MEQ."|".MEI."|".IGU."|".DIF."
programa "PROGRAMA"
real "REAL"
se "SE"
senao "SENAO"
var {variavel}
variavel {letra}({letra}|{numero}){0,7}
variavelVetor {variavel}"["({letra}+|{numero}+)"]"
varLista {variavelVetor}
virgula ","

%%

{abreParenteses}    {fprintf(arq, "ABRE_PARENTESES: %s\n", yytext);}
{atribuicao}        {fprintf(arq, "ATRIBUICAO: %s\n", yytext);}
{enquanto}          {fprintf(arq, "ENQUANTO: %s\n", yytext);}
{entao}             {fprintf(arq, "ENTAO: %s\n", yytext);}
{escreva}           {fprintf(arq, "ESCREVA: %s\n", yytext);}
{erro}              {fprintf(arq, "ERRO: %s\n", yytext);}
{faca}              {fprintf(arq, "FACA: %s\n", yytext);}
{fechaParenteses}   {fprintf(arq, "FECHA_PARENTESES: %s\n", yytext);}
{fimEnq}            {fprintf(arq, "FIMENQ: %s\n", yytext);}
{fimProg}           {fprintf(arq, "FIMPROG: %s\n", yytext);}
{fimSe}             {fprintf(arq, "FIMSE: %s\n", yytext);}
{ignorar}           {}
{inteiro}           {fprintf(arq, "TIPO: %s\n", yytext);}
{leia}              {fprintf(arq, "LEIA: %s\n", yytext);}
{listaInt}          {fprintf(arq, "TIPO: %s\n", yytext);}
{listaReal}         {fprintf(arq, "TIPO: %s\n", yytext);}
{mensagem}          {fprintf(arq, "MENSAGEM: %s\n", yytext);}
{numero}            {fprintf(arq, "NUMERO: %s\n", yytext);}
{numeroReal}        {fprintf(arq, "NUMERO_REAL: %s\n", yytext);}
{op}                {fprintf(arq, "OPERADOR_ARITMETICO: %s\n", yytext);}
{opLogico}          {fprintf(arq, "OPERADOR_LOGICO: %s\n", yytext);}
{opLogicoNeg}       {fprintf(arq, "OPERADOR_LOGICO_NEG: %s\n", yytext);}
{opRelacional}      {fprintf(arq, "OPERADOR_RELACIONAL: %s\n", yytext);}
{programa}          {fprintf(arq, "PROGRAMA: %s\n", yytext);}
{real}              {fprintf(arq, "TIPO: %s\n", yytext);}
{se}                {fprintf(arq, "SE: %s\n", yytext);}
{senao}             {fprintf(arq, "SENAO: %s\n", yytext);}
{var}               {fprintf(arq, "VARIAVEL: %s\n", yytext);}
{varLista}          {fprintf(arq, "VARIAVEL_LISTA: %s\n", yytext);}
{virgula}	     {fprintf(arq, "SEPARADOR: %s\n", yytext);}

%%

int yywrap();

int main(){
    if(!(arq = fopen ("tokens.txt", "w"))){
        printf ("Arquivo inexistente.\n");
        return 0;
   	}
    yylex();
    fclose(arq);
	return 0;
}

int yywrap () { return 1;}
