//leetcode.com/problems/minimum-ascii-delete-sum-for-two-strings/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> dp;
    
    int helper(string& s1, string& s2, int i, int j) {
        if (i >= s1.length() and j >= s2.length())
            return 0;
        
        if (dp[i][j] != -1)
            return dp[i][j];
        
        if (i >= s1.length())
            return dp[i][j] = s2[j] + helper(s1, s2, i, j + 1);
        
        if (j >= s2.length())
            return dp[i][j] = s1[i] + helper(s1, s2, i + 1, j);
        
        if (s1[i] == s2[j])
            return dp[i][j] = helper(s1, s2, i + 1, j + 1);
        
        int deleteFromS1 = s1[i] + helper(s1, s2, i + 1, j);
        int deleteFromS2 = s2[j] + helper(s1, s2, i, j + 1);
        
        return dp[i][j] = min(deleteFromS1, deleteFromS2);
    }
    
    int minimumDeleteSum(string s1, string s2) {
        dp.resize(s1.length() + 1, vector<int> (s2.length() + 1, -1));
        return helper(s1, s2, 0, 0);
    }
};