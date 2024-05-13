#include<bits/stdc++.h>
using namespace std;

string deleteConsecutiveStrings(string s)
{
    int i=0;
    int j=0;

    string result = " ";

    while(j < s.length()){
        if(s[i]==s[j]){
            j++;
        }
        else if(s[j] != s[i] || j == s.length()-1)
        {
            result += s[i];

            i = j;
            j++; 
        }
    }
    result += s[j-1];
    return result ;
}
int main()
{
    string s = "aaaaaaaaaaaaaaaaaaabbbbbbbbbbbbbbb";
 
    cout << "Input  : " << s << endl;
 
    cout << "Output : " << deleteConsecutiveStrings(s) << endl;
 
    return 0;
}