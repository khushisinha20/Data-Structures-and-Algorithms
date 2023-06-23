//leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buyingDate = 0;
        int sellingDate = 0;
        int profit = 0;
        
        for (int i = 1; i < prices.size(); ++i) {
            if (prices[i - 1] <= prices[i])
                sellingDate = i;
            else {
                profit += prices[sellingDate] - prices[buyingDate];
                sellingDate = i;
                buyingDate = i;
            }
        }
        
        profit += prices[sellingDate] - prices[buyingDate];
        return profit;
    }
};