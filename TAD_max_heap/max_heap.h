#ifndef max_heap_H
#define max_heap_H

// Interface de uma max-heap

typedef struct heap heap;

heap* criar_heap(int n);

int esta_cheia_heap(heap* h);
int esta_vazia_heap(heap* h);
int esvaziar_heap(heap* l);
void exibir_heap(heap *h);

int inserir_heap(heap *h, unsigned int v);
void inserir_vetor_heap(heap *h, int* vetor, unsigned int n);

void liberar_heap(heap** l);

int remover_heap(heap *h);

#endif //heap_H