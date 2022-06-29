#ifndef FILA_ENC
#define FILA_ENC

typedef struct c celula;   // célula

typedef struct fila fila;

/*
Cria uma nova fila com a capacidade cap e a retorna
Entrada: cap indica o número máximo de valores que a fila poderá ter
Saída: retorna uma fila com capacidade cap
*/
fila* criar_fila();

/*
Verifica fila vazia
Entrada: fila f
Saída: verdadeiro caso a fila estiver vazia
       falso caso contrário
*/
int esta_vazia_fila(fila* f);

/*
 Retorna o valor presente na frente da fila
 Entrada: fila f
 Saída: elemento que se encontra na frente da fila, caso a fila
       não esteja vazio (comportamento inesperado para fila vazia)
*/
int frente_fila(fila* f);

/*
Entrada: fila f e o valor a ser inserido
Saída: verdadeiro caso a inserção tenha ocorrido com sucesso
       falso caso contrário
*/
int inserir_fila(fila* f, int valor);

/*
Libera a memória alocada para a fila
Entrada: fila f
Saída: verdadeiro caso a fila tenha sido liberada com sucesso
       falso caso contrário
*/
void liberar_fila(fila** f);

/*
Remove um elemento da fila
Entrada: fila f
Saída: verdadeiro caso a remoção tenha ocorrido com sucesso
       falso caso contrário
*/
int remover_fila(fila* f);

/*
Informa o tamanho da fila
Entrada: fila f
Saída: verdadeiro caso a remoção tenha ocorrido com sucesso
       falso caso contrário
*/
int tamanho_fila(fila* f);

#endif  // FILA_ENC