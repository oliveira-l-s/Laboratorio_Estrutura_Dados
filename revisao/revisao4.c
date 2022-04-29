#include <stdio.h>
#include <stdlib.h>

/* Vetores
 * - Declaração e definição
 * - Ponteiro constante
 * - Alocação estática versus alocação dinâmica
 * - Passagem de parâmetros por referência
 * - Protótipo de funções: declaração
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
    int vet[5], k;
    for(k = 0; k < 5; k++)
        vet[k] = k;
    
    for(k = 0; k < 5; k++)
        printf("%d ", vet[k]);
    printf("\n");
    printf("Soma: %d\n", soma(vet, 5));

    int v[] = {1, 2, 3, 4, 5, 5, 6, 7, 5, 3, 2, 9}, i;

    printf("\n");
    printf("sizeof(v): %d\n", sizeof(v));
    printf("sizeof(int): %d\n", sizeof(int));
    printf("sizeof(v)/sizeof(int): %d\n", sizeof(v)/sizeof(int));

    for(i = 0; i < sizeof(v)/sizeof(int); i++)
        printf("%d ", v[i]);

    printf("\n");
    printf("Soma: %d\n", soma(v, sizeof(v)/sizeof(int)));
    printf("Soma: %d\n", soma1(v, sizeof(v)/sizeof(int)));

    return 0;
}