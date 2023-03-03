// incluindo as bibliotecas
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int m, n, count = 0; // declarando três variáveis do tipo int e inicializando a variável count
    char **mapa;         // delcarando uma variável do tipo char sendo ponteiro para ponteiro

    printf("Informe a quantidade de linhas: "); // pedi para o usuário informar a quantidade de linhas
    scanf("%d", &m);
    printf("Informe a quantidade de colunas: "); // e a quantidade de colunas
    scanf("%d", &n);

    if (m < 1 || n >= 1000) // fiz um if para quando m for menor e n maior ou igual a 0 imprima um mensagem de erro
    {
        return printf("\nErro!");
    }

    mapa = (char **)malloc(m * sizeof(char *)); // aloquei dinâmicamente a variável mapa

    for (int i = 0; i < m; i++) // fiz um for para alocar um espaço na memória com o tamanho das colunas
    {
        mapa[i] = malloc(n * sizeof(char));
    }

    for (int i = 0; i < m; i++) // criei um for para o usuário preencher cada espaço da matriz
    {
        printf("Informe os caracteres da %d linha:\n", i + 1);
        for (int j = 0; j < n; j++)
        {
            scanf("%s", &mapa[i][j]);
        }
        printf("\n");
    }

    for (int linha = 0; linha < m; linha++) // fiz dois for para comparar cada linha e coluna
    {
        for (int coluna = 0; coluna < n; coluna++)
        {
            if (linha == 0) // se cada comparação desse for verdadeira vai ser adicionado 1 a variável count
            {
                if ((mapa[linha][coluna] == '#' && mapa[linha][coluna + 1] == '.') || (mapa[linha][coluna] == '#' && mapa[linha][coluna - 1] == '.'))
                {
                    count++;
                }
                else if ((mapa[linha][coluna] == '#' && mapa[linha + 1][coluna] == '.'))
                {
                    count++;
                }
            }
            else if (linha > 0 && linha < m - 1)
            {
                if ((mapa[linha][coluna] == '#' && mapa[linha][coluna + 1] == '.') || (mapa[linha][coluna] == '#' && mapa[linha][coluna - 1] == '.'))
                {
                    count++;
                }
                else if ((mapa[linha][coluna] == '#' && mapa[linha + 1][coluna] == '.') || (mapa[linha][coluna] == '#' && mapa[linha - 1][coluna] == '.'))
                {
                    count++;
                }
            }
            else if (linha == m - 1)
            {
                if ((mapa[linha][coluna] == '#' && mapa[linha][coluna + 1] == '.') || (mapa[linha][coluna] == '#' && mapa[linha][coluna - 1] == '.'))
                {
                    count++;
                }
                else if ((mapa[linha][coluna] == '#' && mapa[linha - 1][coluna] == '.'))
                {
                    count++;
                }
            }
        }
    }
    printf("\nQuantidade de quadrados do territorio que fazem parte da costa da Nlogonia: %d.", count); // imprimindo a quantidade de quadrados do territorio
    for (int i = 0; i < m; i++)
    {
        free(mapa[i]);
    }
    free(mapa);

    return 0;
}