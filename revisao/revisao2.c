#include <stdio.h>

/* Funções
 * - Definição: forma geral
 * - Passagem de parâmetros por valor
 * - Protótipo de funções: declaração
 */

// Passagem de parâmetros por valor
int soma(int v1, int v2) {
    return v1 + v2;
}

int main() {
    int a = 10, b = 5;   // tipo: int

    int r = soma(a, b);
    printf("Soma de %d e %d: %d\n", a, b, r);

    a = b;
    printf("Soma de %d e %d: %d\n", a, b, soma(a, b));

    printf("Soma de %d e %d: %d\n", a, 3, soma(a, 3));
    printf("Soma de %d e %d: %d\n", -3, 3, soma(-3, 3));

    return 0;
}