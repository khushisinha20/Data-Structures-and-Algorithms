//leetcode.com/problems/minimum-cost-to-cut-a-stick/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int dp[102][102];

    int helper(vector<int>& cuts, int left, int right) {
        if (abs(left - right) < 2)
            return 0;

        if (dp[left][right] != -1)
            return dp[left][right];

        int result = INT_MAX;
        for (int i = left + 1; i <= right - 1; ++i) {
            int cost = helper(cuts, left, i) + helper(cuts, i, right) + (cuts[right] - cuts[left]);
            result = min(result, cost);
        }

        return dp[left][right] = result;
    }

    int minCost(int n, vector<int>& cuts) {
        memset(dp, -1, sizeof(dp));

        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(), cuts.end());

        return helper(cuts, 0, cuts.size() - 1);
    }
};
