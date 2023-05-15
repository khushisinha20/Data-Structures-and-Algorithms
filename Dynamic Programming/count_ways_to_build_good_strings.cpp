//leetcode.com/problems/count-ways-to-build-good-strings/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    const int MOD = 1000000007;
    
    int helper(int index, int zero, int one, vector<int>& dp) {
        if (index == 0)
            return 1;
        
        if (index < 0)
            return 0;
        
        if (dp[index] != -1)
            return dp[index];
        
        long long addZero = helper(index - zero, zero, one, dp) % MOD;
        long long addOne = helper(index - one, zero, one, dp) % MOD;
        
        return dp[index] = (addZero + addOne) % MOD;
    }
    
    int countGoodStrings(int low, int high, int zero, int one) {
        int goodStrings = 0;
        vector<int> dp(high + 1, -1);
        
        for (int i = low; i <= high; ++i) {
            goodStrings = (goodStrings % MOD + helper(i, zero, one, dp) % MOD) % MOD;
        }
        
        return goodStrings;
    }
};