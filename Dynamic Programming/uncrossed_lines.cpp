//leetcode.com/problems/uncrossed-lines/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int dp[501][501];

    int helper(int i, int j, vector<int>& nums1, vector<int>& nums2) {
        if (i >= nums1.size() or j >= nums2.size())
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];

        if (nums1[i] == nums2[j])
            return dp[i][j] = 1 + helper(i + 1, j + 1, nums1, nums2);
        else {
            int fixI = helper(i, j + 1, nums1, nums2);
            int fixJ = helper(i + 1, j, nums1, nums2);
            return dp[i][j] = max(fixI, fixJ);
        }

        return 0;
    }

    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        memset(dp, -1, sizeof(dp));
        return helper(0, 0, nums1, nums2);
    }
};
