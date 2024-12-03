#include<bits/stdc++.h>
using namespace std;
void bfs(int row,int col, vector<vector<int>> & vis,vector<vector<char>>& grid){
      vis[row][col] = 1;
      queue<pair<int,int>> q;
      q.push({row,col});
      int n = grid.size();
      int m = grid[0].size();
      
      while(!q.empty()){
          int row = q.front().first;
          int col = q.front().second;
          q.pop();
          
        // travers in the neighbour and mark them if its land
        for(int delrow = -1;delrow <= 1;delrow++){
            for(int delcol = -1;delcol <= 1;delcol++){
                int nebrow = row + delrow;
                int nebcol = col + delcol;
                if(nebrow >= 0 && nebrow < n && nebcol >=0 && nebcol < m 
                && grid[nebrow][nebcol] == '1' && !vis[nebrow][nebcol])
                {
                    vis[nebrow][nebcol] = 1;
                    q.push({nebrow,nebcol});
                }
                
            }
        }
    }
}  
int numIslands(vector<vector<char>>& grid) {
    int n = grid.size();
    int m = grid[0].size();
        
    vector<vector<int>> vis(n, vector<int>(m,0));
    int cnt = 0;
    for(int row = 0; row < n; row++){
        for(int col = 0; col < m; col++){
            if(!vis[row][col] && grid[row][col] == '1'){
                cnt++;
                bfs(row, col,vis,grid);
            }
        }
    }
    return cnt;   
}
int main() {
    vector<vector<char>> M = { { '1', '1', '0', '0', '0' },
                              { '0', '1', '0', '0', '1' },
                              { '1', '0', '0', '1', '1' },
                              { '0', '0', '0', '0', '0' },
                              { '1', '0', '1', '1', '0' } };

    cout << numIslands(M) << endl;

    return 0;
}