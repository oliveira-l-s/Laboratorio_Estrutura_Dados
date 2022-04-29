#include <stdio.h>
#include <stdlib.h>

/* Structs
 * - Declaração e definição
 * - Redefinição de tipo (typedef)
 * - Alocação dinâmica de memória
 * - Passagem de parâmetros por referência
 * - Protótipo de funções: declaração
 * - Desalocação (liberação) de memória
 */

struct pto {
    float x;
    float y;
};

typedef struct pto ponto;

void mostrar(ponto p) {
    printf("(%.2f, %.2f)\n", p.x, p.y);
}

int main() {
    struct pto *p1 = (ponto*) malloc(sizeof(ponto));
    //printf("p1: (%.2f, %.2f)\n", p1.x, p1.y);
    (*p1).x = 10;
    (*p1).y = 15;
    printf("p1: "); //(%.2f, %.2f)\n", p1.x, p1.y);
    mostrar(*p1);

    p1->x += 10;
    p1->y -= 5;
    
    //printf("p1: (%.2f, %.2f)\n", p1.x, p1.y);
    printf("p1: "); //(%.2f, %.2f)\n", p1.x, p1.y);
    mostrar(*p1);

    ponto *p2 = (ponto*) calloc(1, sizeof(ponto));
    p2->x = 100;
    p2->y = -50;
    //printf("p2: (%.2f, %.2f)\n", p2.x, p2.y);
    printf("p2: "); //(%.2f, %.2f)\n", p2.x, p2.y);
    mostrar(*p2);

    p2->x += 10;
    p2->y -= 5;
    
    //printf("p2: (%.2f, %.2f)\n", p2.x, p2.y);
    printf("p2: "); //(%.2f, %.2f)\n", p2.x, p2.y);
    mostrar(*p2);

    free(p1);
    free(p2);

    return 0;
}