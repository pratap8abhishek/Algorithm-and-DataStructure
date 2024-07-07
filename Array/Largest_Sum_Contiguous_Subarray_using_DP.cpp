#include<bits/stdc++.h>
using namespace std;
void maxSubArraySum(int a[],int n)
{
    vector<int> dp(n,0);
    dp[0] = a[0];
    int ans = dp[0];
    for(int i=1;i<n;i++){
        dp[i] = max(a[i],a[i]+dp[i-1]);
        ans = max(ans,dp[i]);
    }
    cout << ans;
}

int main()
{
    int a[] = { -2, -3, 4, -1, -2, 1, 5, -3 };
    int n = sizeof(a) / sizeof(a[0]);
    maxSubArraySum(a, n);
    return 0;
}