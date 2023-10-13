#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{    
    int codigo;
    char nome[500];
} Token;

Token atual;

FILE *arqTokens;

int erro = 0;

void prox_token(void);
void ASD(void);
void inicio(void);
void PROGRAMA(void);
void FIMPROG(void);
void corpo(void);
void declaracao(void);
void tipo(void);
void tipoVetor(void);
void var(void);
void varLinha(void);
void variavel(void);
void varLista(void);
void varListaLinha(void);
void variavelVetor(void);
void descricao(void);
void comandos(void);
void atribuicao(void);
void se(void);
void SE(void);
void ENTAO(void);
void SENAO(void);
void FIMSE(void);
void expressaoAritmetica(void);
void expressaoAritmeticaLinha(void);
void operadorAritmetico(void);
void expressaoRelacional(void);
void operadorRelacional(void);
void expressaoLogica(void);
void expressaoLogicaLinha(void);
void operadorLogico(void);
void leitura(void);
void escrita(void);
void saida(void);
void saidaLinha(void);
void ESCREVA(void);
void entrada(void);
void entradaLinha(void);
void LEIA(void);
void mensagem(void);
void laco(void);
void ENQUANTO(void);
void FACA(void);
void FIMENQ(void);


int main(void) {    
    atual.codigo = -1;
    strcpy(atual.nome, " ");    
    if(!(arqTokens = fopen ("TokenNumero.txt", "r"))){//Teste de verificação da existencia do arquivo
        printf ("Arquivos não existe\n");
        return 0;
   	}    
    ASD();
    return 0;
}

void prox_token(void) {    
    fscanf(arqTokens,"%d %[^\n]s\n", &atual.codigo, atual.nome);
    if(atual.codigo != 50) printf("Token lido: %d %s\n", atual.codigo, atual.nome);
}

void ASD(void){    
    prox_token();    
    inicio();    
    if((atual.codigo == 50)&&(erro == 0)) printf("\n\nSucesso! Código reconhecido!\n");
}

void inicio(void) {    
    PROGRAMA();
    corpo();
    FIMPROG();
}

void PROGRAMA(void){    
    if(atual.codigo == 0) prox_token();//Continua, existe a palavra PROGRAMA
    else{
        if(erro != 1) {
            erro = 1;
            printf("\n\nERRO! Palavra nao foi reconhecida\n");
        }
    }
}

void FIMPROG(void){
    if(atual.codigo == 1) prox_token();//Continua, existe a palavra FIMPROG
    else{
        if(erro != 1) {
            erro = 1;
            printf("\n\nERRO! Palavra nao foi reconhecida\n");
        }
    }
}

void corpo(void){    
    //DECLARACOES();
    declaracao();
    //ALGORITMO();
    descricao();
}

void declaracao(void){    
    if(atual.codigo == 6){
        tipo();
        var();
        if((atual.codigo == 6)||(atual.codigo == 7)) declaracao();
        else{
            //Se não for nem token 6, nem 7 não há declaracoes
            //Continua
        }
    }else{
        if(atual.codigo == 7){
            tipoVetor();
            varLista();
            if((atual.codigo == 6)||(atual.codigo == 7)) declaracao();
        }else{
            //Se não for nem token 6, nem 7 não há declaracoes
            //Continua
        }
    }
}

void tipo(void){    
    if(atual.codigo == 6) prox_token();
    else{
        if(erro != 1) {
            erro = 1;
            printf("\n\nERRO! Palavra nao foi reconhecida\n");
        }
    }
}

void tipoVetor(void){
    if(atual.codigo == 7) prox_token();
    else{
        if(erro != 1) {
            erro = 1;
            printf("\n\nERRO! Palavra nao foi reconhecida\n");
        }
    }
}

void var(void){    
    variavel();
    varLinha();
}

void varLinha(void){
    if(atual.codigo == 19){//Token de virgula
        prox_token();
        variavel();
        varLinha();
    }else{
        //Continua
    }
}

void variavel(void){    
    if(atual.codigo == 13) prox_token();
    else{
        if(erro != 1) {
            erro = 1;
            printf("\n\nERRO! Palavra nao foi reconhecida\n");
        }
    }
}

void varLista(void){    
    variavelVetor();
    varListaLinha();
}

void varListaLinha(){
    if(atual.codigo == 19){//Token de virgula
        prox_token();
        variavelVetor();
        varListaLinha();
    }else{
        //Continua
    }
}

