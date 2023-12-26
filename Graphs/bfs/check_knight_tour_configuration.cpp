// leetcode.com/problems/check-knight-tour-configuration/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool liesInsideGrid(int row, int col, vector<vector<int>>& grid) {
        return row >= 0 and row < grid.size() and col >= 0 and col < grid[0].size();
    }

    bool checkValidGrid(vector<vector<int>>& grid) {
        if (grid[0][0] != 0)
            return false;
        
        int n = grid.size();
        unordered_map<int, pair<int, int>> orderToCoordinateMap;
        queue<pair<int, int>> cells;
        int total = n * n - 1;
        cells.push({0, 0});
        int next = 0;

        vector<pair<int, int>> directions = {{2, 1}, {1, 2}, {-1, 2}, {-2, 1}, {-2, -1}, {-1, -2}, {1, -2}, {2, -1}};

        while (!cells.empty() and next != total) {
            int currentRow = cells.front().first;
            int currentCol = cells.front().second;
            cells.pop();

            for (auto& direction : directions) {
                int nextRow = direction.first + currentRow;
                int nextCol = direction.second + currentCol;

                if (liesInsideGrid(nextRow, nextCol, grid)) {
                    int nextCell = grid[nextRow][nextCol];
                    if (nextCell == next + 1) {
                        cells.push({nextRow, nextCol});
                        orderToCoordinateMap[next] = {nextRow, nextCol};
                        ++next;
                    }
                }
            }
        }

        return next == total;
    }
};
