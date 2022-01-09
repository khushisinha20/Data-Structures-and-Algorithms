//leetcode.com/problems/maximum-subarray/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int current_sum = nums[0];
        int overall_sum = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            if (current_sum >= 0) {
                current_sum += nums[i];
            } else {
                current_sum = nums[i];
            }
            if (current_sum > overall_sum) {
                overall_sum = current_sum;
            }
        }
        return overall_sum;
    }
};