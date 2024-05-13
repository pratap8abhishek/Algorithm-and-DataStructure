#include<bits/stdc++.h>
using namespace std;
int factorial(int n){
    if(n==1 || n==0)
    return 1;
    else
    return n*factorial(n-1);
}
int main()
{
    int num = 5;
    cout<<"Factorial of Given Number is : "<< factorial(num);
    return 0;
}