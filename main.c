/*
Aluno: Rodrigo Otávio Cantanhede Costa
main.c: Arquivo de programa denominado "main.c".
Estrutura de Dados I - Professor Anselmo.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "gCofo.h"

#define TRUE 1
#define FALSE 0

// Função de comparação para buscar um Pokémon pelo ID
int cmpPorId(void *a, void *b) {
    Pokemon *pokemonA = (Pokemon *)a;
    Pokemon *pokemonB = (Pokemon *)b;
    return (pokemonA->id == pokemonB->id);
}

int main() {
    gCofo *colecao = NULL;
    while (1) {
        int escolha;
        printf("\n:-----POKEMENU-----:\n");
        printf("1. Criar Colecao\n");
        printf("2. Inserir Pokemon\n");
        printf("3. Consultar Pokemon na colecao\n");
        printf("4. Listar Pokemons na colecao\n");
        printf("5. Remover Pokemon\n");
        printf("6. Esvaziar a colecao\n");
        printf("7. Sair\n"); 
        printf(":------------------:\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &escolha);
        
        switch (escolha) {
            case 1:
                {   
                    if(colecao == NULL){
                        int tamanho = 0;
                        printf("Digite o tamanho da sua colecao: ");
                        scanf("%d", &tamanho);
                        colecao = gcofCreate(tamanho);
                        if (colecao == NULL){
                            printf("Erro ao criar colecao\n");
                        }
                        else{
                            printf("Colecao Criada com sucesso!\n");
                        }
                    }
                    else {
                        printf("A coleção ja foi criada!");
                    }
                    break;
                }
            case 2:
                // Inserir Pokémon
                {
                    if (colecao != NULL){
                        Pokemon *novoPokemon = (Pokemon *)malloc(sizeof(Pokemon));
                        if (novoPokemon == NULL) {
                        printf("Erro ao alocar memoria para o Pokemon.\n");
                        break;
                        }

                        printf("Nome do Pokemon: ");
                        scanf("%s", novoPokemon->nome);
                        printf("Nivel do Pokemon: ");
                        scanf("%d", &novoPokemon->nivel);
                        printf("Poder do Pokemon: ");
                        scanf("%f", &novoPokemon->poder);
                        printf("Id do Pokemon: ");
                        scanf("%d", &novoPokemon->id);

                        if (gcofInsert(colecao, novoPokemon)) {
                            printf("Pokemon inserido com sucesso!\n");
                            break;
                        } 
                        else {
                            printf("Erro ao inserir o Pokemon.\n");
                            free(novoPokemon);
                            break;
                        }
                    }
                    else {
                        printf("Crie a colecao antes de inserir um pokemon\n");
                        break;
                    }
                    
                }
                break;

            case 3:
            {
                if (colecao != NULL){
                    int idBusca;
                    printf("ID do Pokemon a ser consultado: ");
                    scanf("%d", &idBusca);

                    Pokemon pokemonBusca;
                    pokemonBusca.id = idBusca;

                    Pokemon *pokemonEncontrado = (Pokemon *)gcofQuery(colecao, &pokemonBusca, cmpPorId);

                    if (pokemonEncontrado != NULL) {
                        printf("Nome: %s\nNivel: %d\nPoder: %.2f\n", pokemonEncontrado->nome, pokemonEncontrado->nivel, pokemonEncontrado->poder);
                    } 
                    else {
                        printf("Pokemon nao encontrado.\n");
                    }
                }
                else {
                    printf("Crie a colecao antes de consultar um pokemon\n");
                    break;
                }
            }
            break;

            case 4:
                // Listar Pokémon na coleção
                {
                    if (!(colecao == NULL) && colecao->numItens != 0){
                        printf("Pokemons na colecao:\n");
                    
                        void *pokemon = gcofGetFirst(colecao);
                        while (pokemon != NULL) {
                            printf("Nome: %s\nNivel: %d\nPoder: %.2f\n\n", ((Pokemon *)pokemon)->nome, ((Pokemon *)pokemon)->nivel, ((Pokemon *)pokemon)->poder);
                            pokemon = gcofGetNext(colecao);
                        }
                    }
                    else if (colecao == NULL) {
                        printf("Crie a colecao antes de listar ela\n");
                    }
                    else {
                        printf("Nao ha pokemons na colecao\n");
                    }
                }
                break;

            case 5:
            {
                if (colecao != NULL && colecao->numItens != 0){
                    int idRemover;
                    printf("ID do Pokemon a ser removido: ");
                    scanf("%d", &idRemover);

                    Pokemon pokemonRemover;
                    pokemonRemover.id = idRemover;

                    Pokemon *pokemonRemovido = (Pokemon *)gcofRemove(colecao, &pokemonRemover, cmpPorId);

                    if (pokemonRemovido != NULL) {
                        printf("Pokemon removido com sucesso!\n");
                        free(pokemonRemovido);
                    } 
                    else {
                        printf("Pokemon nao encontrado ou erro ao remover.\n");
                    }
                }
                else{
                    printf("Crie a colecao ou adicione algum pokemon na colecao antes de tentar remover\n");
                }
                
            }
            break;

            case 6:
            {
                // Esvaziar a coleção
                if(colecao != NULL){
                    if (drainOutCof(colecao)) {
                        printf("Colecao esvaziada com sucesso!\n");
                    } 
                    else {
                        printf("Erro ao esvaziar a colecao.\n");
                    }
                    break;
                }
                else{
                    printf("Crie a colecao antes de tentar esvaziar");
                }
                
            }
            break;   

            case 7:
            {
                // Sair do programa
                if (colecao != NULL){
                    if (gcofDestroy(colecao) == 0){
                        printf("Erro ao Destruir colecao, esvazie a colecao antes de sair!\n");
                        break;
                    }
                    else{
                    return 0;
                    } 
                }
            }
            break;

            default:
                printf("Opcao invalida. Tente novamente.\n");
        }
    }

    return 0;
}
