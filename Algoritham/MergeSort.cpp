#include<bits/stdc++.h>
using namespace std;


void merge(int arr[],int left,int mid,int right){
    int n1 = mid - left+ 1;
    int n2 = right - mid;

    vector<int> leftArr(n1), rightArr(n2);

    for(int i = 0;i < n1; i++){
        leftArr[i] = arr[left+i];
    }
    for(int j = 0; j < n2; j++){
        rightArr[j] = arr[mid + 1 + j];
    }

    int i = 0,j = 0, k = left;
    while(i < n1 && j < n2){
        if(leftArr[i] <= rightArr[j]){
            arr[k++] = leftArr[i++];
        }else{
            arr[k++] = rightArr[j++];
        }
    }
    while(i < n1){
        arr[k++] = leftArr[i++];
    }
    while( j < n2){
        arr[k++] = rightArr[j++];
    }


}

void mergeSort(int arr[],int left,int right){
    if(left < right){
        int mid = left + (right - left)/2;

        mergeSort(arr,left,mid);
        mergeSort(arr,mid+1,right);

        merge(arr,left,mid,right);
    }
}

int main(){
    int arr[] = {12,11,13,5,6,7};
    int n = sizeof(arr)/sizeof(arr[0]);

    cout<<"Original Array : ";
    for(int num : arr){
        cout << num << " ";
    }

    mergeSort(arr,0,n-1);

    cout<< "Sorted array : ";
    for(int num : arr){
        cout << num << " ";
    }
    return 0;

}