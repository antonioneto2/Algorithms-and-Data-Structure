// incluindo as bibliotecas
#include <stdio.h>
#include <stdlib.h>

// função principal
int main()
{
    int tamanho = 10;                                  // declarando a variável do tipo int, que será o tamanho do vetor
    int *vetor = (int *)malloc(tamanho * sizeof(int)); // alocando dinâmicamente o vetor

    for (int i = 0; i < tamanho; i++) // for para inializar o vetor
    {
        *(vetor + i) = i;
        printf("%d ", *(vetor + i)); // imprimindo o vetor
    }

    free(vetor); // liberando espaço na memória
    return 0;
}