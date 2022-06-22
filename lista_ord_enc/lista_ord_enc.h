#ifndef LISTA_ORD_ENC
#define LISTA_ORD_ENC

typedef struct no no;

typedef struct lista lista;

int busca_seq_lst(lista* l, int valor, int* pos);

lista* criar_lst();
static no* criar_no(int);

int esta_vazia_lst(lista* l);
void exibir_lst(lista* l);

int inserir_lst(lista* l, int valor);

void liberar_lst(lista** l);

int remover_lst(lista* l, int* valor, int pos);

int tamanho_lst(lista* l);

#endif  // LISTA_ORD_ENC