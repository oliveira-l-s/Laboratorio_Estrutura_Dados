#include <stdio.h>
#include <stdlib.h>

/* Vetores
 * - Declaração e definição
 * - Alocação estática versus alocação dinâmica
 * - Passagem de parâmetros por referência
 * - Protótipo de funções: declaração
 * - Desalocação (liberação) de memória
 */

int soma(int vetor[], int tam) {
    int i, soma = 0;
    for(i = 0; i < tam; i++)
        soma += vetor[i];

    return soma;
}

int soma1(int *vetor, int tam) {
    int i, soma = 0;
    for(i = 0; i < tam; i++)
        soma += vetor[i];

    return soma;
}

int main() {
    int *vet, *v, k;
    vet = (int*) malloc(5*sizeof(int));
    v = (int*) calloc(5, sizeof(int));

    for(k = 0; k < 5; k++) {
        vet[k] = k;
        v[k] = 5 - k;
    }
    
    for(k = 0; k < 5; k++)
        printf("%d ", vet[k]);
    printf("\n");
    printf("Soma: %d\n", soma(vet, 5));
    printf("Soma: %d\n", soma1(vet, 5));

    for(k = 0; k < 5; k++)
        printf("%d ", v[k]);
    printf("\n");
    printf("Soma: %d\n", soma(v, 5));
    printf("Soma: %d\n", soma1(v, 5));

    free(v);
    free(vet);

    return 0;
}