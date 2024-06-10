#include <bits/stdc.h>
using namespace std;

class Solution {
public:
    const int MOD = 1000000007;

    int numberOfSets(int n, int k) {
        vector<vector<int>> dp(n + 1, vector<int> (k + 1, 0));
        vector<vector<int>> prefixSum(n, vector<int> (k + 1, 0));

        for (int i = 0; i <= n; ++i)
            dp[i][0] = 1;

        for (int i = 1; i < n; ++i) {
            for (int j = 1; j <= k; ++j) {
                if (j <= i)
                    prefixSum[i][j] = (prefixSum[i - 1][j] + dp[i - 1][j - 1]) % MOD;
                dp[i][j] = (prefixSum[i][j] + dp[i - 1][j]) % MOD;
            }
        }

        return dp[n - 1][k];
    }
};
