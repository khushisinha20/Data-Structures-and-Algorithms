//leetcode.com/problems/allocate-mailboxes/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int getGroupCost(vector<int>& houses, int i, int j) {
        int median = houses[(i + j) / 2];
        int cost = 0;
        for (int p = i; p <= j; ++p)
            cost += abs(houses[p] - median);
        return cost;
    }

    int helper(vector<vector<int>>& dp, vector<vector<int>>& cost, int index, int k) {
        int n = cost.size();
        if (k == 0 and index == n)
            return 0;

        if (k == 0 or index == n)
            return INT_MAX;

        if (dp[index][k] != -1)
            return dp[index][k];

        int result = INT_MAX;
        for (int j = index; j < n; ++j) {
            int currentCost = cost[index][j];
            int next = helper(dp, cost, j + 1, k - 1);
            if (next != INT_MAX)
                result = min(result, currentCost + next);
        }

        return dp[index][k] = result;
    }

    int minDistance(vector<int>& houses, int k) {
        sort(houses.begin(), houses.end());
        int n = houses.size();

        vector<vector<int>> cost(n, vector<int> (n, 0));
        for (int i = 0; i < n; ++i) {
            for (int j = i; j < n; ++j) {
                cost[i][j] = getGroupCost(houses, i, j);
            }
        }

        vector<vector<int>> dp(n, vector<int> (k + 1, -1));
        return helper(dp, cost, 0, k);
    }
};
