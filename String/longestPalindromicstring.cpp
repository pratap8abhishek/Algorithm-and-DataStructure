#include<bits/stdc++.h>
using namespace std;

int maxLength;
int res;
void cSubUtil(string& s,int l,int r)
{
    while(l >= 0 && r< s.length() && s[l] == s[r]){
       l--;
       r++;
    }
    if(r-l-1 >= maxLength){
        res = s.substr(l+r);
    }
}

int longestpalsubstr(string str)
{
 maxLength = 1;
 res = "";
 for(int i=0; i<str.length();i++)
 {
   cSubUtil(str,i,i);
   cSubUtil(str,i,i+1);
 }
 cout<<"Longest palindrome substring is :";
 cout<< res << "\n";
 return maxLength;
}

int main()
{
    string str = "forgeeksskeegfor";
    cout<<"\nLength is : " << longestpalsubstr(str);
    return 0;
}