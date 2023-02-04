#include <stdio.h>
#include <stdlib.h>

int main()
{

    int qtn_frutas, linha;
    printf("Digite a quantidade de frutas:");
    scanf("%d", &qtn_frutas);

    char **frutas = (char **)malloc(qtn_frutas * sizeof(char *));
    if (frutas == NULL)
    {
        printf("Erro de memoria");
        exit(1);
    }
    for (linha = 0; linha < frutas; linha++)
    {
        frutas[linha] = (char *)malloc(50 * sizeof(char));
    }

    float *preco = (float *)malloc(qtn_frutas * sizeof(float));
    if (preco == NULL)
    {
        exit(1);
    }
    printf("Informe as frutas e seu valor:");
    for (linha = 0; linha < qtn_frutas; linha++)
    {
        scanf(" %[^\n]s", frutas[linha]);
        scanf("%f", &preco[linha]);
    }
    return 0;
}