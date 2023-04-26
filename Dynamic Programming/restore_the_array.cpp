//leetcode.com/problems/restore-the-array/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    const int MOD = 1e9 + 7;
    
    int helper(string& s, int& k, int start, vector<int>& dp) {
        if (start >= s.length())
            return 1;
        
        if (s[start] == '0')
            return 0;
        
        if (dp[start] != -1)
            return dp[start];
        
        long long currentNumber = 0;
        int result = 0;
        
        for (int end = start; end < s.length(); ++end) {
            currentNumber = currentNumber * 10 + (s[end] - '0');
            if (currentNumber > k)
                break;
            result = (result % MOD + helper(s, k, end + 1, dp) % MOD) % MOD;
        }
        
        return dp[start] = result;
    }
    
    int numberOfArrays(string s, int k) {
        vector<int> dp(s.length(), -1);
        return helper(s, k, 0, dp);
    }
};