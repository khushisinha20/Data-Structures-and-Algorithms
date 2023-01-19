//leetcode.com/problems/edit-distance/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int helper(string& word1, string& word2, vector<vector<int>>& dp, int i, int j) {
        if (i == 0 || j == 0)
            return max(i, j);
        
        if (dp[i][j] != -1)
            return dp[i][j];
        
        if (word1[i - 1] == word2[j - 1])
            return dp[i][j] = helper(word1, word2, dp, i - 1, j - 1);
        else 
            return dp[i][j] = min(min(helper(word1, word2, dp, i - 1, j), helper(word1, word2, dp, i, j - 1)), helper(word1, word2, dp, i - 1, j - 1)) + 1;
        
        return -1;
    }
    
    int minDistance(string word1, string word2) {
        vector<vector<int>> dp(word1.size() + 1, vector<int> (word2.size() + 1, -1));
        return helper(word1, word2, dp, word1.length(), word2.length());
    }
};