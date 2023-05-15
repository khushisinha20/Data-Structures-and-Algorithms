//leetcode.com/problems/maximum-number-of-moves-in-a-grid/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int dp[1001][1001];
    
    bool liesInsideGrid(int row, int col, int totalRows, int totalCols) {
        return row >= 0 and row < totalRows and col >= 0 and col < totalCols;
    }
    
    int helper(vector<vector<int>>& grid, int row, int col, int previous) {
        if (!liesInsideGrid(row, col, grid.size(), grid[0].size()))
            return 0;
        
        if (previous >= grid[row][col])
            return 0;
        
        if (dp[row][col] != -1)
            return dp[row][col];
        
        return dp[row][col] = 1 + max(helper(grid, row - 1, col + 1, grid[row][col]), max(helper(grid, row, col + 1, grid[row][col]), helper(grid, row + 1, col + 1, grid[row][col])));
    }
    
    int maxMoves(vector<vector<int>>& grid) {
        memset(dp, -1, sizeof(dp));
        int rows = grid.size();
        int cols = grid[0].size();
        int result = 0;
        
        for (int i = 0; i < rows; ++i) {
            result = max(result, helper(grid, i, 0, -1));
        }
        
        return result - 1;
    }
};
