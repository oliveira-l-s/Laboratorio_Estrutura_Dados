#ifndef LISTA_CIRC_INTEIROS_H
#define LISTA_CIRC_INTEIROS_H

typedef struct lista lista;

int busca_lc(lista* l, int e); // retornar o índice ou -1
int capacidade_lc(lista *l);
lista* criar_lc();
int esta_cheia_lc(lista* l);
int esta_vazia_lc(lista* l);
void exibir_lc(lista* l);
void exibir_n_vezes_lc(lista* l, int n);
int inserir_lc(lista* l, int e);
void liberar_lc(lista** l);
int remover_lc(lista* l, int *v);
int tamanho_lc(lista* l);

#endif // LISTA_CIRC_INTEIROS_H
