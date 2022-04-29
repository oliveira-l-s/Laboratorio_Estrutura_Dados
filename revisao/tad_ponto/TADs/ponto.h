#ifndef PONTO_H
#define PONTO_H

typedef struct pto ponto;

ponto* criar_pto(float x, float y);
float calc_dist_ptos(ponto *p1, ponto *p2);
void liberar_pto(ponto **p);
void mostrar_pto(ponto *p);
void mover_pto(ponto *p, float dx, float dy);

#endif  // PONTO_H