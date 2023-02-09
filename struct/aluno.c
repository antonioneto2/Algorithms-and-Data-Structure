#include <stdio.h>
#include <stdlib.h>

typedef struct aluno
{
    char nome[50];
    int matricula;
    float IRA;
} Aluno;

void imprime(Aluno *aluno, int qtd_alunos)
{
    int index;
    for (index = 0; index < qtd_alunos; index++)
    {
        printf("\n");
        printf("Dados do aluno %d \ nome: %s || matricula: %d || IRA: %f", index + 1, aluno[index].nome, aluno[index].matricula, aluno[index].IRA);
    }
}

int main()
{
    int qtd_alunos, index;
    printf("Informe a quantidade de alunos: ");
    scanf("%d", &qtd_alunos);
    Aluno *vetor_de_alunos = (Aluno *)malloc(qtd_alunos * sizeof(Aluno));
    if (vetor_de_alunos == NULL)
    {
        printf("Erro!");
        exit(1);
    }
    for (index = 0; index < qtd_alunos; index++)
    {
        printf("Digite o nome do aluno: ");
        scanf(" %[^\n]s", vetor_de_alunos[index].nome);
        printf("Digite a matricula: ");
        scanf("%d", &vetor_de_alunos[index].matricula);
        printf("Digite o IRA: ");
        scanf("%f", &vetor_de_alunos[index].IRA);
    }
    imprime(vetor_de_alunos, qtd_alunos);
    free(vetor_de_alunos);

    return 0;
}
