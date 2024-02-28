//www.geeksforgeeks.org/problems/detect-cycle-using-dsu/1

#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
    vector<int> parent;
    vector<int> rank;
    
    int find(int x) {
        if (parent[x] == x)
            return x;
        return parent[x] = find(parent[x]);
    }
    
    void Union(int x, int y) {
        int xParent = find(x);
        int yParent = find(y);
        
        if (rank[xParent] > rank[yParent])
            parent[yParent] = xParent;
        else if (rank[xParent] < rank[yParent])
            parent[xParent] = yParent;
        else {
            parent[xParent] = yParent;
            ++rank[yParent];
        }
    }
    
    int detectCycle(int V, vector<int>adj[]) {
        parent.resize(V);
        rank.resize(V, 0);
        
        for (int i = 0; i < V; ++i)
            parent[i] = i;
            
        for (int node = 0; node < V; ++node) {
            for (int adjacentNode: adj[node]) {
                if (node < adjacentNode) {
                    if (find(node) == find(adjacentNode)) {
                        return true;
                    } else {
                        Union(node, adjacentNode);
                    }
                }
            }
        }
        
        return false;
	}
};
