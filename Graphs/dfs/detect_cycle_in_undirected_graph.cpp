//practice.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    
    bool dfs(vector<int> adj[], vector<bool>& visited, int node, int parent) {
        visited[node] = true;
        for (auto adjacentVertex: adj[node]) {
            if (!visited[adjacentVertex]) {
                if (dfs(adj, visited, adjacentVertex, node))
                    return true;
            } else if (adjacentVertex != parent)
                return true;
        }
        return false;
    }
    
    bool isCycle(int V, vector<int> adj[]) {
        vector<bool> visited(V, false);
        for (int i = 0; i < V; ++i) {
            if (!visited[i]) {
                if (dfs(adj, visited, i, -1))
                    return true;
            }
        }
        return false;
    }
};