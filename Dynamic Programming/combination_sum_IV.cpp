//leetcode.com/problems/combination-sum-iv/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int helper(vector<int>& nums, vector<int>& dp, int target) {
        if (target < 0)
            return 0;
        
        if (target == 0)
            return 1;
        
        if (dp[target] != -1)
            return dp[target];
        
        int combinations = 0;
        for (int i = 0; i < nums.size(); ++i) {
            combinations += helper(nums, dp, target - nums[i]);
        }
        
        return dp[target] = combinations;
    }
    
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(target + 1, -1);
        return helper(nums, dp, target);
    }
};