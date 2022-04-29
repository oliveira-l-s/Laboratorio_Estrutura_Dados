/** @file lista.c
 *  @brief Implementação de uma lista linear sequencial
 *
 *  Este arquivo contém a implementação do tipo e das funções definidas
 *  para uma lista linear.
 *
 *  @author Anderson Grandi Pires
 *  @bug Nenhum bug conhecido
 */

#include "lista.h"
#include <stdlib.h>
#include <stdio.h>

struct lista {
    int qtde, capacidade;
    int *dados;
};

int buscar_lst(lista *l, int valor) {
    if(l == NULL || esta_vazia_lst(l))
        return 0;
    
    int i;
    for(i = 0; i < l->qtde; i++)
        if(l->dados[i] == valor)
            return i+1;
    
    return 0;
}

int capacidade_lst(lista *l) {
    if(l == NULL)
        return ERRO;

    return l->capacidade;
}

lista* criar_lst(int capacidade) {
    if(capacidade <= 0)
        return NULL;

    lista *nova = (lista*) calloc(1, sizeof(lista));
    if(nova == NULL)
        return NULL;

    nova->qtde = 0;
    nova->dados = (int*) calloc(capacidade, sizeof(int));
    if(nova->dados == NULL) {
        free(nova);
        return NULL;
    }
    nova->capacidade = capacidade;

    return nova;
}

int esta_vazia_lst(lista *l) {
    if(l == NULL)
        return ERRO;

    if(l->qtde == 0)
        return VERDADEIRO;
    else
        return FALSO;
}

int esta_cheia_lst(lista *l) {
    if(l == NULL)
        return ERRO;

    return l->qtde == l->capacidade;
}

void exibir_lst(lista *l) {
    if(l == NULL || esta_vazia_lst(l))
        return;
    
    int i;
    for(i = 0; i < tamanho_lst(l); i++)
        printf("%d ", l->dados[i]);
}

int inserir_inicio_lst(lista *l, int valor) {
    if(l == NULL)
        return ERRO;

    if(esta_cheia_lst(l))
        return FALSO;

    int i;
    for(i = l->qtde; i >= 1; i--)
        l->dados[i] = l->dados[i-1];

    l->dados[0] = valor;
    l->qtde++;

    return VERDADEIRO;
}

static int invalido(lista *l, int posicao) {
    if(posicao <= 0 || posicao > l->qtde+1)
        return VERDADEIRO;
    
    return FALSO;
}

int inserir_meio_lst(lista *l, int valor, int pos) {
    if(l == NULL)
        return ERRO;

    if(esta_cheia_lst(l) || invalido(l, pos))
        return FALSO;

    int i;
    for(i = l->qtde; i >= pos; i--)
        l->dados[i] = l->dados[i-1];

    l->dados[pos-1] = valor;
    l->qtde++;

    return VERDADEIRO;
}

int inserir_fim_lst(lista *l, int valor) {
    if(l == NULL)
        return ERRO;
    
    if(esta_cheia_lst(l))
        return FALSO;

    l->dados[l->qtde] = valor;
    l->qtde++;

    return VERDADEIRO;
}

// Função não explicada no vídeo. Veremos na próxima aula
void liberar_lst(lista **l) {
    if(l == NULL || *l == NULL)
        return;
    
    free((*l)->dados);
    free(*l);
    *l = NULL;
}

int remover_inicio_lst(lista *l, int *valor_removido) {
    if(l == NULL)
        return ERRO;
    
    if(esta_vazia_lst(l))
        return FALSO;
    
    *valor_removido = l->dados[0];

    int i;
    for(i = 0; i < l->qtde-1; i++)
        l->dados[i] = l->dados[i+1];

    l->qtde--;

    return VERDADEIRO;
}

int remover_meio_lst(lista *l, int *valor_removido, int pos) {
    if(l == NULL)
        return ERRO;
    
    if(esta_vazia_lst(l))
        return FALSO;

    *valor_removido = l->dados[pos-1];

    int i;
    for(i = pos-1; i < l->qtde-1; i++)
        l->dados[i] = l->dados[i+1];

    l->qtde--;

    return VERDADEIRO;
}

int remover_fim_lst(lista *l, int *valor_removido) {
    if(l == NULL)
        return ERRO;
    
    if(esta_vazia_lst(l))
        return FALSO;
    
    *valor_removido = l->dados[l->qtde-1];

    l->qtde--;

    return VERDADEIRO;
}

int tamanho_lst(lista *l) {
    if(l == NULL)
        return ERRO;
    
    return l->qtde;
}