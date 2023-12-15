

#include <bits/stdc++.h>
using namespace std;

void arithmeticOperator();
void assignment();
void comand();
void comandRead();
void comandWrite();
void declaration();
void description();
void _do();
void _else();
void endIf();
void endProgram();
void endWhile();
void expression();
void _if();
void ifStructure();
void lineExpression();
void lineLogicalExpression();
void logicalExpression();
void logicalOperator();
void message();
void nextToken();
void outMessage();
void program();
void programBody();
void programStructure();
void read();
void readOutVariable();
void readVariable();
void relationalExpression();
void relationalOperator();
void separatorVariable();
void separatorVariableList();
void syntaxAnalisys();
void _then();
void var();
void variable();
void varList();
void variableList();
void variableType();
void variableTypeList();
void _while();
void write();
void whileComand();
void writeMessage();

typedef struct{
    char type[255];
    char value[255];
} token;

FILE *arq;
token current;
int fail;

void syntaxAnalisys(){
    nextToken();
    programStructure();
    if(strcmp(current.type, "FIMPROG:") == 0 && (fail == 0))
        cout << "\nPrograma reconhecido." << endl;
    else
        cout << "\nPrograma nao reconhecido." << endl;
}

void nextToken(){
    fscanf(arq, "%s %[^\n]s\n", current.type, current.value);
    cout << "Token do tipo " << current.type << " Valor: " << current.value << endl;
}

void programStructure(){
    program();
    programBody();
    endProgram();
}

void program(){
    if(strcmp(current.type, "PROGRAMA:") == 0)
        nextToken();
    else{
        if(fail != 1){
            fail = 1;
            cout << "\nPalavra nao reconhecida." << endl;
        }
    }
}

void endProgram(){
    if(strcmp(current.type, "FIMPROG:") != 0){
        if(fail != 1){
            fail = 1;
            cout << "\nPalavra nao reconhecida." << endl;
        }
    }
}

void programBody(){
    declaration();
    description();
}

void declaration(){
    if((strcmp(current.value, "INTEIRO") == 0) || (strcmp(current.value, "REAL") == 0)){
        variableType();
        var();
        if((strcmp(current.value, "INTEIRO") == 0) || (strcmp(current.value, "REAL") == 0) || (strcmp(current.value, "LISTAINT") == 0) || (strcmp(current.value, "LISTAREAL") == 0))
            declaration();
    }else{
        if((strcmp(current.value, "LISTAINT") == 0) || (strcmp(current.value, "LISTAREAL") == 0)){
            variableTypeList();
            varList();
            if((strcmp(current.value, "INTEIRO") == 0) || (strcmp(current.value, "REAL") == 0) || (strcmp(current.value, "LISTAINT") == 0) || (strcmp(current.value, "LISTAREAL") == 0))
                declaration();
        }
    }
}

void variableType(){
    if((strcmp(current.value, "INTEIRO") == 0) || (strcmp(current.value, "REAL") == 0))
        nextToken();
    else{
        if(fail != 1){
            fail = 1;
            cout << "\nPalavra nao reconhecida." << endl;
        }
    }
}

void variableTypeList(){
    if((strcmp(current.value, "LISTAINT") == 0) || (strcmp(current.value, "LISTAREAL") == 0))
        nextToken();
    else{
        if(fail != 1){
            fail = 1;
            cout << "\nPalavra nao reconhecida." << endl;
        }
    }
}

void var(){
    variable();
    separatorVariable();
}

void variable(){
    if(strcmp(current.type, "VARIAVEL:") == 0)
        nextToken();
    else{
        if(fail != 1){
            fail = 1;
            cout << "\nPalavra nao reconhecida." << endl;
        }
    }
}

void separatorVariable(){
    if(strcmp(current.type, "SEPARADOR:") == 0){
        nextToken();
        variable();
        separatorVariable();
    }
}

void varList(){
    variableList();
    separatorVariableList();
}

void variableList(){
    if(strcmp(current.type, "VARIAVEL_LISTA:") == 0)
        nextToken();
    else{
        if(fail != 1){
            fail = 1;
            cout << "\nPalavra nao reconhecida." << endl;
        }
    }
}

void separatorVariableList(){
    if(strcmp(current.type, "SEPARADOR:") == 0){
        nextToken();
        variableList();
        separatorVariableList();
    }
}

