//leetcode.com/problems/maximum-alternating-subsequence-sum/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long dp[1000001][2];
    
    long long helper(vector<int>& nums, int index, bool isEven) {
        if (index >= nums.size())
            return 0;
        
        if (dp[index][isEven] != -1)
            return dp[index][isEven];
        
        long long skip = helper(nums, index + 1, isEven);
        
        long long val = nums[index];
        if (!isEven) {
            val = -val;
        }
        
        long long take = helper(nums, index + 1, !isEven) + val;
        
        return dp[index][isEven] = max(skip, take);
    }
    
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        memset(dp, -1, sizeof(dp));
        return helper(nums, 0, true);
    }
};
