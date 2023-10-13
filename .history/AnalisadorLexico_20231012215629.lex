%{
    #include <stdio.h>
	#include <stdlib.h>
    #include <string.h>
    FILE *tokens;
    FILE *tokensNumero;
%}

numero [0-9]+
numeroReal {numero}+","{numero}+
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
caracter "CARACTER"
cadeia "CADEIA"
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

{programa}          { fprintf(tokens, "Token_inicio_programa: %s\n", yytext);       fprintf(tokensNumero, "%d %s\n", 0, yytext);}
{fimProg}           { fprintf(tokens, "Token_fim_programa: %s\n", yytext); 	    	fprintf(tokensNumero, "%d %s\n", 1, yytext);}
{numero}            { fprintf(tokens, "Token_numero: %s\n", yytext); 			    fprintf(tokensNumero, "%d %s\n", 4, yytext);}
{numeroReal}        { fprintf(tokens, "Token_numero_real: %s\n", yytext); 		    fprintf(tokensNumero, "%d %s\n", 5, yytext);}
{inteiro}           { fprintf(tokens, "Token_tipo: %s\n", yytext); 		       		fprintf(tokensNumero, "%d %s\n", 6, yytext);}
{real}              { fprintf(tokens, "Token_tipo: %s\n", yytext); 				    fprintf(tokensNumero, "%d %s\n", 6, yytext);}
{caracter}          { fprintf(tokens, "Token_tipo: %s\n", yytext); 				    fprintf(tokensNumero, "%d %s\n", 6, yytext);}
{cadeia}            { fprintf(tokens, "Token_tipo: %s\n", yytext); 				    fprintf(tokensNumero, "%d %s\n", 7, yytext);}
{listaInt}          { fprintf(tokens, "Token_tipo: %s\n", yytext); 				    fprintf(tokensNumero, "%d %s\n", 7, yytext);}
{listaReal}         { fprintf(tokens, "Token_tipo: %s\n", yytext); 				    fprintf(tokensNumero, "%d %s\n", 7, yytext);}
{atribuicao}        { fprintf(tokens, "Token_atribuicao: %s\n", yytext); 		    fprintf(tokensNumero, "%d %s\n", 8, yytext);}
{se}                { fprintf(tokens, "Token_condicional: %s\n", yytext); 		    fprintf(tokensNumero, "%d %s\n", 9, yytext);}
{entao}             { fprintf(tokens, "Token_condicional: %s\n", yytext); 		    fprintf(tokensNumero, "%d %s\n", 91, yytext);}
{senao}             { fprintf(tokens, "Token_condicional: %s\n", yytext); 		    fprintf(tokensNumero, "%d %s\n", 92, yytext);}
{fimSe}             { fprintf(tokens, "Token_condicional: %s\n", yytext); 		    fprintf(tokensNumero, "%d %s\n", 93, yytext);}
{leia}              { fprintf(tokens, "Token_leitura: %s\n", yytext); 			    fprintf(tokensNumero, "%d %s\n", 10, yytext);}
{escreva}           { fprintf(tokens, "Token_escrita: %s\n", yytext); 		    	fprintf(tokensNumero, "%d %s\n", 11, yytext);}
{enquanto}          { fprintf(tokens, "Token_laco: %s\n", yytext); 				    fprintf(tokensNumero, "%d %s\n", 12, yytext);}
{faca}              { fprintf(tokens, "Token_laco: %s\n", yytext); 				    fprintf(tokensNumero, "%d %s\n", 121, yytext);}
{fimEnq}            { fprintf(tokens, "Token_laco: %s\n", yytext); 				    fprintf(tokensNumero, "%d %s\n", 122, yytext);}
{var}               { fprintf(tokens, "Token_variavel: %s\n", yytext); 			    fprintf(tokensNumero, "%d %s\n", 13, yytext);}
{varLista}          { fprintf(tokens, "Token_variavel_lista: %s\n", yytext); 	    fprintf(tokensNumero, "%d %s\n", 14, yytext);}
{op}                { fprintf(tokens, "Token_operador_aritmetico: %s\n", yytext);   fprintf(tokensNumero, "%d %s\n", 15, yytext);}
{opLogico}          { fprintf(tokens, "Token_operador_logico: %s\n", yytext); 	    fprintf(tokensNumero, "%d %s\n", 16, yytext);}
{opRelacional}      { fprintf(tokens, "Token_operador_relacional: %s\n", yytext);   fprintf(tokensNumero, "%d %s\n", 17, yytext);}
{mensagem}          { fprintf(tokens, "Token_mensagem: %s\n", yytext); 			    fprintf(tokensNumero, "%d %s\n", 18, yytext);}
{virgula}			{ fprintf(tokens, "Token_virgula: %s\n", yytext); 			    fprintf(tokensNumero, "%d %s\n", 19, yytext);}
{abreParenteses}    { fprintf(tokens, "Token_abreParenteses: %s\n", yytext);        fprintf(tokensNumero, "%d %s\n", 20, yytext);}
{fechaParenteses}   { fprintf(tokens, "Token_fechaParenteses: %s\n", yytext);       fprintf(tokensNumero, "%d %s\n", 21, yytext);}
{opLogicoNeg}       { fprintf(tokens, "Token_operador_logico_Neg: %s\n", yytext);   fprintf(tokensNumero, "%d %s\n", 22, yytext);}
{ignorar}           {}
{erro}              { fprintf(tokens, "Erro lexico: %s\n", yytext); fprintf(tokensNumero, "%d %s\n", 30, yytext);}

%%

int yywrap();

int main(){
	
	
    if(!(tokens = fopen ("TokenDescricao.txt", "w"))){//Teste de verificação da existencia do arquivo
        printf ("Arquivos não existe\n");
        return 0;
   	}

	if(!(tokensNumero = fopen ("TokenNumero.txt", "w"))){//Teste de verificação da existencia do arquivo
        printf ("Arquivos não existe\n");
        return 0;
   	}
    
    yylex();

    fprintf(tokensNumero, "%d %s\n", 50, "$");

    fclose(tokens);
   	fclose(tokensNumero);

	return 0; 
}

int yywrap () { return 1;}
