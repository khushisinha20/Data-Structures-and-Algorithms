//leetcode.com/problems/minimum-skips-to-arrive-at-meeting-on-time/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    double helper(vector<vector<double>>& dp, int index, int skips, vector<int>& dist, int speed) {
        if (index == dist.size())
            return 0;

        if (dp[index][skips] != -1)
            return dp[index][skips];

        double travelTime = (double)dist[index] / speed;

        double withoutSkip = ceil(helper(dp, index + 1, skips, dist, speed) + travelTime);
        double withSkip = (skips > 0) ? helper(dp, index + 1, skips - 1, dist, speed) + travelTime - (1e-7) : INT_MAX;

        return dp[index][skips] = min(withoutSkip, withSkip);
    }

    int minSkips(vector<int>& dist, int speed, int hoursBefore) {
        int n = dist.size();
        vector<vector<double>> dp(n, vector<double>(n + 1, -1));

        for (int skips = 0; skips <= n; ++skips) {
            if (helper(dp, 0, skips, dist, speed) <= hoursBefore)
                return skips;
        }

        return -1;
    }
};
