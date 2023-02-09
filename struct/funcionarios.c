#include <stdio.h>
#include <stdlib.h>

typedef struct funcionario
{
    char nome[50];
    float salario;
    int id;
    char cargo[50];
} Funcionario;

void preenche(Funcionario *dados, int qtd)
{
    int index;
    for (index = 0; index < qtd; index++)
    {
        printf("Digite o nome do funcionario %d: ", index + 1);
        scanf(" %[^\n]s", dados[index].nome);
        printf("Digite o salario do funcionario %d: ", index + 1);
        scanf("%.2f", &dados[index].salario);
        printf("Digite o cargo do funcionario %d: ", index + 1);
        scanf(" %[^\n]s", dados[index].cargo);
        printf("Digite o identificador do funcionario %d: ", index + 1);
        scanf("%d", &dados[index].id);
    }
}

void imprime(Funcionario *imprime, int qtd)
{
    int index;
    for (index = 0; index < qtd; index++)
    {
        printf("\n");
        printf("O nome do %d funcionario e %s \n", index + 1, imprime[index].nome);
        printf("O salario do %d funcionario e %f \n", index + 1, imprime[index].salario);
        printf("O cargo do %d funcionario e %s \n", index + 1, imprime[index].cargo);
        printf("O identificador do %d funcionario e %d ", index + 1, imprime[index].id);
    }
}

int main()
{
    int qtd_funcionario;
    printf("Informe a quatidade de funcionario: ");
    scanf("%d", &qtd_funcionario);
    Funcionario *dados_funcionario = (Funcionario *)malloc(qtd_funcionario * sizeof(Funcionario));
    preenche(dados_funcionario, qtd_funcionario);
    imprime(dados_funcionario, qtd_funcionario);
}