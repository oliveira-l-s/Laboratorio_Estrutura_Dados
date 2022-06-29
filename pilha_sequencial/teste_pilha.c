#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "pilha_seq.h"

int main() {
    srand(time(NULL));
    
    pilha *p = criar_pilha(100);
    int i;
    for(i = 1; i <= 49; i+=2)
        inserir_pilha(p, i);
    
    while(!esta_vazia_pilha(p)) {
        printf("%d ", topo_pilha(p));
        remover_pilha(p);
    }

    inserir_pilha(p, 10);
    printf("\nVazia? %s\n", (esta_vazia_pilha(p) ? "Sim" : "Nao"));
    esvaziar_pilha(p);
    printf("Vazia? %s\n", (esta_vazia_pilha(p) ? "Sim" : "Nao"));

    liberar_pilha(&p);

    return 0;
}