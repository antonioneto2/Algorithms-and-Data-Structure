#include <stdio.h>
#include <string.h>

// Cria Enum Genero
typedef enum genero
{
    masculino,
    feminino
} Genero;

typedef struct pessoa
{
    char nome[50];
    int idade;
    Genero genero;
} Pessoa;

int main()
{
    Pessoa pessoa;
    printf("Digite seu nome: ");
    scanf(" %[^\n]s", pessoa.nome);
    printf("Digite sua idade: ");
    scanf("%d", &pessoa.idade);
    printf("Digite seu genero (0-MASCULINO ou 1-FEMININO) ");
    scanf("%d", (int *)&pessoa.genero);
    if (pessoa.genero == 0)
    {
        printf("Nome: %s | Idade: %d | Genero: Masculino ", pessoa.nome, pessoa.idade);
    }
    else
    {
        printf("Nome: %s | Idade: %d | Genero: Feminino ", pessoa.nome, pessoa.idade);
    }
    return 0;
}