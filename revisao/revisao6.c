#include <stdio.h>
#include <stdlib.h>

/* Structs
 * - Declaração e definição
 * - Redefinição de tipo (typedef)
 * - Alocação estática de memória
 * - Passagem de parâmetros por valor
 * - Protótipo de funções: declaração
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
    struct pto p1 = {10, 6};
    //printf("p1: (%.2f, %.2f)\n", p1.x, p1.y);
    printf("p1: "); //(%.2f, %.2f)\n", p1.x, p1.y);
    mostrar(p1);

    p1.x += 10;
    p1.y -= 5;
    
    //printf("p1: (%.2f, %.2f)\n", p1.x, p1.y);
    printf("p1: "); //(%.2f, %.2f)\n", p1.x, p1.y);
    mostrar(p1);

    ponto p2;
    p2.x = 100;
    p2.y = -50;
    //printf("p2: (%.2f, %.2f)\n", p2.x, p2.y);
    printf("p2: "); //(%.2f, %.2f)\n", p2.x, p2.y);
    mostrar(p2);

    p2.x += 10;
    p2.y -= 5;
    
    //printf("p2: (%.2f, %.2f)\n", p2.x, p2.y);
    printf("p2: "); //(%.2f, %.2f)\n", p2.x, p2.y);
    mostrar(p2);

    return 0;
}