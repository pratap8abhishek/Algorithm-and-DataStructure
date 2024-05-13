#include <bits/stdc++.h>
using namespace std;

void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

void printArray(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        cout << arr[i] << " ";
    }
}
int partition(int arr[], int low; int high)
{
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j < high; j++)
    {
        if (arr[j] <= pivot)
        {
            i++;

            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);

    return (i + 1);
}
void quicksort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);

        quicksort(arr, low, pi - 1);

        quicksort(arr, pi + 1, high);
    }
}
int main()
{
    int arr[] = {8, 7, 6, 1, 0, 9, 2};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Array Before Sorting"
         << " ";
    printArray(arr, n);

    quicksort(arr, 0, n - 1);

    cout << "Array After Sorting"
         << " ";
    printArray(arr, n);
    return 0;
}
