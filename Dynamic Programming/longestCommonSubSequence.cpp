#include<bits/stdc++.h>
using namespace std;

int lcs(string s1,string s2,int m,int n)
{
    if(m ==0 || n == 0)
    return 0;

    if(s1[m-1] == s2[n-1])

    return 1 + lcs(s1,s2,m-1,n-1);

    else

    return 1 + max(lcs(s1,s2,m-1,n),lcs(s1,s2,m,n-1))
}
int main()
{
    string s1 = "AGGTAB";
    string s2 = "GXTXAYB";
    int m = s1.size();
    int n = s2.size();

    cout<< lcs(s1,s2,m,n)<<endl;
    retrn 0;
}

// Soluation using Dynamic Programming

int lcs(string s1,string s2)
{
    int m = s1.size();
    int n = s2.size();

    vector<vector<int>> dp(m+1,vector<int>(n+1,0));

    for(int i = 1; i<=m; i++){
        for(int j = 1; j<=n; j++){
            if(s1[i-1] == s2[j-1])
             dp[i][j] = dp[i-1][j-1]+1;
            else
             dp[i][j] = max(dp[i-1][j],dp[i][j-1])
        }
    }
    return dp[m][n];
}


int main() {
    string s1 = "AGGTAB";
    string s2 = "GXTXAYB";
    cout << lcs(s1, s2) << endl;

    return 0;
}