//leetcode.com/problems/3sum-closest/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int result = nums[0] + nums[1] + nums[nums.size() - 1];
        for (int i = 0; i < nums.size() - 2; ++i) {
            int low = i + 1;
            int high = nums.size() - 1;
            while (low < high) {
                int current_sum = nums[i] + nums[low] + nums[high];
                if (current_sum > target)
                    --high;
                else
                    ++low;
                if (abs(current_sum - target) < abs(result - target))
                    result = current_sum;
            }
        }
        return result;
    }
};