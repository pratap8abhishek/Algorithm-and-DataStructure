// Cyclic Sort

#include<bits/stdc++.h>
using namespace std;

void cycleSort(vector<int>& nums){
    int i = 0;
    while(i < nums.size()){
        
    int correct = nums[i] -1
    ;
    if(nums[i] > 0 && nums[i] <= nums.size() && nums[i] != nums[correct]){
        
        swap(nums[i],nums[correct]);
        
    }else{
        
        i++;
    }
  }
}
void printVector(const vector<int>& nums) {
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;
}

int main()
{
    vector<int> nums = {3,5,2,1,4};
    
    cout<<"original Array";
    printVector(nums);
    
    cycleSort(nums);
    
    cout<<"Sorted Array";
    printVector(nums);
    
    return 0;
}