    int orangesRotting(vector<vector<int>>& mat) {
        // Code here 
           int n = mat.size();
    int m = mat[0].size();
    
    queue<pair<pair<int, int>, int>> q;  
    vector<vector<int>> vis(n, vector<int>(m, 0));
    
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (mat[i][j] == 2) {
                q.push({{i, j}, 0});
                vis[i][j] = 1;
            }
        }
    }
    
    int tm = 0;
    int drow[] = {-1, 0, +1, 0};
    int dcol[] = {0, 1, 0, -1};
    
    while (!q.empty()) {
        int r = q.front().first.first;
        int c = q.front().first.second;
        int t = q.front().second;
        q.pop();
        tm = max(tm, t);  
        
        for (int i = 0; i < 4; i++) {
            int nrow = r + drow[i];
            int ncol = c + dcol[i];
            
           
            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && mat[nrow][ncol] == 1 && !vis[nrow][ncol]) {
                q.push({{nrow, ncol}, t + 1});
                vis[nrow][ncol] = 1;  
                mat[nrow][ncol] = 2;  
            }
        }
    }
    
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (mat[i][j] == 1) {
                return -1; 
            }
        }
    }
    
    return tm;
}