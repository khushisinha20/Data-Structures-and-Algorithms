//leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int oldBuyingStateProfit = -prices[0];
        int oldSellingStateProfit = 0;
        
        for (int i = 1; i < prices.size(); ++i) {
            int newBuyingStateProfit = 0;
            int newSellingStateProfit = 0;
            
            if (oldSellingStateProfit - prices[i] > oldBuyingStateProfit) {
                newBuyingStateProfit = oldSellingStateProfit - prices[i];
            } else {
                newBuyingStateProfit = oldBuyingStateProfit;
            }
            
            if (oldBuyingStateProfit + prices[i] - fee > oldSellingStateProfit) {
                newSellingStateProfit = oldBuyingStateProfit + prices[i] - fee;
            } else {
                newSellingStateProfit = oldSellingStateProfit;
            }
            
            oldBuyingStateProfit = newBuyingStateProfit;
            oldSellingStateProfit = newSellingStateProfit;
        }
        
        return oldSellingStateProfit;
    }
};