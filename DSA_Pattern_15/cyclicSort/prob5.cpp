// Find All Numbers Disappeared in an Array
#include<bits/stdc++.h>
using namespace std;

vector<int> findDisappearedNumbers(vector<int>& nums) {
  int i = 0;
  while( i < nums.size()){
    int correct = nums[i] -1;
    if(nums[i] != nums[correct]){
        swap(nums[i],nums[correct]);
    }else{
        i++;
    }
  }
  vector<int> result;
  for(int i = 0 ; i < nums.size(); i++){
    if(nums[i] != i+1){
        result.push_back(i+1);
    }
  }
return result;
}
void printVector(const vector<int>& nums) {
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;
}

int main()
{
    vector<int> nums = {4, 3, 2, 7, 8, 2, 3, 1};

    cout << "Original array: ";
    printVector(nums);

    vector<int> disappeared = findDisappearedNumbers(nums);

    cout << "Disappeared numbers: ";
    printVector(disappeared);

    return 0;

}