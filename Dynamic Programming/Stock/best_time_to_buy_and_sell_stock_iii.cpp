//leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/

#include <bits/stdc++.h>
using namespace std;

/*
class Solution {
public:
    int helper(vector<int>& prices, int index, bool canBuy, int capacity, vector<vector<vector<int>>>& memo) {
        if (index == prices.size())
            return 0;
        
        if (capacity == 0)
            return 0;

        if (memo[index][canBuy][capacity] != -1)
            return memo[index][canBuy][capacity];

        int maxProfit = 0;

        if (canBuy) {
            int buy = -prices[index] + helper(prices, index + 1, false, capacity, memo);
            int notBuy = helper(prices, index + 1, true, capacity, memo);
            maxProfit = max(buy, notBuy);
        } else {
            int sell = prices[index] + helper(prices, index + 1, true, capacity - 1, memo);
            int notSell = helper(prices, index + 1, false, capacity, memo);
            maxProfit = max(sell, notSell);
        }

        return memo[index][canBuy][capacity] = maxProfit;
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n < 2) return 0;

        vector<vector<vector<int>>> memo(n, vector<vector<int>>(2, vector<int>(3, -1)));
        return helper(prices, 0, true, 2, memo);
    }
};
*/

/*
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n < 2) return 0;

        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(3, 0)));
        
        for (int i = n - 1; i >= 0; --i) {
            for (int canBuy = 0; canBuy < 2; ++canBuy) {
                for (int capacity = 1; capacity < 3; ++capacity) {
                    if (canBuy) {
                        int buy = -prices[i] + dp[i + 1][0][capacity];
                        int notBuy = dp[i + 1][1][capacity];
                        dp[i][canBuy][capacity] = max(buy, notBuy);
                    } else {
                        int sell = prices[i] + dp[i + 1][1][capacity - 1];
                        int notSell = dp[i + 1][0][capacity];
                        dp[i][canBuy][capacity] = max(sell, notSell);
                    }
                }
            }
        }
        
        return dp[0][1][2];
    }
};
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n < 2) return 0;

        vector<vector<int>> dp(2, vector<int>(3, 0));

        for (int i = n - 1; i >= 0; --i) {
            vector<vector<int>> nextDp(2, vector<int>(3, 0));
            for (int canBuy = 0; canBuy < 2; ++canBuy) {
                for (int capacity = 1; capacity < 3; ++capacity) {
                    if (canBuy) {
                        int buy = -prices[i] + dp[0][capacity];
                        int notBuy = dp[1][capacity];
                        nextDp[canBuy][capacity] = max(buy, notBuy);
                    } else {
                        int sell = prices[i] + dp[1][capacity - 1];
                        int notSell = dp[0][capacity];
                        nextDp[canBuy][capacity] = max(sell, notSell);
                    }
                }
            }
            dp = nextDp;
        }

        return dp[1][2];
    }
};
