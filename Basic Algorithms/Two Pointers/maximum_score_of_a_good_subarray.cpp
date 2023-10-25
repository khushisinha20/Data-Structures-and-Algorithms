//leetcode.com/problems/maximum-score-of-a-good-subarray/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        int n = nums.size();
        int left = k;
        int right = k;
        int currentMin = nums[k];
        int result = currentMin;
        
        while (left > 0 or right < n - 1) {
            int leftValue = left > 0 ? nums[left - 1] : 0;
            int rightValue = right < n - 1 ? nums[right + 1] : 0;
            
            if (leftValue < rightValue) {
                ++right;
                currentMin = min(currentMin, nums[right]);
            } else {
                --left;
                currentMin = min(currentMin, nums[left]);
            }
            
            result = max(result, currentMin * (right - left + 1));
        }
        
        return result;
    }
};