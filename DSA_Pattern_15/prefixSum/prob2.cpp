#include<bits/stdc++.h>
using namespace std;
void rangeSumQueries(int arr[],int n,vector<pair<int, int>>& queries){
    vector<int> prefix(n);
    prefix[0] = arr[0];
    for(int i = 1; i < n;i++){
        prefix[i] = prefix[i-1] + arr[i];;
    }
     
    for(auto q: queries){
        int L = q.first;
        int R = q.second;
        
        int sum;
        if(L == 0){
            sum = prefix[R];
        }else{
            sum = prefix[R] - prefix[L-1];
        }
        cout<<"Sum from index"<< L << "to" << R << "=" << sum << endl;
    }
}
int main()
{
  int arr[] = {2, 4, 6, 8, 10};
  int n = sizeof(arr) / sizeof(arr[0]);

  vector<pair<int, int>> queries = {{1, 3}, {0, 2}, {2, 4}};

  rangeSumQueries(arr, n, queries);

  return 0;  
}