//leetcode.com/problems/coin-change/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int infinity = INT_MAX - 1;
    
    int helper(vector<int>& coins, int amount, int index, vector<vector<int>>& dp) {
        if (amount == 0)
            return 0;
        
        if (amount < 0)
            return infinity;
        
        if (index >= coins.size())
            return infinity;
        
        if (dp[index][amount] != -1)
            return dp[index][amount];
        
        int result = -1;
        
        if (amount - coins[index] >= 0) {
            int takeCoin = 1 + helper(coins, amount - coins[index], index, dp);
            int skipCoin = helper(coins, amount, index + 1, dp);
            result = min(takeCoin, skipCoin);
        } else {
            int skipCoin = helper(coins, amount, index + 1, dp);
            result = skipCoin;
        }
        
        return dp[index][amount] = result;
    }
    
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>> dp(coins.size() + 1, vector<int> (amount + 1, -1));
        int result = helper(coins, amount, 0, dp);
        return result == infinity ? -1 : result;
    }
};

/*
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int infinity = INT_MAX - 1;
        vector<vector<int>> dp(coins.size() + 1, vector<int> (amount + 1, infinity));
        
        for (int index = 0; index <= coins.size(); ++index)
            dp[index][0] = 0;
        
        for (int index = coins.size() - 1; index >= 0; --index) {
            for (int amt = 1; amt <= amount; ++amt) {
                if (amt - coins[index] >= 0) {
                    int takeCoin = 1 + dp[index][amt - coins[index]];
                    int skipCoin = dp[index + 1][amt];
                    dp[index][amt] = min(takeCoin, skipCoin);
                } else
                    dp[index][amt] = dp[index + 1][amt];
            }
        }
        
        return dp[0][amount] == infinity ? -1 : dp[0][amount];
    }
};
*/