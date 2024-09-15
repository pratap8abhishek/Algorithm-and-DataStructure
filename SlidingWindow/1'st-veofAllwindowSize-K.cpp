#include<bits/stdc++.h>
using namespace std;
void findFirstNegativeNumber(const vector<int>& arr,int k)
{
    queue<int> negatives;
    int n = arr.size();
    for(int i=0;i<n;i++){
        if(!negatives.empty() && negatives.front() < i-k+1){
            negatives.pop();
        }

        if(arr[i]<0){
            negatives.push(i);
        }
        if(i >= k-1){
            if(!negatives.empty()){
                cout<< arr[negatives.front()]<<" ";
            }else{
                cout<<"0";
            }
        }
    }
    cout<<endl;

}
int main()
{
    vector<int> arr = {12,-1,-7,8,-15,30,16,28};
    int k = 3;
    findFirstNegativeNumber(arr,k);
    return 0;
}