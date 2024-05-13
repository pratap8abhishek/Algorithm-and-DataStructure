#include <bits/stdc++.h>
using namespace std;
// void isPalindrome(char str[])
// {
//     int l=0;
//     int r = strlen(str)-1;
// //     while(l<r){
// //         if(str[l++] != str[r--]){
// //             return 0;
// //         }
// //     }
// //      return 1;
// while (l < r)
//     {
//         if (str[l++] != str[r--])
//         {
//             cout<<" is not a palindrome\n";
//             return;
//         }
//     }
//     cout<<" is a palindrome\n";
// }
string isPalindrome(string S)
{
    for (int i = 0; i < S.length() / 2; i++)
    {
        if (S[i] != S[S.length() - i - 1])
        {
            return "No";
        }
    }
    return "Yes";
}
int main()
{
    string S = "ABCDCBA";
    cout << isPalindrome(S);
    isPalindrome("abba");
    // if(isPalindrome){
    //     cout<<'Given String is Palindrome'<<endl;
    // }else{
    //     cout<<"Given string is Not a Palindrome"<<endl;
    // }
    return 0;
}