void description(){
    if((strcmp(current.type, "VARIAVEL:") == 0) || (strcmp(current.type, "VARIAVEL_LISTA:") == 0) || (strcmp(current.type, "SE:") == 0) || (strcmp(current.type, "ENQUANTO:") == 0) || (strcmp(current.type, "LEIA:") == 0) || (strcmp(current.type, "ESCREVA:") == 0)){
        comand();
        description();
    }
}

void comand(){
    if((strcmp(current.type, "VARIAVEL:") == 0) || (strcmp(current.type, "VARIAVEL_LISTA:") == 0)){
        if(strcmp(current.type, "VARIAVEL:") == 0)
            variable();
        else{
            if(strcmp(current.type, "VARIAVEL_LISTA:") == 0)
                variableList();
        }
        assignment();
    }else{
        if(strcmp(current.type, "SE:") == 0)
            ifStructure();
        else{
            if(strcmp(current.type, "LEIA:") == 0)
                comandRead();
            else{
                if(strcmp(current.type, "ESCREVA:") == 0)
                    comandWrite();
                else{
                    if(strcmp(current.type, "ENQUANTO:") == 0)   
                        whileComand();
                }
            }
        }
    }
}

void assignment(){
    if(strcmp(current.type, "ATRIBUICAO:") == 0){
        nextToken();
        expression();
    }else{
        if(fail != 1){
            fail = 1;
            cout << "\nPalavra nao reconhecida." << endl;
        }
    }
}

void expression(){
    if(strcmp(current.type, "ABRE_PARENTESES:") == 0){
        nextToken();
        expression();
        if(strcmp(current.type, "FECHA_PARENTESES:") == 0){
            nextToken();
            lineExpression();
        }else{
            if(fail != 1){
                fail = 1;
                cout << "\nPalavra nao reconhecida." << endl;
            }
        }
    }else{
        if((strcmp(current.type, "NUMERO:") == 0) || (strcmp(current.type, "NUMERO_REAL:") == 0) || (strcmp(current.type, "VARIAVEL:") == 0) || (strcmp(current.type, "VARIAVEL_LISTA:") == 0)){
            nextToken();
            lineExpression();
        }else{
            if(fail != 1){
                fail = 1;
                cout << "\nPalavra nao reconhecida." << endl;
            }
        }
    }
}

void lineExpression(){
    if(strcmp(current.type, "OPERADOR_ARITMETICO:") == 0){
        arithmeticOperator();
        expression();
    }
}

void arithmeticOperator(){
    if(strcmp(current.type, "OPERADOR_ARITMETICO:") == 0)
        nextToken();
    else{
        if(fail != 1){
            fail = 1;
            cout << "\nPalavra nao reconhecida." << endl;
        }
    }
}

void comandWrite(){
    write();
    writeMessage();
}

void write(){

    if(strcmp(current.type, "ESCREVA:") == 0)
        nextToken();
    else{
        if(fail != 1){
            fail = 1;
            cout << "\nPalavra nao reconhecida." << endl;
        }
    }
}

void writeMessage(){
    if(strcmp(current.type, "VARIAVEL:") == 0){
        variable();
        outMessage();
    }else{
        if(strcmp(current.type, "VARIAVEL_LISTA:") == 0){
            variableList();
            outMessage();
        }else{
            if(strcmp(current.type, "MENSAGEM:") == 0){
                message();
                outMessage();
            }else{
                if(fail != 1){
                    fail = 1;
                    cout << "\nPalavra nao reconhecida." << endl;
                }
            }
        }
    }
}

void message(){
    if(strcmp(current.type, "MENSAGEM:") == 0)
        nextToken();
    else{
        if(fail != 1){
            fail = 1;
            cout << "\nPalavra nao reconhecida." << endl;
        }
    }
}

void outMessage(){
    if(strcmp(current.type, "SEPARADOR:") == 0){
        nextToken();
        if(strcmp(current.type, "VARIAVEL_LISTA:") == 0){
            variableList();
            outMessage();
        }else{
            if(strcmp(current.type, "MENSAGEM:") == 0){
                message();
                outMessage();
            }else{
                if(strcmp(current.type, "VARIAVEL:") == 0){
                    variable();
                    outMessage();
                }else{
                    if(fail != 1){
                        fail = 1;
                        cout << "\nPalavra nao reconhecida." << endl;
                    }
                }
            }
        }
    }
}

