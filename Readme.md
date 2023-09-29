# README - Trabalho com gCofo e Pokémon - VSCODE

## Descrição
Este trabalho implementa um contêiner genérico chamado `gCofo` e o utiliza para gerenciar uma coleção de Pokémon. Cada Pokémon é representado por uma estrutura de dados com nome, nível, poder e ID.

## Arquivos

- `gCofo.h`: Arquivo de cabeçalho que define a estrutura `gCofo` e as funções para gerenciar o contêiner.
- `gCofo.c`: Implementação das funções definidas em `gCofo.h` para manipular o contêiner.
- `main.c`: Programa principal que utiliza o `gCofo` para criar, inserir, consultar, listar, remover e esvaziar a coleção de Pokémon.

## Compilação

Para compilar o programa, você pode usar o compilador GCC da seguinte maneira:

```shell
gcc main.c gCofo.c -o main
```
## Execução

Para executar o programa use:
```shell
./main
```