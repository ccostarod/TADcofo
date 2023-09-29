/*
Aluno: Rodrigo Otávio Cantanhede Costa
cofo.h: Arquivo de implementação denominado "gCofo.c".
Estrutura de Dados I - Professor Anselmo.
*/

#include "gCofo.h"
#include <stdlib.h>
#define TRUE 1
#define FALSE 0

gCofo *gcofCreate(int maxItens){
    gCofo *gc;
    if (maxItens > 0){
        gc = (gCofo *)malloc(sizeof(gCofo));
        if (gc != NULL){
            gc->item = (void **)malloc(sizeof(void *) * maxItens);
            if (gc->item != NULL){
                gc->numItens = 0;
                gc->maxItens = maxItens;
                gc->cur = -1;
                return gc;
            }
            free(gc);
        }
    }
    return NULL;
}

int gcofDestroy(gCofo *gc){
    if (gc != NULL){
        if(gc->numItens == 0){ 
            free(gc->item);
            free(gc);
            return TRUE;
        }
    }
    return FALSE;
}

int drainOutCof(gCofo *gc){
    if(gc!=NULL){
        while(gc->numItens > 0){
            free(gc->item[gc->numItens-1]);   
            gc->numItens--;
        }
        return TRUE;
    }
    return FALSE;
}

int gcofInsert(gCofo *gc, void *item){
    if(gc != NULL){
        if(gc->numItens < gc->maxItens){
            gc->item[gc->numItens] = item;
            gc->numItens++;
            return TRUE;
        }
    }
    return FALSE;
}

void *gcofGetFirst(gCofo *gc){
    if (gc != NULL){
        void *elem;
        if (gc->numItens > 0){
            elem = gc->item[0];
            gc->cur = 0;
            return elem;
        }
    }
    return NULL;
}

void *gcofGetNext(gCofo *gc){
    if (gc != NULL){
        void *elem;
        if(gc->numItens > 0 && gc->cur < gc->numItens - 1){
            gc->cur++;
            elem = gc->item[gc->cur]; // Corrigido de 'gc->item[c->cur]'
            return elem;
        }
    }
    return NULL;
}

void *gcofQuery(gCofo *gc, void *key, int (*cmp)(void *A, void *B)) {
    if (gc != NULL) {
        int i;
        for (i = 0; i < gc->numItens; i++) {
            if (cmp(key, gc->item[i]) == TRUE) {
                return gc->item[i];
            }
        }
    }
    return NULL;
}

void *gcofRemove(gCofo *gc, void *key, int (*cmp)(void *, void *))
{
    int i, j;
    void *data;
    int stat;
    if (gc != NULL)
    {
        if (gc->numItens > 0)
        {
            i = 0;
            stat = cmp(key, gc->item[i]);
            for (i = 0; i < gc->numItens; i++)
            {
                stat = cmp((void *)key, (void *)gc->item[i]);
                if (stat == TRUE)
                {
                    break;
                }
            }
            if (stat == TRUE)
            {
                data = gc->item[i];
                for (j = i; j < gc->numItens - 1; j++)
                {
                    gc->item[j] = gc->item[j + 1];
                }
                gc->numItens--;
                return data;
            }
        }
    }
    return NULL;
}
