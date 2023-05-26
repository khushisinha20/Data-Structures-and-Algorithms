//leetcode.com/problems/count-ways-to-build-good-strings/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int dp[301][11];

    int helper(vector<int>& jobDifficulty, int& n, int d, int index) {
        if (d == 1)
            return *max_element(jobDifficulty.begin() + index, jobDifficulty.end());

        if (dp[index][d] != -1)
            return dp[index][d];

        int maxDifficulty = INT_MIN;
        int result = INT_MAX;

        for (int i = index; i <= n - d; ++i) {
            maxDifficulty = max(maxDifficulty, jobDifficulty[i]);
            result = min(result, maxDifficulty + helper(jobDifficulty, n, d - 1, i + 1));
        }

        return dp[index][d] = result;
    }

    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int n = jobDifficulty.size();

        if (n < d)
            return -1;

        memset(dp, -1, sizeof(dp));
        return helper(jobDifficulty, n, d, 0);
    }
};
