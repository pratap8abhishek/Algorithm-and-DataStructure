#include <bits/stdc++.h>
using namespace std;
int minSum(int arr[], int n, int k)
{
    if (n < k)
    {
        cout << "Invalid";
        return -1;
    }
    int res = 0;
    for (int i = 0; i < k; i++)
        res += arr[i];

    int curr_sum = res;
    for (int i = k; i < n; i++)
    {
        curr_sum += arr[i] - arr[i - k];
        res = min(res, curr_sum);
    }
    return res;
}

int main()
{
    int arr[] = {1, 4, 2, 10, 2, 3, 1, 0, 20};
    int k = 4;
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << minSum(arr, n, k);
    return 0;
}