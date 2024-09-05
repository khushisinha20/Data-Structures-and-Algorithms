//leetcode.com/problems/graph-connectivity-with-threshold/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    class UnionFind {
        vector<int> parent;
        vector<int> rank;

    public:
        UnionFind(int size) {
            parent.resize(size);
            rank.resize(size, 1);

            for (int i = 0; i < size; ++i)
                parent[i] = i;
        }

        int find(int u) {
            if (u != parent[u]) {
                parent[u] = find(parent[u]);
            }
            return parent[u];
        }

        void unionSets(int u, int v) {
            int rootU = find(u);
            int rootV = find(v);
            if (rootU != rootV) {
                if (rank[rootU] > rank[rootV])
                    parent[rootV] = rootU;
                else if (rank[rootU] < rank[rootV])
                    parent[rootU] = rootV;
                else {
                    parent[rootV] = rootU;
                    ++rank[rootU];
                }
            }
        }
    };

    vector<bool> areConnected(int n, int threshold, vector<vector<int>>& queries) {
        UnionFind uf(n + 1);

        for (int divisor = threshold + 1; divisor <= n; ++divisor) {
            for (int multiple = divisor * 2; multiple <= n; multiple += divisor) {
                uf.unionSets(divisor, multiple);
            }
        }

        vector<bool> result;
        for (auto& query: queries) {
            result.push_back(uf.find(query[0]) == uf.find(query[1]));
        }

        return result;
    }
};
