//leetcode.com/problems/maximum-sum-circular-subarray/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSubarraySum(vector<int>& nums) {
        int current_sum = nums[0];
        int overall_sum = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            if (current_sum >= 0) {
                current_sum += nums[i];
            } else {
                current_sum = nums[i];
            }
            overall_sum = max(overall_sum, current_sum);
        }
        return overall_sum;
    }
    
    bool areAllElementsNegative(vector<int>& nums) {
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] >= 0) {
                return false;
            }
        }
        return true;
    }
    
    int minSubarraySum(vector<int>& nums) {
        int current_sum = INT_MAX;
        int overall_sum = INT_MAX;
        for (int i = 0; i < nums.size(); ++i) {
            if (current_sum < 0) {
                current_sum += nums[i];
            } else {
                current_sum = nums[i];
            }
            overall_sum = min(overall_sum, current_sum);
        }
        return overall_sum;
    }
    
    
    int maxSubarraySumCircular(vector<int>& nums) {
        int sum = 0;
        for (int i = 0; i < nums.size(); ++i) {
            sum += nums[i];
        }
        if (areAllElementsNegative(nums)) {
            int max_element = nums[0];
            for (int i = 1; i < nums.size(); ++i) {
                max_element = max(max_element, nums[i]);
            }
            return max_element;
        }
        return max((sum - minSubarraySum(nums)), maxSubarraySum(nums));
    }
};