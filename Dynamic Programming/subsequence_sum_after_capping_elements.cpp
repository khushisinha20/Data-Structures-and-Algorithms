//leetcode.com/problems/subsequence-sum-after-capping-elements/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<bool> subsequenceSumAfterCapping(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        vector<vector<int>> dp(n + 1, vector<int> (k + 1, false));
        for (int i = 0; i <= n; ++i) {
            dp[i][0] = true;
        }

        for (int i = 1; i <= n; ++i) {
            for (int sum = 0; sum <= k; ++sum) {
                dp[i][sum] = dp[i - 1][sum];
                if (sum - nums[i - 1] >= 0)
                    dp[i][sum] = dp[i][sum] || dp[i - 1][sum - nums[i - 1]];
            }
        }

        vector<bool> ans(n, false);
        for (int cap = 1; cap <= n; ++cap) {
            auto it = lower_bound(nums.begin(), nums.end(), cap);
            int index = it - nums.begin();
            int maxUse = n - index;

            for (int count = 0; count <= maxUse; ++count) {
                int remaining = k - count * cap;
                if (remaining >= 0 and dp[index][remaining]) {
                    ans[cap - 1] = true;
                }
            }
        }

        return ans;
    }
};
