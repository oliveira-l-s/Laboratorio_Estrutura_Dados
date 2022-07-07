// INCLUDE GUARD
#ifndef FILA_H
#define FILA_H

#define VERDADEIRO 1
#define FALSO 0
#define ERRO -1

typedef struct fila fila;
typedef struct no no;

int capacidade_f(fila*);
fila* criar_f(int capacidade); // lista* criar(void);
int esta_vazia_f(fila *f);
int esta_cheia_f(fila *f);
int enfileirar_f(fila *f, no* no);
no* frente_f(fila *f);
void liberar_f(fila **f);
int desenfileirar_f(fila *f);
int tamanho_f(fila *f);

#endif // FILA_H