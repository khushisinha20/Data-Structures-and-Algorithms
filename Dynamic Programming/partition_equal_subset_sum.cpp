//leetcode.com/problems/partition-equal-subset-sum/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool hasSubsetWithTargetSum(vector<int>& nums, int target) {
        vector<vector<bool>> dp(nums.size() + 1, vector<bool> (target + 1, false));
        for (int i = 0; i < nums.size() + 1; ++i) {
            for (int j = 0; j < target + 1; ++j) {
                if (j == 0)
                    dp[i][j] = true;
                else if (i == 0)
                    dp[i][j] = false;
                else {
                    if (nums[i - 1] <= j)
                        dp[i][j] = dp[i - 1][j - nums[i - 1]] || dp[i - 1][j];
                    else
                        dp[i][j] = dp[i - 1][j];
                }
            }
        }
        return dp[nums.size()][target];
    }
    
    bool canPartition(vector<int>& nums) {
        int totalSum = accumulate(nums.begin(), nums.end(), 0);
        return totalSum % 2 == 0 ? hasSubsetWithTargetSum(nums, totalSum / 2) : false;
    }
};