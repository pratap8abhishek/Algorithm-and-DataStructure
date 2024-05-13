#include<bits/stdc++.h>
using namespace std;
int getMinMax(int arr[],int n){
    sort(arr,arr+n);
    cout<<"Min Ele is : "<<arr[0]<<" ";
    cout<<"Max Ele is : "<<arr[n-1]<<" ";
}
int main(){
    int arr[] = {5, 2, 4, 3, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    getMinMax(arr, n);
    return 0;
}