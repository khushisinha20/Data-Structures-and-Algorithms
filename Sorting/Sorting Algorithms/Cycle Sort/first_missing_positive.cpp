//leetcode.com/problems/first-missing-positive/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void cycleSort(vector<int>& nums) {
        int i = 0;
        while (i < nums.size()) {
            long long correct_index = (long long) nums[i] - 1ll;
            if (nums[i] > 0 && nums[i] <= nums.size() && nums[i] != nums[correct_index])
                swap(nums[i], nums[correct_index]);
            else
                ++i;
        }
    }
    
    int firstMissingPositive(vector<int>& nums) {
        cycleSort(nums);
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] != i + 1)
                return i + 1;
        }
        return nums.size() + 1; 
    }
};