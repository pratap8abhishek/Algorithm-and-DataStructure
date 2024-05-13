#include<bits/stdc++.h>
using namespace std;
int removeDuplicate(int arr[],int n)
{
    unordered_map<int,int> m;
    for(int i=0;i<n;i++){
        m[arr[i]]++;
    }
     for (auto it : m) {
        if (it.second > 1) {
            cout << it.first << " "; 
        }
    }
    cout << endl;
}
int main(){
    int arr[] = {1,1,1,2,2,8,4,4};
    int n = sizeof(arr)/sizeof(arr[0]);
    removeDuplicate(arr,n);
    return 0;
}