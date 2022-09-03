#include <bits/stdc++.h>
using namespace std;

class Solution {
    void dfs(int node, vector<int> adj[], vector<bool>& visited, vector<int>& vertices) {
        visited[node] = true;
        vertices.push_back(node);
        
        for (auto it: adj[node]) {
            if (!visited[it])
                dfs(it, adj, visited, vertices);
        }
    }
    
  public:
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        vector<bool> visited(V, false);
        int start = 0;
        vector<int> vertices;
        dfs(start, adj, visited, vertices);
        return vertices;
    }
};