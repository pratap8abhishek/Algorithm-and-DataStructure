#include <bits/stdc++.h>
using namespace std;

// Corrected function to count 1s in a range
int countOnes(vector<int>& arr, int L, int R)
{
    int count = 0;
    for (int i = L; i <= R; i++) {
        if (arr[i] == 1)
            count++;
    }
    return count;
}

int main()
{
    vector<int> arr = {1, 0, 1, 1, 0, 1};

    vector<pair<int, int>> queries = {
        {0, 2},  // should return 2 (1,0,1)
        {1, 4},  // should return 2 (0,1,1,0)
        {2, 5}   // should return 3 (1,1,0,1)
    };

    for (auto [L, R] : queries) {
        cout << "Number of 1s in range [" << L << ", " << R << "] = ";
        cout << countOnes(arr, L, R) << endl;
    }

    return 0;
}
