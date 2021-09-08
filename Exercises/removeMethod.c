#include <stdio.h>
#include <stdlib.h>

const int MAX = 40;

void readMatriz(int matriz[][MAX], int m, int n);
void printMatriz(int matriz[][MAX], int m, int n);
void convertMatrixToTramp(int matrix[][MAX], int m, int n);

void main()
{
    int ROWS, COLS, matrix[MAX][MAX];
    /* Read the data of the matrix */
    do
    {
        printf("Ingrese el numero  de filas de la matriz\n");
        scanf("%i", &ROWS);
    } while (ROWS > MAX || ROWS < 1);

    do
    {
        printf("Ingrese el numero  de columnas de la matriz\n");
        scanf("%i", &COLS);
    } while (COLS > MAX || COLS < 1);

    readMatriz(matrix, ROWS, COLS);
    /* print matrix data */
    printMatriz(matrix, ROWS, COLS);
    /* Find the A^T of the matrix */
    //convertMatrixToTramp(matrix, ROWS, COLS);

    for (int i = 0; i < COLS; i++)
    {
        for (int j = 0; j < ROWS; j++)
        {
            matrix[j][i] = matrix[i][j];
        }
    }

    printf("transpuesta:\n\n");

    for (int i = 0; i < COLS; i++)
    {
        printf("| ");
        for (int j = 0; j < ROWS; j++)
        {
            printf("%i ", matrix[i][j]);
        }
        printf(" |");
        printf("\n");
    }
}

void convertMatrixToTramp(int matrix[][MAX], int m, int n)
{
    int T[MAX][MAX];

    /*  for (int rows = 0; rows < n; rows++)
    {
        for (int cols = 0; cols < m; cols++)
        {
            T[rows][cols] = matrix[rows][cols];
        }
    } */
}

void readMatriz(int matriz[][MAX], int m, int n)
{
    printf("ingrese los valores de la matriz\n\n");

    for (int filas = 0; filas < m; filas++)
    {
        for (int cols = 0; cols < n; cols++)
        {
            printf("A(%i, %i)  ", filas, cols);
            scanf("%i", &matriz[filas][cols]);
        }
    }
}

void printMatriz(int matriz[][MAX], int m, int n)
{
    system("cls");
    printf("su matriz");
    printf("\n\n");

    for (int filas = 0; filas < m; filas++)
    {
        printf("| ");
        for (int cols = 0; cols < n; cols++)
        {
            printf("%i ", matriz[filas][cols]);
        }
        printf(" |");
        printf("\n");
    }
}