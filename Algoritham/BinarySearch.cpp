#include<bits/stdc++.h>
using namespace std;
int binarysearch(int arr[],int n,int target){
    int left = 0;
    int right = n-1;
    while(left <= right){
        int mid = left +(right - left)/2;

        if(arr[mid] == target){
            return mid;
        }else if(arr[mid] < target){
            left = mid + 1;
        }else{
            right  = mid - 1;
        }
    }
    return -1;
}



int main(){
    int arr[] = {1,4,3,2,6,7,9};
    int k = 9;
    int n = sizeof(arr)/sizeof(arr[0]);
    binarysearch(arr,n,k);
    return 0;
}