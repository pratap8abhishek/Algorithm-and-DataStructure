#include<bits/stdc++.h>
using namespace std;
void lowestMissing(int arr[],int n){
    map<int,int> mp;
    for(int i=0;i<n;i++){
        mp[arr[i]] = i;
    }
//     for (auto pair : mp) {
//         cout << "Key: " << pair.first << " Value: " << pair.second <<endl;
//     }
for(int i=1;i<){

}
}
int main(){
    int arr[] = {2,3,4,-1,10,-15};
    int n = sizeof(arr)/sizeof(arr[0]);
    lowestMissing(arr,n);
    return 0;
}
