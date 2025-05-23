#include<bits/stdc++.h>
using namespace std;

void heapify(int arr[], int n, int i){
    int largest = i;
    int left = 2*i+1;
    int right = 2*i+2;

    // if left child is larger than the root
    if(left < n && arr[left] > arr[largest])
    {
        largest = left;
    }

    //If the right child is larger than the largest so far
    if(right < n && arr[right] > arr[largest]){
        largest  = right;
    }

    // if the largest is not the root
    if(largest != i){
        swap(arr[i],arr[largest]);
        heapify(arr,n,largest);
    }
}

void heapSort(int arr[],int n){

    //Build a Max Heap
    for(int i = n/2 - 1; i >= 0; --i){
        heapify(arr,n,i);
    }

    // Extract elements from the heap one by one
    for(int i = n-1; i > 0; --i){

        // Move the current root(Largest) to the end
        swap(arr[0],arr[i]);
    
    // Call heapify on the reduced heap
    heapify(arr, i, 0);
    }
}
int main()
{
    int arr[] = {12,11,13,5,6,7};
    int n = sizeof(arr)/sizeof(arr[0]);

    heapSort(arr,n);
    cout<< "Sorted Array : ";
    for(int num : arr){
        cout << num << " ";
    }
    cout<<endl;
    return 0;
}