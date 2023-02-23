#include <stdio.h>  //biblioteca padrão
#include <stdlib.h> //biblioteca de alocação dinâmica

// função principal
int main()
{

    int questoes;             // declarei uma variável do tipo int para o numero das questões
    int contador1, contador2; // declarei duas variáveis do tipo int para ser os contadores para as estruturas de repetições

    char *gabarito = (char *)malloc(questoes * sizeof(char)); // aloquei dinamicamente um espaço na memória para a variável gabarito do tipo char

    // testando se a alocação deu certo
    if (gabarito == NULL)
    {
        printf("Erro ao alocar memória");
        exit(1);
    }

    printf("Digite o número de questões: "); // imprimindo mensagem
    scanf("%d", &questoes);                  // pedindo ao usuário um numero inteiro para armazenar na variável questoes

    // fiz um for para o usuário digitar o gabarito de acordo com o numero de questoes
    for (contador1 = 0; contador1 < questoes; contador1++)
    {
        printf("\nDigite o gabarito da questão %d:\t", contador1 + 1);
        scanf("%s", gabarito);
    }

    printf("\n"); // quebra de linha

    char respostas[10][questoes]; // declarei uma matriz respostas do tipo char, com o número de alunos e o número de questoes

    // fiz um for para o usuário digitar as respostas de cada aluno, e como é uma matriz tem que ser dois for
    for (contador1 = 0; contador1 < 10; contador1++)
    {
        printf("Digite as respostas do aluno %d:", contador1 + 1);
        for (contador2 = 0; contador2 < questoes; contador2++)
        {
            printf("\nResposta %d:", contador2 + 1);
            scanf("%s", respostas[contador1]);
        }
    }

    printf("\n"); // quebra de linha

    float *notas = (float *)malloc(10 * sizeof(float)); // aloquei dinamicamente um espaço na memória para o vetor notas do tipo float

    // testando se a alocação deu certo
    if (gabarito == NULL)
    {
        printf("Erro ao alocar memória");
        exit(1);
    }

    int aprovados = 0, acertos = 0; // declarei duas variáveis do tipo inteiro e inicializei as duas com 0
    float nota;                     // declarei uma variável do tipo float
    float percentual;               // declarei uma variável do tipo float

    // fiz um for para saber a nota do aluno, se as respostas digitadas anteriormentes forem igual ao gabarito, vai somando o número de acertos para cada aluno na variável acertos
    for (contador1 = 0; contador1 < 10; contador1++)
    {
        for (contador2 = 0; contador2 < questoes; contador2++)
        {
            if (respostas[contador1][contador2] == gabarito[contador2])
            {
                acertos++;
            }
        }

        nota = acertos * 10 / questoes; // a variável nota recebe o cálculo da nota por questão
        notas[contador1] = nota;        // o vetor notas recebe a nota de cada aluno

        if (nota >= 6)
        { // se a nota for maior que 6, vai somando o numéro de alunos aprovados na variável aprovados
            aprovados++;
        }
    }

    printf("\nNota dos alunos:\n"); // imprimindo mensagem

    // fiz um for para imprimir a nota dos alunos
    for (contador1 = 0; contador1 < 10; contador1++)
    {
        printf("Aluno %d: %.1f\n", contador1 + 1, notas[contador1]);
    }

    percentual = aprovados * 100 / 10;                                 // armazenei o cálculo da porcentagem dos alunos aprovados na variável percentual
    printf("\nPorcentagem de alunos aprovados: %.1f%%\n", percentual); // imprimindo o percentual de alunos aprovados

    free(gabarito); // liberei a memória alocada a variável gabarito
    free(notas);    // liberei a memória alocada a variável notas

    return 0;
}