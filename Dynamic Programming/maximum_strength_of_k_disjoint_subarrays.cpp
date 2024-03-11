//leetcode.com/problems/maximum-strength-of-k-disjoint-subarrays/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long helper(vector<vector<vector<long long>>>& dp, vector<int>& nums, int index, long long k, bool startNew) {
        if (k == 0)
            return 0;
        
        if (index >= nums.size())
            return -1e18;
        
        if (dp[index][k][startNew] != -1)
            return dp[index][k][startNew];
        
        long long notTake = -1e18;
        if (startNew) {
            notTake = helper(dp, nums, index + 1, k, startNew);
        } 
        
        long long take = -1e18;
        
        if (k % 2 != 0) {
            take = helper(dp, nums, index + 1, k, false) + nums[index] * k;
            take = max(take, helper(dp, nums, index + 1, k - 1, true) + nums[index] * k);
        } else {
            take = helper(dp, nums, index + 1, k, false) - nums[index] * k;
            take = max(take, helper(dp, nums, index + 1, k - 1, true) - nums[index] * k);
        }
        
        return dp[index][k][startNew] = max(take, notTake);
    }
    
    long long maximumStrength(vector<int>& nums, int k) {
        long long n = nums.size();
        vector<vector<vector<long long>>> dp(n + 1, vector<vector<long long>> (k + 1, vector<long long> (2, -1)));
        return helper(dp, nums, 0, k, true);
    }
};