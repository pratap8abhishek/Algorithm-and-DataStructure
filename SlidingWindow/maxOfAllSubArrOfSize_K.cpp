#include<bits/stdc++.h>
using namespace std;
vector<int> max_of_subarrays(const vector<int>& arr, int K) {
    // Create a deque to store indices
    deque<int> deq;  
    vector<int> result;

    for (int i = 0; i < arr.size(); i++) 
    {
        // Remove elements not within the current window
        if (!deq.empty() && deq.front() == i - K) 
        {
            deq.pop_front();
        }

        // Remove elements from the deque if they are smaller than the current element
        while (!deq.empty() && arr[deq.back()] <= arr[i]) 
        {
            deq.pop_back();
        }

        // Add the current element index to the deque
        deq.push_back(i);

        // If we've reached the window size, append the maximum to the result
        if (i >= K - 1) 
        {
            result.push_back(arr[deq.front()]);
        }
    }
    return result;
}
int main()
{
    vector<int> arr = {10,5,7,2,8,7};
    int k = 3;
    vector<int> result = max_of_subArray(arr,k);
    for(int val : result){
        cout << val <<" ";
    }
    return 0;
}