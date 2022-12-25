//leetcode.com/problems/target-sum/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if ((sum < abs(target)) || ((sum + target) % 2 != 0))
            return 0;
        
        int subsetSum1 = (sum + target) / 2;
        vector<vector<int>> dp(nums.size() + 1, vector<int> (subsetSum1 + 1, 0));
        
        dp[0][0] = 1;
        
        for (int i = 1; i < nums.size() + 1; ++i) {
            for (int j = 0; j < subsetSum1 + 1; ++j) {
                if (nums[i - 1] <= j)
                    dp[i][j] = dp[i - 1][j] + dp[i - 1][j - nums[i - 1]];
                else
                    dp[i][j] = dp[i - 1][j];
            }
        }
        return dp[nums.size()][subsetSum1];
    }
};