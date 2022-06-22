#include <stdio.h>
#include "lista_enc.h"

int main() {
    lista *l = criar_lst();

    int i;
    printf("\nInsercao inicio: ");
    for(i = 1; i <= 15; i++)
        inserir_inicio_lst(l, i);
    printf("\nLista: ");
    exibir_lst(l);
    printf("\n\n");

    printf("Valores removidos: ");
    int valor_removido;
    for(i = 1; i <= 5; i++) {
        if(remover_inicio_lst(l, &valor_removido))
            printf("%d ", valor_removido);
    }
    printf("\n\n");
    printf("Lista: ");
    exibir_lst(l);
    printf("\n\n");

    for(i = 21; i <= 35; i++)
        inserir_fim_lst(l, i);

    printf("Lista: ");
    exibir_lst(l);
    printf("\n\n");

    int pos = 0;
    if(busca_seq_lst(l, 36, &pos)) {
        printf("Busca bem sucedida");
        printf("\nPosicao: %d", pos);
    } else
        printf("Busca sem sucesso");

    for(i = 101; i <= 105; i++)
        inserir_meio_lst(l, i, 3);

    printf("\n\n");
    printf("Lista: ");
    exibir_lst(l);
    printf("\n\n");

    remover_meio_lst(l, &valor_removido, 4);
    printf("Valor removido: %d ", valor_removido);
    printf("\n\n");
    printf("Lista: ");
    exibir_lst(l);

    printf("\n\nValores removidos: ");
    for(i = 1; i <= 5; i++) {
        if(remover_fim_lst(l, &valor_removido))
            printf("%d ", valor_removido);
    }
    printf("\n\n");
    exibir_lst(l);

    inserir_fim_lst(l, 5);
    exibir_lst(l); printf("\n\n");
    inserir_inicio_lst(l, 10);
    exibir_lst(l); printf("\n\n");
    inserir_meio_lst(l, 15, 2);
    exibir_lst(l); printf("\n\n");

    liberar_lst(&l);

    printf("\nImprimir lista vazia\n");
    exibir_lst(l);

    return 0;
}