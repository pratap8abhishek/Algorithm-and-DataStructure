#include <bits/stdc++.h>
using namespace std;

void prefixSum(int arr[], int n) {
    int prefix[n];
    prefix[0] = arr[0];

    for (int i = 1; i < n; i++) {
        prefix[i] = prefix[i - 1] + arr[i];
    }

    // Print the prefix sum array
    for (int i = 0; i < n; i++) {
        cout << prefix[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[] = {2, 4, 6, 8};
    int n = sizeof(arr) / sizeof(arr[0]);

    prefixSum(arr, n);
    return 0;
}
