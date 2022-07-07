#include <stdio.h>
#include <stdlib.h>
#include "abb_enc.h"

/* int nos[] = {6, 7, 9, 4, 8, 2, 10, 5, 3, 1};
              6
        4          7
     2     5          9
   1   3            8   10

   Pré-ordem: 6 4 2 1 3 5 7 9 8 10
   Em-ordem: 1 2 3 4 5 6 7 8 9 10
   Pós-ordem: 1 3 2 5 4 8 10 9 7 6
   Busca em largura: 6 4 7 2 5 9 1 3 8 10
*/

int main() {
    /*
               3
        1             7
           2     4           9
                   5      8     10 
                     6
    */
    int nos[] = {3, 7, 4, 1, 2, 9, 10, 5, 6, 8};
    int i, qtde_nos = sizeof(nos)/sizeof(int);

    arvore* a = criar_arv(nos[0]);

    for(i = 1; i < qtde_nos; i++)
        adicionar_no_arv(a, nos[i]);

    no* r = get_raiz_arv(a);
    if(r != NULL) {
        printf("Percurso em pre-ordem: ");
        pre_ordem_arv(r);
        printf("\n");

        printf("Percurso em em-ordem: ");
        em_ordem_arv(r);
        printf("\n");

        printf("Percurso em pos-ordem: ");
        pos_ordem_arv(r);
        printf("\n");

        printf("Busca em largura: ");
        busca_largura(a);
        printf("\nBusca em profundidade: ");
        printf("\n");

        for(i = 0; i < qtde_nos; i++) {
            int b = nos[i];
            if(buscar_arv(a, b))
                printf("\nValor %d esta na arvore\n", b);
            else
                printf("\nValor %d nao encontrado\n", b);
        }
        
        printf("\n");
        for(i = 0; i < qtde_nos; i++) {
            int b = i*2;
            if(buscar_arv(a, b))
                printf("\nValor %d esta na arvore\n", b);
            else
                printf("\nValor %d nao encontrado\n", b);
        }
    }

    liberar_arv(&a);
    printf("\nArvore liberada: %s\n", (a == NULL ? "Sim" : "Nao"));
    return 0;
}
