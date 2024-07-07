
// -----------------------Kadane’s Algorithm--------------------

#include <iostream>
#include <climits>
using namespace std;
int max_subArraySum(int a[],int n){
    int max_sum = INT_MIN;
    int curr_sum = 0;
    for(int i=0; i<n; i++){
        curr_sum = curr_sum + a[i];
        if(max_sum < curr_sum)
        max_sum = curr_sum;

        if(curr_sum < 0)
        curr_sum = 0;
    }
    return max_sum;
}

int main()
{
   int arr[] = {-2,-3,4,-1,-2,1,5,-3};
   int n = sizeof(arr)/sizeof(arr[0]);
   int max_sum = max_subArraySum(arr,n);
   cout<<"max contigous sum is : "<<max_sum;
   return 0; 
}