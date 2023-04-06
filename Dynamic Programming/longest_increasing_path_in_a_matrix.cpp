//leetcode.com/problems/longest-increasing-path-in-a-matrix/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> dp;
    
    int helper(vector<vector<int>>& matrix, int row, int col, int previous) {
        if (row < 0 or row >= matrix.size() or col < 0 or col >= matrix[0].size() or previous >= matrix[row][col])
            return 0;
        
        if (dp[row][col] != -1)
            return dp[row][col];
        
        int path = max({helper(matrix, row + 1, col, matrix[row][col]),
                       helper(matrix, row - 1, col, matrix[row][col]),
                       helper(matrix, row, col + 1, matrix[row][col]),
                       helper(matrix, row, col - 1, matrix[row][col])});
        
        return dp[row][col] = path + 1;
    }
    
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        dp.resize(rows, vector<int> (cols, -1));
        int result = INT_MIN;
        
        for (int row = 0; row < rows; ++row) 
            for (int col = 0; col < cols; ++col) 
                result = max(result, helper(matrix, row, col, -1));
        
        return result;
    }
};