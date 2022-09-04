//practice.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    
    bool bfs(vector<int> adj[], vector<bool> visited, int source) {
        queue<pair<int, int>> q;
        q.push({source, -1});
        visited[source] = true;
        
        while (!q.empty()) {
            int vertex = q.front().first;
            int parent = q.front().second;
            q.pop();
            
            for (auto adjascentVertex: adj[vertex]) {
                if (!visited[adjascentVertex]) {
                    visited[adjascentVertex] = true;
                    q.push({adjascentVertex, vertex});
                } else if (parent != adjascentVertex)
                    return true;
            }
        }
        return false;
    }
    
    bool isCycle(int V, vector<int> adj[]) {
        vector<bool> visited(V + 1, false);
        for (int vertex = 0; vertex < V; ++vertex) {
            if (!visited[vertex]) {
                if (bfs(adj, visited, vertex))
                    return true;
            }
        }
        return false;
    }
};