// incluindo a biblioteca
#include <stdio.h>

// cria enum mes
typedef enum mes
{
    zero,
    janeiro,
    fevereiro,
    marco,
    abril,
    maio,
    junho,
    julho,
    agosto,
    setembro,
    outubro,
    novembro,
    dezembro
} Mes;

typedef struct data // cria uma struct data e renomeando
{
    int dia;
    Mes mes;
    int ano;
} Data;

// função principal
int main()
{
    Data data; // variável do tipo Data
    int mes;   // variável do tipo int

    printf("Informe o dia: "); // pedindo e lendo o dia, mes e ano para o usuário
    scanf("%d", &data.dia);

    printf("Informe o mes: ");
    scanf("%d", (int)&data.mes);

    printf("Informe o ano: ");
    scanf("%d", &data.ano);

    // caso o usuário escolha um dos itens abaixo será imprimido na tela
    switch (data.mes)
    {
    case 1:
        printf("%d/jan/%d", data.dia, data.ano);
        break;
    case 2:
        printf("%d/fev/%d", data.dia, data.ano);
        break;
    case 3:
        printf("%d/mar/%d", data.dia, data.ano);
        break;
    case 4:
        printf("%d/abr/%d", data.dia, data.ano);
        break;
    case 5:
        printf("%d/mai/%d", data.dia, data.ano);
        break;
    case 6:
        printf("%d/jun/%d", data.dia, data.ano);
        break;
    case 7:
        printf("%d/jul/%d", data.dia, data.ano);
        break;
    case 8:
        printf("%d/ago/%d", data.dia, data.ano);
        break;
    case 9:
        printf("%d/set/%d", data.dia, data.ano);
        break;
    case 10:
        printf("%d/out/%d", data.dia, data.ano);
        break;
    case 11:
        printf("%d/nov/%d", data.dia, data.ano);
        break;
    case 12:
        printf("%d/dez/%d", data.dia, data.ano);
        break;
    default:
        break;
    }
    return 0;
} // fim