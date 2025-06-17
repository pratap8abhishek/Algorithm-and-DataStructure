#include<bits/stdc++.h>
using namespace std;

int subarraySum(vector<int>& nums,int k)
{
    unordered_map<int,int> prefixCount;
    prefixCount[0] = 1;

    int count = 0, sum = 0;

    for(int num: nums){
        sum += num;

        if(prefixCount.find(sum - k) != prefixCount.end()){
            count += prefixCount[sum - k];
        }
        prefixCount[sum]++;
    }
    return count;
}
int main() {
    vector<int> nums = {1, 1, 1};
    int k = 2;

    cout << "Number of subarrays with sum " << k << " = " << subarraySum(nums, k) << endl;
    return 0;
}
