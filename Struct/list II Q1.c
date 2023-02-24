// incluindo as bibliotecas
#include <stdio.h>
#include <stdlib.h>

typedef struct funcionario // criando uma struct que guarda as informações do funcionario
{
    char nome[50];
    float salario;
    int id;
    char cargo[50];
} Funcionario;

void preenche(Funcionario *dados, int qtd) // função
{
    int index; // declarando contador
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

void imprime(Funcionario *imprime, int qtd) // função impime
{
    int index;                            // declarando o contador do tipo int
    for (index = 0; index < qtd; index++) // inicializando o for
    {
        printf("\n");
        printf("Funcionario %d | Nome: %s | Salario: %.2f | Cargo: %s | Id: %d", index + 1, imprime[index].nome, imprime[index].salario, imprime[index].cargo, imprime[index].id);
        // imprimindo funcionario, nome salario, cargo e id
    }
}

void muda_salario(Funcionario *sal, int quant) // função que muda o salario
{
    int i, alteracao;                                                                             // declara duas variáveis do tipo int
    printf("\n");                                                                                 // quebra de linha
    printf("deseja alterar o valor do salario dos funcionarios?(use 1 para sim e 2 para nao)\n"); // pergunta ao usuário se quer alteral o salrio, em seguida ler o valor da alteração
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

void maior_salario(Funcionario *maiorsal, int quant) // função do maior salario com parametros
{
    int i; // declarando a variável do contador
    float maiors = 0;
    char mcargo[50];
    for (i = 0; i < quant; i++)
    {
        if (maiorsal[i].salario > maiors) // compara os salarios
        {
            maiors = maiorsal[i].salario;
            strcpy(mcargo, maiorsal[i].cargo); // copia a string para outra
        }
    }
    printf("\n");
    printf("o cargo da pessoa com o maior salario e: %s e o salario dessa pessoa e: %f\n", mcargo, maiors);
    // mostra para o usuário o cargo da pessoa com o maior salario e o salario dessa pessoa
}

// função principal
int main()
{
    int qtd_funcionario;
    printf("Informe a quatidade de funcionario: ");
    scanf("%d", &qtd_funcionario);
    Funcionario *dados_funcionario = (Funcionario *)malloc(qtd_funcionario * sizeof(Funcionario)); // alocando dinâmicamente
    preenche(dados_funcionario, qtd_funcionario);                                                  // chamada da função
    imprime(dados_funcionario, qtd_funcionario);                                                   // chamada da função
    muda_salario(dados_funcionario, qtd_funcionario);                                              // chamada da função
    maior_salario(dados_funcionario, qtd_funcionario);                                             // chamada da função

    for (int i = 0; i < qtd_funcionario; i++) // for para liberar espaço da alocação
    {
        free(dados_funcionario);
    }

    free(dados_funcionario); // liberando espaço da memória

    return 0;
}