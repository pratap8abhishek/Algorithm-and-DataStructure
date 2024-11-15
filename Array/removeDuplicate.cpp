#include<bits/stdc++.h>
using namespace std;

int removeDuplicate(vector<int>& arr){
    int n = arr.size();
    if(n <=1)
    return n;

    sort(arr.begin(), arr.end());
    
    int idx = 1;
    for(int i = 1;i<n;i++){
     if(arr[i]!=arr[i-1]){
         arr[idx++] = arr[i];
     }
 } 
 return idx;
}
int main()
{
    vector<int> arr = {2,1,2,2,3,4,4,4,5,5};
    int n = removeDuplicate(arr);
    for(int i=0;i<n;i++)
    cout<< arr[i]<<" ";
    return 0;
}