void comandRead(){
    read();
    readVariable();
}

void read(){

    if(strcmp(current.type, "LEIA:") == 0){
        nextToken();
    }else{
        if(fail != 1){
            fail = 1;
            cout << "\nPalavra nao reconhecida." << endl;
        }
    }
}

void readVariable(){
    if(strcmp(current.type, "VARIAVEL:") == 0){
        variable();
        readOutVariable();
    }else{
        if(strcmp(current.type, "VARIAVEL_LISTA:") == 0){
            variableList();
            readOutVariable();
        }else{
            if(fail != 1){
                fail = 1;
                cout << "\nPalavra nao reconhecida." << endl;
            }
        }
    }
}

void readOutVariable(){
    if(strcmp(current.type, "SEPARADOR:") == 0){
        nextToken();
        if(strcmp(current.type, "VARIAVEL:") == 0){
            variable();
            readOutVariable();
        }else{
            if(strcmp(current.type, "VARIAVEL_LISTA:") == 0){
                variableList();
                readOutVariable();
            }else{
                if(fail != 1){
                    fail = 1;
                    cout << "\nPalavra nao reconhecida." << endl;
                }
            }
        }
    }
}

void ifStructure(){
    _if();
    logicalExpression();
    _then();
    description();
    _else();
    endIf();
}

void _if(){
    if(strcmp(current.type, "SE:") == 0){
        nextToken();
    }else{
        if(fail != 1){
            fail = 1;
            cout << "\nPalavra nao reconhecida." << endl;
        }
    } 
}

void logicalExpression(){
    if(strcmp(current.type, "OPERADOR_LOGICO_NEG:") == 0){
        nextToken();
        logicalExpression();
    }else{
        relationalExpression();
        lineLogicalExpression();
    } 
}

void lineLogicalExpression(){
    if(strcmp(current.type, "OPERADOR_LOGICO:") == 0){                 
        logicalOperator();
        relationalExpression();
    } 
}

void logicalOperator(){
    if(strcmp(current.type, "OPERADOR_LOGICO:") == 0){
        nextToken();
    }else{
        if(fail != 1){
            fail = 1;
            cout << "\nPalavra nao reconhecida." << endl;
        }
    }
}

void relationalExpression(){
    expression();
    relationalOperator();
    expression();
}

void relationalOperator(){
    if(strcmp(current.type, "OPERADOR_RELACIONAL:") == 0){
        nextToken();
    }else{
        if(fail != 1){
            fail = 1;
            cout << "\nPalavra nao reconhecida." << endl;
        }
    }
}

void _then(){
    if(strcmp(current.type, "ENTAO:") == 0)
        nextToken();
    else{
        if(fail != 1){
            fail = 1;
            cout << "\nPalavra nao reconhecida." << endl;
        }
    }
}

void _else(){
    if(strcmp(current.type, "SENAO:") == 0){
        nextToken();
        description();
    }
}

void endIf(){
    if(strcmp(current.type, "FIMSE:") == 0)
        nextToken();
    else{
        if(fail != 1){
            fail = 1;
            cout << "\nPalavra nao reconhecida." << endl;
        }
    } 
}

void whileComand(){
    _while();
    logicalExpression();
    _do();
    description();
    endWhile();
}

void _while(){
    if(strcmp(current.type, "ENQUANTO:") == 0){
        nextToken();
    }else{
        if(fail != 1){
            fail = 1;
            cout << "\nPalavra nao reconhecida." << endl;
        }
    }
}

void _do(){
    if(strcmp(current.type, "FACA:") == 0)
        nextToken();
    else{
        if(fail != 1){
            fail = 1;
            cout << "\nPalavra nao reconhecida." << endl;
        }
    }
}

void endWhile(){
    if(strcmp(current.type, "FIMENQ:") == 0)
        nextToken();
    else{
        if(fail != 1){
            fail = 1;
            cout << "\nPalavra nao reconhecida." << endl;
        }
    }
}

int main(){
    strcpy(current.type, " ");
    strcpy(current.value, " ");
    fail = 0;
    arq = fopen ("tokens.txt", "r");
    if(!arq){
        cout << "\nArquivo inexistente." << endl;
        return -1;
   	}
    syntaxAnalisys();
    return 0;
}
