// First and Last Position in a Sorted Array

#include<bits/stdc++.h>
using namespace std;

int firstOccurence(int arr[],int n, int key){
    int s = 0;
    int e = n-1;
    int mid = s+(e-s)/2;
    int ans = -1;

    while(s<=e){
        if(arr[mid] == key){
            ans = mid;
            e = mid -1;
        }
        //got to right wala part
        else if(key>arr[mid]){
            s = mid+1;

        }
        // go to left wala part
        else if(key<arr[mid]){
            e = mid-1;
        }
        mid = s+(e-s)/2;
    }
    return ans;
}

int lastOccurence(int arr[],int n, int key){
    int s = 0;
    int e = n-1;
    int mid = s+(e-s)/2;
    int ans = -1;

    while(s<=e){
        if(arr[mid] == key){
            ans = mid;
            s = mid +1;
        }
        //got to right wala part
        else if(key>arr[mid]){
            s = mid+1;

        }
        // go to left wala part
        else if(key<arr[mid]){
            e = mid-1;
        }
        mid = s+(e-s)/2;
    }
    return ans;
}
int main(){
    int arr[] = {0,6};
    int x = 6;
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<"First occurence of 6 is at Index "<<firstOccurence(arr,n,x)<<endl;
    cout<<"Last occurence of 6 is at Index "<<lastOccurence(arr,n,x)<<endl;
    return 0;
}


















