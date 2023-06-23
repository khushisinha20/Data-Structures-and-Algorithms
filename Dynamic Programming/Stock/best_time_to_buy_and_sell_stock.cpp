//leetcode.com/problems/best-time-to-buy-and-sell-stock/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buyingPrice = INT_MAX;
        int profitIfSoldToday = INT_MIN;
        int profit = INT_MIN;
        
        for (int i = 0; i < prices.size(); ++i) {
            if (prices[i] < buyingPrice)
                buyingPrice = prices[i];
            profitIfSoldToday = prices[i] - buyingPrice;
            profit = max(profitIfSoldToday, profit);
        }
        
        return profit;
    }
};