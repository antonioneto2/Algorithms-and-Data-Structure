#include <stdio.h>
#include <stdlib.h>

int **criaMtrizFloat(int linhas, int colunas)
{
    int **matriz = (int **)malloc(linhas * sizeof(int *));
    int linha;
    for (linha = 0; linha < linhas; linha++)
    {
        matriz[linha] = (int *)malloc(colunas * sizeof(int));
    }
    return matriz;
}

int main()
{
    int linhas = 2;
    int colunas = 2;
    int **matriz = criaMtrizFloat(linhas, colunas);
    int i, j;
    printf("Digite os valores para matriz: \n");
    for (i = 0; i < linhas; i++)
    {
        for (j = 0; j < colunas; j++)
        {
            matriz[i][j] = i * 3 + j;
        }
    }
    for (i = 0; i < linhas; i++)
    {
        for (j = 0; j < colunas; j++)
        {
            printf("%d\t", matriz[i][j]);
        }
    }
    return 0;
}
