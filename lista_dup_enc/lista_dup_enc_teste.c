#include <stdio.h>
#include "lista_dup_enc.h"


int main() {
    lista *l = criar_lst();

    int i;
    printf("\nInsercao [inicio]: \n");
    for(i = 1; i <= 15; i++)
        if(inserir_inicio_lst(l, i))
            printf("Valor %d inserido\n", i);
        else
            printf("Falha na insercao\n");
    printf("Lista: \n");
    exibir_lst(l); printf("\n");
    printf("\n\n");

    printf("Remocao [inicio]: \n");
    int valor_removido;
    for(i = 1; i <= 5; i++) {
        if(remover_inicio_lst(l, &valor_removido))
            printf("valor removido: %d\n", valor_removido);
        else
            printf("Falha na remocao\n");
    }
    printf("\n\n");
    printf("Lista: \n");
    exibir_lst(l); printf("\n");
    printf("\n\n");

    printf("Insercao [fim]: \n");
    for(i = 21; i <= 35; i++)
        if(inserir_fim_lst(l, i))
            printf("Valor %d inserido\n", i);
        else
            printf("Falha na insercao\n");

    printf("Lista: \n");
    exibir_lst(l); printf("\n");
    printf("\n\n");

    printf("Busca\n");
    int pos = 0;
    if(busca_seq_lst(l, 36, &pos)) {
        printf("Busca bem sucedida\n");
        printf("\nValor %d Posicao: %d", 36, pos);
    } else
        printf("Busca sem sucesso\n");

    if(busca_seq_lst(l, 23, &pos)) {
        printf("Busca bem sucedida\n");
        printf("Valor %d Posicao: %d\n", 23, pos);
    } else
        printf("Busca sem sucesso\n");

    printf("\nInsercao [meio - 3a posicao]: \n");
    for(i = 101; i <= 105; i++)
        if(inserir_meio_lst(l, i, 3))
            printf("Valor %d inserido\n", i);
        else
            printf("Falha na insercao\n");

    printf("\n\n");
    printf("Lista: \n");
    exibir_lst(l); printf("\n");
    printf("\n\n");

    printf("\nRemocao [meio - 4a posicao]: \n");
    if(remover_meio_lst(l, &valor_removido, 4))
        printf("Valor %d removido\n", valor_removido);
    else
        printf("Falha na remocao\n");

    printf("\n\n");
    exibir_lst(l); printf("\n");
    printf("\n\n");

    printf("\nRemocao [fim]: \n");
    for(i = 1; i <= 5; i++) {
        if(remover_fim_lst(l, &valor_removido))
            printf("%d ", valor_removido);
        else
            printf("Falha na remocao\n");
    }
    printf("\n\n");
    exibir_lst(l); printf("\n");
    printf("\n\n");

    printf("\nInsercao [fim]: \n");
    if(inserir_fim_lst(l, 5))
        printf("Valor %d inserido\n", 5);
    else
        printf("Falha na insercao\n");
    exibir_lst(l); printf("\n");
    printf("\n\n");

    printf("\nInsercao [inicio]: \n");
    if(inserir_inicio_lst(l, 100))
        printf("Valor %d inserido\n", 100);
    else
        printf("Falha na insercao\n");
    exibir_lst(l); printf("\n");
    printf("\n\n");

    printf("\nInsercao [meio - 2a posicao]: \n");
    if(inserir_meio_lst(l, 15, 2))
        printf("Valor %d inserido\n", 15);
    else
        printf("Falha na insercao\n");
    exibir_lst(l); printf("\n");
    printf("\n\n");

    liberar_lst(&l);

    printf("\nImprimir lista vazia\n");
    exibir_lst(l);

    return 0;
}