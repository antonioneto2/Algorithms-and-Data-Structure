// incluindo as bibliotecas
#include <stdio.h>
#include <stdlib.h>

// delcarando a função principal
int main()
{
    int qtd_frutas, linha;                                        // declarando duas variáveis do tipo int
    float soma = 0;                                               // declarando uma variável do tipo float e inicalizando ela
    printf("Digite a quantidade de frutas: ");                    // impirindo uma mensagem para o usuário
    scanf("%d", &qtd_frutas);                                     // pedindo para o usuário digitar a quantidade de frutas
    char **frutas = (char **)malloc(qtd_frutas * sizeof(char *)); // declarando uma variável do tipo char e alocando dinamicamente
    if (frutas == NULL)                                           // testando se a alocação deu certo
    {
        printf("Erro!"); // Imprimindo uma mensagem de erro caso a alocação falhe
        exit(1);
    }

    for (linha = 0; linha < qtd_frutas; linha++) // criei um for para definir a quantidade de linhas e aloquei dinâmicamente
    {
        frutas[linha] = (char *)malloc(50 * sizeof(char));
    }

    float *valor = (float *)malloc(qtd_frutas * sizeof(float)); // aloquei dinamicante a variável valor, com o tamanho da quantidade de frutas
    if (valor == NULL)                                          // testei novamente
    {
        printf("Erro!");
        exit(1);
    }

    printf("Informe as frutas e os seus valores: \n"); // pedi para o usuário informar as frutas e seus valores, e para isso criei um for
    for (linha = 0; linha < qtd_frutas; linha++)
    {
        printf("Nome da fruta: ");
        scanf(" %[^\n]s ", frutas[linha]);
        printf("Valor: ");
        scanf(" %f", &valor[linha]);
        soma += valor[linha];
    }

    for (linha = 0; linha < qtd_frutas; linha++) // fiz um for para realocar o tamanho de caracteres da minha matriz frutas
    {
        frutas[linha] = (char *)realloc(frutas[linha], 50 * sizeof(char));
    }

    printf("\nSeu pedido:"); // criei um for para mostrar quais as frutas o usuário digitou e seu preço
    for (linha = 0; linha < qtd_frutas; linha++)
    {
        printf("\n%s - R$%.2f", frutas[linha], valor[linha]);
    }

    printf("\nValor final: R$%.2f", soma); // imprimi o valor da somatoria de todas as frutas

    for (linha = 0; linha < qtd_frutas; linha++) // fiz um for para liberar a memória da matriz
    {
        free(frutas[linha]);
    }

    free(frutas); // liberando a memória
    free(valor);  // liberando a memória

    return 0;
} // fim