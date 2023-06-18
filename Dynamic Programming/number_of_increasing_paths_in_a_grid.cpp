#include <bits/stdc++.h>
using namespace std;

//leetcode.com/problems/number-of-increasing-paths-in-a-grid/

class Solution {
public:
    int MOD = 1000000007;
    int dp[1001][1001];
    vector<vector<int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    
    bool isSafe(vector<vector<int>>& grid, int& row, int& col) {
        return row >= 0 and row < grid.size() and col >= 0 and col < grid[0].size();
    }
    
    int dfs(vector<vector<int>>& grid, int row, int col) {
        if (dp[row][col] != -1)
            return dp[row][col];
        
        int increasingPaths = 1;
        
        for (auto& direction: directions) {
            int newRow = direction[0] + row;
            int newCol = direction[1] + col;
            
            if (isSafe(grid, newRow, newCol) and grid[newRow][newCol] > grid[row][col]) {
                increasingPaths = (increasingPaths + dfs(grid, newRow, newCol)) % MOD;
            }
        }
        
        return dp[row][col] = increasingPaths;
    }
    
    int countPaths(vector<vector<int>>& grid) {
        memset(dp, -1, sizeof(dp));
        int ROWS = grid.size();
        int COLS = grid[0].size();
        
        int result = 0;
        
        for (int row = 0; row < ROWS; ++row)
            for (int col = 0; col < COLS; ++col)
                result = (result + dfs(grid, row, col)) % MOD;
        
        return result;
    }
};
