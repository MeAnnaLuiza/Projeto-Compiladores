%{
    #include <stdio.h>
    #include <stdlib.h>

    int yyparse();
    int yylex();
    FILE *yyin;

    int yywrap() { return 1; }

    void yyerror (const char *s);

    int main(int argc, char *argv[]);

%}

%token programa fimProg numero numeroReal inteiro real
%token mensagem virgula abreParenteses fechaParenteses opLogicoNeg
%token listaInt listaReal atribuicao se entao senao fimse leia escreva
%token enquanto faca fimEnq variavel variavelVetor op opLogico opRelacional

%%

Ini     : S {printf("Gramatica reconhecida!\n");}

S       : programa corpo fimProg;

corpo   : declaracao descricao;

declaracao      : tipo var declaracao
		| tipoLista variavelLista declaracao
		| /* empty */;

tipo    : inteiro
        | real;

tipoLista       : listaInt
                | listaReal;

var        : variavel var2;

var2    : virgula variavel var2
        | /* empty */;

variavelLista   : variavelVetor variavelLista2;

variavelLista2  : virgula variavelVetor variavelLista2
                |  /* empty */;

descricao       : comandos descricao
                | /* empty */;

comandos        : SE
		| LEITURA
		| ESCRITA
		| LACO
		| variavel ATRIBUICAO
                | variavelVetor ATRIBUICAO;

ATRIBUICAO      : atribuicao expressaoAritmetica;

SE      : se expressaoLogica entao descricao SENAO fimse;

SENAO   : senao descricao
        | /* empty */;

ESCRITA         : escreva saida;

saida           : variavel saida2
                | variavelVetor saida2
                | mensagem saida2;

saida2          : virgula variavel saida2
                | virgula variavelVetor saida2
                | virgula mensagem saida2
                | /* empty */;

LEITURA : leia LEITURA;

LEITURA : variavel
        | variavel virgula LEITURA
	| variavelVetor
        | variavelVetor virgula LEITURA;

LACO : enquanto expressaoLogica faca descricao fimEnq;

expressaoAritmetica     : abreParenteses expressaoAritmetica fechaParenteses expressaoAritmetica2
                        | variavel expressaoAritmetica2
                        | variavelVetor expressaoAritmetica2
                        | numero expressaoAritmetica2
                        | numeroReal expressaoAritmetica2;

expressaoAritmetica2    : op expressaoAritmetica
                        | /* empty */;

expressaoRelacional     : expressaoAritmetica opRelacional expressaoAritmetica;

expressaoLogica         : opLogicoNeg expressaoLogica
                        | expressaoRelacional expressaoLogica2;

expressaoLogica2        : opLogico expressaoLogica
                        | /* empty */;

%%

void yyerror (const char *s) {
        extern int yylineno;
  	printf("Erro %s na linha %d\n", s, yylineno+1);
}

int main(int argc, char *argv[]) {

        if(argc != 2){
	        printf("Erro ao executar o arquivo!\n");
		exit(1);
	}

        yyin = fopen(argv[1], "r");
        yyparse();

        return 0;
}