//leetcode.com/problems/maximize-palindrome-length-from-subsequences/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestPalindrome(string word1, string word2) {
        string s = word1 + word2;
        int n = word1.length();
        int m = word2.length();
        int len = n + m;

        vector<vector<int>> dp(len, vector<int> (len, 0));

        for (int i = 0; i < len; ++i)
            dp[i][i] = 1;

        for (int l = 2; l <= len; ++l) {
            for (int i = 0; i + l - 1 < len; ++i) {
                int j = i + l - 1;
                if (s[i] == s[j])
                    dp[i][j] = dp[i + 1][j - 1] + 2;
                else
                    dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
            }
        }

        int ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = n; j < len; ++j) {
                if (s[i] == s[j]) {
                    ans = max(ans, dp[i][j]);
                }
            }
        }

        return ans;
    }
};
