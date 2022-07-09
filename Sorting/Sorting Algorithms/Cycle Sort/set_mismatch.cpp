//leetcode.com/problems/set-mismatch/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void cycleSort(vector<int>& nums) {
        int i = 0;
        while (i < nums.size()) {
            int correct_index = nums[i] - 1;
            if (nums[i] != nums[correct_index])
                swap(nums[i], nums[correct_index]);
            else
                ++i;
        }
    }
    
    vector<int> findErrorNums(vector<int>& nums) {
        cycleSort(nums);
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] != i + 1) 
                return {nums[i], i + 1};   
        }
        return {-1, -1};
    }
};
