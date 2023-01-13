//leetcode.com/problems/minimum-falling-path-sum/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int helper(vector<vector<int>>& matrix, int row, int col, vector<vector<int>>& dp) {
        if (row >= matrix.size() || col < 0 || col >= matrix.size())
            return INT_MAX;
        
        if (row == matrix.size() - 1)
            return matrix[row][col];
        
        if (dp[row][col] != -1)
            return dp[row][col];
        
        return dp[row][col] = matrix[row][col] + min(helper(matrix, row + 1, col, dp), min(helper(matrix, row + 1, col + 1, dp), helper(matrix, row + 1, col - 1, dp)));
    }
    
    int minFallingPathSum(vector<vector<int>>& matrix) {
        vector<vector<int>> dp(matrix.size(), vector<int> (matrix.size(), -1));
        int minSumFallingPath = INT_MAX;
        
        for (int i = 0; i < matrix.size(); ++i) {
            minSumFallingPath = min(minSumFallingPath, helper(matrix, 0, i, dp));
        }
        return minSumFallingPath;
    }
};