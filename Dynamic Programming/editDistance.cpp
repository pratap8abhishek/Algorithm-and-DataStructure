#include<bits/stdc++.h>
using namespace std;
int editDist(string &s1,string &s2)
{
    int m = s1.size();
    int n = s2.size();

    if(m == 0)
    return n;

    if(n == 0)
    return m;

    if(s1[m-1] == s2[n-1])
    return editDist(s1,s2,m-1,n-1);

    return 1 + min({editDist(s1,s2,m,n-1),
                editDist(s1,s2,m-1,n),
                editDist(s1,s2,m-1,n-1)});
}
int main()
{
    string s1 = "GEEXSFRGEEKKS";
    string s2 = "GEEKSFORGEEKS";

    cout << editDist(s1, s2);
    return 0;
}

// SOluation using Dynamic programming
int editDistDP(string &s1,string &s2){
    int m = s1.size();
    int n = s2.size();

    vector<vector<int>> dp(m+1,vector<int>(n+1));

    for(int i = 0; i <= m; i++)
    dp[i][0] = i;

    for(int j = 0; j<=n;j++)
    dp[0][j] = j;

    for(int i = 1;i <= m;i++){
        for(int j = 0;j<=n;j++){
            if(s1[i-1] == s2[j-1])
            dp[i][j] = dp[i-1][j-1];
            else
            dp[i][j] = 1 + min({dp[i][j-1],
                                dp[i-1][j],
                                dp[i-1][j-1]});
        }
    }
    return dp[m][n];
}


int main()
{
    string s1 = "GEEXSFRGEEKKS";
    string s2 = "GEEKSFORGEEKS";

    cout << editDistDP(s1, s2);
    return 0;
}

