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

int binarySearch(int arr[],int l,int r,int x){
    if(r>l){
        int mid = l+(r-l)/2;

        if(arr[mid] == x){
            return mid;
        }
        if(arr[mid]>x)
        return binarySearch(arr,l,mid-1,x);

        return binarySearch(arr,mid+1,r,x);
    }
     return -1;
}

int main(){
    int arr[] = {7,9,1,2,3};
    int k = 2; 
    int n = sizeof(arr)/sizeof(arr[0]);
    int pivot = getPivot(arr,n);
    if(k>=arr[pivot] && k<=arr[n-1]){
        cout<<"ele. in 2nd part at Index "<< binarySearch(arr,pivot,n-1,k)<<endl;
    }
    else{
        cout<<"ele. in 2nd part at Index "<< binarySearch(arr,0,pivot-1,k)<<endl;
    }

}