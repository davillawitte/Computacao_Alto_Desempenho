#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

double calcular_pi(long num_pontos)
{
    long dentro_do_circulo = 0;

    for (long i = 0; i < num_pontos; i++)
    {
        double x = (double)rand() / RAND_MAX;
        double y = (double)rand() / RAND_MAX;

        if ((x * x + y * y) <= 1)
        {
            dentro_do_circulo++;
        }
    }

    return 4.0 * dentro_do_circulo / num_pontos;
}

int main()
{
    srand(time(NULL)); // Semente para gerar números aleatórios

    long iteracoes[] = {1000, 10000, 100000, 1000000, 10000000};
    int num_testes = sizeof(iteracoes) / sizeof(iteracoes[0]);

    printf("Estimativa de Pi com diferentes quantidades de pontos:\n");
    for (int i = 0; i < num_testes; i++)
    {
        printf("Pontos: %ld -> Pi ≈ %.10f\n", iteracoes[i], calcular_pi(iteracoes[i]));
    }

    return 0;
}
