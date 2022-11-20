//leetcode.com/problems/number-of-provinces/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    class disjointSet {
        vector<int> parent;
        vector<int> rank;
        public:
        disjointSet(int n) {
            parent.resize(n + 1);
            rank.resize(n + 1, 0);
            for (int i = 0; i <= n; ++i)
                parent[i] = i;
        }
        
        int find(int node) {
            if (parent[node] == node)
                return node;
            parent[node] = find(parent[node]);
            return parent[node];
        }
        
        void unionByRank(int u, int v) {
            int parentOfU = find(u);
            int parentOfV = find(v);
            if (parentOfU == parentOfV)
                return;
            if (rank[parentOfU] < rank[parentOfV])
                parent[parentOfU] = parentOfV;
            else if (rank[parentOfV] < rank[parentOfU])
                parent[parentOfV] = parentOfU;
            else {
                parent[parentOfV] = parentOfU;
                ++rank[parentOfU];
            }
        }
    };
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        disjointSet ds(isConnected.size());
        for (int rows = 0; rows < isConnected.size(); ++rows)
            for (int cols = 0; cols < isConnected[0].size(); ++cols)
                if (isConnected[rows][cols])
                    ds.unionByRank(rows, cols);
        
        int provinces = 0;
        for (int i = 0; i < isConnected.size(); ++i)
            if (ds.find(i) == i)
                ++provinces;
        
        return provinces;
    }
};