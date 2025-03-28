#include<bits/stdc++.h>
using namespace std;

int partition(vector<int>& arr,int low,int high){
    int pivot = arr[high];

    int i = low - 1;

    for(int j = low; j <= high-1; j++){
        if(arr[j] < pivot){
            i++;
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[i+1],arr[high]);
    return i+1;

}

void quicksort(vector<int>& arr,int low,int high){
    if(low < high){
        int pi = partition(arr,low,high);

        quicksort(arr,low,pi-1);
        quicksort(arr,pi+1,high);
    }
}
int main()
{
    vector<int> arr = {10,7,8,9,1,5};
    int n = arr.size();
    quicksort(arr,0,n-1);

    for(int i= 0;i<n;i++){
        cout<< arr[i]<<" ";
    }
    return 0;
}

// https://jobs.sap.com/job/Bangalore-Developer-560066/1140349501/?feedId=384233&utm_campaign=SAP_Linkedin&utm_source=LinkedinJobPostings