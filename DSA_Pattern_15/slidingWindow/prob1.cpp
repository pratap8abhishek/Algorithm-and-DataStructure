#include <iostream>
#include <vector>
using namespace std;

int maxSumSlidingWindow(vector<int>& arr, int k) {
    int maxSum = 0, windowSum = 0;

    // Compute sum of first 'k' elements
    for (int i = 0; i < k; i++)
        windowSum += arr[i];

    maxSum = windowSum;

    // Slide the window from index k to end
    for (int i = k; i < arr.size(); i++) {
        windowSum += arr[i] - arr[i - k]; // Slide the window
        maxSum = max(maxSum, windowSum);
    }

    return maxSum;
}

int main() {
    vector<int> arr = {2, 1, 5, 1, 3, 2};
    int k = 3;
    cout << "Maximum Sum: " << maxSumSlidingWindow(arr, k) << endl; // Output: 9
    return 0;
}
