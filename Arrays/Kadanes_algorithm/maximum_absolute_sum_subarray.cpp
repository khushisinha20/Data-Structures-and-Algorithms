//leetcode.com/problems/maximum-absolute-sum-of-any-subarray/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int current_positive_sum =0;
        int current_negative_sum = 0;
        int overall_sum = 0;
        for (int i = 0; i < nums.size(); ++i) {
            current_positive_sum += nums[i];
            current_negative_sum += nums[i];
            overall_sum = max(overall_sum, max(current_positive_sum, abs(current_negative_sum)));
            if (current_positive_sum < 0)
                current_positive_sum = 0;
            if (current_negative_sum > 0)
                current_negative_sum = 0;
        }
        return overall_sum;
    }
};