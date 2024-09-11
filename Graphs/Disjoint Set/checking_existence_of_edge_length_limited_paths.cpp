//leetcode.com/problems/checking-existence-of-edge-length-limited-paths/

#include <bits/stdc++.h>
using namespace std;

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

    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }

    void unionSets(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);

        if (rootX != rootY) {
            if (rank[rootX] > rank[rootY])
                parent[rootY] = rootX;
            else if (rank[rootY] > rank[rootX])
                parent[rootX] = rootY;
            else {
                parent[rootY] = rootX;
                ++rank[rootX];
            }
        }
    }
};

class Solution {
public:
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries) {
        int m = edgeList.size();
        int q = queries.size();

        sort(edgeList.begin(), edgeList.end(), [](vector<int>& a, vector<int>& b) {
            return a[2] < b[2];
        });

        vector<pair<int, vector<int>>> indexedQueries;
        for (int i = 0; i < q; ++i)
            indexedQueries.push_back({i, queries[i]});

        sort(indexedQueries.begin(), indexedQueries.end(), [](pair<int, vector<int>>& a, pair<int, vector<int>>& b) {
            return a.second[2] < b.second[2];
        });

        UnionFind uf(n);
        vector<bool> result(q, false);
        int edgeIndex = 0;

        for (auto& [index, query]: indexedQueries) {
            int p = query[0];
            int q = query[1];
            int limit = query[2];

            while (edgeIndex < m and edgeList[edgeIndex][2] < limit) {
                uf.unionSets(edgeList[edgeIndex][0], edgeList[edgeIndex][1]);
                ++edgeIndex;
            }

            if (uf.find(p) == uf.find(q))
                result[index] = true;
        }

        return result;
    }
};
