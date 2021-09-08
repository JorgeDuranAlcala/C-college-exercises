#include <stdio.h>
int binarySearch(int arr[], int left, int right, int target);
int bsi(int *arr, int T, int target);

void main()
{
    int RES = 1, nums[] = {0, 1, 2, 3, 4, 5, 6};

    //printf("length: %d", sizeof nums / sizeof nums[0]);

    RES = binarySearch(nums, 0, sizeof nums / sizeof nums[0], 4);
    printf("resultado de la busqueda binaria recursiva: %i\n", RES);

    RES = bsi(nums, sizeof nums / sizeof nums[0], 3);
    printf("resultado de la busqueda binaria iterativa: %i\n", RES);
}

int binarySearch(int arr[], int left, int right, int target)
{
    int mid = (left + right) / 2;
    if (arr[mid] == target)
        return arr[mid];
    else if (target < mid)
        return binarySearch(arr, left, right - 1, target);
    else
        return binarySearch(arr, left + 1, right, target);
}

int bsi(int *arr, int T, int target)
{
    int left = 0, right = T - 1, mid, result = 0;
    while (left <= right && (!result))
    {
        mid = (left + right) / 2;
        if (arr[mid] == target)
            result = arr[mid];
        else if (target > arr[mid])
            left = mid + 1;
        else
            right = mid - 1;
    }
    return result;
}