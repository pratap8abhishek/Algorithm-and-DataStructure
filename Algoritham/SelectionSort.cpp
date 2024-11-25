#include<bits/stdc++.h>
using namespace std;

void selectionSort(int arr[],int n){
  for(int i = 0; i < n-1; ++i){
    int minIndx = i;
    for(int j = i+1; j<n; ++j){
        if(arr[j] < arr[minIndx]){
            minIndx = j;
        }
    }
    swap(arr[i],arr[minIndx]);
  }
}
int main(){
    int arr[] = {64, 25, 12, 22, 11};
    int n = sizzeof(arr)/sizeof(arr[0]);
    selectionSort(arr,n);

    cout << "Sorted array: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}