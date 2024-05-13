#include <bits/stdc++.h>
using namespace std;
int Secondlargest(int arr[], int n)
{
    int max = arr[0];
    int temp = 0;
    for (int i = 1; i < n; i++)
    {
        temp = max;
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    return temp;
}
int main()
{
    int arr[] = {10, 324, 45, 90, 9808,100000};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Second Largest in given array is " << Secondlargest(arr, n);
    return 0;
}