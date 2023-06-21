//leetcode.com/problems/dice-roll-simulation/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int MOD = 1000000007;
    int dp[5001][7][16];
    
    int helper(int n, int previous, int rollCount, vector<int>& rollMax) {
        if (n == 0)
            return 1;
        
        if (previous != -1 and dp[n][previous][rollCount] != -1)
            return dp[n][previous][rollCount];
        
        int ans = 0;
        
        for (int i = 0; i < 6; ++i) {
            if (previous == i and rollCount >= rollMax[i])
                continue;
            if (previous == i)
                ans = (ans + helper(n - 1, i, rollCount + 1, rollMax)) % MOD;
            else
                ans = (ans + helper(n - 1, i, 1, rollMax)) % MOD;
        }
        
        if (previous != -1)
            dp[n][previous][rollCount] = ans;
        
        return ans;
    }
    
    int dieSimulator(int n, vector<int>& rollMax) {
        memset(dp, -1, sizeof(dp));
        return helper(n, -1, 0, rollMax);
    }
};