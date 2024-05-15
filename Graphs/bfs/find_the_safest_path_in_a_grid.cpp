//leetcode.com/problems/find-the-safest-path-in-a-grid/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool liesInsideGrid(int row, int col, vector<vector<int>>& grid) {
        int n = grid.size();
        return row >= 0 && row < n && col >= 0 && col < n;
    }

    vector<vector<int>> getMinimumDistanceFromThief(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> minDist(n, vector<int>(m, INT_MAX));

        queue<pair<int, int>> coordinates;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == 1) {
                    coordinates.push({i, j});
                    minDist[i][j] = 0;
                }
            }
        }

        vector<pair<int, int>> directions = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

        while (!coordinates.empty()) {
            auto [currentRow, currentCol] = coordinates.front();
            coordinates.pop();

            for (auto& [xDirection, yDirection]: directions) {
                int newRow = currentRow + xDirection;
                int newCol = currentCol + yDirection;

                if (liesInsideGrid(newRow, newCol, grid) && minDist[newRow][newCol] > minDist[currentRow][currentCol] + 1) {
                    minDist[newRow][newCol] = minDist[currentRow][currentCol] + 1;
                    coordinates.push({newRow, newCol});
                }
            }
        }

        return minDist;
    }

    int maximumSafenessFactor(vector<vector<int>>& grid) {
        vector<vector<int>> minDist = getMinimumDistanceFromThief(grid);
        vector<pair<int, int>> directions = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
        priority_queue<tuple<int, int, int>> coordSafenessPQ;
        int n = grid.size();

        if (grid[0][0] == 1 || grid[n - 1][n - 1] == 1)
            return 0;

        vector<vector<bool>> visited(n, vector<bool>(n, false));
        visited[0][0] = true;
        coordSafenessPQ.push({minDist[0][0], 0, 0});
        int maxSafenessFactor = 0;

        while (!coordSafenessPQ.empty()) {
            auto [safenessFactor, currentRow, currentCol] = coordSafenessPQ.top();
            coordSafenessPQ.pop();

            if (currentRow == n - 1 && currentCol == n - 1) {
                maxSafenessFactor = max(maxSafenessFactor, safenessFactor);
                continue;
            }

            for (auto& [xDirection, yDirection]: directions) {
                int newRow = currentRow + xDirection;
                int newCol = currentCol + yDirection;

                if (liesInsideGrid(newRow, newCol, grid) && !visited[newRow][newCol]) {
                    visited[newRow][newCol] = true;
                    int newSafenessFactor = min(safenessFactor, minDist[newRow][newCol]);
                    coordSafenessPQ.push({newSafenessFactor, newRow, newCol});
                }
            }
        }

        return maxSafenessFactor;
    }
};
