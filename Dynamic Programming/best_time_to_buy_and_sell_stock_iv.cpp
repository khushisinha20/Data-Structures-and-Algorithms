//leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/

#include <bits/stdc++.h>
using namespace std;

/*
class Solution {
public:
    int helper(vector<vector<vector<int>>>& dp, vector<int>& prices, int& k, int index, bool canBuy, int capacity) {
        if (index >= prices.size())
            return 0;
        
        if (capacity == 0)
            return 0;
        
        if (dp[index][canBuy][capacity] != -1)
            return dp[index][canBuy][capacity];
        
        int result;
        
        if (canBuy) {
            int buy = -prices[index] + helper(dp, prices, k, index + 1, false, capacity);
            int notBuy = helper(dp, prices, k, index + 1, true, capacity);
            result = max(buy, notBuy);
        } else {
            int sell = prices[index] + helper(dp, prices, k, index + 1, true, capacity - 1);
            int notSell = helper(dp, prices, k, index + 1, false, capacity);
            result = max(sell, notSell);
        }
        
        return dp[index][canBuy][capacity] = result; 
    }
    
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(k + 1, -1))); 
        return helper(dp, prices, k, 0, true, k); 
    }
};
*/

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(3, vector<int>(k + 1, 0)));

        for (int i = n - 1; i >= 0; --i) {
            for (int canBuy = 0; canBuy < 2; ++canBuy) {
                for (int capacity = 1; capacity <= k; ++capacity) {
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

        return dp[0][1][k];
    }
};
