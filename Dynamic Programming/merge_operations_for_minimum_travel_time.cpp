//leetcode.com/problems/merge-operations-for-minimum-travel-time/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int helper(int i, int k, int currRate, vector<int>& position, vector<int>& time, vector<vector<vector<int>>>& dp, int& n) {
        if (i == n - 1)
            return k > 0 ? INT_MAX : 0;

        if (dp[i][k][currRate] != -1)
            return dp[i][k][currRate];

        int result = INT_MAX;
        int skipMerge = helper(i + 1, k, time[i + 1], position, time, dp, n);
        if (skipMerge != INT_MAX) {
            int dist = position[i + 1] - position[i];
            result = min(result, dist * currRate + skipMerge);
        }

        if (k > 0) {
            int mergeTime = time[i + 1];
            int mergeCount = 0;

            for (int j = i + 2; j < n and mergeCount < k; ++j) {
                ++mergeCount;
                mergeTime += time[j];
                int performMerge = helper(j, k - mergeCount, mergeTime, position, time, dp, n);
                if (performMerge != INT_MAX) {
                    int dist = position[j] - position[i];
                    result = min(result, dist * currRate + performMerge);
                }
            }
        }

        return dp[i][k][currRate] = result;
    }

    int minTravelTime(int l, int n, int k, vector<int>& position, vector<int>& time) {
        int cumulativeTime = accumulate(time.begin(), time.end(), 0);
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>> (k + 1, vector<int> (cumulativeTime + 1, -1)));
        return helper(0, k, time[0], position, time, dp, n);
    }
};
