//leetcode.com/problems/palindromic-substrings/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countSubstrings(string s) {
        int n = s.length();
        vector<vector<bool>> dp(n, vector<bool> (n, false));
        int palindromeCount = 0;
        
        for (int i = 0; i < n; ++i) {
            dp[i][i] = true;
            ++palindromeCount;
        }
        
        for (int i = 0; i < n - 1; ++i) {
            if (s[i] == s[i + 1]) {
                dp[i][i + 1] = true;
                ++palindromeCount;
            }
        }
        
        for (int length = 3; length <= n; ++length) {
            for (int i = 0; i < n - length + 1; ++i) {
                int j = i + length - 1;
                if (s[i] == s[j] and dp[i + 1][j - 1]) {
                    dp[i][j] = true;
                    ++palindromeCount;
                }
            }
        }
        
        return palindromeCount;
    }
};