//leetcode.com/problems/best-time-to-buy-and-sell-stock/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int overall_profit = 0;
        int profit_if_sold_today = 0;
        int least_so_far = INT_MAX;
        for (int i = 0; i < prices.size(); ++i) {
            if (prices[i] < least_so_far) {
                least_so_far = prices[i];
            }
            profit_if_sold_today = (prices[i] - least_so_far);
            if (profit_if_sold_today > overall_profit) {
                overall_profit = profit_if_sold_today;
            }
        }
        return overall_profit;
    }
};