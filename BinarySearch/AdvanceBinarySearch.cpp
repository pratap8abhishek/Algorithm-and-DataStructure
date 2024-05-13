// Book Allocation Problem
// Each Student get at least one Book.
// Each Book should be allocated to a student
// Book allocaton shoud be done in contigonous manner
// max. No. of pages assigned to a student is min.

#include<bits/stdc++.h>
using namespace std;
bool isPossible(int arr[], int n, int m, int mid){
    int stdcnt = 1;
    int pageSum = 0;
    for(int i=0;i<n;i++){
       if(pageSum+arr[i]<=mid)
       {
        pageSum +=arr[i];
       } 
       else{
        stdcnt++;
        if(stdcnt > m ||arr[i]>mid){
            return false;
        }
        pageSum = arr[i];
       }
    }
    return true;
}
int allocateBooks(int arr[],int n,int m){
    int s = 0;
    int sum = 0;
    for(int i=0;i<n;i++){
        sum += arr[i];
    }
    int e = sum;
    int ans = -1;
    int mid = s+(e-s)/2;
    while(s<=e){
       if(isPossible(arr,n,m,mid)){
          ans = mid;
          e = mid-1;
       }
       else{
        s = mid+1;
       }
       mid = s+(e-s)/2;
    }
    return ans;
}
int main(){
   int arr[] = {10,20,30,40};
   int n = sizeof(arr)/sizeof(arr[0]);
   int m = 2;
   cout<<allocateBooks(arr,n,m);
   return 0;
}











