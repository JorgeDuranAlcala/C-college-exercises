#include <stdio.h>

int binarySearch(int *, int size, int target);
void Sort(int *, int size);

int main(int argc, char const *argv[])
{

    int arr[] = {45, 56, 22, 4, 3, 4, 1};

    Sort(arr, sizeof arr / sizeof arr[0]);

    printf("[");
    for (int i = 0; i < sizeof arr / sizeof arr[0]; i++)
    {
        printf("%i, ", arr[i]);
    }
    printf("]\n\n");

    int result = binarySearch(arr, sizeof arr / sizeof arr[0], 4);
    printf("El resultado de la busqueda fue: %i", result);

    return 0;
}

int binarySearch(int arr[], int size, int target)
{
    int right = size - 1, left = 0, mid;

    while (left <= right)
    {
        mid = (left + right) / 2;
        if (arr[mid] == target)
            return arr[mid];
        else if (target > mid)
        {
            left++;
        }
        else
        {
            right--;
        }
    }

    return -1;
}

void Sort(int arr[], int size)
{
    for (int i = 1; i < size; i++) // O(n)
    {
        int current = arr[i]; // O(n)
        int j = i - 1;        // O(n)
        while (j >= 0 && arr[j] > current)
        {                        // O(n^2)
            arr[j + 1] = arr[j]; // O(n^2)
            j--;                 // O(n^2)
        }
        arr[j + 1] = current; // O(n)
    }
}