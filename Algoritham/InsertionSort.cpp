#include<bits/stdc++.h>
using namespace std;
void InsertionSort(int arr[],int n){
    for(int i = 1; i < n; ++i){
        int key = arr[i];
        int j = i - 1;

        while(j >= 0 && arr[j] > key ){
            arr[j+1] = arr[j];
            --j;
        }
        arr[j+1] = key;

    }
}

int main(){
    int arr[] = {64, 25, 12, 22, 11};
    int n = sizeof(arr)/sizeof(arr[0]);

    InsertionSort(arr,n);

    cout << "Sorted array: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}