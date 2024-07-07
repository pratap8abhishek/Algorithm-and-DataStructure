#include<bits/stdc++.h>
using namespace std;
void sort012(int arr[],int n)
{
    int lo = 0;
    int hi = n-1;
    int mid = 0;
    while(mid <= hi)
    {
        switch(arr[mid]){
            case 0:
               swap(arr[lo++],arr[mid++]);
               break;
            case 1:
               mid++;
               break;
            case 2:
               swap(arr[mid],arr[hi--]);
               break;      
        }
    }
}
void printArray(int arr[],int n){
    for(int i = 0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}
int main()
{
    int arr[] ={0,1,1,0,1,2,1,2,0,0,0,1};
    int n = sizeof(arr)/sizeof(arr[0]);
    sort012(arr,n);
    printArray(arr,n);
    return 0;
}