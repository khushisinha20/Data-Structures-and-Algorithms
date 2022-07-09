//leetcode.com/problems/find-all-duplicates-in-an-array/

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
    
    vector<int> findDuplicates(vector<int>& nums) {
        cycleSort(nums);
        vector<int> res;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] != i + 1)
                res.push_back(nums[i]);
        }
        return res;
    }
};