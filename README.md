
# Projeto Compiladores

Este repositório tem o objetivo de apresentar uma possível solução para os problemas apresentados no enunciado do projeto da disciplina CIC220 - Compiladores, na Universidade Federal de Itajubá.


## Executando o analisador léxico

Primeiro deve-se compilar o analisador léxico com comando `flex` e após isso, compilar o arquivo `lex.yy.c` gerado com o `GCC` e executá-lo com a entrada. Os comandos utilizados são listados abaixo:

```bash
  flex AnalisadorLexico.lex

  gcc lex.yy.c -o analisa_lexico

  ./analisa_lexico < exemplo1.txt
```

Após isso, será gerado um aquivo chamado `TokenDescricao.txt`, que será utilizado como arquivo de entrada do analisador sintático.

## Executando o analisador sintático

Primeiro deve-se compilar o analisador sintático com o `GCC`, depois passar o arquivo de saída do analisador léxico como entrada. Os comandos utilizados são listados abaixo:

```bash
  gcc AnalisadorSintatico.c -o ana_sintatico

  ./ana_sintatico < TokenDescricao.txt
```

Após isso, será retornado se o código foi reconhecido ou não.