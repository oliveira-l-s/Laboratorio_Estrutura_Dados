#include <stdio.h>
#include "lista_ord_enc.h"

void info(lista* l) {
    printf("\n");
    printf("tamanho: %d\n", tamanho_lst(l));
    exibir_lst(l);
    printf("\n\n");
}

int main() {
    lista* l = criar_lst();

    int i;
    for(i = 1; i <= 16; i++)
        if(inserir_lst(l, i))
            printf("Valor %d inserido com sucesso.\n", i);
        else
            printf("Falha na insercao.\n");

    info(l);

    int valor_removido;
    for(i = 1; i <= 20; i*=2) {
        if(remover_lst(l, &valor_removido, i))
            printf("Valor removido: %d\n", valor_removido);
        else
            printf("Falha na remocao.\n");
    }
    if(remover_lst(l, &valor_removido, 12))
        printf("Valor removido: %d\n", valor_removido);
    else
        printf("Falha na remocao.\n");

    info(l);

    for(i = 10; i <= 20; i++)
        if(inserir_lst(l, i))
            printf("Valor %d inserido com sucesso.\n", i);
        else
            printf("Falha na insercao.\n");

    info(l);

    int pos = 0;
    if(busca_seq_lst(l, 36, &pos)) {
        printf("Busca bem sucedida");
        printf("\nPosicao: %d", pos);
    } else
        printf("Busca sem sucesso");
    printf("\n\n");

    for(i = 5; i >= -2; i--)
        if(inserir_lst(l, i))
            printf("Valor %d inserido com sucesso.\n", i);
        else
            printf("Falha na insercao.\n");
    
    info(l);

    int p = 4; // tamanho_lst(l);
    printf(">>>> Remocao na posicao %d\n", p);
        if(remover_lst(l, &valor_removido, p))
            printf("%d ", valor_removido);
        else
            printf("falha na remocao\n");

    info(l);

    for(i = 1; i <= 5; i++) {
        if(remover_lst(l, &valor_removido, tamanho_lst(l)))
            printf("\nValor removido: %d", valor_removido);
        else
            printf("\nFalha na remocao.");
    }

    info(l);

    for(int i = 5; i <= 15; i+=5) {
        if(inserir_lst(l, i))
            printf("\nValor %d inserido com sucesso.\n", i);
        else
            printf("\nFalha na insercao.\n");
        info(l);
    }

    printf("remocao de elementos\n");
    while(!esta_vazia_lst(l)) {
        if(remover_lst(l, &valor_removido, tamanho_lst(l)))
            printf("%d ", valor_removido);
        else
            printf("Falha na remocao.\n");
    }

    info(l);

    if(inserir_lst(l, 30))
        printf("Valor %d inserido com sucesso.\n", 30);
    else
        printf("Falha na insercao.\n");
    
    info(l);

    if(inserir_lst(l, -10))
        printf("Valor %d inserido com sucesso.\n", -10);
    else
        printf("Falha na insercao.\n");
    
    info(l);

    liberar_lst(&l);

    info(l);

    return 0;
}