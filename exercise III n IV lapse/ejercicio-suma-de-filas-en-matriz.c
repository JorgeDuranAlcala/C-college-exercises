#include <stdio.h>
#include <stdlib.h>

/**  
 * @author Jorge Luis Duran Alcala
 * @cedula 28.511.812
 * @carrera Ingenieria de sistemas D1
 * @Asignatura Lenguajes de Programacion I
 * @Profesora Ing. Wilmary Colmenarez
 **/

// establecer maximo tamaño que puede tener la matriz
const int MAX = 50;

// leer los datos que tendra la matriz
void readMatriz(int matriz[][MAX], int m, int n);
// imprimir la matriz por motivos visuales
void printMatriz(int matriz[][MAX], int m, int n);
// funcion que encuentra la fila cuya suma es la menor de todas
int encontrar_fila_suma_menor(int matriz[][MAX], int m, int n);
// imprimir fila cuya suma es la menor de todas
void printFilaMenorSuma(int matriz[][MAX], int m, int n);

void main()
{
    int matriz[MAX][MAX];
    int FIL, COL, exit;
    do
    {
        system("cls");

        // preguntar al usuario cuantas filas tendra la matriz
        do
        {
            printf("Cuantas filas quiere en su matriz?\n");
            scanf("%i", &FIL);
        } while (FIL > MAX || FIL < 1);
        // preguntar al usuario cuantas columnas tendra la matriz
        do
        {
            printf("Cuantas columnas quiere en su matriz?\n");
            scanf("%i", &COL);
        } while (COL > MAX || COL < 1);

        // leer datos de la matriz
        readMatriz(matriz, FIL, COL);
        // imprimir la matriz dada por el usuario
        printMatriz(matriz, FIL, COL);
        // imprimir cual es la fila cuya suma es la menor
        printFilaMenorSuma(matriz, FIL, COL);

        // preguntar al usuario si quiere terminar el programa
        printf("....Presiona 0 y enter para terminar el programa\n");
        scanf("%i", &exit);

    } while (exit != 0);
}

/* leer los datos que se almacenaran en la matriz */
void readMatriz(int matriz[][MAX], int m, int n)
{
    printf("ingrese los valores de la matriz\n\n");

    for (int filas = 0; filas < m; filas++)
    {
        for (int cols = 0; cols < n; cols++)
        {
            printf("A(%i, %i)  ", filas + 1, cols + 1);
            scanf("%i", &matriz[filas][cols]);
        }
    }
}

void printMatriz(int matriz[][MAX], int m, int n)
{
    system("cls");
    printf("su matriz");
    printf("\n\n");
    // imprimir la matriz por motivos visuales
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

void printFilaMenorSuma(int matriz[][MAX], int m, int n)
{
    // imprimir resultado de la busqueda
    printf("la fila con la menor suma de elementos es la numero %i\n\n", encontrar_fila_suma_menor(matriz, m, n));
}

int encontrar_fila_suma_menor(int matriz[][MAX], int m, int n)
{
    int numero_fila;
    int min;
    int SUMS[m];

    // hacer las sumas y almacenarlas en un array llamado SUMS
    for (int filas = 0; filas < m; filas++)
    {
        int sum = 0;

        for (int cols = 0; cols < n; cols++)
        {
            sum += matriz[filas][cols];
        }

        SUMS[filas] = sum;
    }

    min = SUMS[0];

    // luego buscar por el menor elemento en el array
    // Ademas de guardar el numero de la fila en la variable "numero_fila"

    for (int i = 0; i < sizeof SUMS / sizeof SUMS[0]; i++)
    {
        if (SUMS[i] <= min)
        {
            min = SUMS[i];
            numero_fila = i + 1;
        }
    }
    // retornar el numero de la fila
    return numero_fila;
}