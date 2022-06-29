#ifndef PILHA_H
#define PILHA_H

/** @file lista_seq.h
 *  @brief Interface de uma lista linear sequencial
 *
 *  Este arquivo contém a interface do tipo e das funções definidas
 *  para uma lista linear sequencial.
 *
 *  @author Anderson Grandi Pires
 *  @bug Nenhum bug conhecido
 */

// Interface da pilha

// Tipo de dados
typedef struct lst pilha;

/*
Cria uma nova pilha com a capacidade cap e a retorna
Entrada: cap indica o número máximo de valores que a pilha poderá ter
Saída: retorna uma pilha com capacidade igual a cap
*/
pilha* criar_pilha(int cap);

/*
Verifica se a pilha está vazia
Entrada: pilha l
Saída: verdadeiro caso a pilha esteja vazia
       falso caso contrário
*/
int esta_vazia_pilha(pilha* p);

/*
Esvazia uma pilha
Entrada: pilha p
Saída: verdadeiro caso a pilha tenha sido esvaziada
       falso caso contrário
*/
int esvaziar_pilha(pilha *p);

/*
Retorna o topo da pilha
Entrada: pilha p
Saída: item do topo da pilha
*/
int topo_pilha(pilha *p);

/*
Libera a memória alocada para a pilha
Entrada: pilha p
Saída: verdadeiro caso a pilha tenha sido liberada com sucesso
       falso caso contrário
*/
int liberar_pilha(pilha **p);

/*
Insere valor na pilha
Entrada: pilha p e o valor a ser inserido
Saída: verdadeiro caso a inserção tenha ocorrido com sucesso
       falso caso contrário
*/
int inserir_pilha(pilha *p, int valor);

/*
Remove um elemento da pilha
Entrada: pilha p
Saída: verdadeiro caso a remoção tenha ocorrido com sucesso
       falso caso contrário
*/
int remover_pilha(pilha *p);

#endif // PILHA_H