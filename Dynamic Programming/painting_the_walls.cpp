//leetcode.com/problems/painting-the-walls/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int helper(int index, int remaining, vector<int>& cost, vector<int>& time, vector<vector<int>>& dp) {
        if (remaining <= 0)
            return 0;
        
        if (index == cost.size())
            return 1e9;
        
        if (dp[index][remaining] != -1)
            return dp[index][remaining];
        
        int paint = cost[index] + helper(index + 1, remaining - 1 - time[index], cost, time, dp);
        int notPaint = helper(index + 1, remaining, cost, time, dp);
        
        return dp[index][remaining] = min(paint, notPaint);
    }
    
    int paintWalls(vector<int>& cost, vector<int>& time) {
        int n = cost.size();
        
        vector<vector<int>> dp(n + 1, vector<int> (n + 1, -1));
        
        return helper(0, n, cost, time, dp);
    }
};