//leetcode.com/problems/redundant-connection-ii/description/

#include <bits/stdc++.h>
using namespace std;

class DSU {
public:
    vector<int> parent;
    vector<int> rank;

    DSU(int n) {
        parent.resize(n + 1);
        rank.resize(n + 1, 1);
        for (int i = 1; i <= n; ++i)
            parent[i] = i;
    }

    int find(int x) {
        if (x != parent[x])
            parent[x] = find(parent[x]);
        return parent[x];
    }

    bool unite(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);

        if (rootX == rootY)
            return false;

        if (rank[rootX] > rank[rootY])
            parent[rootY] = rootX;
        else if (rank[rootX] < rank[rootY])
            parent[rootX] = rootY;
        else {
            parent[rootY] = rootX;
            ++rank[rootX];
        }

        return true;
    }
};

class Solution {
public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> parent(n + 1, 0);
        vector<int> candA, candB;

        for (auto& edge: edges) {
            int u = edge[0];
            int v = edge[1];
            if (parent[v] == 0)
                parent[v] = u;
            else {
                candA = {parent[v], v};
                candB = {u, v};
                edge[1] = 0;
            }
        }

        DSU dsu(n);
        for (auto& edge: edges) {
            if (edge[1] == 0)
                continue;
            int u = edge[0];
            int v = edge[1];
            if (!dsu.unite(u, v))
                return candA.empty() ? edge : candA;
        }

        return candB;
    }
};
