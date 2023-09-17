//leetcode.com/problems/arithmetic-slices/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int totalSlicesCount = 0;
        int currentSliceCount = 0;
        
        for (int i = 2; i < nums.size(); ++i) {
            if (nums[i] - nums[i - 1] == nums[i - 1] - nums[i - 2]) {
                ++currentSliceCount;
                totalSlicesCount += currentSliceCount;
            } else {
                currentSliceCount = 0;
            }
        }
        
    
        return totalSlicesCount;
    }
};