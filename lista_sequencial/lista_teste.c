/** @file lista_teste.c
 *  @brief Arquivo de teste para uma lista linear sequencial
 *
 *  Este arquivo apresenta alguns testes para as funcionalidades
 *  definidas na lista linear sequencial
 *
 *  @author Anderson Grandi Pires
 *  @bug Nenhum bug conhecido
 */

#include <stdio.h>
#include "lista.h"

void apresentacao(lista* l) {
    printf("Esta vazia: ");
    if(esta_vazia_lst(l))  // if(esta_vazia_lst(l1) == VERDADEIRO)
        printf("Sim\n");
    else
        printf("Nao\n");
    printf("Esta cheia: ");
    if(esta_cheia_lst(l))  // if(esta_vazia_lst(l1) == VERDADEIRO)
        printf("Sim\n");
    else
        printf("Nao\n");
    printf("Tamanho: %d\n", tamanho_lst(l));
    printf("Capacidade: %d\n", capacidade_lst(l));
    printf("Lista: ");
    exibir_lst(l);
    printf("\n");
}

int main() {
    lista *l1 = criar_lst(10);
    if(l1 == NULL)
        printf("Erro na criacao da lista\n");
    else
        printf("Lista criada com sucesso!\n");
    apresentacao(l1);

    int i;
    for(i = 1; i <= 15; i++)
        if(inserir_fim_lst(l1, i) == VERDADEIRO)
            printf("Valor %d inserido com sucesso!\n", i);
        else
            printf("Erro na insercao.\n");
    
    inserir_meio_lst(l1, 100, 3);
    apresentacao(l1);

    int v_removido;
    if(remover_inicio_lst(l1, &v_removido) == VERDADEIRO)
        printf("Valor %d removido da lista\n", v_removido);
    else
        printf("Remocao nao efetuada\n");
    
    if(remover_fim_lst(l1, &v_removido) == VERDADEIRO)
        printf("Valor %d removido da lista\n", v_removido);
    else
        printf("Remocao nao efetuada\n");

    apresentacao(l1);
    if(remover_meio_lst(l1, &v_removido, 3) == VERDADEIRO)
        printf("Valor %d removido da lista\n", v_removido);
    else
        printf("Remocao nao efetuada\n");

    apresentacao(l1);

    while(!esta_vazia_lst(l1)) {
        if(remover_meio_lst(l1, &v_removido, tamanho_lst(l1)) == VERDADEIRO)
            printf("Valor %d removido da lista\n", v_removido);
        else {
            printf("Remocao nao efetuada\n");
            printf("Remocao nao efetuada\n");
        }
    }

    apresentacao(l1);

    printf("\nConteudo de l: %p\n", l1);
    liberar_lst(&l1);
    printf("Conteudo de l: %p\n", l1);

    return 0;
}

/*
    lista *l2 = criar_lst(25);
    if(l2 == NULL)
        printf("Erro na criacao da lista\n");
    else
        printf("Lista criada com sucesso!\n");
    printf("Esta vazia: ");
    if(esta_vazia_lst(l2))  // if(esta_vazia_lst(l1) == VERDADEIRO)
        printf("Sim\n");
    else
        printf("Nao\n");
    printf("Esta cheia: ");
    if(esta_cheia_lst(l2))  // if(esta_vazia_lst(l1) == VERDADEIRO)
        printf("Sim\n");
    else
        printf("Nao\n");
    printf("Tamanho: %d\n", tamanho_lst(l2));
    printf("Capacidade: %d\n", capacidade_lst(l2));
*/