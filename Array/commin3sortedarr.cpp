#include<bits/stdc++.h>
using namespace std;
vector<int>

int main()
{
    vector<int> A = {1,5,10,20,30};
    vector<int> B = {5,13,15,20};
    vector<int> C = {5,20};

    vector<int> ans = commonElements(A,B,C);
    cout<<"Common Elements: ";
    for(int i=0;i<ans.size();i++){
        cout << ans[i] << " ";
    }
    return 0;
}