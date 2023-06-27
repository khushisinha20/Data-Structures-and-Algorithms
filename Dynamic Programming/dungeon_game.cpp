//leetcode.com/problems/dungeon-game/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int dp[201][201];
    
    int helper(vector<vector<int>>& grid, int row, int col) {
        if (row >= grid.size() or col >= grid[0].size())
            return INT_MAX;
        
        if (row == grid.size() - 1 and col == grid[0].size() - 1) 
            return grid[row][col] <= 0 ? abs(grid[row][col]) + 1 : 1;
        
        if (dp[row][col] != -1)
            return dp[row][col];
        
        int right = helper(grid, row, col + 1);
        int down = helper(grid, row + 1, col);
        
        int ans = min(right, down) - grid[row][col];
        
        return dp[row][col] = ans <= 0 ? 1 : ans;
    }
    
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        memset(dp, -1, sizeof dp);
        return helper(dungeon, 0, 0);
    }
};