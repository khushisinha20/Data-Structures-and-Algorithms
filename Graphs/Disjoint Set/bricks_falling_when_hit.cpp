//leetcode.com/problems/bricks-falling-when-hit/

#include <bits/stdc++.h>
using namespace std;

class UnionFind {
    vector<int> parent;
    vector<int> rank;
    vector<int> count;

public:
    UnionFind(int size) {
        parent.resize(size);
        rank.resize(size, 1);
        count.resize(size, 1);

        for (int i = 0; i < size; ++i)
            parent[i] = i;
    }

    int find(int x) {
        if (x != parent[x])
            parent[x] = find(parent[x]);

        return parent[x];
    }

    void unite(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);

        if (rootX != rootY) {
            if (rank[rootX] > rank[rootY]) {
                parent[rootY] = rootX;
                count[rootX] += count[rootY];
                count[rootY] = 0;
            } else if (rank[rootX] < rank[rootY]) {
                parent[rootX] = rootY;
                count[rootY] += count[rootX];
                count[rootX] = 0;
            } else {
                parent[rootY] = rootX;
                count[rootX] += count[rootY];
                count[rootY] = 0;
                ++rank[rootX];
            }
        }
    }

    int getCount(int x) {
        return count[find(x)];
    }
};

class Solution {
public:
    vector<int> hitBricks(vector<vector<int>>& grid, vector<vector<int>>& hits) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> originalGrid = grid;

        for (auto& hit: hits)
            grid[hit[0]][hit[1]] = 0;

        UnionFind uf(m * n + 1);
        auto index = [&](int r, int c) {
            return r * n + c;
        };
        int top = m * n;

        for (int row = 0; row < m; ++row) {
            for (int col = 0; col < n; ++col) {
                if (grid[row][col] == 1) {
                    if (row == 0)
                        uf.unite(index(row, col), top);

                    if (row > 0 and grid[row - 1][col] == 1)
                        uf.unite(index(row, col), index(row - 1, col));

                    if (col > 0 and grid[row][col - 1] == 1)
                        uf.unite(index(row, col), index(row, col - 1));
                }
            }
        }

        vector<int> result(hits.size(), 0);

        for (int i = hits.size() - 1; i >= 0; --i) {
            int row = hits[i][0];
            int col = hits[i][1];

            if (originalGrid[row][col] == 0)
                continue;

            int countBeforeRemoving = uf.getCount(top);
            grid[row][col] = 1;
            if (row == 0)
                uf.unite(index(row, col), top);

            for (auto [dRow, dCol]: vector<pair<int, int>>{{1, 0}, {-1, 0}, {0, 1}, {0, -1}}) {
                int newRow = row + dRow;
                int newCol = col + dCol;
                if (newRow >= 0 and newRow < m and newCol >= 0 and newCol < n and grid[newRow][newCol] == 1)
                    uf.unite(index(row, col), index(newRow, newCol));
            }

            int countAfterRemoving = uf.getCount(top);
            result[i] = max(countAfterRemoving - countBeforeRemoving - 1, 0);
        }

        return result;
    }
};
