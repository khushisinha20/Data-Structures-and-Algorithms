//leetcode.com/problems/most-stones-removed-with-same-row-or-column/

#include <bits/stdc++.h>
using namespace std;

class DisjointSet {
    vector<int> rank;
    map<int, int> parent;
    int components;

public:
    DisjointSet(int n) : components(0) {
        rank.resize(n, 1);
    }

    int find(int node) {
        if (parent[node] == node)
            return node;
        return parent[node] = find(parent[node]);
    }

    void unify(int x, int y) {
        int xParent = find(x);
        int yParent = find(y);

        if (xParent == yParent)
            return;

        if (rank[xParent] < rank[yParent])
            parent[xParent] = yParent;
        else if (rank[xParent] > rank[yParent])
            parent[yParent] = xParent;
        else {
            parent[xParent] = yParent;
            ++rank[yParent];
        }

        --components;
    }

    void add(int x) {
        if (parent.find(x) == parent.end()) {
            parent[x] = x;
            ++components;
        }
    }

    int getComponents() const {
        return components;
    }
};

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();

        int maxRow = getMaxRow(stones);
        int maxCol = getMaxCol(stones);

        DisjointSet dsu(maxRow + maxCol + 2); 
        int threshold = maxRow + 1;

        for (auto& stone: stones) {
            dsu.add(stone[0]);
            dsu.add(threshold + stone[1]);
            dsu.unify(stone[0], threshold + stone[1]);
        }

        return n - dsu.getComponents();
    }

private:
    int getMaxRow(const vector<vector<int>>& stones) {
        int maxRow = 0;
        for (const auto& stone : stones) {
            maxRow = max(maxRow, stone[0]);
        }
        return maxRow;
    }

    int getMaxCol(const vector<vector<int>>& stones) {
        int maxCol = 0;
        for (const auto& stone : stones) {
            maxCol = max(maxCol, stone[1]);
        }
        return maxCol;
    }
};