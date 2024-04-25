//leetcode.com/problems/sorting-three-groups/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestNonDecreasingSubsequence(vector<vector<int>>& dp, vector<int>& nums, int index, int previous) {
        if (index >= nums.size())
            return 0;

        if (dp[index][previous] != -1)
            return dp[index][previous];

        int take = 0;
        int notTake = 0;

        if (nums[index] >= previous) {
            take = 1 + longestNonDecreasingSubsequence(dp, nums, index + 1, nums[index]);
        }

        notTake = longestNonDecreasingSubsequence(dp, nums, index + 1, previous);

        return dp[index][previous] = max(take, notTake);
    }

    int minimumOperations(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(4, -1));
        return n - longestNonDecreasingSubsequence(dp, nums, 0, 0);
    }
};
