#include <stdlib.h>
#include <stdio.h>
#include "fila_seq.h"

#define VERDADEIRO 1
#define FALSO 0

struct f {
    int * dados;
    int qtde;
    int cap;
};

int capacidade_fila(fila *l) {
    if(l == NULL)
        return 0;

    return l->cap;
}

fila* criar_fila(int cap_fila) {
    if(cap_fila < 1)
        return NULL;

    fila* nova = (fila*) malloc(sizeof(fila));
    if(nova == NULL)
        return NULL;
    
    nova->dados = (int*) calloc(cap_fila, sizeof(int));
    if(nova->dados == NULL) {
        free(nova);
        return NULL;
    }

    nova->qtde = 0;
    nova->cap = cap_fila;

    return nova;
}

int esta_vazia_fila(fila* l) {
    if(l == NULL)
        return VERDADEIRO;

    return l->qtde == 0;
}

int esta_cheia_fila(fila* l) {
    if(l == NULL)
        return FALSO;

    return l->qtde == l->cap;
}

int esvaziar_fila(fila *l) {
    if(l == NULL)
        return FALSO;
    
    l->qtde = 0;
    return VERDADEIRO;
}

int frente_fila(fila *l) {
    return l->dados[0];
}

int inserir_fila(fila *l, int valor) {
    if(l == NULL || esta_cheia_fila(l))
        return FALSO;
    
    if(!esta_cheia_fila(l)) {
        l->dados[l->qtde] = valor;
        l->qtde++;
    }

    return VERDADEIRO;
}

int liberar_fila(fila **l) {
    if(l == NULL)
        return FALSO;
        
    free((*l)->dados);
    free(*l);
    *l = NULL;
    
    return VERDADEIRO;
}

int remover_fila(fila *l) {
    if(l == NULL || esta_vazia_fila(l))
        return FALSO;

    int i;
    for(i = 0; i < l->qtde-1; i++)
        l->dados[i] = l->dados[i+1];
    
    l->qtde--;

    return VERDADEIRO;
}

int tamanho_fila(fila *l) {
    if(l == NULL)
        return 0;
    
    return l->qtde;
}
