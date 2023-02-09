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
        printf("Digite o nome do funcionario %d: \n", index + 1);
        scanf(" %[^\n]s", dados[index].nome);
        printf("Digite o salario do funcionario %d: \n", index + 1);
        scanf(" %f", &dados[index].salario);
        printf("Digite o cargo do funcionario %d: \n", index + 1);
        scanf(" %[^\n]s", dados[index].cargo);
        printf("Digite o Id do funcionario %d: \n", index + 1);
        scanf("%d", &dados[index].id);
    }
}

void imprime(Funcionario *imprime, int qtd)
{
    int index;
    for (index = 0; index < qtd; index++)
    {
        printf("\n");
        printf("Funcionario %d | Nome: %s | Salario: %.2f | Cargo: %s | Id: %d", index + 1, imprime[index].nome, imprime[index].salario, imprime[index].cargo, imprime[index].id);
    }
}

void muda_salario(Funcionario *sal, int quant)
{
    int i, alteracao;
    printf("\n");
    printf("deseja alterar o valor do salario dos funcionarios?(use 1 para sim e 2 para nao)\n");
    scanf("%d", &alteracao);
    if (alteracao == 2)
    {
        printf("o salario nao foi alterado");
    }
    else
    {
        for (i = 0; i < quant; i++)
        {
            printf("digite o novo salario do %d funcionario: ", i + 1);
            scanf("%f", &sal[i].salario);
        }
    }
}

void maior_salario(Funcionario *maiorsal, int quant)
{
    int i;
    float maiors = 0;
    char mcargo[50];
    for (i = 0; i < quant; i++)
    {
        if (maiorsal[i].salario > maiors)
        {
            maiors = maiorsal[i].salario;
            strcpy(mcargo, maiorsal[i].cargo);
        }
    }
    printf("\n");
    printf("o cargo da pessoa com o maior salario e: %s e o salario dessa pessoa e: %f\n", mcargo, maiors);
}

int main()
{
    int qtd_funcionario;
    printf("Informe a quatidade de funcionario: ");
    scanf("%d", &qtd_funcionario);
    Funcionario *dados_funcionario = (Funcionario *)malloc(qtd_funcionario * sizeof(Funcionario));
    preenche(dados_funcionario, qtd_funcionario);
    imprime(dados_funcionario, qtd_funcionario);
    muda_salario(dados_funcionario, qtd_funcionario);
    maior_salario(dados_funcionario, qtd_funcionario);
}