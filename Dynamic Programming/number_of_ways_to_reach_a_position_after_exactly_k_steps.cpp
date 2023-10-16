//leetcode.com/problems/number-of-ways-to-reach-a-position-after-exactly-k-steps/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    unordered_map<string, int> dp;
    const int MOD = 1000000007;
    const char DELIMETER = '-';
    
    string getKey(int position, int steps) {
        return to_string(steps) + DELIMETER + to_string(position);
    }
    
    int helper(int currentPos, int& endPos, int stepsLeft) {
        string key = getKey(currentPos, stepsLeft);
        
        if (stepsLeft == 0)
            return currentPos == endPos;
        
        if (dp.find(key) != dp.end())
            return dp[key];
        
        int ways = 0;
        ways = (ways + helper(currentPos - 1, endPos, stepsLeft - 1)) % MOD;
        
        ways = (ways + helper(currentPos + 1, endPos, stepsLeft - 1)) % MOD;
        
        return dp[key] = ways % MOD;
    }
    
    int numberOfWays(int startPos, int endPos, int k) {
        return helper(startPos, endPos, k);
    }
};