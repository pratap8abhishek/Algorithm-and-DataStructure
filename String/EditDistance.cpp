#include <bits/stdc++.h>
using namespace std;

// Recursive Approach Overlapping Sub Problem

// int min(int x,int y,int z){
//     return min(min(x,y),z);
// }
// int editDistance(string str1,string str2,int n,int m)
// {
//     if(m==0)
//     return n;
//     if(n==0)
//     return m;
//     if(str1[n-1] == str2[m-1])
//     return editDistance(str1,str2,m-1,n-1);

//     return 1+min(editDistance(str1,str2,n-1,m),editDistance(str1,str2,n,m-1),editDistance(str1,str2,m-1,n-1));
// }
// int main()
// {
//    string str1 = "Sunday";
//    string str2 = "Saturday";
//    int n = str1.length();
//    int m = str2.length();
//    cout<<editDistance(str1,str2,n,m)<<endl;
//    return 0;
// }

// Solve using Dp

int editDistance(string s1, string s2, int n, int m, vector<vector<int>>& dp)
{
    if (n == 0)
        return m;
    if (m == 0)
        return n;

    if (dp[n][m] != -1)
        return dp[n][m];

    if(s1[n-1] == s2[m-1])
    {
        return dp[n][m] = editDistance(s1,s2,n-1,m-1,dp);
    } 
    else{
         int insert, del, replace; 

        insert = editDistance(s1, s2, n, m - 1, dp);
        del = editDistance(s1, s2, n - 1, m, dp);
        replace = editDistance(s1, s2, n - 1, m - 1, dp);
        return dp[n][m] = 1 + min(insert, min(del, replace));
}
}

int main()
{
    string str1 = "saturday";
    string str2 = "sunday";
    int n = str1.length();
    int m = str2.length();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
    cout << editDistance(str1, str2, n, m, dp);
    return 0;
}