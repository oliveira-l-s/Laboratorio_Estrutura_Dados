#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "lista_ord_enc.h"

#define VERDADEIRO 1
#define FALSO 0
#define ERRO -1

struct no {
    int conteudo;
    struct no* prox;
};

struct lista {
    no *prim;
    int qtde;
};

int busca_seq_lst(lista* l, int valor, int* pos) {
    if(esta_vazia_lst(l))
        return FALSO;
    
    int cont = 1;
    no* temp = l->prim;
    while(temp != NULL) {
        if(temp->conteudo == valor) {
            *pos = cont;
            return VERDADEIRO;
        }
        temp = temp->prox;
        cont++;
    }

    return FALSO;
}

lista* criar_lst() {
    lista* l = (lista*) calloc(1, sizeof(lista));
    if(l == NULL)
        return NULL;

    return l;
}

static no* criar_no(int valor) {
    no* novo = (no*) calloc(1, sizeof(no));
    if(novo == NULL)
        return NULL;
    
    novo->prox = NULL;
    novo->conteudo = valor;

    return novo;
}

int esta_vazia_lst(lista* l) {
    if(l == NULL)
        return ERRO;
    
    if(l->prim == NULL)
        return VERDADEIRO;

    return FALSO;
}

void exibir_lst(lista* l) {
    if(l == NULL)
        return;
    
    no *temp = l->prim;
    while(temp != NULL) {
        printf("%d ", temp->conteudo);
        temp = temp->prox;
    }
}

int inserir_lst(lista* l, int valor) {
    if(l == NULL)
        return ERRO;

    no *novo = criar_no(valor);
    if(novo == NULL)
        return FALSO;

    no *temp = NULL;
    if(esta_vazia_lst(l)) {
        l->prim = novo;
        l->qtde++;
        return VERDADEIRO;
    } else {
        temp = l->prim;
        if(temp->conteudo >= valor) {
            novo->prox = l->prim;
            l->prim = novo;
            l->qtde++;
            return VERDADEIRO;
        } else {
            int i;
            for(i = 1; i <= tamanho_lst(l)-1; i++) {
                if(temp->prox->conteudo > valor) {
                    novo->prox = temp->prox;
                    temp->prox = novo;
                    l->qtde++;
                    return VERDADEIRO;
                }
                temp = temp->prox;
            }
        }
    }

    if(temp != NULL) {
        temp->prox = novo;
        l->qtde++;
    }

	return VERDADEIRO;
}

void liberar_lst(lista **l) {
    if(l == NULL || *l == NULL)
        return;

    no *temp = (*l)->prim;
    while(temp != NULL) {
        (*l)->prim = (*l)->prim->prox;
        (*l)->qtde--;
        free(temp);
        temp = (*l)->prim;
    }

    free(*l);
    *l = NULL;
}

int remover_lst(lista* l, int* valor, int pos) {
    if(l == NULL || esta_vazia_lst(l) || valor == NULL)
        return FALSO;
    
    if(pos < 1 || pos > l->qtde)
        return FALSO;

    no* temp = l->prim;
    if(pos == 1) {
        *valor = l->prim->conteudo;
        l->prim = l->prim->prox;
        free(temp);
    } else {
        int i;
        for(i = 1; i < pos - 1; i++)
            temp = temp->prox;
        *valor = temp->prox->conteudo;
        no *aux = temp->prox;
        temp->prox = temp->prox->prox;
        free(aux);
    }
    l->qtde--;

    return VERDADEIRO;
}

int tamanho_lst(lista* l) {
    if(l == NULL)
        return 0;
    
    return l->qtde;
}