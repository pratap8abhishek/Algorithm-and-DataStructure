//  find first missing +ve





#include<bits/stdc++.h>
using namespace std;

int findmissingPositive(vector<int>& nums)
{
    int i = 0;
    while(i < nums.size()){
        int correct = nums[i] - 1;
        if(nums[i] > 0 && nums[i] < nums.size() && nums[i] != nums[correct]){
            swap(nums[i],nums[correct]);
        }else{
            i++;
        }
    }
    for(int i = 0; i < nums.size();i++){
        if(nums[i] != i+1)
           return i+1;
    }
    return nums.size() + 1;
}

void printVector(const vector<int>& nums) {
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;
}

int main()
{
    vector<int> nums = {3,4,-1,1};


    int missing = findmissingPositive(nums);

    cout << "First missing positive: " << missing << endl;

    return 0;
}