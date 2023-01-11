//leetcode.com/problems/is-subsequence/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestCommonSubsequence(string& text1, string& text2) {
        int m = text1.length();
        int n = text2.length();
        
        vector<vector<int>> dp(m + 1, vector<int> (n + 1, -1));
        
        for (int i = 0; i < m + 1; ++i) {
            for (int j = 0; j < n + 1; ++j) {
                if (i == 0 || j == 0)
                    dp[i][j] = 0;
                else if (text1[i - 1] == text2[j - 1])
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                else 
                    dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
            }
        }
        return dp[m][n];
    }
    
    bool isSubsequence(string s, string t) {
        return longestCommonSubsequence(s, t) == s.length();
    }
};