//leetcode.com/problems/minimum-cost-to-merge-stones/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> getPrefixSum(vector<int>& stones) {
        int n = stones.size();
        vector<int> prefixSum(n, 0);
        prefixSum[0] = stones[0];
        for (int i = 1; i < n; ++i)
            prefixSum[i] = prefixSum[i - 1] + stones[i];
        return prefixSum;
    }

    int helper(vector<int>& prefixSum, vector<vector<int>>& dp, int& k, int i, int j) {
        if (j - i + 1 < k)
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];

        int minCost = INT_MAX;

        for (int m = i; m < j; m += (k - 1)) {
            minCost = min(minCost, helper(prefixSum, dp, k, i, m) + helper(prefixSum, dp, k, m + 1, j));
        }

        if ((j - i) % (k - 1) == 0)
            minCost += (i == 0 ? prefixSum[j] : prefixSum[j] - prefixSum[i - 1]);

        return dp[i][j] = minCost;
    }

    int mergeStones(vector<int>& stones, int k) {
        int n = stones.size();

        if ((n - 1) % (k - 1) != 0)
            return -1;

        vector<int> prefixSum = getPrefixSum(stones);
        vector<vector<int>> dp(n, vector<int> (n, -1));
        return helper(prefixSum, dp, k, 0, n - 1);
    }
};
