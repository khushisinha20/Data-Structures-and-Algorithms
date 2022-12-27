//practice.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    bool bfs(int& V, vector<int> adj[], int source) {
        queue<pair<int, int>> nodes;
        nodes.push({source, -1});
        vector<bool> visited(V, false);
        visited[source] = true;
        
        while (!nodes.empty()) {
            int node = nodes.front().first;
            int parent = nodes.front().second;
            nodes.pop();
            
            for (auto adjacentNode: adj[node]) {
                if (!visited[adjacentNode]) {
                    nodes.push({adjacentNode, node});
                    visited[adjacentNode] = true;
                } else {
                    if (adjacentNode != parent)
                        return true;
                }
            }
        }
        return false;
    }
  
    bool isCycle(int V, vector<int> adj[]) {
        for (int vertex = 0; vertex < V; ++vertex) {
            if (bfs(V, adj, vertex))
                return true;
        }
        return false;
    }
};