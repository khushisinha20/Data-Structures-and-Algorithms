//leetcode.com/problems/unique-paths-ii/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int helper(vector<vector<int>>& obstacleGrid, vector<vector<int>>& dp, int row, int col) {
        if (row < 0 || row >= obstacleGrid.size() || col < 0 || col >= obstacleGrid[0].size() || obstacleGrid[row][col] == 1)
            return 0;
            
        if (row == obstacleGrid.size() - 1 && col == obstacleGrid[0].size() - 1) 
            return 1;
        
        if (dp[row][col] != -1) 
            return dp[row][col];
        
        int down = helper(obstacleGrid, dp, row + 1, col);
        int right = helper(obstacleGrid, dp, row, col + 1);
        
       return dp[row][col] = down + right;
    }
    
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        vector<vector<int>> dp(obstacleGrid.size(), vector<int> (obstacleGrid[0].size(), -1));
        return helper(obstacleGrid, dp, 0, 0);
    }
};