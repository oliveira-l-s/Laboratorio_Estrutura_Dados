#include <stdio.h>

int main() {
    // Ponteiros
    int a, b,   // tipo: int
        *c;     // tipo: ponteiro para int => armazena um endereço de memória

    a = 10;
    b = 5;
    c = &a;     // operador de referência => devolver o endereço (referência) da variável

    printf("Conteudo de a: %d\n", a);
    printf("Endereco de a: %p\n", &a);
    printf("Conteudo de b: %d\n", b);
    printf("Endereco de b: %p\n", &b);
    printf("Conteudo de c: %p\n", c);
    printf("Endereco de c: %p\n", &c);
    printf("\n");

    *c = -11;   // * é um operador de dereferenciação, ou seja, acessa o "conteúdo" da variável
                // => b = &a => *b = *(&a) => * cancela o operador & => *&a = a

    printf("Conteudo de a: %d\n", a);
    printf("Endereco de a: %p\n", &a);
    printf("Conteudo de b: %d\n", b);
    printf("Endereco de b: %p\n", &b);
    printf("Conteudo de c: %p\n", c);
    printf("Endereco de c: %p\n", &c);
    printf("\n");

    b = *c;

    printf("Conteudo de a: %d\n", a);
    printf("Endereco de a: %p\n", &a);
    printf("Conteudo de b: %d\n", b);
    printf("Endereco de b: %p\n", &b);
    printf("Conteudo de c: %p\n", c);
    printf("Endereco de c: %p\n", &c);
    printf("\n");

    c = &b;
    *c = 99;

    printf("Conteudo de a: %d\n", a);
    printf("Endereco de a: %p\n", &a);
    printf("Conteudo de b: %d\n", b);
    printf("Endereco de b: %p\n", &b);
    printf("Conteudo de c: %p\n", c);
    printf("Endereco de c: %p\n", &c);
    printf("\n");

    return 0;
}