//leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/

#include <bits/stdc++.h>
using namespace std;

/*
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int> (2, -1));
        
        dp[0][0] = 0;
        dp[0][1] = -prices[0];
        
        for (int i = 1; i < n; ++i) {
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i]);
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i]);
        }
        
        return max(dp[n - 1][0], dp[n - 1][1]);
    }
};
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        if (n < 2)
            return 0;

        vector<int> previous(2, -1);
        vector<int> current(2, -1);

        previous[0] = 0;
        previous[1] = -prices[0];

        for (int i = 1; i < n; ++i) {
            current[0] = max(previous[0], previous[1] + prices[i]);
            current[1] = max(previous[1], previous[0] - prices[i]);
            previous[0] = current[0];
            previous[1] = current[1];
        }

        return max(current[0], current[1]);
    }
};
