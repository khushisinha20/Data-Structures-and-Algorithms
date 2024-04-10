//leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/

#include <bits/stdc++.h>
using namespace std;

/*
class Solution {
public:
    int helper(vector<vector<int>>& dp, int index, bool canBuy, vector<int>& prices) {
        if (index >= prices.size()) {
            return 0;
        }
        
        if (dp[index][canBuy] != -1) {
            return dp[index][canBuy];
        }
        
        if (canBuy) {
            int buy = -prices[index] + helper(dp, index + 1, false, prices);
            int notBuy = helper(dp, index + 1, true, prices);
            dp[index][canBuy] = max(buy, notBuy);
        } else {
            int sell = prices[index] + helper(dp, index + 2, true, prices);
            int notSell = helper(dp, index + 1, false, prices);
            dp[index][canBuy] = max(sell, notSell);
        }
        
        return dp[index][canBuy];
    }
               
    
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n <= 1) {
            return 0;
        }
        
        vector<vector<int>> dp(n, vector<int>(2, -1));
        return helper(dp, 0, true, prices);
    }
};
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n + 2, vector<int> (3, 0));

        for (int i = n - 1; i >= 0; --i) {
            for (int canBuy = 0; canBuy < 2; ++canBuy) {
                if (canBuy) {
                    int buy = -prices[i] + dp[i + 1][0];
                    int notBuy = dp[i + 1][1];
                    dp[i][canBuy] = max(buy, notBuy);
                } else {
                    int sell = prices[i] + dp[i + 2][1];
                    int notSell = dp[i + 1][0];
                    dp[i][canBuy] = max(sell, notSell);
                }
            }
        }

        return dp[0][1];
    }
};
