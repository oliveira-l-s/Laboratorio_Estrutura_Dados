#include "fila.h"
#include <stdlib.h>
#include <stdio.h>

struct no {
    int dado;
    no *esq;    // sae
    no *dir;    // sad
};

struct fila {
    int qtde, capacidade;
    no* *dados;
};

int capacidade_f(fila *f) {
    if(f == NULL)
        return ERRO;

    return f->capacidade;
}

fila* criar_f(int capacidade) {
    if(capacidade <= 0)
        return NULL;

    fila *nova = (fila*) calloc(1, sizeof(fila));
    if(nova == NULL)
        return NULL;

    nova->qtde = 0;
    nova->dados = (no**) calloc(capacidade, sizeof(no*));
    if(nova->dados == NULL) {
        liberar_f(&nova);
        return NULL;
    }
    nova->capacidade = capacidade;

    return nova;
}

int desenfileirar_f(fila *f) {
    if(f == NULL)
        return ERRO;
    
    if(esta_vazia_f(f))
        return FALSO;
    
    int i;
    for(i = 0; i < f->qtde-1; i++)
        f->dados[i] = f->dados[i+1];

    f->qtde--;

    return VERDADEIRO;
}

int enfileirar_f(fila *f, no* no) {
    if(f == NULL)
        return ERRO;
    
    if(esta_cheia_f(f))
        return FALSO;

    f->dados[f->qtde] = no;
    f->qtde++;

    return VERDADEIRO;
}

int esta_vazia_f(fila *f) {
    if(f == NULL)
        return ERRO;

    if(f->qtde == 0)
        return VERDADEIRO;
    else
        return FALSO;
}

int esta_cheia_f(fila *f) {
    if(f == NULL)
        return ERRO;

    return f->qtde == f->capacidade;
}

no* frente_f(fila *f) {
    if(f == NULL || esta_vazia_f(f))
        return NULL;
    
    return f->dados[0];
}

void liberar_f(fila **f) {
    if(f == NULL || *f == NULL)
        return;
    
    while(!esta_vazia_f(*f)) {
        desenfileirar_f(*f);
    }
    free((*f)->dados);
    free(*f);
    *f = NULL;
}

int tamanho_f(fila *f) {
    if(f == NULL)
        return ERRO;
    
    return f->qtde;
}