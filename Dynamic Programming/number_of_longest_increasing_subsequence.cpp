//leetcode.com/problems/number-of-longest-increasing-subsequence/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1);
        vector<int> countOfLIS(n, 1);
        
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[j] < nums[i]) {
                    if (dp[i] == dp[j] + 1)
                        countOfLIS[i] += countOfLIS[j];
                    else if (dp[i] < dp[j] + 1) {
                        dp[i] = dp[j] + 1;
                        countOfLIS[i] = countOfLIS[j];
                    }
                }
            }
        }
        
        int maxLengthLIS = *max_element(dp.begin(), dp.end());
        int result = 0;
        
        for (int i = 0; i < countOfLIS.size(); ++i) {
            if (dp[i] == maxLengthLIS)
                result += countOfLIS[i];
        }
        
        return result;
    }
};