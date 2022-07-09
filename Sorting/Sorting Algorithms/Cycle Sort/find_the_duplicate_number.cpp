//leetcode.com/problems/find-the-duplicate-number/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int i = 0;
        while (i < nums.size()) {
            if (nums[i] != i + 1) {
                int correct_index = nums[i] - 1;
                if (nums[i] != nums[correct_index]) 
                    swap(nums[i], nums[correct_index]);
                else
                    return nums[i];
            } else
                ++i;
        }
        return -1;
    }
};