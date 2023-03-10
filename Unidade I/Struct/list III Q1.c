#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VAGAS 15 // total de vagas para os alunos
#define MAX_TURMAS 2 // total de turmas que existem

struct aluno // struct aluno que guarda os dados que o aluno vai ter ao realizar sua matricula em uma turma
{
    int mat;
    char nome[70];
    float notas[3];
    float media;
};
typedef struct aluno Aluno;

struct turma // turmas para cadastra os alunos com uma struct aluno declarada dentro do seu corpo
{
    char id;
    int vagas;
    Aluno *alunos[MAX_VAGAS];
};
typedef struct turma Turma;

Turma *turmas[MAX_TURMAS]; // declarando uma variável do tipo Truma

void inicializa() // função para inicializar o vetor
{
    for (int i = 0; i < MAX_TURMAS; i++)
    {
        turmas[i] = NULL;
    }
}

Turma *cria_turma(char id) // função com um parametro que cria turma
{
    Turma *turma = (Turma *)malloc(sizeof(Turma)); // alocando dinâmicamente

    if (turma == NULL) // testando a alocação
    {
        exit(1);
    }

    turma->id = id;

    turma->vagas = MAX_VAGAS;

    for (int i = 0; i < MAX_VAGAS; i++)
    {
        turma->alunos[i] = NULL;
    }

    return turma;
}

void matricula_aluno(Turma *turma, int mat, char *nome) // função matricula
{
    turma->vagas -= 1; // diminui a quantidade de vagas da turma

    for (int j = 0; j < MAX_VAGAS; j++)
    {
        if (turma->alunos[j] == NULL)
        {
            turma->alunos[j] = (Aluno *)malloc(sizeof(Aluno)); // aloca o vetor Aluno

            for (int k = 0; k < 3; k++)
            {
                turma->alunos[j]->notas[k] = 0; // inicializa as notas com zero
            }

            turma->alunos[j]->mat = mat;
            strcpy(turma->alunos[j]->nome, nome);

            break;
        }
    }
}

void lanca_notas(Turma *turma)
{
    float nota = 0, media = 0;
    for (int i = 0; i < MAX_VAGAS; i++)
    { // percorre o vetor de Alunos
        media = 0;
        if (turma->alunos[i] != NULL && turma->alunos[i]->notas[0] == 0)
        { // verifica se ha vagas preenchidas e se falta alunos receber as notas
            printf("\nMatricula: %d\tAluno: %s\n", turma->alunos[i]->mat, turma->alunos[i]->nome);
            for (int j = 0; j < 3; j++)
            { // preenche as notas de um aluno
                printf("Digite a nota %d: ", j + 1);
                scanf("%f", &nota);

                turma->alunos[i]->notas[j] = nota;

                media += nota;
            }
            turma->alunos[i]->media = media / 3;
        }
    }
}

void imprime_alunos(Turma *turma) // função que imprime a matricula, nome e media
{
    for (int i = 0; i < MAX_VAGAS; i++)
    {
        if (turma->alunos[i] != NULL)
        {
            printf("Matricula: %d\tNome: %s\nMedia: %.1f\n", turma->alunos[i]->mat, turma->alunos[i]->nome, turma->alunos[i]->media);
        }
    }
}

void imprime_turmas(Turma **turmas, int n) // função que imprime a turma, vagas disponiveis e lista de alunos matriculados
{
    for (int i = 0; i < n; i++)
    {
        printf("Turma: %c\tVagas disponiveis: %d\n", turmas[i]->id, turmas[i]->vagas);
        printf("Lista de alunos matriculados: \n");
        for (int j = 0; j < MAX_VAGAS; j++)
        {
            if (turmas[i]->alunos[j] != NULL)
            {
                printf("%s\n", turmas[i]->alunos[j]->nome);
            }
        }
    }
}

Turma *procura_turma(Turma **turmas, int n, char id) // função do tipo Turma
{
    Turma *turma = (Turma *)malloc(sizeof(Turma)); // alocando dinâmicamente

    if (turma == NULL)
    {
        exit(1);
    }

    for (int i = 0; i < MAX_VAGAS; i++)
    {
        turma->alunos[i] = (Aluno *)malloc(sizeof(Aluno));
    }

    for (int j = 0; j <= n; j++)
    {
        if (j == n)
        {
            printf("\nTurma inexistente!\n");

            return 0;
        }

        if (turmas[j]->id == id)
        {
            turma = turmas[j];
            break;
        }
    }

    return turma;
}

