//leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int helper(vector<vector<int>>& dp, int index, bool canBuy, vector<int>& prices, int& fee) {
        if (index >= prices.size()) {
            return 0;
        }

        if (dp[index][canBuy] != -1) {
            return dp[index][canBuy];
        }

        if (canBuy) {
            int buy = -prices[index] + helper(dp, index + 1, false, prices, fee);
            int notBuy = helper(dp, index + 1, true, prices, fee);
            dp[index][canBuy] = max(buy, notBuy);
        } else {
            int sell = prices[index] - fee + helper(dp, index + 1, true, prices, fee);
            int notSell = helper(dp, index + 1, false, prices, fee);
            dp[index][canBuy] = max(sell, notSell);
        }

        return dp[index][canBuy];
    }


    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        if (n <= 1) {
            return 0;
        }

        vector<vector<int>> dp(n, vector<int>(2, -1));
        return helper(dp, 0, true, prices, fee);
    }
};
