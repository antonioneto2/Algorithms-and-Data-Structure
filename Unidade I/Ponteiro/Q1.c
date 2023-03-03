// Esssa pedia somente para analisar o código e descrever qual a saída ele darias
#include <stdio.h>

int main()
{
    int x, y, *p; // declaração de variáveis inteiras, 'x' e 'y', e um ponteiro 'p' do tipo inteiro
    y = 0;        // a variável y recebe o valor 0
    p = &y;       // o ponteiro 'p' recebe o endereço de y
    x = *p;       // x recebe o conteúdo de p, que é 0, pois p está apontado para y, então o conteúdo dele é o que está em y
    x = 4;        // x que antes era 0, agora recebe 4
    (*p)++;       // o conteúdo de p recebe um incremento, que é a mesma coisa de y+1
    --x;          // o que está em x recebe um decremento, que é o que tem em x-1
    (*p) += x;    // o conteúdo de p, recebe o que está em p mais o que está em x, (*p+x)

    printf("%d %d %d", x, y, *p); // imprimindo o valor de x, y e p
    return 0;
}