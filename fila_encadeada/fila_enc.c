#include <stdio.h>
#include <stdlib.h>

#include "fila_enc.h"

#define VERDADEIRO 1
#define FALSO 0
#define ERRO -1

struct c {
    int conteudo;
    celula *prox;
};

struct fila {
    celula *prim;
    int qtde;
};

fila* criar_fila() {
    fila* f = (fila*) calloc(1, sizeof(fila));
    if(f == NULL)
        return NULL;

    f->prim = NULL;
    f->qtde = 0;

    return f;
}

static celula* criar_no(int valor) {
    celula* novo = (celula*) calloc(1, sizeof(celula));
    if(novo == NULL)
        return NULL;
    
    novo->prox = NULL;
    novo->conteudo = valor;

    return novo;
}

int esta_vazia_fila(fila* f) {
    if(f == NULL)
        return ERRO;
    
    if(f->qtde == 0)        // if(f->prim == NULL)
        return VERDADEIRO;

    return FALSO;
}

int frente_fila(fila *f) {
    return f->prim->conteudo;
}

int inserir_fila(fila* f, int valor) {
    celula *cel = criar_no(valor);
    if(f == NULL || cel == NULL)
        return FALSO;
    
    if(esta_vazia_fila(f))
        f->prim = cel;
    else {
        celula *temp = f->prim;
        while(temp->prox != NULL)
            temp = temp->prox;
        temp->prox = cel;
    }

    f->qtde++;

    return VERDADEIRO;
}

void liberar_fila(fila **f) {
    if(f == NULL)
        return;

    celula *temp = (*f)->prim;
    while(temp != NULL) {
        (*f)->prim = (*f)->prim->prox;
        free(temp);
        temp = (*f)->prim;
        (*f)->qtde--;
    }

    free(*f);
    *f = NULL;
}

int remover_fila(fila *f) {
    if(f == NULL || esta_vazia_fila(f))
        return FALSO;
    
    celula *temp = f->prim;
    f->prim = f->prim->prox;
    free(temp);
    f->qtde--;
    
    return VERDADEIRO;
}

int tamanho_fila(fila* f) {
    if(f == NULL)
        return 0;
    
    return f->qtde;
}