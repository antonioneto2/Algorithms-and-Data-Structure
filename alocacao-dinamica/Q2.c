#include <stdio.h>
#include <stdlib.h>

int main()
{
    int linhas = 3;
    int colunas = 3;
    int **matriz = (int **)malloc(linhas * sizeof(int *));
    int linha;
    for (linha = 0; linha < linhas; linha++)
    {
        matriz[linha] = (int *)malloc(colunas * sizeof(int));
    }
    int i, j;
    printf("Digite os valores para matriz: \n");
    for (i = 0; i < linhas; i++)
    {
        for (j = 0; j < colunas; j++)
            ;
        {
            scanf("%f", &matriz[i][j]);
        }
    }
    for (linha = 0; linha < linhas; linha++)
    {
        free(matriz[linha]);
    }
    free(matriz);

    return 0;
}