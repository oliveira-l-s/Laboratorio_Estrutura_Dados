#include <stdio.h>
#include <stdlib.h>

/* Structs
 * - Declaração e definição
 * - Redefinição de tipo (typedef)
 * - Alocação estática versus alocação dinâmica
 * - Passagem de parâmetros por valor e por referência
 * - Protótipo de funções: declaração
 * - Desalocação (liberação) de memória
 */

typedef struct pto {
    float x;
    float y;
} ponto;

ponto* criar(float x, float y);
void mostrar(ponto *p);
void mover(ponto *p, float dx, float dy);

int main() {
    /*struct pto *p1 = (ponto*) malloc(sizeof(ponto));
    (*p1).x = 10;
    (*p1).y = 15;*/
    ponto *p1 = criar(10, 15);
    printf("p1: ");
    mostrar(p1);

    mover(p1, 10, -5);
    
    printf("p1: ");
    mostrar(p1);

    //ponto *p2 = (ponto*) calloc(1, sizeof(ponto));
    ponto *p2 = criar(0, 0);
    mover(p2, 100, -50);
    printf("p2: ");
    mostrar(p2);

    mover(p2, 10, -5);
    
    printf("p2: ");
    mostrar(p2);

    free(p1);
    free(p2);

    return 0;
}

ponto* criar(float x, float y) {
    ponto *novo = (ponto*) calloc(1, sizeof(ponto));
    novo->x = x;
    novo->y = y;
    return novo;
}

void mostrar(ponto *p) {
    printf("(%.2f, %.2f)\n", p->x, p->y);
}

void mover(ponto *p, float dx, float dy) {
    p->x += dx;
    p->x += dy;
}