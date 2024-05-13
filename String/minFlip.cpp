#include<bits/stdc++.h>
using namespace std;
char flip(char ch) {return (ch =='0') ? '1':'0';}

int getFlip(string str,char expected)
{
    int flipcnt = 0;
    for(int i=0;i<str.length();i++){
        if(str[i]!=expected)
        flipcnt++;

        expected = flip(expected);
    }
    return flipcnt;

}
int minFlipToMakeStringAlternate(string str)
{
    return min(getFlip(str,0),getFlip(str,1));
}
int main()
{
    string str = "0001010111";
    cout << minFlipToMakeStringAlternate(str);
    return 0;
}