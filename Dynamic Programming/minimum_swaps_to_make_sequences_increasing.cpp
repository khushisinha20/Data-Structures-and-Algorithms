//leetcode.com/problems/minimum-swaps-to-make-sequences-increasing/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int helper(vector<int>& nums1, vector<int>& nums2, int index, bool isSwapped, vector<vector<int>>& dp) {
        int n = nums1.size();
        if (index >= n)
            return 0;

        if (dp[index][isSwapped] != -1)
            return dp[index][isSwapped];

        int previous1 = nums1[index - 1];
        int previous2 = nums2[index - 1];

        if (isSwapped)
            swap(previous1, previous2);

        int ans = INT_MAX;
        if (nums1[index] > previous1 and nums2[index] > previous2)
            ans = helper(nums1, nums2, index + 1, false, dp);

        if (nums2[index] > previous1 and nums1[index] > previous2)
            ans = min(ans, 1 + helper(nums1, nums2, index + 1, true, dp));

        return dp[index][isSwapped] = ans;
    }

    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        nums1.insert(nums1.begin(), -1);
        nums2.insert(nums2.begin(), -1);
        int n = nums1.size();
        vector<vector<int>> dp(n + 1, vector<int> (2, -1));
        return helper(nums1, nums2, 1, false, dp);
    }
};
