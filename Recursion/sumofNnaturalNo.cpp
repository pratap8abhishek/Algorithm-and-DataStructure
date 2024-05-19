#include<bits/stdc++.h>
using namespace std;


// Parametrize Recursion
void SumofAll(int n, int sum)
{
    if(n<1){
        cout<<sum<<endl;
        return;
    }
    SumofAll(n-1,sum+n)
}
int main(){
    int n = 10;
    SumofAll(n,0);
    return 0;
}

// Functional Recurssion
int sumofN(int n)
{
    if(n == 0)
    {
        return 0;
    }
    return n + sumofN(n-1);
}
int main()
{
    int n =10;

     cout << "Sum of first " << n << " natural numbers is " << sumofN(n) << endl;
    return 0;
}