#include<bits/stdc++.h>
using namespace std;
int reverseAnArray(int arr[], int l, int r)
{
    if(l>=r) return 0;

    swap(arr[l],arr[r]);
    reverseAnArray(arr,l+1,r-1);
}

int main()
{
     int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    reverseAnArray(arr, 0, n - 1);

    cout << "Reversed array is: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
   return 0;  
}