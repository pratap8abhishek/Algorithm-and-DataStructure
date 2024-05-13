#include<bits/stdc++.h>
using namespace std;

int getPivot(int arr[],int n){
    int s = 0;
    int e = n-1;
    int mid = s+ (e-s)/2;
    while(s<e){
        if(arr[mid]>=arr[0]){
            s = mid+1;
        }
        else{
            e = mid;
        }
        mid = s+ (e-s)/2;
    } 
    return s;
}
int main(){
    int arr[] = {4,5,6,1,2,3};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<"Pivot is at index "<<getPivot(arr,n)<<endl;
}