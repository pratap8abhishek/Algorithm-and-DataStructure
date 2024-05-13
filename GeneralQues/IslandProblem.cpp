void bfs(int row,int col,vector<vector<int>>& vis, vector<vector<int>>& grid){
    vis[row][col] = 1;
    queue<pair<int,int>> q;
    q.push({row,col});
    int n = grid.size();
    int m = grid[0].size();
    while(!q.empty()){
        int row = q.front().first;
        int col = q.front().second;
        q.pop();

        for(int delrow = -1; delrow<=1; delrow++){
            for(int delcol = -1; delcol<=1, delcol++){
                int nrow = row + delrow;
                int ncol = col + delcol;

                if(nrow >=0 && nrow <n && ncol >=0 &&ncol<m && grid[nrow][col] =='1' && !vis[nrow][ncol]){
                    vis[nrow][col] = 1;
                    q.push({nrow,ncol});
                }
            }
        }
    }
}
int numIsland(vector<vector<char>>& gird){
    int n = grid.size();
    int m = grid[0].size();

    vector<vector<int>> vis(n,vector<int>(m,0));
    int cnt = 0;
    for(int row = 0, row<n; row++){
        for(col = 0; col<m; col++){
           if(!vis[row][col]){
            cnt++;
            dfs(row,col,vis,grid);
           }
        }
    }
    return cnt;
}