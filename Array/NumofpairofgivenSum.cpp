#include<bits/stdc++.h>
using namespace std;
void pairedElement(int arr[],int sum,int n){
    int low = 0;
    int high = n-1;
    unordered_map<int,int> m;
    while(low < high){
        if(arr[low]+arr[high] == sum){
            if(m.find(arr[low])== m.end() || m.find(arr[high])== m.end()){
                cout<<"The Pair is : ("<<arr[low]<<" ,"<<arr[high]<<")"<<endl;
                m[arr[low]]++;
                m[arr[high]]++;
            }
            low++;
            high--;
        }
        else if(arr[low]+arr[high] >sum){
            high--;
        }
        else{
          low++;     
        }
    }
}


int main(){
    int arr[] = {2,3,4,-2,6,8,3,3};
    int n = sizeof(arr)/sizeof(arr[0]);
    int sum = 6;
    sort(arr,arr+n);
    pairedElement(arr,sum,n);
    return 0;
}