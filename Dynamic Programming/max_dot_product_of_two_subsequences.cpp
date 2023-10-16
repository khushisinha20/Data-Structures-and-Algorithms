//leetcode.com/problems/max-dot-product-of-two-subsequences/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int dp[501][501][2];
    
    int helper(vector<int>& nums1, int index1, vector<int>& nums2, int index2, int isEmpty) {
        int n1 = nums1.size();
        int n2 = nums2.size();

        if (index1 == n1 or index2 == n2) {
            if (isEmpty)
                return -1000000000;
            return 0;
        }

        if (dp[index1][index2][isEmpty] != -1)
            return dp[index1][index2][isEmpty];
        
        int skipFirst = helper(nums1, index1 + 1, nums2, index2, isEmpty);
        int take = nums2[index2] * nums1[index1] + helper(nums1, index1 + 1, nums2, index2 + 1, 0);
        int skipSecond = helper(nums1, index1, nums2, index2 + 1, isEmpty);
        
        return dp[index1][index2][isEmpty] = max(take, max(skipFirst, skipSecond));
    }

    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        memset(dp, -1, sizeof dp);
        return helper(nums1, 0, nums2, 0, 1);
    }
};
