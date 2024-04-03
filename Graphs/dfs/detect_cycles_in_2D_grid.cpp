//leetcode.com/problems/detect-cycles-in-2d-grid/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    bool dfs(vector<vector<char>>& grid, vector<vector<bool>>& visited, int row, int col, int prevRow, int prevCol, char current) {
        if (row < 0 || row >= grid.size() || col < 0 || col >= grid[0].size() || grid[row][col] != current)
            return false;

        if (visited[row][col])
            return true;

        visited[row][col] = true;

        for (auto& direction: directions) {
            int newRow = row + direction[0];
            int newCol = col + direction[1];
            if (newRow != prevRow || newCol != prevCol) {
                if (dfs(grid, visited, newRow, newCol, row, col, current)) {
                    return true;
                }
            }
        }

        return false;
    }

    bool containsCycle(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<bool>> visited(n, vector<bool>(m, false));

        for (int row = 0; row < n; ++row) {
            for (int col = 0; col < m; ++col) {
                if (!visited[row][col] && dfs(grid, visited, row, col, -1, -1, grid[row][col]))
                    return true;
            }
        }

        return false;
    }
};
