//leetcode.com/problems/coin-change-ii/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int helper(vector<int>& coins, int amount, int index, vector<vector<int>>& dp) {
        // If the amount becomes negative, we can't make any more combinations.
        if (amount < 0)
            return 0;
        
        // If the amount becomes 0, we have found a valid combination.
        if (amount == 0)
            return 1;
        
        // If we have exhausted all the coins, but the amount is still greater than 0,
        // there are no valid combinations.
        if (index >= coins.size())
            return 0;
        
        // If the result for the current index and amount is already calculated, return it.
        if (dp[index][amount] != -1)
            return dp[index][amount];
        
        // Try to use the current coin and/or skip to the next coin.
        int takeCoin = helper(coins, amount - coins[index], index, dp);
        int skipCoin = helper(coins, amount, index + 1, dp);
        
        // Store the result in the DP table and return the total number of combinations.
        return dp[index][amount] = takeCoin + skipCoin;
    }
    
    int change(int amount, vector<int>& coins) {
        vector<vector<int>> dp(coins.size(), vector<int>(amount + 1, -1));
        return helper(coins, amount, 0, dp);
    }
};

/*
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<vector<int>> dp(coins.size() + 1, vector<int>(amount + 1, 0));

        for (int i = 0; i <= coins.size(); ++i)
            dp[i][0] = 1;

        for (int i = 1; i <= coins.size(); ++i) {
            for (int j = 1; j <= amount; ++j) {
                int skipCoin = dp[i - 1][j];
                int includeCoin = 0;
                if (j - coins[i - 1] >= 0)
                    includeCoin = dp[i][j - coins[i - 1]];
                dp[i][j] = skipCoin + includeCoin;
            }
        }

        return dp[coins.size()][amount];
    }
};
*/