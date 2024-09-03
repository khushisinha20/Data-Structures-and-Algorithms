//leetcode.com/problems/count-different-palindromic-subsequences/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    const int MOD = 1e9 + 7;

    int helper(vector<vector<vector<int>>>& dp, string& s, int start, int end, int letter) {
        if (start > end)
            return 0;
        
        if (start == end)
            return s[start] == letter + 'a';
        
        if (dp[start][end][letter] != -1)
            return dp[start][end][letter];
        
        int ans = 0;
        if (s[start] == s[end]) {
            if (s[start] == letter + 'a') {
                for (int i = 0; i < 4; ++i) {
                    ans = (ans + helper(dp, s, start + 1, end - 1, (letter + i) % 4)) % MOD;
                }
                ans = (ans + 2) % MOD; 
            } else {
                ans = helper(dp, s, start + 1, end - 1, letter) % MOD;
            }
        } else {
            ans = (helper(dp, s, start + 1, end, letter) + helper(dp, s, start, end - 1, letter) - helper(dp, s, start + 1, end - 1, letter) + MOD) % MOD;
        }
        
        return dp[start][end][letter] = ans;
    }
    
    int countPalindromicSubsequences(string s) {
        int n = s.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(4, -1)));
        
        int result = 0;
        for (int i = 0; i < 4; ++i) {
            result = (result + helper(dp, s, 0, n - 1, i)) % MOD;
        }
        
        return result;
    }
};

