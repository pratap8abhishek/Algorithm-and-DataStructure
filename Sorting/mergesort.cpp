#include <bits/stdc++.h>
using namespace std;

int merge(int arr[],int l,int mid,int r){
  int n1 = mid-l+1;
  int n2 = r-mid;
  
  int L[n1], M[n2];

  for(int i=0;i<n1;i++)
    L[i] = arr[l+i]; 
  for(int j=0;j<n2;j++)
    M[j] = arr[mid+1+j];

  int i,j,k;
  i=0;
  j=0;
  k=l;

  while(i<n1 && j<n2){
    if(L[i]<=M[j]){
        arr[k] = L[i];
        i++;
    }else{
        arr[k] = M[j];
        j++;
    }
    k++;
  }
  while(i<n1){
    arr[k] = L[i];
    i++;
    k++;
  }
  while(j<n2){
    arr[k] = M[j];
    j++;
    k++;
  }
}
int mergeSort(int arr[],int l,int r){
    if(l<r){
        int mid = l+(r-l)/2;
        mergeSort(arr,l,mid);
        mergeSort(arr,mid+1,r);

        merge(arr,l,mid,r);
    }
}
int printArray(int arr[],int n){
   for(int i=0;i<n-1;i++){
    cout<<arr[i]<<" "<<endl;
   }
}
int main()
{
    int arr[] = {12,4,56,76,5,34,6,};
    int size = sizeof(arr) / sizeof(arr[0]);
    mergeSort(arr,0,size-1);

    cout<<"Sorted array is"<<endl;
    printArray(arr,size);
    return 0;
}