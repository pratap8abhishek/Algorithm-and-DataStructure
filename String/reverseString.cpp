#include <bits/stdc++.h>
using namespace std;
// void ReverseString(string &str)
// {
//     int len = str.length();
//     int n = len;
//     for (int i = 0; i < n / 2; i++)
//     {
//         swap(str[i], str[n - i - 1]);
//     }
// }
// int main()
// {
//     string str = "Abhishek";
//     ReverseString(str);
//     cout << "Reverse string is " << str;
//     return 0;
// }
void ReverseString(string &s)
{
    int len = s.length();
    int n = len;
    for(int i=0;i<n/2;i++){
        swap(s[i],s[n-i-1]);
    }
}
int main()
{
    string str = "Abhishek";
    ReverseString(str);
    cout << "Reverse string is " << str;
    return 0;
}