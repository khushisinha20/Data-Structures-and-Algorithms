#include <bits/stdc++.h>
using namespace std;

class Solution  {
    public:
    int knapSack(int W, int wt[], int val[], int n)  { 
        vector<vector<int>> dp(n + 2, vector<int> (W + 2, -1));
        
        for (int i = 0; i < n + 1; ++i) {
            for (int j = 0; j < W + 1; ++j) {
                if (i == 0 || j == 0)
                    dp[i][j] = 0;
                else if (wt[i - 1] <= j)
                    dp[i][j] = max(val[i - 1] + dp[i - 1][j - wt[i - 1]], dp[i - 1][j]);
                else
                    dp[i][j] = dp[i - 1][j];
            }
        }
        return dp[n][W];
    }
};
