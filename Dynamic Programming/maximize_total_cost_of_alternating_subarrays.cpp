//leetcode.com/problems/maximize-total-cost-of-alternating-subarrays/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long helper(vector<int>& nums, int index, bool isStartEven, vector<vector<long long>>& dp) {
        if (index >= nums.size())
            return 0;

        if (dp[index][isStartEven] != -1)
            return dp[index][isStartEven];

        long long extend = 0;
        long long startNew = 0;

        if (isStartEven) {
            extend = -nums[index] + helper(nums, index + 1, !isStartEven, dp);
        } else {
            extend = nums[index] + helper(nums, index + 1, !isStartEven, dp);
        }

        startNew = nums[index] + helper(nums, index + 1, true, dp);

        return dp[index][isStartEven] = max(extend, startNew);
    }

    long long maximumTotalCost(vector<int>& nums) {
        int n = nums.size();
        vector<vector<long long>> dp(n, vector<long long>(2, -1));
        return helper(nums, 0, false, dp);
    }
};
