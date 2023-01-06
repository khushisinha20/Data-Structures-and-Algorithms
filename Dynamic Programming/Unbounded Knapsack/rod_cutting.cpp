//practice.geeksforgeeks.org/problems/rod-cutting0840/1

#include <bits/stdc++.h>
using namespace std;

class Solution{
  public:
    int cutRod(int price[], int n) {
        vector<vector<int>> dp(n + 1, vector<int> (n + 1, 0));
        vector<int> length(n);
        for (int i = 0; i < n; ++i)
            length[i] = i + 1;
        for (int i = 0; i < n + 1; ++i) {
            for (int j = 0; j < n + 1; ++j) {
                if (i == 0)
                    dp[i][j] = 0;
                else if (j == 0)
                    dp[i][j] = 0;
                else {
                    if (length[i - 1] <= j)
                        dp[i][j] = max(price[i - 1] + dp[i][j - length[i - 1]], dp[i - 1][j]);
                    else
                        dp[i][j] = dp[i - 1][j];
                }
            }
        }
        return dp[n][n];
    }
};