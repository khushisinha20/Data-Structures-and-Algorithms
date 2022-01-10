#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int current_max = nums[0];
        int overall_max = nums[0];
        int current_min = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] < 0) {
                swap(current_max, current_min);
            }
            current_max = max(nums[i], current_max * nums[i]);
            current_min = min(nums[i], current_min * nums[i]);
            overall_max = max(current_max, overall_max);
        }
        return overall_max;
    }
};