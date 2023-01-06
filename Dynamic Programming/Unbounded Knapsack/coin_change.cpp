//leetcode.com/problems/coin-change/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>> dp(coins.size() + 1, vector<int> (amount + 1, 0));
        for (int i = 0; i < coins.size() + 1; ++i) {
            for (int j = 0; j < amount + 1; ++j) {
                if (j == 0)
                    dp[i][j] = 0;
                else if (i == 0)
                    dp[i][j] = INT_MAX - 1;
                else {
                    if (coins[i - 1] <= j)
                        dp[i][j] = min(dp[i][j - coins[i - 1]] + 1, dp[i - 1][j]);
                    else
                        dp[i][j] = dp[i - 1][j];
                }
            }
        }
        return dp[coins.size()][amount] == INT_MAX - 1 ? -1 : dp[coins.size()][amount];
    }
};