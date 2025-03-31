#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 2000 // Tamanho máximo da matriz

double matrix[MAX_SIZE][MAX_SIZE];
double vector[MAX_SIZE];
double result[MAX_SIZE];

double get_execution_time(clock_t start, clock_t end)
{
    return (double)(end - start) / CLOCKS_PER_SEC;
}

void initialize_matrix_vector(int size)
{
    for (int i = 0; i < size; i++)
    {
        vector[i] = 1.0; // Simples para facilitar validação
        for (int j = 0; j < size; j++)
        {
            matrix[i][j] = (double)(i + j) / size;
        }
    }
}

void matrix_vector_mult_row_major(int size)
{
    for (int i = 0; i < size; i++)
    {
        result[i] = 0.0;
        for (int j = 0; j < size; j++)
        {
            result[i] += matrix[i][j] * vector[j];
        }
    }
}

void matrix_vector_mult_col_major(int size)
{
    for (int j = 0; j < size; j++)
    {
        for (int i = 0; i < size; i++)
        {
            result[i] += matrix[i][j] * vector[j];
        }
    }
}

int main()
{
    printf("Size\tRow-Major (s)\tCol-Major (s)\n");
    for (int size = 100; size <= MAX_SIZE; size += 200)
    {
        initialize_matrix_vector(size);

        clock_t start, end;

        start = clock();
        matrix_vector_mult_row_major(size);
        end = clock();
        double time_row_major = get_execution_time(start, end);

        start = clock();
        matrix_vector_mult_col_major(size);
        end = clock();
        double time_col_major = get_execution_time(start, end);

        printf("%d\t%.6f\t%.6f\n", size, time_row_major, time_col_major);
    }
    return 0;
}
