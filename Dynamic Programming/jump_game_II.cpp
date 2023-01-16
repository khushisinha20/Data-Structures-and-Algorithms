//leetcode.com/problems/jump-game-ii/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int helper(vector<int>& nums, vector<int>& dp, int index) {
        if (index == nums.size() - 1)
            return 0;
        
        if (dp[index] != -1)
            return dp[index];
        
        int jumps = nums[index];
        int minJumps = 1e9;
        
        for (int i = 1; i <= jumps; ++i) {
            if (index + i < nums.size()) {
                int currentJumps = 1 + helper(nums, dp, index + i);
                minJumps = min(minJumps, currentJumps);
            }
        }
        return dp[index] = minJumps;
    }
    
    int jump(vector<int>& nums) {
        vector<int> dp(nums.size() + 1, -1);
        return helper(nums, dp, 0);
    }
};