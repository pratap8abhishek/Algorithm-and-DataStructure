#include <bits/stdc++.h>
using namespace std;
bool isPossible(int a[],int n,int cow,int minDist){
    int cntCow = 1;
    int lastplacedCow = a[0];
    for(int i=1;i<n;i++){
        if(a[i] - lastplacedCow >= minDist){
            cntCow++;
            lastplacedCow = a[i];
        }
    }
    if(cntCow>=cows) return true;
    return false;
}
int main()
{
    int n = 5, cow = 3;
    int a[] = {1, 2, 8, 4, 9};
    sort(a, a + n);
    int low = 1, 
    int high = a[n - 1] - a[0];
    while (low <= high)
    {
        int mid = (low + high) >> 1;
        if(isPossible(a,n,cows,mid)){
            low = mid+1;
        }else{
            high = mid-1;
        }
    }
    cout<<"The largest min. dist is :"<<high<<endl;
    return 0;
}