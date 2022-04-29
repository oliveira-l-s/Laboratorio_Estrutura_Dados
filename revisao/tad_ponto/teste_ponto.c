#include <stdio.h>
#include <stdlib.h>
#include "../TADs/ponto.h"

int main() {
    ponto *p1 = criar_pto(10, 15);
    printf("p1: ");
    mostrar_pto(p1);

    mover_pto(p1, 10, -5);
    
    printf("p1: ");
    mostrar_pto(p1);

    ponto *p2 = criar_pto(0, 0);
    mover_pto(p2, 100, -50);
    printf("p2: ");
    mostrar_pto(p2);

    mover_pto(p2, 10, -5);
    
    printf("p2: ");
    mostrar_pto(p2);

    ponto *origem = criar_pto(0, 0);
    float dist = calc_dist_ptos(p1, origem);
    printf("Distancia de p1 para origem: %.2f\n", dist);

    printf("Distancia de p1 para p2: %.2f", calc_dist_ptos(p1, p2));

    liberar_pto(&p1);
    liberar_pto(&p2);

    return 0;
}