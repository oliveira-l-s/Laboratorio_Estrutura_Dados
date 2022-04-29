#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stddef.h>
#include "ponto.h"

struct pto {
    float x;
    float y;
};

float calc_dist_ptos(ponto *p1, ponto *p2) {
    return sqrt(pow(p2->y - p1->y, 2) + pow(p2->x - p1->x, 2));
}

ponto* criar_pto(float x, float y) {
    ponto *novo = (ponto*) calloc(1, sizeof(ponto));
    novo->x = x;
    novo->y = y;
    return novo;
}

void mostrar_pto(ponto *p) {
    printf("(%.2f, %.2f)\n", p->x, p->y);
}

void mover_pto(ponto *p, float dx, float dy) {
    p->x += dx;
    p->x += dy;
}

void liberar_pto(ponto **p) {
    free(*p);
    *p = NULL;
}
