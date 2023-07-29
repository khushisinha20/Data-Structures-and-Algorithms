//leetcode.com/problems/maximum-side-length-of-a-square-with-sum-less-than-or-equal-to-threshold/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> getPrefixSum(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                dp[i][j] = mat[i - 1][j - 1] + dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1];
            }
        }

        return dp;
    }

    int querySum(vector<vector<int>>& prefixSum, int row1, int col1, int row2, int col2) {
        return prefixSum[row2][col2] - prefixSum[row1 - 1][col2] - prefixSum[row2][col1 - 1] + prefixSum[row1 - 1][col1 - 1];
    }

    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        vector<vector<int>> prefixSum = getPrefixSum(mat);
        int n = mat.size();
        int m = mat[0].size();
        int maxSide = 0;

        for (int row = 1; row <= n; ++row) {
            for (int col = 1; col <= m; ++col) {
                for (int k = 1; k <= min(n, m); ++k) {
                    if (row + k - 1 <= n && col + k - 1 <= m) {
                        int sum = querySum(prefixSum, row, col, row + k - 1, col + k - 1);
                        if (sum <= threshold)
                            maxSide = max(maxSide, k);
                    }
                }
            }
        }

        return maxSide;
    }
};
