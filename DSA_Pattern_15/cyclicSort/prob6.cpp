// Set Mismatch
#include<bits/stdc++.h>
using namespace std;

vector<int> findErrorNums(vector<int>& nums)
{
    int i = 0;
    while(i < nums.size()){
        int correct = nums[i] -1;
        if(nums[i] != nums[correct]){
            swap(nums[i],nums[correct]);
        }else{
            i++;
        }
    }
    for(int i = 0; i< nums.size();i++){
        if(nums[i] != i+1){
            return {nums[i],i+1};
        }
    }
    return {};
}
void printVector(const vector<int>& nums) {
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;
}
int main() {
    vector<int> nums = {1, 2, 2, 4};

    cout << "Original array: ";
    printVector(nums);

    vector<int> result = findErrorNums(nums);

    cout << "Duplicate and missing number: ";
    printVector(result);  // Output: [2, 3]

    return 0;
}