// função principal
int main()
{
    Turma *t = (Turma *)malloc(sizeof(Turma)); // retorna a turma que o usuario procura

    int op, index = 0, mat = 0; // index vai controlar o limite do vetor turmas
    char id, *nome;
    nome = (char *)malloc(81 * sizeof(char)); // alocando dinâmicamente e imprimendp o menu para o usuário
    printf("Bem-vindo ao Programa de Gerenciamento de Turmas!\n");
    printf("Este programa gerencia as turmas ofertadas, fornecendo as funcionalidades de matricula, lancamento de notas e listagem de alunos.\n");
    printf("Autor: Heitor Claudino\tVersao: 1.0\n");
    while (op != 8)
    {
        printf("\n\nMenu:\n");
        printf("1 - Criar turma\n2 - Listar turmas\n3 - Matricular Aluno\n4 - Lancar notas\n5 - Listar alunos\n6 - Listar turmas\n7 - Procurar uma turma\n8 - Sair\n\nDigite sua opcao: ");
        scanf("%d", &op);

        printf("\n");
        switch (op)
        {
        case 1:
            if (index >= MAX_TURMAS)
            {
                printf("Nao e possivel criar mais turmas!");
                break;
            }

            printf("Criando nova turma...\n");
            printf("Informe um id: ");
            scanf(" %c", &id);

            turmas[index] = cria_turma(id);
            printf("\nTurma %c criada com sucessso!", turmas[index]->id);
            index++;

            break;
        case 2:
            if (turmas[0] == NULL)
            {
                printf("Nao ha turmas cadastradas!\n");
                break;
            }

            printf("Listando turmas...\n");
            for (int k = 0; k < index; k++)
            {
                printf("Turma %c - %d vagas disponiveis\n", turmas[k]->id, turmas[k]->vagas);
            }

            break;
        case 3:
            if (turmas[0] == NULL)
            {
                printf("Nao ha turmas cadastradas!\n");
                break;
            }

            printf("Matriculando aluno...\n");
            printf("Digite o id da turma: ");
            scanf(" %c", &id);

            for (int i = 0; i <= index; i++)
            {
                if (i == index)
                {
                    printf("\nTurma inexistente!\n");
                    break;
                }

                if (turmas[i]->vagas == 0)
                {
                    printf("Nao ha mais vagas para esta turma!");
                    break;
                }

                if (turmas[i]->id == id)
                {
                    printf("Digite a matricula: ");
                    scanf("%d", &mat);
                    printf("Digite o nome: ");
                    scanf(" %[^\n]s", nome);

                    matricula_aluno(turmas[i], mat, nome);
                    printf("Aluno matriculado com sucesso!");
                    break;
                }
            }

            break;
        case 4:
            if (turmas[0] == NULL)
            {
                printf("Nao ha turmas cadastradas!\n");
                break;
            }
            printf("Lancando notas...\n");
            printf("Digite o id da turma: ");
            scanf(" %c", &id);

            for (int i = 0; i <= index; i++)
            {
                if (i == index)
                {
                    printf("\nTurma inexistente!\n");
                    break;
                }
                if (turmas[i]->id == id)
                {
                    if (turmas[i]->alunos[0] != NULL)
                    { // verifica se o aluno ja tem nota
                        lanca_notas(turmas[i]);
                        break;
                    }
                    else
                    {
                        printf("\nNao ha alunos matriculados nesta turma!\n");
                        break;
                    }
                }
            }

            break;
        case 5:
            if (turmas[0] == NULL)
            {
                printf("Nao ha turmas cadastradas!\n");
                break;
            }
            printf("Listando alunos..\n");
            printf("Digite o id da turma: ");
            scanf(" %c", &id);

            for (int i = 0; i <= index; i++)
            {
                if (i == index)
                {
                    printf("\nTurma inexistente!\n");
                    break;
                }
                if (turmas[i]->id == id)
                {
                    if (turmas[i]->alunos[0] != NULL)
                    {
                        imprime_alunos(turmas[i]);
                        break;
                    }
                    else
                    {
                        printf("\nNao ha alunos matriculados nesta turma!\n");
                        break;
                    }
                }
            }

            break;
        case 6:
            if (turmas[0] == NULL)
            {
                printf("Nao ha turmas cadastradas!\n");
                break;
            }
            printf("Imprimindo dados das turmas...\n");
            imprime_turmas(turmas, index);

            break;
        case 7:
            if (turmas[0] == NULL)
            {
                printf("Nao ha turmas cadastradas!\n");
                break;
            }
            printf("Procurando por uma turma...\n");
            printf("Digite o id da turma: ");
            scanf(" %c", &id);

            t = procura_turma(turmas, index, id);
            if (t == 0)
            {
                break;
            }

            printf("Turma: %c\tVagas disponiveis: %d\nLista de alunos matriculados:\n", t->id, t->vagas);
            for (int j = 0; j < MAX_VAGAS; j++)
            {
                if (t->alunos[j] != NULL)
                {
                    printf("%s\n", t->alunos[j]->nome);
                    break;
                }
            }

            break;
        case 8:
            printf("Obrigado por usar este programa!");

            break;
        default:
            break;
        }
    }

    free(turmas);
    free(t);
    free(nome);

    return 0;
}