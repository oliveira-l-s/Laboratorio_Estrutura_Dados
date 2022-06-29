/** @file pilha.c
 *  @brief Implementação de uma pilha com representação sequencial
 *
 *  Este arquivo contém a implementação do tipo e das funções definidas
 *  para uma pilha.
 *
 *  @author Anderson Grandi Pires
 *  @bug Nenhum bug conhecido
 */

#include <stdlib.h>
#include <stdio.h>
#include "pilha_seq.h"

#define VERDADEIRO 1
#define FALSO 0
#define ERRO -1

struct lst {
    int qtde, capacidade;
    int *dados;
};

pilha* criar_pilha(int cap) {
        if(cap <= 0)
        return NULL;

    pilha *nova = (pilha*) calloc(1, sizeof(pilha));
    if(nova == NULL)
        return NULL;

    nova->qtde = 0;
    nova->dados = (int*) calloc(cap, sizeof(int));
    if(nova->dados == NULL) {
        free(nova);
        return NULL;
    }
    nova->capacidade = cap;

    return nova;
}

int esta_vazia_pilha(pilha* p) {
    if(p == NULL)
        return ERRO;

    if(p->qtde == 0)
        return VERDADEIRO;
    else
        return FALSO;
}

int esvaziar_pilha(pilha *p) {
    if(p == NULL)
        return FALSO;
    
    p->qtde = 0;
    return VERDADEIRO;
}

int inserir_pilha(pilha *p, int valor) {
    if(p == NULL)
        return ERRO;
    
    if(p->qtde == p->capacidade)
        return FALSO;

    p->dados[p->qtde] = valor;
    p->qtde++;

    return VERDADEIRO;
}

int liberar_pilha(pilha **p) {
    if(p == NULL || *p == NULL)
        return FALSO;
    
    free((*p)->dados);
    free(*p);
    *p = NULL;
    
    return VERDADEIRO;
}

int remover_pilha(pilha *p) {
    if(p == NULL)
        return ERRO;
    
    if(esta_vazia_pilha(p))
        return FALSO;
    
    p->qtde--;

    return VERDADEIRO;
}

int topo_pilha(pilha *p) {
    return p->dados[p->qtde-1];
}
