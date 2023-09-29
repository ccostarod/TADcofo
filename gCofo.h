/*
Aluno: Rodrigo Otávio Cantanhede Costa
cofo.h: Arquivo de especificação denominado "gCofo.h".
Estrutura de Dados I - Professor Anselmo.
*/

#ifndef _GCOFO_H_
#define _GCOFO_H_

typedef struct {
    char nome[30];
    int nivel;
    float poder;
    int id;
} Pokemon;

typedef struct _gCofo_{
    int numItens;
    int maxItens;
    int cur;
    void **item;
}gCofo;

gCofo *gcofCreate(int maxItens);
int gcofInsert(gCofo *gc, void *item);
void *gcofRemove(gCofo *gc, void *key, int (*cmp)(void *A, void *B));
void *gcofQuery(gCofo *gc, void *key, int (*cmp)(void *A, void *B));
void *gcofGetFirst(gCofo *gc);
void *gcofGetNext(gCofo *gc);
int gcofDestroy(gCofo*);
int drainOutCof(gCofo *gc);

#endif