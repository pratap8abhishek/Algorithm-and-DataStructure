#include<bits/stdc++.h>
using namespace std;

 bool detect(int src, vector<vector<int>>& adj, int vis[]) {
        vis[src] = 1;
        queue<pair<int, int>> q;  // {node, parent}
        q.push({src, -1});
        
        while (!q.empty()) {
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();
            
            for (auto adjacentNode : adj[node]) {
                if (!vis[adjacentNode]) {
                    vis[adjacentNode] = 1;
                    q.push({adjacentNode, node});
                } else if (parent != adjacentNode) {
                    // Cycle detected
                    return true;
                }
            }
        }
        return false;  // No cycle detected
    }



  bool isCycle(vector<vector<int>>& adj) {
        int V = adj.size();  // Initialize V correctly
        int vis[V] = {0};    // Visited array
        
        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                if (detect(i, adj, vis)) {
                    return true;  // Cycle detected
                }
            }
        }
        return false;  // No cycle detected
    }