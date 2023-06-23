//leetcode.com/problems/longest-arithmetic-subsequence/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n + 1, vector<int> (1002, 1));
        int longestLength = 1;
        int SHIFT = 501;
        
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                int diff = nums[i] - nums[j] + SHIFT;
                dp[i][diff] = max(1 + dp[j][diff], dp[i][diff]);
                longestLength = max(dp[i][diff], longestLength);
            }
        }
        
        return longestLength;
    }
};