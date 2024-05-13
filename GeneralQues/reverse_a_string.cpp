#include <bits/stdc++.h>
using namespace std;

void ReverseString(string &str)
{
    int len = str.length();
    int n = len - 1;
    int i = 0;
    while (i <= n)
    {
        swap(str[i], str[n]);
        n = n - 1;
        i = i + 1;
    }
}
int main()
{
    string str = "abcd";
    ReverseString(str);
    cout << "Reverse string is " << str;
    return 0;
}