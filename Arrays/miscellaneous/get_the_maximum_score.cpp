//leetcode.com/problems/get-the-maximum-score/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSum(vector<int>& nums1, vector<int>& nums2) {
        int i = 0, j = 0;
        long long sumFromNums1 = 0;
        long long sumFromNums2 = 0;
        long long result = 0;
        int MOD = 1e9 + 7;

        while (i < nums1.size() && j < nums2.size()) {
            if (nums1[i] < nums2[j]) {
                sumFromNums1 += nums1[i++];
            } else if (nums1[i] > nums2[j]) {
                sumFromNums2 += nums2[j++];
            } else {
                result = (result + max(sumFromNums1, sumFromNums2) + nums1[i]) % MOD;
                sumFromNums1 = 0;
                sumFromNums2 = 0;
                ++i;
                ++j;
            }
        }

        while (i < nums1.size()) {
            sumFromNums1 += nums1[i++];
        }

        while (j < nums2.size()) {
            sumFromNums2 += nums2[j++];
        }

        result = (result + max(sumFromNums1, sumFromNums2)) % MOD;

        return result;
    }
};

