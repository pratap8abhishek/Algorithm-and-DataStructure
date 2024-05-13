#include<bits/stdc++.h>
using namespace std;
bool IsPalindrome(string str,int n)
{
 for(int i=0;i<=n/2;i++)
 {
    if(str[i] != str[n-i-1])
    return false;
 }
 return true;
}
int main()
{
    string str = "aba";
    int n = str.length();
    if(IsPalindrome(str,n)){
       cout<<"Given String is a Palindrom";
    }else{
       cout<<"Given String is not a Palindrom";
    };
    return 0;
}