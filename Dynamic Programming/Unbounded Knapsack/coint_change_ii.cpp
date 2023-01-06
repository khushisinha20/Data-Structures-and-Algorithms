//leetcode.com/problems/coin-change-ii/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<vector<int>> dp(coins.size() + 1, vector<int> (amount + 1, 0));
        
        for (int i = 0; i < coins.size() + 1; ++i) {
            for (int j = 0; j < amount + 1; ++j) {
                if (j == 0)
                    dp[i][j] = true;
                else if (i == 0)
                    dp[i][j] = false;
                else {
                    if (coins[i - 1] <= j)
                        dp[i][j] = dp[i][j - coins[i - 1]] + dp[i - 1][j];
                    else
                        dp[i][j] = dp[i - 1][j];
                }
            }
        }
        return dp[coins.size()][amount];
    }
};