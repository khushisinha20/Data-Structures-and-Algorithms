//leetcode.com/problems/minimum-path-sum/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int helper(int row, int col, vector<vector<int>>& grid, vector<vector<int>>& dp) {
        if (row < 0 || row >= grid.size() || col < 0 || col >= grid[0].size())
            return INT_MAX;
        
        if (row == grid.size() - 1 && col == grid[0].size() - 1)
            return grid[row][col];
        
        if (dp[row][col] != -1)
            return dp[row][col];
        
        return dp[row][col] = grid[row][col] + min(helper(row + 1, col, grid, dp), helper(row, col + 1, grid, dp));
    }
    
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        vector<vector<int>> dp(m, vector<int> (n, -1));
        return helper(0, 0, grid, dp);
    }
};