//practice.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    bool dfs(int vertex, vector<int> adj[], vector<bool>& visitedNode, vector<bool>& visitedPath) {
        visitedNode[vertex] = true;
        visitedPath[vertex] = true;
        
        for (auto adjacentVertex: adj[vertex]) {
            if (!visitedNode[adjacentVertex]) {
                if (dfs(adjacentVertex, adj, visitedNode, visitedPath))
                    return true;
            } else if (visitedPath[adjacentVertex])
                return true;
        }
        
        visitedPath[vertex] = false;
        return false;
    }
    
    bool isCyclic(int V, vector<int> adj[]) {
        vector<bool> visitedNode(V, false);
        vector<bool> visitedPath(V, false);
        for (int vertex = 0; vertex < V; ++vertex) {
            if (!visitedNode[vertex]) {
                if (dfs(vertex, adj, visitedNode, visitedPath))
                    return true;
            }
        }
        return false;
    }
};