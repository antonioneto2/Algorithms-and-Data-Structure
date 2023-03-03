// incluindo a biblioteca
#include <stdio.h>

typedef struct funcionarios // criando uma struct e renomendoa
{
    char nome[50], cargo[100];
    float salario;
} Funcionario;

// função principal
int main()
{
    int n;                                            // declarando variável
    printf("Informe a quantidade de funcionarios: "); // pedindo e lendo a quantidade de funcionarios
    scanf("%d", &n);

    Funcionario funcionario[n]; // declarando um vetor do tipo Funcionario

    for (int i = 0; i < n; i++) // crindo um for para pedir as informações dos funconarios
    {
        printf("Informe o nome do %d funcionario: ", i + 1);
        scanf(" %[^\n]", funcionario[i].nome);

        printf("Informe o salario do %d funcionario: ", i + 1);
        scanf("%f", &funcionario[i].salario);

        printf("Informe o cargo do %d funcionario: ", i + 1);
        scanf(" %[^\n]", funcionario[i].cargo);
    }

    printf("\n");
    for (int i = 0; i < n; i++) // for para imprimir as informações dos funcionarios
    {
        printf("Informe o nome do %d funcionario: %s\n", i + 1, funcionario[i].nome);
        printf("Informe o salario do %d funcionario: %f\n", i + 1, funcionario[i].salario);
        printf("Informe o cargo do %d funcionario: %s\n", i + 1, funcionario[i].cargo);
        printf("\n");
    }

    return 0;
} // fim