void variavelVetor(void){    
    if(atual.codigo == 14) prox_token();
    else{
        if(erro != 1) {
            erro = 1;
            printf("\n\nERRO! Palavra nao foi reconhecida\n");
        }
    }
}

void descricao(void){    
    if(((atual.codigo == 9)&&(strncmp(atual.nome, "SE", strlen("SE")) == 0))
       ||(atual.codigo == 10)
       ||(atual.codigo == 11)
       ||((atual.codigo == 12)&&(strncmp(atual.nome, "ENQUANTO", strlen("ENQUANTO")) == 0))
       ||(atual.codigo == 13)
       ||(atual.codigo == 14)){
        //prox_token();
        comandos();
        descricao();
    }else{
        //Continua
    }
}

void comandos(void){    
    if(((atual.codigo == 13)||(atual.codigo == 14))){ //Se for algum tipo de variavel, é atribuição
        if(atual.codigo == 13) variavel();
        else if(atual.codigo == 14) variavelVetor();        
        atribuicao();        
    }else{
        if(atual.codigo == 9){
            se();
        }else{
            if(atual.codigo == 10){
                leitura();
            }else{
                if(atual.codigo == 11){
                    escrita();
                }else{
                    if(atual.codigo == 12){
                        laco();
                    }else{
                        //Continua, não é nenhum comando
                    }
                }
            }
        }
    }
    
}

void atribuicao(void){    
    if(atual.codigo == 8){
        prox_token();
        expressaoAritmetica();
    }else{
        if(erro != 1) {
            erro = 1;
            printf("\n\nERRO! Palavra nao foi reconhecida\n");
        }
    }
}

void se(void){    
    SE();
    expressaoLogica();
    ENTAO();
    descricao();
    SENAO();
    FIMSE();
}

void SE(void){
    if(atual.codigo == 9){
        prox_token();
    }else{
        if(erro != 1) {
            erro = 1;
            printf("\n\nERRO! Palavra nao foi reconhecida\n");
        }
    }
}

void ENTAO(void){
    if(atual.codigo == 91){
        prox_token();
    }else{
        if(erro != 1) {
            erro = 1;
            printf("\n\nERRO! Palavra nao foi reconhecida\n");
        }
    }
}

void SENAO(void){
    if(atual.codigo == 92){
        prox_token();
        descricao();
    }else{
        //Continua
        //Nao possui a clausula senao
    }
}

void FIMSE(void){
    if(atual.codigo == 93){
        prox_token();
    }else{
        if(erro != 1) {
            erro = 1;
            printf("\n\nERRO! Palavra nao foi reconhecida\n");
        }
    }
}

void expressaoAritmetica(void){
    if(atual.codigo == 20){//abre parenteses
        prox_token();
        expressaoAritmetica();
        
        if(atual.codigo == 21){//fecha parenteses
            prox_token();
            
            expressaoAritmeticaLinha();
            
        }else{ //se nao tiver o fecha parenteses )
            if(erro != 1) {
                erro = 1;
                printf("\n\nERRO! Palavra nao foi reconhecida\n");
            }    
        }
    }else{
        if((atual.codigo == 4)||(atual.codigo == 5)||(atual.codigo == 13)||(atual.codigo == 14)){ // se for um numero comum ou numero real ou variavel ou variavel vetor
            prox_token(); 
            expressaoAritmeticaLinha();
            
        }else{
            if(erro != 1) {
                erro = 1;
                printf("\n\nERRO! Palavra nao foi reconhecida\n");
            }
        }
    }
}

void expressaoAritmeticaLinha(void){
    if(atual.codigo == 15){
        operadorAritmetico();
        expressaoAritmetica();
    }else{
        //Continua
        //Acabou a Expressao Aritmetica
    }    
}

void operadorAritmetico(void){    
    if(atual.codigo == 15){
        prox_token();        
    }else{
        if(erro != 1) {
            erro = 1;
            printf("\n\nERRO! Palavra nao foi reconhecida\n");
        }
    }
}

void expressaoRelacional(void){    
    expressaoAritmetica();
    operadorRelacional();
    expressaoAritmetica();
}

void operadorRelacional(){    
    if(atual.codigo == 17){
        prox_token();        
    }else{
        if(erro != 1) {
            erro = 1;
            printf("\n\nERRO! Palavra nao foi reconhecida\n");
        }
    }
}

