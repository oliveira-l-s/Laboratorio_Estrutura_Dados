#ifndef ABB_ENC_H    // INCLUDE GUARD
#define ABB_ENC_H

// INTERFACE DA ARVORE BINÁRIA DE BUSCA (ABB) ENCADEADA DE INTEIROS

typedef struct no no;
typedef struct arv arvore;

int adicionar_no_arv(arvore* a, int valor);

void busca_largura(arvore* a);

int buscar_arv(arvore* a, int valor);

arvore* criar_arv(int valor_raiz);
no* criar_no(int valor);

void em_ordem_arv(no *n);

no* get_raiz_arv(arvore* a);

void liberar_arv(arvore** a);
void liberar_no_arv(no** no);

void pre_ordem_arv(no *n);
void pos_ordem_arv(no *n);

int remover_arv(arvore* a, int valor);

no* sae_arv(no* n);
no* sad_arv(no* n);

#endif // ARVORE_ENC_H