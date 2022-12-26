//leetcode.com/problems/ones-and-zeroes/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countOnes(string& str) {
        return count(str.begin(), str.end(), '1');
    }
    
    int countZeroes(string& str) {
        return count(str.begin(), str.end(), '0');
    }
    
    int helper(vector<string>& strs, int index, int n, int m, vector<vector<vector<int>>>& dp) {
        if (index == 0)
            return 0;
        
        if (dp[index][m][n] != -1)
            return dp[index][m][n];
        
        int ones = countOnes(strs[index - 1]);
        int zeroes = countZeroes(strs[index - 1]);
        
        if (m - zeroes >= 0 && n - ones >= 0) {
            int includeString = 1 + helper(strs, index - 1, n - ones, m - zeroes, dp);
            int excludeString = helper(strs, index - 1, n, m, dp);
            return dp[index][m][n] = max(includeString, excludeString);
        } else 
            return dp[index][m][n] = helper(strs, index - 1, n, m, dp);
    }
    
    int findMaxForm(vector<string>& strs, int m, int n) {
        int size = strs.size();
        vector<vector<vector<int>>> dp(size + 1, vector<vector<int>> (m + 1, vector<int> (n + 1, -1)));
        int largestSubsetSize = helper(strs, strs.size(), n, m, dp);
        return largestSubsetSize;
    }
};