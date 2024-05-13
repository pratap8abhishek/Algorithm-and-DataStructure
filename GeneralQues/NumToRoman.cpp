#include<bits/stdc++.h>
using namespace std;
string printRoman(int num)
{
    string roman[] = {"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
    int value[] = {1000,900,500,400,100,90,50,40,10,9,5,4,1};
    int n =  sizeof(value)/sizeof(value[0]);
    string result = "";
    for(int i=0;i<n;++i){
        while(num-value[i]>=0){
           result += roman[i];
           num -= value[i];
        }
    }
    return result;
}
int main()
{
    int num = 9;
    cout<<"Roman Represent of Given Number is "<<printRoman(num);
    return 0;
}