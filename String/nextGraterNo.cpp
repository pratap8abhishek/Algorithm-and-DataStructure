#include <bits/stdc++.h>
using namespace std;
void swap(char *a,char *b)
{
    char temp = *a;
    *a = *b;
    *b = temp;
}
void nextGrater(char arr[],int n)
{
    int i,j;
    for( i = n-1;i>0;i--){
        if(arr[i]>arr[i-1])
        break;
    }
    if(i==0)
    {
        cout<<"Next Number is Not Possible";
        return;
    }

    int x = arr[i-1];
    int smallest = i;
    
    for(j = i+1;j<n;j++)
    if(arr[j]>x && arr[j]<arr[smallest])
    smallest = j;

    swap(&arr[smallest],&arr[i-1]);
     sort(arr + i, arr + n);
  
    cout << "Next number with same set of digits is " << arr;
  
    return;
}

int main()
{
    char arr[] = "218765";
    nextGrater(arr,6);
}