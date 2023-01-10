//leetcode.com/problems/longest-palindromic-subsequence/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestCommonSubsequence(string& text1, string& text2) {
        vector<vector<int>> dp(text1.length() + 1, vector<int> (text2.length() + 1, -1));
        
        for (int i = 0; i <= text1.length(); ++i) {
            for (int j = 0; j <= text2.length(); ++j) {
                if (i == 0 || j == 0)
                    dp[i][j] = 0;
                else if (text1[i - 1] == text2[j - 1])
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        
        return dp[text1.length()][text2.length()];
    }
    
    int longestPalindromeSubseq(string s) {
        string reversedString = string(s.rbegin(), s.rend());
        int lps = longestCommonSubsequence(s, reversedString);
        return lps;
    }
};