#include<bits/stdc++.h>
using namespace std;

void dfs(int node,vector<int> adj[],int vis[], vector<int> &ls){
    vis[node] = 1;
    ls.push_back(node);
    //travers all its neighbours
    for(auto it : adj[node]){
        if(!vis[it]){
            dfs(it,adj,vis,ls);
        }
    }
}
vector<int> dfsOfGraph(int V,vector<int> adj[]){
    int vis[V] = {0};
    int start = 0;
    vector<int> ls;
    dfs(start, adj, vis, ls);
    return ls;
   }  

int main() {
    int V = 5; // Number of vertices
    vector<int> adj[V]; // Adjacency list

    // Add edges to the graph
    adj[0].push_back(1);
    adj[0].push_back(2);
    adj[1].push_back(0);
    adj[1].push_back(3);
    adj[2].push_back(0);
    adj[3].push_back(1);
    adj[4].push_back(4);

    // Perform DFS
    vector<int> result = dfsOfGraph(V, adj);

    // Print the DFS traversal
    cout << "DFS Traversal of the graph: ";
    for (int node : result) {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}