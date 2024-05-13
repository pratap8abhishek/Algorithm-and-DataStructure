#include <bits/stdc++.h>
using namespace std;
int maxSubArray(int arr[], int n)
{
    if (n == 1)
        return arr[0];

    int m = n / 2;

    int left_max = maxSubArray(arr, m);
    int right_max = maxSubArray(arr + m, n - m);

    int left_sum = INT_MIN, right_sum = INT_MIN, sum = 0;

    for (int i = m; i < n; i++)
    {
        sum += arr[i];
        right_sum = max(right_sum, sum);
    }
    sum = 0;

    for (int i = m - 1; i >= 0; i--)
    {
        sum += arr[i];
        left_sum = max(left_sum, sum);
    }
    int cross_max = left_sum + right_sum;

    return max(cross_max, max(left_max, right_max));
}

int main()
{
    int arr[] = {-2, -3, 4, -1, -2, 1, 5, -3};
    int n = sizeof(arr) / sizeof(arr[0]);
    int max_Sum = maxSubArray(arr, n);
    cout << "maximum Sub Array Sum Is:" << max_Sum << " ";
    return 0;
}