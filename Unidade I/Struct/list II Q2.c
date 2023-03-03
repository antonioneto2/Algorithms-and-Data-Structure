// incluindo as bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct pessoa // criando uma strct e renomeandoa
{
    char nome[50];
    float documento;
    int idade;
} Pessoa;

void cadastra_pessoas(Pessoa *pessoa, int qtdPessoas) // função sem retorno com dois parametros , uma do tipo Pessoa ponteiro e outra do tipo int
{
    int i; // contador
    for (i = 0; i < qtdPessoas; i++)
    {
        printf("Digite o nome da pessoa %d: \n", i + 1); // pedindo e lendo o nome da pessoa
        scanf(" %[^\n]s", pessoa[i].nome);
        printf("Digite o documento da pessoa %d: \n", i + 1); // pedindo e lendo o documento da pessoa
        scanf("%f", &pessoa[i].documento);
        printf("Digite a idade da pessoa %d: \n", i + 1); // pedindo e lendo a idade da pessoa
        scanf("%d", &pessoa[i].idade);
    }
}

void imprime_pessoas(Pessoa *pessoa, int qtdPessoas) // função que imprime o nome, documento e idade da pessoa
{
    int i;
    for (i = 0; i < qtdPessoas; i++)
    {
        printf("Pessoa %d: \n", i + 1);
        printf("Nome: %s | Documento: %.1f | Idade: %d \n", pessoa[i].nome, pessoa[i].documento, pessoa[i].idade);
    }
}

void altera_idade(Pessoa *pessoa, int qtdPessoas) // função idade
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

void imprime_maior_menor_idade(Pessoa *pessoa, int qtdPessoas) // função sem retorno, com parametro do tipo Pessoa ponteiro e do tipo int
{
    int i;                    // variável usado no contador
    int maiorIdade = 0;       // declarando e inicializando a variável maiorIdade do tipo int
    int menorIdade = 9999;    // declarando e inicializando a variável menorIdade do tipo int
    char nomePessoaVelha[20]; // vetor de char de 20 carateres
    char nomePessoaNova[20];
    for (i = 0; i < qtdPessoas; i++) // contador para inicializar o vetor
    {
        if (pessoa[i].idade > maiorIdade)
        {
            maiorIdade = pessoa[i].idade;
            strcpy(nomePessoaVelha, pessoa[i].nome); // copinado string
        }
        if (pessoa[i].idade < menorIdade)
        {
            menorIdade = pessoa[i].idade;
            strcpy(nomePessoaNova, pessoa[i].nome); // copiando stsring
        }
    }
    printf("Pessoa com maior idade: %s (%d anos)\n", nomePessoaVelha, maiorIdade); // imprime a maior idade
    printf("Pessoa com menor idade: %s (%d anos)\n", nomePessoaNova, menorIdade);  // imprime a menor idade
}

// função principal
int main()
{
    int qtdPessoas, i;                                                 // declarando duas variáveis do tipo int
    printf("Digite a quantidade de pessoas que deseja cadastrar: \n"); // pede e ler a quantidade de pessoas que querem se cadastrar
    scanf("%d", &qtdPessoas);

    Pessoa *pessoa = (Pessoa *)malloc(qtdPessoas * sizeof(Pessoa));
    if (pessoa == NULL)
    {
        printf("Memória insuficiente.");
        exit(1);
    }

    cadastra_pessoas(pessoa, qtdPessoas);          // chamada da função
    imprime_pessoas(pessoa, qtdPessoas);           // chamada da função
    altera_idade(pessoa, qtdPessoas);              // chamada da função
    imprime_maior_menor_idade(pessoa, qtdPessoas); // chamada da função

    free(pessoa); // liberando espaço da alocação
    return 0;
}