// incluindo as bibliotecas
#include <stdio.h>
#include <math.h>

// criando uma função sem retorno, com quatro parametros do tipo float sendo dois ponteiros
void calcula_hexagono(float l, float *area, float *perimetro)
{
    *area = (3 * pow(l, 2) * sqrt(3)) / 2; // implimentando a formula da área
    *perimetro = 6 * l;                    // implementando a formula do perimetro
}

// função principal
int main()
{
    float l, x, y;                           // declarando as variáveis que vão servir de parametro
    printf("Informe o lado do hexagono: ");  // imprimindo uma mensagem para o usuário digitar o lado do hexagono
    scanf("%f", &l);                         // pedindo ao usuário de informe o tamanho do lado
    calcula_hexagono(l, &x, &y);             // chamando a função e passando os parametros
    printf("Area: %f\nPerimetro: %f", x, y); // imprimindo a área e o perimetro
    return 0;
}