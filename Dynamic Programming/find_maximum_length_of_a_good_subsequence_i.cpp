//leetcode.com/problems/find-the-maximum-length-of-a-good-subsequence-i/

#include <bits/stdc++.h>
using namespace std;

/*
class Solution {
public:
    int helper(vector<vector<vector<int>>>& dp, vector<int>& nums, int k, int previousIndex, int currentIndex) {
        if (currentIndex >= nums.size())
            return 0;

        if (dp[previousIndex + 1][currentIndex][k] != -1)
            return dp[previousIndex + 1][currentIndex][k];

        int take = 0;
        if (previousIndex == -1 || nums[previousIndex] == nums[currentIndex]) {
            take = 1 + helper(dp, nums, k, currentIndex, currentIndex + 1);
        } else if (nums[previousIndex] != nums[currentIndex] && k > 0) {
            take = 1 + helper(dp, nums, k - 1, currentIndex, currentIndex + 1);
        }

        int notTake = helper(dp, nums, k, previousIndex, currentIndex + 1);

        return dp[previousIndex + 1][currentIndex][k] = max(take, notTake);
    }

    int maximumLength(vector<int>& nums, int k) {
        int n = nums.size();
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(n + 1, vector<int>(k + 1, -1)));
        return helper(dp, nums, k, -1, 0);
    }
};
*/

class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        int n = nums.size();
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>> (n + 1, vector<int> (k + 1, 0)));

        for (int currentIndex = n - 1; currentIndex >= 0; --currentIndex) {
            for (int previousIndex = -1; previousIndex < currentIndex; ++previousIndex) {
                for (int transitionsLeft = 0; transitionsLeft <= k; ++transitionsLeft) {
                    int notTake = dp[previousIndex + 1][currentIndex + 1][transitionsLeft];
                    int take = 0;
                    if (previousIndex == -1 or nums[previousIndex] == nums[currentIndex])
                        take = 1 + dp[currentIndex + 1][currentIndex + 1][transitionsLeft];
                    else if (transitionsLeft > 0)
                        take = 1 + dp[currentIndex + 1][currentIndex + 1][transitionsLeft - 1];

                    dp[previousIndex + 1][currentIndex][transitionsLeft] = max(take, notTake);
                }
            }
        }

        return dp[0][0][k];
    }
};
