#include<bits/stdc++.h>
using namespace std;

int countGrater(count vector<int>& arr,int L,int R,int x)
{
    int count = 0;
    for(int i = L; i <= R; i++){
        if(arr[i] > x)
        count++;
    }
    return count;
}

int main()
{
  vector<int> arr = {1, 3, 5, 7, 9, 11};
    vector<tuple<int, int, int>> queries = {
        {1, 4, 5},  // Count > 5 in arr[1..4]
        {0, 5, 6},  // Count > 6 in arr[0..5]
        {2, 3, 3}   // Count > 3 in arr[2..3]
    }; 
    for (auto [L, R, X] : queries) {
        int result = countGreater(arr, L, R, X);
        cout << "Count of elements > " << X << " in range [" << L << ", " << R << "] = " << result << endl;
    }

    return 0; 
}