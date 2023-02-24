// incluindo as bibliotecas
#include <stdio.h>
#include <string.h>

// Cria Enum Genero
typedef enum genero
{
    masculino,
    feminino
} Genero;

typedef struct pessoa // crinado uma struct e renomeandoa
{
    char nome[50];
    int idade;
    Genero genero;
} Pessoa;

// função principal
int main()
{
    Pessoa pessoa; // declarando um variável do tipo Pessoa
    // pedindo para o usuário preencher as variáveis da estruct
    printf("Digite seu nome: ");
    scanf(" %[^\n]s", pessoa.nome);
    printf("Digite sua idade: ");
    scanf("%d", &pessoa.idade);
    printf("Digite seu genero (0-MASCULINO ou 1-FEMININO) ");
    scanf("%d", (int *)&pessoa.genero); // forçando ler um inteiro
    if (pessoa.genero == 0)             // comparando com 0, se igual imprime na tela
    {
        printf("Nome: %s | Idade: %d | Genero: Masculino ", pessoa.nome, pessoa.idade);
    }
    else
    {
        printf("Nome: %s | Idade: %d | Genero: Feminino ", pessoa.nome, pessoa.idade);
    }
    return 0;
} // fim