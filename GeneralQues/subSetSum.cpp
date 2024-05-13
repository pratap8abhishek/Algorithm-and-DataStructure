#include<bits/stdc++.h>
using namespace std;

bool isSubsetSum(const vector<int>& set,int n int target){
    vector<vector<bool> dp(n+1,vector<bool>(target+1,false));
    for(int i=0;i<n;++i){
        dp[i][0]  = true;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=target;++j){
            if(j<set[i-1]){
                dp[i][j] = dp[i-1][j];
            }else{
                dp[i][j] = dp[i-1][j] ||dp[i-1][j-set[i-1]];
            }
        }
    }
     return subset[n][sum];
}
int main(){
    vector<int> set = {3, 34, 4, 12, 5, 2};
    int target = 9;

    int n = set.size();
    if (isSubsetSum(set, n, target)) {
        cout << "Subset with sum " << target << " exists.\n";
    } else {
        cout << "Subset with sum " << target << " does not exist.\n";
    }

    return 0;
}