void expressaoLogica(void){
    if(atual.codigo == 22){
        prox_token();
        expressaoLogica();        
    }else{
        expressaoRelacional();
        expressaoLogicaLinha();
    }
}

void expressaoLogicaLinha(void){
    if(atual.codigo == 16){ //operador logico
            operadorLogico();
            expressaoRelacional();
    }else{
        //Se o proximo nao for um operador, acabou a expressao logica
        //Continuar
    }
}

void operadorLogico(void){    
    if(atual.codigo == 16){
        prox_token();        
    }else{
        if(erro != 1) {
            erro = 1;
            printf("\n\nERRO! Palavra nao foi reconhecida\n");
        }
    }
}

void escrita(void){
    ESCREVA();
    saida();
}

void saida(void){
    if(atual.codigo == 13){//Token de Variavel
        variavel();
        saidaLinha();
    }else{
        if(atual.codigo == 14){//Token de VariavelVetor
            variavelVetor();
            saidaLinha();
        }else{
            if(atual.codigo == 18){//Token Mensagem
                mensagem();
                saidaLinha();
            }else{
                if(erro != 1) {
                    erro = 1;
                    printf("\n\nERRO! Palavra nao foi reconhecida\n");
                }
            }
        }
    }
}

void saidaLinha(void){
    if(atual.codigo == 19){//Token de virgula
        prox_token();
        if(atual.codigo == 13){//Token de Variavel
            variavel();
            saidaLinha();
        }else{
            if(atual.codigo == 14){//Token de VariavelVetor
                variavelVetor();
                saidaLinha();
            }else{
                if(atual.codigo == 18){//Token Mensagem
                    mensagem();
                    saidaLinha();
                }else{
                    if(erro != 1) {
                        erro = 1;
                        printf("\n\nERRO! Palavra nao foi reconhecida\n");
                    }
                }
            }
        }
    }else{
        //Continua
    }
}

void ESCREVA(void){
    if(atual.codigo == 11){
        prox_token();        
    }else{
        if(erro != 1) {
            erro = 1;
            printf("\n\nERRO! Palavra nao foi reconhecida\n");
        }
    }
}

void mensagem(void){
    if(atual.codigo == 18){
        prox_token();        
    }else{
        if(erro != 1) {
            erro = 1;
            printf("\n\nERRO! Palavra nao foi reconhecida\n");
        }
    }
    
}

void leitura(void){
    LEIA();
    entrada();
}

void entrada(void){
    if(atual.codigo == 13){
        variavel();
        entradaLinha();
    }else{
        if(atual.codigo == 14){
            variavelVetor();
            entradaLinha();
        }else{
            if(erro != 1) {
                erro = 1;
                printf("\n\nERRO! Palavra nao foi reconhecida\n");
            }
        }
    }
}

void entradaLinha(void){
    if(atual.codigo == 19){ //Token de virgula
        prox_token();
        if(atual.codigo == 13){
            variavel();
            entradaLinha();
        }else{
            if(atual.codigo == 14){
                variavelVetor();
                entradaLinha();
            }else{
                if(erro != 1) {
                    erro = 1;
                    printf("\n\nERRO! Palavra nao foi reconhecida\n");
                }
            }
        }
    }else{
        //Continua
    }
}

void LEIA(void){
    if(atual.codigo == 10){
        prox_token();        
    }else{
        if(erro != 1) {
            erro = 1;
            printf("\n\nERRO! Palavra nao foi reconhecida\n");
        }
    }
}

void laco(void){    
    ENQUANTO();
    expressaoLogica();
    FACA();
    descricao();
    FIMENQ();    
}

void ENQUANTO(void){
    if(atual.codigo == 12){
        prox_token();
    }else{
        if(erro != 1) {
            erro = 1;
            printf("\n\nERRO! Palavra nao foi reconhecida\n");
        }
    }
}

void FACA(void){
    if(atual.codigo == 121){
        prox_token();            
    }else{
        if(erro != 1) {
            erro = 1;
            printf("\n\nERRO! Palavra nao foi reconhecida\n");
        }
    }
   
}

void FIMENQ(void){
    if(atual.codigo == 122){
        prox_token();            
    }else{
        if(erro != 1) {
            erro = 1;
            printf("\n\nERRO! Palavra nao foi reconhecida\n");
        }
    }
}