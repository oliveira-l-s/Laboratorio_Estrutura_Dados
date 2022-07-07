#include <stdlib.h>
#include <stdio.h>
#include "abb_enc.h"
#include "fila.h"

// IMPLEMENTAÇÃO DA ÁRVORE BINÁRIA DE BUSCA (ENCADEADA)

#define FALSO 0
#define VERDADEIRO 1

struct no {
    int info;
    no *sae;    // sae
    no *sad;    // sad
};

struct arv {
    no *raiz;
};

int adicionar_no_arv(arvore* a, int valor) {
    if(a == NULL)
        return FALSO;

    no *temp = a->raiz;
    while(temp != NULL) {
        if(valor <= temp->info) {
            if(temp->sae == NULL) {
                temp->sae = criar_no(valor);
                break;
            }
            temp = temp->sae;
        } else {
            if(temp->sad == NULL) {
                temp->sad = criar_no(valor);
                break;
            }
            temp = temp->sad;
        }
    }
    
    return VERDADEIRO;
}

void busca_largura(arvore* a) {
    if(a == NULL)
        return;
    
    fila *f = criar_f(15);

    enfileirar_f(f, get_raiz_arv(a));
    while(!esta_vazia_f(f)) {
        no* temp = frente_f(f);
        desenfileirar_f(f);
        if(temp != NULL) {
            printf("%d ", temp->info);
            enfileirar_f(f, sae_arv(temp));
            enfileirar_f(f, sad_arv(temp));
        }
    }
    liberar_f(&f);
}

int buscar_arv(arvore* a, int valor) {
    if(a == NULL)
        return FALSO;
    
    no* temp = a->raiz;
    while(temp != NULL) {
        printf("%d ", temp->info);  // somente para teste (remover)
        if(temp->info == valor) {
            return VERDADEIRO;
        } else {
            if(valor < temp->info)
                temp = temp->sae;
            else
                temp = temp->sad;
        }
    }

    return FALSO;
}

arvore* criar_arv(int valor_raiz) {
    arvore *a = (arvore*) malloc(sizeof(arvore));
    if(a == NULL)
        return NULL;

    no *raiz = (no*) criar_no(valor_raiz);
    if(raiz != NULL)
        a->raiz = raiz;
    else
        return NULL;
    
    return a;
}

no* criar_no(int valor) {
    no *novo = (no*) malloc(sizeof(no));
    if(novo == NULL)
        return NULL;

    novo->info = valor;
    novo->sad = NULL;
    novo->sae = NULL;

    return novo;
}

no* get_raiz_arv(arvore* a) {
    if(a == NULL)
        return NULL;
    
    return a->raiz;
}

no* sae_arv(no* n) {
    if(n == NULL)
        return NULL;
    
    return n->sae;
}

no* sad_arv(no* n) {
    if(n == NULL)
        return NULL;

    return n->sad;
}

void liberar_arv(arvore** a) {
    if(*a == NULL)
        return;
    liberar_no_arv(&((*a)->raiz));
    free(*a);
    *a = NULL;
}

void liberar_no_arv(no** no) {
    if(*no != NULL) {
        liberar_no_arv(&((*no)->sae));
        liberar_no_arv(&((*no)->sad));
        free(*no);
        *no = NULL;
    }
}

void pre_ordem_arv(no *n) {
    if(n != NULL) {
        printf("%d ", n->info);
        pre_ordem_arv(n->sae);
        pre_ordem_arv(n->sad);
    }
}

void em_ordem_arv(no *n) {
    if(n != NULL) {
        em_ordem_arv(n->sae);
        printf("%d ", n->info);
        em_ordem_arv(n->sad);
    }
}

void pos_ordem_arv(no *n) {
    if(n != NULL) {
        pos_ordem_arv(n->sae);
        pos_ordem_arv(n->sad);
        printf("%d ", n->info);
    }
}