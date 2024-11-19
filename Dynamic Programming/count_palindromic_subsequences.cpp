//leetcode.com/problems/count-palindromic-subsequences/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    const int MOD = 1e9 + 7;
    
    int helper(string& s, string& t, int sIndex, int tIndex, vector<vector<int>>& dp) {
        if (tIndex == t.length())
            return 1;
        
        if (sIndex == s.length())
            return 0;
        
        if (dp[sIndex][tIndex] != -1)
            return dp[sIndex][tIndex];
        
        int skip = helper(s, t, sIndex + 1, tIndex, dp) % MOD;
        int take = 0;
        if (s[sIndex] == t[tIndex])
            take = helper(s, t, sIndex + 1, tIndex + 1, dp) % MOD;
        
        return dp[sIndex][tIndex] = (take + skip) % MOD;
    }
    
    int countPalindromes(string s) {
        int n = s.length();
        long long result = 0;
        vector<vector<int>> dp;
        
        for (char first = '0'; first <= '9'; ++first) {
            for (char second = '0'; second <= '9'; ++second) {
                for (char mid = '0'; mid <= '9'; ++mid) {
                    string palindrome = {first, second, mid, second, first};
                    dp.assign(n, vector<int> (5, -1));
                    result = (result + helper(s, palindrome, 0, 0, dp)) % MOD;
                }
            }
        }
        
        return result;
    }
};
