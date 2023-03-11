//leetcode.com/problems/minimum-cost-to-make-at-least-one-valid-path-in-a-grid/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool liesInsideGrid(vector<vector<int>>& grid, int& row, int& col) {
        return row >= 0 and row < grid.size() and col >= 0 and col < grid[0].size();
    }
    
    int minCost(vector<vector<int>>& grid) {
        vector<vector<int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        queue<pair<int, int>> cells;
        vector<vector<int>> minimumCost(grid.size(), vector<int> (grid[0].size(), 10000));
        
        cells.push({0, 0});
        minimumCost[0][0] = 0;
        
        while (!cells.empty()) {
            auto row = cells.front().first;
            auto col = cells.front().second;
            cells.pop();
            
            for (auto& direction: directions) {
                int adjacentRow = row + direction.front();
                int adjacentCol = col + direction.back();
                
                if (!liesInsideGrid(grid, adjacentRow, adjacentCol))
                    continue;
                
                int cost = direction != directions[grid[row][col] - 1];
                
                if (minimumCost[adjacentRow][adjacentCol] > minimumCost[row][col] + cost) {
                    cells.push({adjacentRow, adjacentCol});
                    minimumCost[adjacentRow][adjacentCol] = minimumCost[row][col] + cost;
                }
            }
        }
        
        return minimumCost[grid.size() - 1][grid[0].size() - 1];
    }
};