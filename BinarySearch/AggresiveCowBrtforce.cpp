#include<bits/stdc++.h>
using namespace std;
bool isCompatible(vector < int > arr,int dist, int cow){
    int n = arr.size();
    int k = arr[0];
    cow--;
    for(int i=1;i<n;i++){
        if(arr[i]-k>=dist){
            cow--;
            if(!cow){
                return true;
            }
            k = arr[i];
        }
    }
    return false;
}

int main(){
    int n=5,m=3;
    vector<int> arr {1,2,8,4,5};
    sort(arr.begin(),arr.end());
    int maxD = arr[n-1]-arr[0];
    int ans = INT_MIN;
    for(int d = 1;d<=maxD;d++){
        bool possible = isCompatible(arr,d,m);
        if(possible){
            ans = max(ans,d);
        }
    }
    cout<<"The largest min distance is : "<<ans;
}