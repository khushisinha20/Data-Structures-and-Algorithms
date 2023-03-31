//leetcode.com/problems/cherry-pickup-ii/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int dp[71][71][71];
    vector<int> colDirections = {1, 0, -1};
    
    int helper(vector<vector<int>>& grid, int row, int col1, int col2) {
        if (row == grid.size())
            return 0;
        
        if (col1 < 0 or col1 >= grid[0].size() or col2 < 0 or col2 >= grid[0].size())
            return INT_MIN;
        
        if (dp[row][col1][col2] != -1)
            return dp[row][col1][col2];
        
        int maxCherries = 0;
        
        for (int i = 0; i < 3; ++i) 
            for (int j = 0; j < 3; ++j) 
                maxCherries = max(maxCherries, helper(grid, row + 1, col1 + colDirections[i], col2 + colDirections[j]));
            
        maxCherries += (col1 == col2) ? grid[row][col1] : grid[row][col1] + grid[row][col2];
        return dp[row][col1][col2] = maxCherries;
    }
    
    int cherryPickup(vector<vector<int>>& grid) {
        memset(dp, -1, sizeof dp);
        return helper(grid, 0, 0, grid[0].size() - 1);
        
    }
};