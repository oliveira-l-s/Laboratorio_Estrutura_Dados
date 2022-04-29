#include <stdio.h>

/* Funções
 * - Definição: forma geral
 * - Passagem de parâmetros por referência
 * - Passagem de parâmetros por valor e por referência
 * - Protótipo de funções: declaração
 */

// Passagem de parâmetros por valor
void troca1(int v1, int v2) {
    int temp = v1;
    v1 = v2;
    v2 = temp;
}

// Passagem de parâmetros por valor
void troca2(int *v1, int *v2) {
    int temp = *v1;
    *v1 = *v2;
    *v2 = temp;
}

// Passagem de parâmetros por valor e por referência
void soma(int v1, int v2, int *res) {    
    *res = v1 + v2;
}

int main() {
    int a = 10, b = 5;   // tipo: int

    troca1(a, b);
    printf("a: %d, b: %d\n", a, b);

    troca2(&a, &b);
    printf("a: %d, b: %d\n", a, b);

    int r;
    soma(a, b, &r);
    printf("\nSoma de %d e %d: %d\n", a, b, r);

    return 0;
}