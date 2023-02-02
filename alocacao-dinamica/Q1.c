#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int tamanho = 10;
    int i;
    int *vetor = (int *)malloc(tamanho * sizeof(int));
    if (vetor == NULL)
    {
        printf("ERRO!");
        exit(1);
    }
    for (i = 0; i < tamanho; i++)
    {
        vetor[i] = i;
    }
    for (i = 0; i < tamanho; i++)
    {
        printf("%d\t", vetor[i]);
    }
    free(vetor);
}