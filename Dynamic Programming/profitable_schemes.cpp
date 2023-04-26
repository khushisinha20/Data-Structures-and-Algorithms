//leetcode.com/problems/profitable-schemes/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    const int MOD = 1000000007;
    int dp[101][101][101];
    
    int helper(int& n, int& minProfit, vector<int>& group, vector<int>& profit, int index, int currentProfit, int people) {
        if (people > n)
            return 0;
        
        if (index == group.size()) {
            if (currentProfit >= minProfit)
                return dp[index][currentProfit][people] = 1;
            return dp[index][currentProfit][people] = 0;
        }
        
        if (dp[index][currentProfit][people] != -1)
            return dp[index][currentProfit][people];
        
        long long notTaken = helper(n, minProfit, group, profit, index + 1, currentProfit, people) % MOD;
        long long taken = helper(n, minProfit, group, profit, index + 1, min(currentProfit + profit[index], minProfit), people + group[index]) % MOD;
        
        return dp[index][currentProfit][people] = (notTaken + taken) % MOD;
    }
    
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        memset(dp, -1, sizeof(dp));
        return helper(n, minProfit, group, profit, 0, 0, 0);
    }
};