#include<bits/stdc++.h>
using namespace std;
bool IsPrime(int n){
  if(n%1 == 0 && n%n == 0){
    return true;
  }else{
    return false;
  }
}
int main()
{
    int n = 7;
    // const isprime = IsPrime(n);
    if(IsPrime(n)){
        cout<<"Given Number is a Prime Number";
    }else{
        cout<<"Given Number is not a Prime Number";
    }
    return 0;
}