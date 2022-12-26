#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        vector<int> bfs;
        queue<int> nodes;
        nodes.push(0);
        vector<bool> visited(V);
        visited[0] = true;
        
        while (!nodes.empty()) {
            int currentNode = nodes.front();
            nodes.pop();
            
            bfs.push_back(currentNode);
            
            for (auto adjacentNode: adj[currentNode]) {
                if (!visited[adjacentNode]) {
                    visited[adjacentNode] = true;
                    nodes.push(adjacentNode);
                }
            }
        }
        return bfs;
    }
};