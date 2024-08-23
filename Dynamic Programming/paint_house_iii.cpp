//leetcode.com/problems/paint-house-iii/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    const int INF = 1e9;

    int helper(vector<vector<vector<int>>>& dp, vector<int>& houses, vector<vector<int>>& cost, int index, int lastColor, int target) {
        if (index >= houses.size())
            return target == 0 ? 0 : INF;

        if (target < 0)
            return INF;

        if (dp[index][lastColor][target] != -1)
            return dp[index][lastColor][target];

        int minimumCost = INF;

        if (houses[index] != 0) {
            if (houses[index] == lastColor)
                minimumCost = helper(dp, houses, cost, index + 1, houses[index], target);
            else
                minimumCost = helper(dp, houses, cost, index + 1, houses[index], target - 1);
        } else {
            int totalColors = cost[0].size();
            for (int color = 1; color <= totalColors; ++color) {
                int paintingCost = cost[index][color - 1];
                if (color == lastColor)
                    minimumCost = min(minimumCost, paintingCost + helper(dp, houses, cost, index + 1, color, target));
                else
                    minimumCost = min(minimumCost, paintingCost + helper(dp, houses, cost, index + 1, color, target - 1));
            }
        }

        return dp[index][lastColor][target] = minimumCost;
    }

    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        vector<vector<vector<int>>> dp(m + 1, vector<vector<int>> (n + 1, vector<int> (target + 1, -1)));
        int result = helper(dp, houses, cost, 0, 0, target);
        return result == INF ? -1 : result;
    }
};
