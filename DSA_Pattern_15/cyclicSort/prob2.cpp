// Missing Number

#include<bits/stdc++.h>
using namespace std;

int missingNumber(vector<int>& nums)
{
  int i = 0;
  while(i < nums.size()){
    int correct = nums[i]-1;

    if(nums[i] > 0 && nums[i] < nums.size() && nums[i] != nums[correct]){
        swap(nums[i],nums[correct]);
    }else{
        i++;
    }
  }

  for(int i = 0; i < nums.size(); i++){
    if(nums[i] != i)  return i;
  }
  
}
void printVector(const vector<int>& nums) {
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;
}

int main(){
  vector<int> nums = {3, 0, 1};

  cout << "Input array: ";
  printVector(nums);

  int missing = missingNumber(nums);

  cout << "Missing number is: " << missing << endl;

  return 0;  
}