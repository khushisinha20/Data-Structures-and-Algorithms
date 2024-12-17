//leetcode.com/problems/pizza-with-3n-slices/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int helper(int start, int end, vector<int>& slices, int n, vector<vector<int>>& dp) {
        if (n == 0 or start > end)
            return 0;

        if (dp[start][n] != -1)
            return dp[start][n];

        int take = slices[start] + helper(start + 2, end, slices, n - 1, dp);
        int notTake = helper(start + 1, end, slices, n, dp);

        return dp[start][n] = max(take, notTake);
    }

    int maxSizeSlices(vector<int>& slices) {
        int k = slices.size();
        vector<vector<int>> dp1(k, vector<int> (k, -1));
        int case1 = helper(0, k - 2, slices, k / 3, dp1);
        vector<vector<int>> dp2(k, vector<int> (k, -1));
        int case2 = helper(1, k - 1, slices, k / 3, dp2);
        return max(case1, case2);
    }
};
