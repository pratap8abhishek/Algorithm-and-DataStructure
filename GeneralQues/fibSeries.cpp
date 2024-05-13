#include<bits/stdc++.h>
using namespace std;
int fibSeries(int n)
{
    if(n==0 || n==1){
     return 1;
    }
    else{
       return fibSeries(n-1)+ fibSeries(n-2);
    }
}
int main()
{
    int n = 5;
    cout<<"fib of given Number is : "<<fibSeries(n);
    return 0;
}