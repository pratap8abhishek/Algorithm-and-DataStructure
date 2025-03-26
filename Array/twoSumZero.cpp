#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> twoSum(vector<int>& nums) {
    vector<vector<int>> result;
    sort(nums.begin(), nums.end()); // Sorting to use two-pointer approach

    int left = 0, right = nums.size() - 1;

    while (left < right) {
        int sum = nums[left] + nums[right];

        if (sum == 0) {
            result.push_back({nums[left], nums[right]});
            left++;
            right--;

            // Skip duplicate values to avoid duplicate pairs
            while (left < right && nums[left] == nums[left - 1]) left++;
            while (left < right && nums[right] == nums[right + 1]) right--;
        } 
        else if (sum < 0) {
            left++;
        } 
        else {
            right--;
        }
    }

    return result;
}

int main() {
    vector<int> nums = {-1, 0, 1, 2, -1, -4};

    vector<vector<int>> duplets = twoSum(nums);

    cout << "Unique Pairs with sum 0:\n";
    for (auto duplet : duplets) {
        cout << "[";
        for (int num : duplet) {
            cout << num << " ";
        }
        cout << "]\n";
    }

    return 0;
}
