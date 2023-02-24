// incluindo as bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// função proincipal
int main()
{
    int tamanho = 10;                                  // declarando a variável do tipo int, que será o tamanho do vetor
    int i;                                             // declarando o contador
    int *vetor = (int *)malloc(tamanho * sizeof(int)); // alocando dinâmicamente o vetor
    if (vetor == NULL)                                 // testando se a alocação foi feita com sucesso
    {
        printf("ERRO!"); // imprimindo mensagem de erro caso a alocação tenha sido mal sucedida
        exit(1);
    }
    for (i = 0; i < tamanho; i++) // for para preencher o vetor
    {
        vetor[i] = i;
    }
    for (i = 0; i < tamanho; i++) // for para imprimir cada posição do vetor
    {
        printf("%d\t", vetor[i]);
    }
    free(vetor); // liberando espaço do vetor
    return 0;
}