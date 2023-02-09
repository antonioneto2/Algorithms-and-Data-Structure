#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct pessoa
{
    char nome[50];
    float documento;
    int idade;
} Pessoa;

void cadastra_pessoas(Pessoa *pessoa, int qtdPessoas)
{
    int i;
    for (i = 0; i < qtdPessoas; i++)
    {
        printf("Digite o nome da pessoa %d: \n", i + 1);
        scanf(" %[^\n]s", pessoa[i].nome);
        printf("Digite o documento da pessoa %d: \n", i + 1);
        scanf("%f", &pessoa[i].documento);
        printf("Digite a idade da pessoa %d: \n", i + 1);
        scanf("%d", &pessoa[i].idade);
    }
}

void imprime_pessoas(Pessoa *pessoa, int qtdPessoas)
{
    int i;
    for (i = 0; i < qtdPessoas; i++)
    {
        printf("Pessoa %d: \n", i + 1);
        printf("Nome: %s | Documento: %.1f | Idade: %d \n", pessoa[i].nome, pessoa[i].documento, pessoa[i].idade);
    }
}

void altera_idade(Pessoa *pessoa, int qtdPessoas)
{
    int id, i;
    float documento;
    printf("Digite o documento da pessoa a ter sua idade alterada: \n");
    scanf("%f", &documento);
    for (i = 0; i < qtdPessoas; i++)
    {
        if (pessoa[i].documento == documento)
        {
            printf("Digite a nova idade da pessoa %d: \n", i + 1);
            scanf("%d", &pessoa[i].idade);
        }
    }
}

void imprime_maior_menor_idade(Pessoa *pessoa, int qtdPessoas)
{
    int i;
    int maiorIdade = 0;
    int menorIdade = 9999;
    char nomePessoaVelha[20];
    char nomePessoaNova[20];
    for (i = 0; i < qtdPessoas; i++)
    {
        if (pessoa[i].idade > maiorIdade)
        {
            maiorIdade = pessoa[i].idade;
            strcpy(nomePessoaVelha, pessoa[i].nome);
        }
        if (pessoa[i].idade < menorIdade)
        {
            menorIdade = pessoa[i].idade;
            strcpy(nomePessoaNova, pessoa[i].nome);
        }
    }
    printf("Pessoa com maior idade: %s (%d anos)\n", nomePessoaVelha, maiorIdade);
    printf("Pessoa com menor idade: %s (%d anos)\n", nomePessoaNova, menorIdade);
}

int main(void)
{
    int qtdPessoas, i;
    printf("Digite a quantidade de pessoas que deseja cadastrar: \n");
    scanf("%d", &qtdPessoas);

    Pessoa *pessoa = (Pessoa *)malloc(qtdPessoas * sizeof(Pessoa));
    if (pessoa == NULL)
    {
        printf("Memória insuficiente.");
        exit(1);
    }

    cadastra_pessoas(pessoa, qtdPessoas);
    imprime_pessoas(pessoa, qtdPessoas);
    altera_idade(pessoa, qtdPessoas);
    imprime_maior_menor_idade(pessoa, qtdPessoas);

    free(pessoa);
    return 0;
}