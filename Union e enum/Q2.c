#include <stdio.h>
#include <string.h>

// Define a union Tipo para armazenar os tipos de produtos
typedef union
{
    char alimento[20];
    char bebida[20];
    char eletronico[20];
} Tipo;

// Define a struct Produto com os campos nome, preço e tipo
struct Produto
{
    char nome[50];
    float preco;
    Tipo tipo;
};

int main()
{
    // Declaração de uma variável do tipo Produto
    struct Produto produto;

    // Leitura dos dados do produto
    printf("Digite o nome do produto: ");
    scanf("%s", produto.nome);

    printf("Digite o preco do produto: ");
    scanf("%f", &produto.preco);

    printf("Digite o tipo do produto (ALIMENTO, BEBIDA ou ELETRONICO): ");
    char tipo[20];
    scanf("%s", tipo);

    // Verifica o tipo do produto e armazena na union Tipo
    if (strcmp(tipo, "ALIMENTO") == 0)
    {
        strcpy(produto.tipo.alimento, tipo);
    }
    else if (strcmp(tipo, "BEBIDA") == 0)
    {
        strcpy(produto.tipo.bebida, tipo);
    }
    else if (strcmp(tipo, "ELETRONICO") == 0)
    {
        strcpy(produto.tipo.eletronico, tipo);
    }
    else
    {
        printf("Tipo de produto invalido!\n");
        return 1;
    }

    // Imprime os dados do produto
    printf("\nDados do produto:\n");
    printf("Nome: %s\n", produto.nome);
    printf("Preco: R$ %.2f\n", produto.preco);
    printf("Tipo: %s\n", tipo);

    return 0;
}
