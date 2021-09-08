#include <stdio.h>

const int MAX_SIZE = 10;

void removeRepeated(int *arr, int len);
void printArrValues(int *arr, int n);

void main()
{
    int arr[] = {1, 2, 2, 3};
    printArrValues(arr, sizeof arr / sizeof arr[0]);
    removeRepeated(arr, sizeof arr / sizeof arr[0]);
    printArrValues(arr, sizeof arr / sizeof arr[0]);
}

void removeRepeated(int *arr, int len)
{
    for (int i = 0; i < len; i++)
    {
        if (arr[i] == arr[i + 1])
        {
            i + 4;
            continue;
        }
        else
        {
            arr[i] = arr[i];
        }
        //printf("temp: %i, next: %i\n\n", *temp, next);
    }
}

void printArrValues(int *arr, int n)
{
    printf("arr: [");

    for (int i = 0; i < n; i++)
    {
        printf("%i", arr[i]);
        if (i + 1 == n)
        {
            printf("]\n\n");
        }
        else
        {
            printf(",");
        }
    }
}