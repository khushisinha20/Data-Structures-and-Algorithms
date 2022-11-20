//leetcode.com/problems/number-of-operations-to-make-network-connected/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    class disjointSet {
        vector<int> rank;
        vector<int> parent;
        public:
        disjointSet(int n) {
            rank.resize(n + 1, 0);
            parent.resize(n + 1);
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
    
    int findExtraConnections(vector<vector<int>>& connections, disjointSet& ds) {
        int extraConnections = 0;
        for (auto connection: connections) {
            if (ds.find(connection[0]) == ds.find(connection[1]))
                ++extraConnections;
            else 
                ds.unionByRank(connection[0], connection[1]);
        }
        return extraConnections;
    }
    
    int findTotalComponents(int n, disjointSet& ds) {
        int components = 0;
        for (int i = 0; i < n; ++i) 
            if (ds.find(i) == i)
                ++components;
        return components;
    }
    
    int makeConnected(int n, vector<vector<int>>& connections) {
        disjointSet ds(n);
        int extraConnections = findExtraConnections(connections, ds);
        int components = findTotalComponents(n, ds);
        if (extraConnections >= components - 1)
            return components - 1;
        return -1;
    }
};