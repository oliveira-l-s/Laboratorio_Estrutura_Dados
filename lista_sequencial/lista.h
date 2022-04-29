/** @file lista.h
 *  @brief Interface de uma lista linear sequencial
 *
 *  Este arquivo contém os protótipos das funções disponibilizadas
 *  para uma lista linear. Constantes simbólicas foram definidas para
 *  os valores lógicos verdadeiro e falso, além de um código de erro.
 *
 *  @author Anderson Grandi Pires
 *  @bug Nenhum bug conhecido
 */

// INCLUDE GUARD
#ifndef LISTA
#define LISTA

#define VERDADEIRO 1
#define FALSO 0
#define ERRO -1

typedef struct lista lista;

int buscar_lst(lista *l, int valor);
int capacidade_lst(lista *l);
lista* criar_lst(int capacidade); // lista* criar(void);
int esta_vazia_lst(lista *l);
int esta_cheia_lst(lista *l);
void exibir_lst(lista *l);
int inserir_inicio_lst(lista *l, int valor);
int inserir_meio_lst(lista *l, int valor, int pos);
int inserir_fim_lst(lista *l, int valor);
void liberar_lst(lista **l);
int remover_inicio_lst(lista *l, int *valor_removido);
int remover_meio_lst(lista *l, int *valor_removido, int pos);
int remover_fim_lst(lista *l, int *valor_removido);
int tamanho_lst(lista *l);

#endif // LISTA