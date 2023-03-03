#include <stdio.h>

int main()
{
    int x, *p; // declaração de uma variável x inteira, e um ponteiro 'p' do tipo inteiro
    x = 100;   // a variável x está recebendo o valor 100
    p = &x;    // o ponteiro p está apontado para x

    printf("Valor de p = %p\tValor de *p = %d", p, *p); // imprindo o valor de p e o conteúdo de p
    return 0;
}
