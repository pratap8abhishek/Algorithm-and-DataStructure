#include<bits/stdc++.h>
using namespace std;
bool isSafe(int newx,int newy,vector<vector<bool>> &vis,vector<vector<int>> &arr,int n){
    if((newx >= 0 && newx < n)&&(newy>=0 &&newy <n)&&vis[newx][newy]!=1 && arr[newx][newy] == 1){
        return true;
    }
    else
        return false;
}
vector solve(int x,int y,vector<vector<int>> &arr,int n,vector<string> &ans,vector<vector<bool>> &vis, string path){
    //Base Case
    if(x == n-1 && y == n-1){
      ans.push_back(path);
      return;
    }
     vis[x][y] = 1;
    //Down
    if(isSafe(x+1,y,vis,arr,n)){
        solve(x+1,y,arr,n,ans,vis,path +'D');
    }
    //UP
    if(isSafe(x-1,y,vis,arr,n)){
        solve(x-1,y,arr,n,ans,vis,path +'U');
    }
    //Left
    if(isSafe(x,y-1,vis,arr,n)){
        solve(x,y-1,arr,n,ans,vis,path +'L');
    }
    //Right
    if(isSafe(x,y+1,vis,arr,n)){
       
        solve(x,y+1,arr,n,ans,vis,path +'R');
    }
    vis[x][y] = 0;
    
}


int main()
{
   vector<vector<int>> arr = {
    {1,0,0,0},
    {1,1,0,1},
    {1,1,0,0},
    {0,1,1,1}};
    vector<vector<bool>>visited(n,vector<bool>(n,0));

    int n = arr.size();
    vector<string> result;
    string currentPath = "";
    if(arr[0][0] ==0)
    return result;

    solve(0,0,arr,n,result,visited,currentPath);

    // if(result.size() == 0)
    //    cout<< -1;
    // else
    //   for(int i=0;i<result.size();i++)
    //    cout<<result[i]<<" ";
return 0;
}
