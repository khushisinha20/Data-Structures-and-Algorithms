//leetcode.com/problems/number-of-good-paths/description/

#include <bits/stdc++.h>
using namespace std;

class DSU {
public:
    vector<int> parent, rank;

    DSU(int n) {
        parent.resize(n);
        iota(parent.begin(), parent.end(), 0);
        rank.resize(n, 1);
    }

    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }

    void unite(int x, int y) {
        int parentX = find(x);
        int parentY = find(y);

        if (parentX == parentY)
            return;

        if (rank[parentX] < rank[parentY]) {
            parent[parentX] = parentY;
        } else if (rank[parentX] > rank[parentY]) {
            parent[parentY] = parentX;
        } else {
            parent[parentX] = parentY;
            ++rank[parentY];
        }
    }
};

class Solution {
public:
    vector<vector<int>> createGraph(int& n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n);

        for (auto& edge: edges) {
            int u = edge[0];
            int v = edge[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        return graph;
    }

    int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
        int n = vals.size();
        vector<vector<int>> graph = createGraph(n, edges);

        map<int, vector<int>> valToNodes;
        for (int i = 0; i < n; ++i)
            valToNodes[vals[i]].push_back(i);

        DSU dsu(n);
        int result = 0;

        for (auto& [val, nodes]: valToNodes) {
            for (int u: nodes) {
                for (int v: graph[u]) {
                    if (vals[v] <= val) {
                        dsu.unite(u, v);
                    }
                }
            }

            unordered_map<int, int> groupCount;
            for (int u: nodes) {
                int root = dsu.find(u);
                ++groupCount[root];
            }

            for (auto& [_, count]: groupCount)
                result += (count * (count + 1)) / 2;
        }

        return result;
    }
};
