#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> bellman_ford(int V, vector<vector<int>>& edges, int S) {
        vector<int> shortestDistance(V, 1e8);
        shortestDistance[S] = 0;
        
        for (int i = 0; i < V - 1; ++i) {
            for (auto edge: edges) {
                int u = edge[0];
                int v = edge[1];
                int edgeWeight = edge[2];
                if (shortestDistance[u] != 1e8 && shortestDistance[u] + edgeWeight < shortestDistance[v]) {
                    shortestDistance[v] = shortestDistance[u] + edgeWeight;
                }
            }
        }
        
        //One more iteration for cycle detection
        for (auto edge: edges) {
            int u = edge[0];
            int v = edge[1];
            int edgeWeight = edge[2];
            if (shortestDistance[u] != 1e8 && shortestDistance[u] + edgeWeight < shortestDistance[v]) 
                return {-1};
        }
        
        return shortestDistance;
    }
};