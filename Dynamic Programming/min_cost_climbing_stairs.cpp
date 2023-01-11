//leetcode.com/problems/min-cost-climbing-stairs/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int helper(int index, vector<int>& cost, vector<int>& dp) {
        if (index >= cost.size())
            return 0;
        
        if (dp[index] != -1)
            return dp[index];
        
        return dp[index] = cost[index] + min(helper(index + 1, cost, dp), helper(index + 2, cost, dp));
    }
    
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> dp(cost.size(), -1);
        return min(helper(0, cost, dp), helper(1, cost, dp));
    }
};