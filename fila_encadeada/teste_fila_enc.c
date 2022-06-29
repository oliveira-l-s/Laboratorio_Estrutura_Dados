#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "fila_enc.h"

int main() {
    srand(time(NULL));
    
    fila *f = criar_fila(100);
    int i;
    for(i = 1; i <= 49; i+=2)
        inserir_fila(f, i);
    
    printf("Vazia? %s\n", (esta_vazia_fila(f) ? "Sim" : "Nao"));
    while(!esta_vazia_fila(f)) {
        printf("%d ", frente_fila(f));
        remover_fila(f);
    }
    printf("\nVazia? %s\n", (esta_vazia_fila(f) ? "Sim" : "Nao"));

    liberar_fila(&f);

    return 0;
}