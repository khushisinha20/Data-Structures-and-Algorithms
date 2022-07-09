//leetcode.com/problems/missing-number/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void cycleSort(vector<int>& nums) {
        int i = 0;
        while (i < nums.size()) {
            int correct_index = nums[i];
            if (nums[i] < nums.size() && nums[i] != nums[correct_index])
                swap(nums[i], nums[correct_index]);
            else
                ++i;
        }
    }
    
    int findMissingNumber(vector<int>& nums) {
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] != i)
                return i;
        }
        return nums.size();
    }
        
    int missingNumber(vector<int>& nums) {
        cycleSort(nums);
        return findMissingNumber(nums);
    }
};