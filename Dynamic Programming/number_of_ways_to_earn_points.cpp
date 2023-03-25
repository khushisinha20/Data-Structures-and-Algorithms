//leetcode.com/problems/number-of-ways-to-earn-points/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    const int MOD = 1000000007;
    
    int helper(vector<vector<int>>& dp, vector<vector<int>>& types, int target, int index) {
        int n = types.size();
        
        if (target == 0)
            return 1;
        
        if (index >= n)
            return 0;
        
        if (target < 0)
            return 0;
        
        if (dp[index][target] != -1)
            return dp[index][target];
        
        int ways = 0;
        
        for (int choice = 0; choice <= types[index][0]; ++choice) {
            int take = helper(dp, types, target - (choice * types[index][1]), index + 1) % MOD; 
            ways = (ways + take) % MOD;
        }
        
        return dp[index][target] = ways % MOD;
    }
    
    int waysToReachTarget(int target, vector<vector<int>>& types) {
        int n = types.size();
        vector<vector<int>> dp(n + 1, vector<int> (target + 1, -1));
        int index = 0;
        return helper(dp, types, target, index);
    }
};