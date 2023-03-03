// incluindo as bibliotecas
#include <stdio.h>
#include <stdlib.h>

// criei uma função do tipo int para criar uma matriz
// criei como parametro as variáveis linhas e colunas
int **criaMtrizInt(int linhas, int colunas)
{
    int **matriz = (int **)malloc(linhas * sizeof(int *)); // aloquei dinâmicamente a matriz
    int linha;
    for (linha = 0; linha < linhas; linha++)
    {
        matriz[linha] = (int *)malloc(colunas * sizeof(int));
    }
    return matriz;
}

// função principal
int main()
{
    int linhas = 3;                               // declarei a variável linhas do tipo int i inicializei
    int colunas = 3;                              // declarei a variável colunas do tipo int i inicializei
    int **matriz = criaMtrizInt(linhas, colunas); // como minha função é um ponteiro para ponteiro, declarei a variável matriz também ponterio e passei o parametro linhas e colunas
    int i, j;                                     // declarei as variáveis para o contador de linhas e colunas
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
