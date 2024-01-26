//leetcode.com/problems/out-of-boundary-paths/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    const int MOD = 1e9 + 7;

    int findPathsHelper(int m, int n, int maxMove, int row, int col, vector<vector<vector<int>>>& dp) {
        if (row < 0 or row >= m or col < 0 or col >= n)
            return 1;

        if (maxMove == 0)
            return 0;

        if (dp[row][col][maxMove] != -1)
            return dp[row][col][maxMove];

        long long result = 0;

        result = (result + findPathsHelper(m, n, maxMove - 1, row + 1, col, dp)) % MOD;
        result = (result + findPathsHelper(m, n, maxMove - 1, row, col + 1, dp)) % MOD;
        result = (result + findPathsHelper(m, n, maxMove - 1, row - 1, col, dp)) % MOD;
        result = (result + findPathsHelper(m, n, maxMove - 1, row, col - 1, dp)) % MOD;

        return dp[row][col][maxMove] = result;
    }

    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        vector<vector<vector<int>>> dp(m, vector<vector<int>> (n, vector<int> (maxMove + 1, -1)));
        return findPathsHelper(m, n, maxMove, startRow, startColumn, dp) % MOD;
    }
};
