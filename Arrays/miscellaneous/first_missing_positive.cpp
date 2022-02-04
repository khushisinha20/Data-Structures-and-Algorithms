//leetcode.com/problems/first-missing-positive/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        bool contains_one = false;
        for (int n: nums) {
            if (n == 1) {
                contains_one = true;
                break;
            }
        }
        if (!contains_one)
            return 1;
        if (nums.size() == 1 && contains_one)
            return 2;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] < 1 || nums[i] > nums.size()) {
                nums[i] = 1;
            }
        }
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[abs(nums[i]) - 1] > 0) {
                nums[abs(nums[i]) - 1] *= -1;
            }
        }
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] > 0)
                return i + 1;
        }
        return nums.size() + 1;
    }
};