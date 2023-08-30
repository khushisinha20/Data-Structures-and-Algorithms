//leetcode.com/problems/number-of-ways-to-stay-in-the-same-place-after-some-steps/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    const int MOD = 1000000007;
    unordered_map<string, int> dp;
    
    int helper(int stepsLeft, int& arrLen, int position) {
        string key = to_string(stepsLeft) + '-' + to_string(position);
        
        if (position == 0 and stepsLeft == 0)
            return 1;
        
        if (position < 0 or position >= arrLen or stepsLeft == 0)
            return 0;
        
        if (dp.find(key) != dp.end())
            return dp[key];
        
        long long stay = helper(stepsLeft - 1, arrLen, position) % MOD;
        long long moveRight = helper(stepsLeft - 1, arrLen, position + 1) % MOD;
        long long moveLeft = helper(stepsLeft - 1, arrLen, position - 1) % MOD;
        
        return dp[key] = (stay + moveRight + moveLeft) % MOD; 
    }
    
    int numWays(int steps, int arrLen) {
        return helper(steps, arrLen, 0) % MOD;
    }
};