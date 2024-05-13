#include <bits/stdc++.h>
using namespace std;

int getMissingNumber(int arr[], int n)
{
    int total = (n + 1) * (n + 2) / 2;
    for (int i = 0; i < n; i++)
        total -= arr[i];
    return total;
}

int main()
{
    int arr[] = {1, 2, 3, 5, 6, 7, 8};
    int n = sizeof(arr) / sizeof(arr[0]);
    int miss = getMissingNumber(arr, n);
    cout << "Missing Number is : " << miss << " ";
    return 0;
}
