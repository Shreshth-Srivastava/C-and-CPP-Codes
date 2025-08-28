#include <stdio.h>

void merge(int *arr, int low, int mid, int high)
{
    int n1 = mid - low + 1, n2 = high - mid, arr1[n1], arr2[n2],i = 0, j = 0, k = low; // !Important note : k = low
    for (int i = 0; i < n1; i++)
        arr1[i] = arr[low + i];
    for (int j = 0; j < n2; j++)
        arr2[j] = arr[mid + 1 + j];
    while (i < n1 && j < n2)
    {
        if (arr1[i] < arr2[j])
        {
            arr[k] = arr1[i];
            i++;
        }
        else
        {
            arr[k] = arr2[j];
            j++;
        }
        k++;
    }
    while (i < n1)
    {
        arr[k] = arr1[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        arr[k] = arr2[j];
        j++;
        k++;
    }
}

void MergeSort(int *arr, int low, int high)
{
    if (low >= high)
        return;
    else
    {
        int mid = low + (high - low) / 2;
        MergeSort(arr, low, mid);
        MergeSort(arr, mid + 1, high);
        merge(arr, low, mid, high);
    }
}

int main(void)
{
    int arr[10] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    MergeSort(arr, 0, 9);
    for (int i = 0; i < 10; i++)
        printf("\n%d", arr[i]);
    return 0;
}