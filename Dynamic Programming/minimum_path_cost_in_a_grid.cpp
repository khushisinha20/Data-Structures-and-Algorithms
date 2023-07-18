//leetcode.com/problems/minimum-path-cost-in-a-grid/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& moveCost) {
        int ROWS = grid.size();
        int COLS = grid[0].size();
        vector<vector<int>> dp(ROWS, vector<int> (COLS, 0));
        
        for (int i = 0; i < COLS; ++i)
            dp[ROWS - 1][i] = grid[ROWS - 1][i];
        
        for (int row = ROWS - 2; row >= 0; --row) {
            for (int col = 0; col < COLS; ++col) {
                int currentCellValue = grid[row][col];
                int take = INT_MAX;
                
                for (int i = 0; i < moveCost[currentCellValue].size(); ++i)
                    take = min(take, dp[row + 1][i] + currentCellValue + moveCost[currentCellValue][i]);
                
                dp[row][col] = take;
            }
        }
        
        int minCost = INT_MAX;
        
        for (int i = 0; i < COLS; ++i)
            minCost = min(minCost, dp[0][i]);
        
        return minCost;
    }
};