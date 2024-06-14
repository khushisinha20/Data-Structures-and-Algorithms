//leetcode.com/problems/maximum-non-negative-product-in-a-matrix/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProductPath(vector<vector<int>>& grid) {
        const int MOD = 1000000007;
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<long long>> maxProduct(m, vector<long long> (n, 0));
        vector<vector<long long>> minProduct(m, vector<long long> (n, 0));

        maxProduct[0][0] = grid[0][0];
        minProduct[0][0] = grid[0][0];

        for (int i = 1; i < m; ++i)
            maxProduct[i][0] = minProduct[i][0] = maxProduct[i - 1][0] * grid[i][0];

        for (int j = 1; j < n; ++j)
            maxProduct[0][j] = minProduct[0][j] = maxProduct[0][j - 1] * grid[0][j];

        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                if (grid[i][j] >= 0) {
                    maxProduct[i][j] = max(maxProduct[i - 1][j], maxProduct[i][j - 1]) * grid[i][j];
                    minProduct[i][j] = min(minProduct[i - 1][j], minProduct[i][j - 1]) * grid[i][j];
                } else {
                    maxProduct[i][j] = min(minProduct[i - 1][j], minProduct[i][j - 1]) * grid[i][j];
                    minProduct[i][j] = max(maxProduct[i - 1][j], maxProduct[i][j - 1]) * grid[i][j];
                }
            }
        }

        long long result = maxProduct[m - 1][n - 1];
        if (result < 0)
            return -1;
        else
            return result % MOD;
    }
};
